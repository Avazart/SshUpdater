#ifndef SSH_H
#define SSH_H

#include <libssh2.h>
#include "SshException.h"
//----------------------------------------------------------------------------------
namespace Ssh
{
   void init();
   void exit();
}
//----------------------------------------------------------------------------------
#endif // SSH_H
