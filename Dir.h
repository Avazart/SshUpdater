#ifndef DIR_H
#define DIR_H
//-------------------------------------------------------------------
#include <vector>
#include <string>

typedef std::vector<std::string> Strings;
//-------------------------------------------------------------------
Strings entryList(const std::string& path);
bool isDir(const std::string& path);
bool isRegularFile(const std::string &path);
std::string fileName(const std::string& path);
//-------------------------------------------------------------------
#endif // DIR_H
