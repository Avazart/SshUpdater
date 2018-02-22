#include "Sftp.h"
//-----------------------------------------------------------------------
#include <fstream>
//-----------------------------------------------------------------------
//  Handle
//-----------------------------------------------------------------------
SftpHandle::SftpHandle(LIBSSH2_SFTP_HANDLE *handle)
  :handle_(handle)
{

}
//-----------------------------------------------------------------------
SftpHandle::~SftpHandle()
{
  close();
}
//-----------------------------------------------------------------------
void SftpHandle::close()
{
    if(handle_)
        libssh2_sftp_close_handle(handle_);
}
//-----------------------------------------------------------------------
SftpHandle::SftpHandle(SftpHandle &&sftpHandle)
   :handle_(sftpHandle.handle_)
{
    sftpHandle.handle_= nullptr;
}
//-----------------------------------------------------------------------
SftpHandle &SftpHandle::operator=(SftpHandle &&sftpHandle)
{
    if(handle_ != sftpHandle.handle_)
    {
      handle_ = sftpHandle.handle_;
      sftpHandle.handle_= nullptr;
    }
    return *this;
}
//-----------------------------------------------------------------------
ssize_t SftpHandle::write(const char *buffer, size_t count)
{
    ssize_t length = libssh2_sftp_write(handle_,buffer,count);
    if(length<0)
        throw SshException(length);

    return length;
}
//-----------------------------------------------------------------------
ssize_t SftpHandle::read(char *buffer, size_t count)
{
    ssize_t length = libssh2_sftp_read(handle_,buffer,count);
    if(length<0)
        throw SshException(length);

    return length;
}
//-----------------------------------------------------------------------
// SFTP
//-----------------------------------------------------------------------
Sftp::Sftp(LIBSSH2_SESSION *session)
{
    sftp_ = libssh2_sftp_init(session);
    if(!sftp_)
    {
       throw SshException("Unable to open a sftp session!");
    }
}
//-----------------------------------------------------------------------
Sftp::~Sftp()
{
   shutdown();
}
//-----------------------------------------------------------------------
void Sftp::shutdown()
{
    if(sftp_)
        libssh2_sftp_shutdown(sftp_);
}
//-----------------------------------------------------------------------
SftpHandle Sftp::open(const std::string &filename,
                      unsigned long flags,
                      long mode,
                      int openType) const
{
    LIBSSH2_SFTP_HANDLE * handle =
     libssh2_sftp_open_ex(sftp_,
                          filename.c_str(),
                          filename.size(),
                          flags,
                          mode,
                          openType);

    if(!handle)
    {
       throw SshException(libssh2_sftp_last_error(sftp_),"libssh2_sftp_open_ex() failed!");
    }

    return SftpHandle(handle);
}
//-----------------------------------------------------------------------
void Sftp::put(const std::string& srcFileName,
               const std::string& destFileName,
               std::size_t bufferSize /*=2048*/)
{
  std::ifstream ofs(srcFileName.c_str(),std::ios::binary);
  if(!ofs)
     throw SshException("File \""+srcFileName+"\" not found!");

  const unsigned long flags = Sftp::OpenFlag::write|Sftp::OpenFlag::create|Sftp::OpenFlag::tranc;
  const long mode =   Sftp::FileMode::irusr|Sftp::FileMode::iwusr|Sftp::FileMode::irgrp|Sftp::FileMode::iroth;
  const int openType= Sftp::OpenType::file;

  SftpHandle handle = Sftp::open(destFileName,flags,mode,openType);

  char buffer[bufferSize];
  while(ofs)
  {
     ofs.read(buffer,bufferSize);
     if(ofs.gcount())
        handle.write(buffer,ofs.gcount());
  }
}
//-----------------------------------------------------------------------
Sftp::Sftp(Sftp &&sftp)
   :sftp_(sftp.sftp_)
{
   sftp.sftp_= nullptr;
}
//-----------------------------------------------------------------------
Sftp &Sftp::operator=(Sftp &&sftp)
{
    if(sftp_ != sftp.sftp_)
    {
      sftp_ = sftp.sftp_;
      sftp.sftp_= nullptr;
    }
    return *this;
}
//-----------------------------------------------------------------------



