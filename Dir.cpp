#include "Dir.h"
//-------------------------------------------------------------------
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
//-------------------------------------------------------------------
#include <memory>
#include <cstring>
//-------------------------------------------------------------------
Strings entryList(const std::string &path)
{
    Strings files;
    std::unique_ptr<DIR, int(*)(DIR*)>
            dir(opendir(path.c_str()),&closedir);
    if(!dir)
        return files;

    struct dirent *dirp= readdir(dir.get());
    while(dirp)
    {
      if(strcmp(dirp->d_name,".")!=0  && strcmp(dirp->d_name,"..")!=0)
         files.push_back(dirp->d_name);

      dirp = readdir(dir.get());
    }

    return files;
}
//-------------------------------------------------------------------
/*
S_ISDIR — directory
S_ISREG — regular file
S_ISCHR — character device
S_ISBLK — block device
S_ISFIFO — FIFO
S_ISLNK — symbolic link
S_ISSOCK — socket
*/
//-------------------------------------------------------------------
bool isDir(const std::string &path)
{
    struct stat sb;
    if(stat(path.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode))
        return true;
    return false;
}
//-------------------------------------------------------------------
bool isRegularFile(const std::string &path)
{
    struct stat sb;
    if(stat(path.c_str(), &sb) == 0 && S_ISREG(sb.st_mode))
        return true;
    return false;
}
//-------------------------------------------------------------------
const std::string pathSeparators= "\\/";
//-------------------------------------------------------------------
std::string fileName(const std::string& path)
{
  std::size_t s= path.find_last_of(pathSeparators);
  if(s==std::string::npos)
    return path;

  return path.substr(s+1,path.size()-(s+1));
}
//-------------------------------------------------------------------

