#include "Stdafx.h"
#include "LogEngine.h"

#ifndef PROFILEENGINE_H_INCLUDED
#define PROFILEENGINE_H_INCLUDED

namespace core
{

class DLL_EXPORT ProfileEngine{

public:

    ProfileEngine(int level);
    ~ProfileEngine();
    void setRefIniTime(const char *msg);
    void setRefFinTime(const char *msg);

    void setMsg(const char *msg);
    void setCalculateSizeOfTAD(const char *msg, long capacity){};
    void printVirtualMemoryUsed();
    void printRAMMemoryUsed();
    void printCPUUsed();

private:

    LogEngine *log;
    long initTime;

};

}

#endif // PROFILEENGINE_H_INCLUDED
