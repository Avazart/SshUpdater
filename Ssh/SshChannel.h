#ifndef SSHCHANNEL_H
#define SSHCHANNEL_H

#include <libssh2.h>
#include "SshException.h"
//----------------------------------------------------------------------------------
class SshChannel
{
public:
    explicit SshChannel(LIBSSH2_SESSION* session);
    virtual ~SshChannel();
    void close();


    void processStartup(const std::string& request,
                        const std::string& message);

    void shell();
    void subsystem(const std::string &subsystemStr);
    void exec(const std::string& command);


    int exitStatus();


    enum IgnoreMode:int
    {
      /* Extended Data Handling */
       normal = LIBSSH2_CHANNEL_EXTENDED_DATA_NORMAL,//        0
       ignore = LIBSSH2_CHANNEL_EXTENDED_DATA_IGNORE,//        1
       merge = LIBSSH2_CHANNEL_EXTENDED_DATA_MERGE,//         2
       stderr = SSH_EXTENDED_DATA_STDERR// 1
     };

    void setHandleExtendedData(int ignoreMode);

    ssize_t read(char *buffer, std::size_t bufferLength,int streamId= 0);
    ssize_t write(const char *buffer, std::size_t bufferLength, int streamId=0);

    bool eof();
    void sendEof();

    int exitStatus() const;

    SshChannel(SshChannel&& sshChannel);
    SshChannel& operator=(SshChannel&& sshChannel);
protected:
    SshChannel( const SshChannel& ) = delete;
    SshChannel& operator=( const SshChannel& ) = delete;

private:
    LIBSSH2_CHANNEL *channel_;
};
//----------------------------------------------------------------------------------
#endif // SSHCHANNEL_H
