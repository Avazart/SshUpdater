#ifndef SFTP_H
#define SFTP_H
//-----------------------------------------------------------------------------------------------
#include <libssh2.h>
#include <libssh2_sftp.h>
#include <string>
#include "SshException.h"
//-----------------------------------------------------------------------------------------------
class SftpHandle
{
public:
    explicit SftpHandle(LIBSSH2_SFTP_HANDLE* handle);
    ~SftpHandle();
    void close();


    SftpHandle(SftpHandle&& sftpHandle);
    SftpHandle& operator=(SftpHandle&& sftpHandle);

    ssize_t write(const char *buffer,size_t count);
    ssize_t read(char *buffer,size_t count);

protected:
    SftpHandle( const SftpHandle& ) = delete;
    SftpHandle& operator=( const SftpHandle& ) = delete;
private:
    LIBSSH2_SFTP_HANDLE *handle_;
};
//-----------------------------------------------------------------------------------------------
class Sftp
{
public:
    enum OpenFlag:unsigned long
    {
      read=   LIBSSH2_FXF_READ,
      write = LIBSSH2_FXF_WRITE,
      append= LIBSSH2_FXF_APPEND,
      create= LIBSSH2_FXF_CREAT,
      tranc=  LIBSSH2_FXF_TRUNC,
      excl=   LIBSSH2_FXF_EXCL
    };

    enum FileMode:long
    {
      irwxu = LIBSSH2_SFTP_S_IRWXU,    //   0000700     /* RWX mask for owner */
      irusr = LIBSSH2_SFTP_S_IRUSR,    //   0000400     /* R for owner */
      iwusr = LIBSSH2_SFTP_S_IWUSR,    //   0000200     /* W for owner */
      ixusr = LIBSSH2_SFTP_S_IXUSR,    //   0000100     /* X for owner */
       /* Read, write, execute/search by group */
      irwxg = LIBSSH2_SFTP_S_IRWXG,    //   0000070     /* RWX mask for group */
      irgrp = LIBSSH2_SFTP_S_IRGRP,    //   0000040     /* R for group */
      iwgrp = LIBSSH2_SFTP_S_IWGRP,    //   0000020     /* W for group */
      ixgrp = LIBSSH2_SFTP_S_IXGRP,    //   0000010     /* X for group */
       /* Read, write, execute/search by others */
      irwxo = LIBSSH2_SFTP_S_IRWXO,    //   0000007     /* RWX mask for other */
      iroth = LIBSSH2_SFTP_S_IROTH,    //   0000004     /* R for other */
      iwoth = LIBSSH2_SFTP_S_IWOTH,    //   0000002     /* W for other */
      ixoth = LIBSSH2_SFTP_S_IXOTH     //   0000001     /* X for other */
    };

    enum OpenType:int
    {
        file = LIBSSH2_SFTP_OPENFILE,
        dir =  LIBSSH2_SFTP_OPENDIR
    };


    explicit Sftp(LIBSSH2_SESSION* session);
    virtual ~Sftp();
    void  shutdown();

    SftpHandle open(const std::string& filename,
                    unsigned long flags,
                    long mode=0,
                    int openType= OpenType::file)const;


    void put(const std::string& srcFileName,
                const std::string& destFileName, std::size_t bufferSize=2048);

    Sftp(Sftp&& sftp);
    Sftp& operator=(Sftp&& sftp);
protected:
    Sftp( const Sftp& ) = delete;
    Sftp& operator=( const Sftp& ) = delete;

private:
    LIBSSH2_SFTP *sftp_;
};
//-----------------------------------------------------------------------------------------------
#endif // SFTP_H
