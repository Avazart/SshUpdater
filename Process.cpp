#include "Process.h"
//------------------------------------------------------
#include <unistd.h>
//------------------------------------------------------
Process::Process(const std::string &program)
    :pipe_(nullptr),
     program_(program)

{
}

Process::~Process()
{
  close();
}

void Process::close()
{
    if(pipe_)
        pclose(pipe_);
}

void Process::setProgram(const std::string &program)
{
    program_= program;
}

void Process::start()
{
   pipe_ = popen(program_.c_str(), "r");
   if(!pipe_)
      throw std::runtime_error("Can not run proccess \""+program_+"\"");
}

ssize_t Process::read(char *buffer, size_t count)
{
   return fread(buffer,1,count, pipe_);
}

bool Process::eof()
{
   return feof(pipe_);
}
