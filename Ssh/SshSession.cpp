#include "SshSession.h"
#include "SshUtils.h"
//------------------------------------------------------------------------------------
SshSession::SshSession()
    :connected_(false)
{
    session_  = libssh2_session_init();
}
//------------------------------------------------------------------------------------
SshSession::~SshSession()
{
    disconnect();

    if(session_)
        libssh2_session_free(session_);
}
//------------------------------------------------------------------------------------
void SshSession::handshake(int sock)
{
    if(libssh2_session_handshake(session_, sock))
        throw SshException("Failure establishing SSH session");

    connected_= true;
}
//------------------------------------------------------------------------------------
void SshSession::handshake(const std::string &host, int port)
{
   SshSession::handshake(createSocket(host,port));
}
//------------------------------------------------------------------------------------
void SshSession::disconnect()
{
    if(connected_)
    {
        libssh2_session_disconnect(session_,"Normal Shutdown, Thank you for playing");
        connected_= false;
    }
}
//------------------------------------------------------------------------------------
std::string SshSession::hostkeyHashString(const std::string& sep)
{
    const std::string s = libssh2_hostkey_hash(session_, LIBSSH2_HOSTKEY_HASH_SHA1);
    std::ostringstream ss;
    for(std::size_t i = 0; i < s.size(); ++i)
        ss<< std::hex
          << std::uppercase
          << std::setw(2)
          << std::setfill('0')
          << (int)(unsigned char)s[i]
             << sep;
    return ss.str();
}
//------------------------------------------------------------------------------------
std::string SshSession::userAuthList(const std::string &userName)
{
    return libssh2_userauth_list(session_,userName.c_str(),userName.size());
}
//------------------------------------------------------------------------------------
void SshSession::userAuthPassword(const std::string &userName, const std::string &password)
{
   int rc= libssh2_userauth_password(session_,userName.c_str(),password.c_str());
   if(rc!=0)
       throw SshException(rc,"Authentication by password failed!");
}
//------------------------------------------------------------------------------------
void SshSession::userAuthPublicKeyFromFile(const std::string &publicKeyFileName,
                                           const std::string &privateKeyFileName,
                                           const std::string &userName,
                                           const std::string &passwordPhrase)
{
    int rc =libssh2_userauth_publickey_fromfile_ex(session_,
                                                   userName.c_str(),
                                                   userName.size(),
                                                   publicKeyFileName.c_str(),
                                                   privateKeyFileName.c_str(),
                                                   passwordPhrase.c_str());


    if(rc!=0)
       throw SshException(rc,"libssh2_userauth_publickey_fromfile_ex() failed");
}
//------------------------------------------------------------------------------------
SshChannel SshSession::channel() const
{
    return SshChannel(session_);
}
//------------------------------------------------------------------------------------
Sftp SshSession::sftp() const
{
    return Sftp(session_);
}
//------------------------------------------------------------------------------------
void SshSession::setBlocking(bool blocking)
{
    libssh2_session_set_blocking(session_,blocking);
}
//------------------------------------------------------------------------------------
void SshSession::setTimeout(long timeout)
{
   libssh2_session_set_timeout(session_,timeout);
}
//------------------------------------------------------------------------------------
SshSession::SshSession(SshSession &&sshSession)
    :session_(sshSession.session_),
     connected_(sshSession.connected_)
{
    sshSession.session_= nullptr;
    sshSession.connected_= false;
}
//------------------------------------------------------------------------------------
SshSession &SshSession::operator=(SshSession &&sshSession)
{
    if(session_ != sshSession.session_)
    {
        session_ = sshSession.session_;
        connected_ = sshSession.connected_;

        sshSession.session_= nullptr;
        sshSession.connected_= false;
    }
    return *this;
}
//------------------------------------------------------------------------------------
