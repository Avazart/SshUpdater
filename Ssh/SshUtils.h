#ifndef SSHUTILS_H
#define SSHUTILS_H
//---------------------------------------------------------
#include <string>
//---------------------------------------------------------
int createSocket(const std::string& host,int port=22);
//---------------------------------------------------------
#endif // SSHUTILS_H
