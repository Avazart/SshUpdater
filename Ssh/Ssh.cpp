#include "Ssh.h"




void Ssh::init()
{
    int rc = libssh2_init (0);
    if(rc != 0)
    {
       throw SshException("libssh2 initialization failed (%d)\n");
    }
}


void Ssh::exit()
{
   libssh2_exit();
}
