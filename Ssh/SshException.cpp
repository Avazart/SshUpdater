#include "SshException.h"


std::string errorMessage(int code)
{
    switch(code)
    {
      case LIBSSH2_ERROR_ALLOC:
          return  "An internal memory allocation call failed";
      case LIBSSH2_ERROR_SOCKET_SEND:
          return "Unable to send data on socket.";
      case LIBSSH2_ERROR_TIMEOUT:
           return "Error timeout";
      case LIBSSH2_ERROR_SOCKET_TIMEOUT :
          return "Socket timeout";
      case LIBSSH2_ERROR_PUBLICKEY_UNVERIFIED :
          return  "The username/public key combination was invalid.";
      case LIBSSH2_ERROR_AUTHENTICATION_FAILED :
          return  "Authentication using the supplied public key was not accepted.";
      case LIBSSH2_ERROR_CHANNEL_CLOSED:
           return "The channel has been closed.";
      case LIBSSH2_ERROR_CHANNEL_EOF_SENT:
           return "The channel has been requested to be closed.";
      case LIBSSH2_ERROR_CHANNEL_REQUEST_DENIED:
           return "Reqest denied";
      case LIBSSH2_ERROR_SFTP_PROTOCOL:
         return "An invalid SFTP protocol response was received on the socket,"
                 "or an SFTP operation caused an errorcode to be returned by the server. ";
    }
    return std::string();
}
//---------------------------------------------------------------------------------------
// SshException
//---------------------------------------------------------------------------------------
SshException::SshException(const std::string &msg)
  : code_(0),
    message_(msg)
{
}

SshException::SshException(int code, const std::string &msg)
  :code_(code)
{
   message_ = errorMessage(code_);
   if (message_.empty())
      message_= msg;
}

const std::string SshException::message() const
{
    return message_;
}
//------------------------------------------------------------------
int SshException::code() const
{
    return code_;
}
//------------------------------------------------------------------
// EOFException
//------------------------------------------------------------------
EOFException::EOFException()
{

}
//------------------------------------------------------------------
const std::string EOFException::message() const
{
   return "End of file";
}
//------------------------------------------------------------------
