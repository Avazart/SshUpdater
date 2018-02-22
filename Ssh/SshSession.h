#ifndef SSHCLIENT_H
#define SSHCLIENT_H

#include <libssh2.h>

#include <sstream>
#include <iomanip>

#include "SshException.h"
#include "SshChannel.h"
#include "Sftp.h"

class SshSession
{
public:
    SshSession();
    virtual ~SshSession();

    void handshake(int sock);

    void handshake(const std::string& host,int port=22);

    void disconnect();


     std::string hostkeyHashString(const std::string& sep = " ");
     std::string userAuthList(const std::string& userName);


     void userAuthPassword(const std::string& userName,
                           const std::string& password);


     void userAuthPublicKeyFromFile(const std::string& publicKeyFileName,
                                    const std::string& privateKeyFileName,
                                    const std::string& userName,
                                    const std::string& passwordPhrase);


     SshChannel channel()const;
     Sftp sftp()const;

     void setBlocking(bool blocking);

     void setTimeout(long timeout);

     SshSession(SshSession&& sshSession);
     SshSession& operator=(SshSession&& sshSession);
protected:
     SshSession( const SshSession& ) = delete;
     SshSession& operator=( const SshSession& ) = delete;

private:
     LIBSSH2_SESSION* session_;
     bool connected_;
};

#endif // SSHCLIENT_H
