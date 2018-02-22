#include <iostream>
#include <fstream>

// SSH
#include "Ssh/Ssh.h"
#include "Ssh/SshSession.h"

// Json
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

// Dir
#include "Dir.h"

// Sub proccess
#include "Process.h"
//-------------------------------------------------------------------------------------
const std::string cmds[2]=
{
    "apt update && apt -y full-upgrade",
    "apt -y autoremove"
};

const std::size_t bufferSize= 256;
//-------------------------------------------------------------------------------------
bool updateLocalPackages(std::ostream& log);

void workWithServer(const std::string& host,
                    int port,
                    const std::string& userName,
                    const std::string& password,
                    const Strings &patches,
                    const Strings &destDirs,
                    std::ostream& log);

int  execute(SshSession& session,
             const std::string& command,
             std::ostream& log);

void updatePackages(SshSession& session,
                    std::ostream& log);

void putPatches(SshSession& session,
                const Strings& patches,
                const Strings& destDirs,
                std::ostream& log);
//-------------------------------------------------------------------------------------
int main()
{
//    std::cout<< "[update local packages:]" <<std::endl;
//    if(!updateLocalPackages(std::cout))
//        return 1;

    Ssh::init();

    std::ifstream ifs("./config.json");
    if(!ifs)
    {
        std::cerr<< "File \"config.json\" not found!" << std::endl;
        return 2;
    }
    rapidjson::IStreamWrapper isw(ifs);
    rapidjson::Document document;
    document.ParseStream(isw);

    if(!document.IsObject() || !document.HasMember("servers"))
    {
        std::cerr<< "Json parsing error is not object!" << std::endl;
        return 3;
    }

    const rapidjson::Value& patchesValue = document["patches"];
    if(!patchesValue.IsArray())
    {
        std::cerr<< "Json parsing error \"patches\" is not array!" << std::endl;
        return 4;
    }

    Strings patches;
    for(const rapidjson::Value& patchValue: patchesValue.GetArray())
    {
        if(patchValue.IsString())
            patches.push_back(patchValue.GetString());
    }

    const rapidjson::Value& seversValue = document["servers"];
    if(!seversValue.IsArray())
    {
        std::cerr<< "Json parsing error \"servers\" is not array!" << std::endl;
        return 5;
    }

    for(const rapidjson::Value& server: seversValue.GetArray())
    {
        if(server.HasMember("host") &&
           server.HasMember("port") &&
           server.HasMember("username") &&
           server.HasMember("password") &&
           server.HasMember("destDirs") &&

           server["host"].IsString() &&
           server["port"].IsInt() &&
           server["username"].IsString() &&
           server["password"].IsString() &&
           server["destDirs"].IsArray() )
        {
            std::string host = server["host"].GetString();
            int port = server["port"].GetInt();
            std::string userName = server["username"].GetString();
            std::string password = server["password"].GetString();

            const rapidjson::Value& destDirsValue = server["destDirs"];
            Strings destDirs;
            for(const rapidjson::Value& destDirValue: destDirsValue.GetArray())
            {
                if(destDirValue.IsString())
                    destDirs.push_back(destDirValue.GetString());
            }


            std::cout<< std::endl <<"["<< userName <<"@"<< host << "]"<<std::endl;
            try
            {
                workWithServer(host, port, userName, password, patches, destDirs, std::cout);
            }
            catch(const SshException& e)
            {
                std::cerr<<"[Ssh error \"" <<e.message()<<"\""<< e.code()<<"]"<< std::endl;
            }
        }
        else
        {
            std::cerr<< "Json parsing error \"server\" has not one of members!" << std::endl;
        }
    }


    Ssh::exit();
    std::cout<< "Done!" << std::endl;
    return 0;
}
//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
bool updateLocalPackages(std::ostream& log)
{
    try
    {
        char buffer[bufferSize];
        for(std::string cmd :cmds)
        {
            log<< "["<<cmd<<"]"<<std::endl;
            Process process(cmd);
            process.start();
            while(!process.eof())
            {
                ssize_t length=  process.read(buffer,bufferSize);
                if(length>0)
                    log<< std::string(buffer,length);
                else
                    break;
            }
        }
    }
    catch(const std::runtime_error& e)
    {
        log<<"["<<e.what()<<"]"<<std::endl;
        return false;
    }
    return true;
}
//-------------------------------------------------------------------------------------
void workWithServer(const std::string& host,
                    int port,
                    const std::string& userName,
                    const std::string& password,
                    const Strings& patches,
                    const Strings &destDirs,
                    std::ostream& log)
{
    SshSession session;
    session.handshake(host,port);
    session.setTimeout(30000);
    session.userAuthPassword(userName,password);

    updatePackages(session,log);
    putPatches(session,patches,destDirs,log);
}
//-------------------------------------------------------------------------------------
int execute(SshSession& session,const std::string& command,std::ostream& log)
{
    SshChannel channel = session.channel();
    channel.setHandleExtendedData(SshChannel::IgnoreMode::merge);

    char buffer[bufferSize];
    channel.exec(command);
    while(!channel.eof())
    {
        ssize_t length=  channel.read(buffer,bufferSize);
        if(length>0)
            log<< std::string(buffer,length);
    }
    log<< "[Finished with exit code: "<< channel.exitStatus()<<"]"<< std::endl;
    return channel.exitStatus();
}
//-------------------------------------------------------------------------------------
void updatePackages(SshSession& session,std::ostream& log)
{
    log<< "["<<cmds[0]<<"]"<<std::endl;
    if(execute(session,cmds[0],log)==0)
    {
        log<< "["<<cmds[1]<<"]"<<std::endl;
        execute(session,cmds[1],log);
    }
}
//-------------------------------------------------------------------------------------
void putPatches(SshSession& session,
                   const Strings& patches,
                   const Strings& destDirs,
                   std::ostream& log)
{
    Sftp sftp= session.sftp();
    for(const std::string& destDir:destDirs)
        for(const std::string& patchFile:patches)
        {
            const std::string newFile = destDir+'/'+fileName(patchFile);
            try
            {
                log<<"[Sftp put: \""<< patchFile<<"\" to \""+newFile+"\"]"<<std::endl;
                sftp.put(patchFile,newFile);
            }
            catch(const SshException& e)
            {
                log<<"[Can not upload patch: \""<< patchFile<<"\" "
                  <<"to: \""<< newFile<<"\" "
                 <<"\""<< e.message()<<"\" #"<< e.code()<<"]"<< std::endl;
            }
        }
}
//-------------------------------------------------------------------------------------
