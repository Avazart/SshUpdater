#include "SshUtils.h"
//------------------------------------------------------------------------------------
#include <errno.h>
#include <stdio.h>
#include <ctype.h>

#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//------------------------------------------------------------------------------------
#include  <fstream>
#include "SshException.h"
//------------------------------------------------------------------------------------
int createSocket(const std::string& host,int port/*=22*/)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    unsigned long hostaddr= inet_addr(host.c_str());

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = hostaddr;
    if(connect(sock,(struct sockaddr*)(&sin),sizeof(struct sockaddr_in))!=0)
      throw SshException("Can not create socket!");

    return sock;
}
//------------------------------------------------------------------------------------



