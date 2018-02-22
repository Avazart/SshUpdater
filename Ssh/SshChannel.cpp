#include "SshChannel.h"

SshChannel::SshChannel(LIBSSH2_SESSION *session)
{
   channel_ = libssh2_channel_open_session(session);
   if(!channel_)
   {
      throw SshException("Unable to open a session!");
   }
}

SshChannel::~SshChannel()
{
  close();
}

void SshChannel::close()
{
    if(channel_)
    {
      libssh2_channel_free(channel_);
      channel_= 0;
    }
}

void SshChannel::processStartup(const std::string &request, const std::string &message)
{
   int rc = libssh2_channel_process_startup(channel_,
                                            request.c_str(),
                                            request.size(),
                                            message.c_str(),
                                            message.size());
   if(!rc)
      throw SshException("libssh2_channel_process_startup error!");
}

void SshChannel::shell()
{
    /* Open a SHELL on that pty */
   if(libssh2_channel_shell(channel_))
       throw SshException("Unable to request shell on allocated pty!");
}

void SshChannel::subsystem(const std::string &subsystemStr)
{
  if(libssh2_channel_subsystem(channel_,subsystemStr.c_str()))
      throw SshException("Unable to request subsystem on allocated pty!");
}

void SshChannel::exec(const std::string &command)
{
  if(libssh2_channel_exec(channel_,command.c_str()))
      throw SshException("Unable to request exec on allocated pty!");
}

int SshChannel::exitStatus()
{
    return libssh2_channel_get_exit_status(channel_);
}

void SshChannel::setHandleExtendedData(int ignoreMode)
{
   libssh2_channel_handle_extended_data(channel_,ignoreMode);
}

ssize_t SshChannel::read(char *buffer, std::size_t bufferLength, int streamId)
{
  ssize_t rc= libssh2_channel_read_ex(channel_,streamId,buffer, bufferLength);

  if(rc<0)
      throw SshException(rc,"libssh2_channel_read_ex failed");

  return rc;
}

ssize_t SshChannel::write(const char *buffer, std::size_t bufferLength, int streamId)
{
  ssize_t rc= libssh2_channel_write_ex(channel_, streamId, buffer, bufferLength);

  if(rc<0)
      throw SshException(rc,"libssh2_channel_write_ex failed");

  return rc;
}

bool SshChannel::eof()
{
  return libssh2_channel_eof(channel_)==1;
}

void SshChannel::sendEof()
{
    libssh2_channel_send_eof(channel_);
}

int SshChannel::exitStatus() const
{
  return libssh2_channel_get_exit_status(channel_);
}

SshChannel::SshChannel(SshChannel &&sshChannel)
{
  channel_ = sshChannel.channel_;
  sshChannel.channel_ = nullptr;
}

SshChannel &SshChannel::operator=(SshChannel &&sshChannel)
{
  if(channel_ != sshChannel.channel_)
  {
    channel_ = sshChannel.channel_;
    sshChannel.channel_ = nullptr;
  }
  return *this;
}
