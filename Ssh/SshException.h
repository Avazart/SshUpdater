#ifndef SSHEXCEPTION_H
#define SSHEXCEPTION_H

#include <libssh2.h>
#include <string>
//-----------------------------------------------------
std::string errorMessage(int code);
//-----------------------------------------------------
class Exception
{
public:
    virtual const std::string message() const=0;
    virtual ~Exception(){}
};
// ---------------------------------------------------------------------------
class EOFException: public Exception
{
  public:
    EOFException();
    const std::string message()const;
};
//-----------------------------------------------------
class SshException: public Exception
{
public:
    explicit SshException(const std::string& msg);
    explicit SshException(int code,const std::string& msg=std::string());

    virtual const std::string message() const;
    virtual int code() const;
private:
    int code_;
    std::string message_;
};
//-----------------------------------------------------
#endif // SSHEXCEPTION_H
