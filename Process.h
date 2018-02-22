#ifndef PROCESS_H
#define PROCESS_H
//----------------------------------
#include <string>
#include <stdexcept>
//----------------------------------
class Process
{
public:
    Process(const std::string &program= std::string());
    virtual ~Process();
    void close();

    void setProgram(const std::string& program);
    void start();

    ssize_t read(char *buffer, size_t count);
    bool eof();

protected:
    Process( const Process& ) = delete;
    Process& operator=( const Process& ) = delete;

private:
    std::string program_;
    FILE* pipe_;
};
//----------------------------------
#endif // PROCESS_H
