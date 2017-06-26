#include "core/logs/ProfileEngine.h"

namespace core
{
    ProfileEngine::ProfileEngine(int level){
        log = new LogEngine();
        log->setOwnFile("PROFILENGINE.log");
        log->deleteLogFile();
        log->startUp(level,0);
        log->printLogFlag();
    }

    ProfileEngine::~ProfileEngine(){
    }

    void ProfileEngine::setRefIniTime(const char *msg){
        initTime = SDL_GetTicks();
        char msg_1[1000];
        for(int i=0; i<1000; i++){msg_1[1000]='\0';}
        sprintf(msg_1,"%s - INI",msg);
        log->debug("%s",msg_1);
    }

    void ProfileEngine::setRefFinTime(const char *msg){
        long endTime = SDL_GetTicks();
        char msg_1[1000];
        for(int i=0; i<1000; i++){msg_1[1000]='\0';}
        long time = endTime -initTime;

        endTime = 0;
        initTime = 0;

        sprintf(msg_1,"%s - END TIME [%d] MS",msg,time);
        log->debug("%s",msg_1);
    }

    void ProfileEngine::setMsg(const char *msg){
        log->debug("%s",msg);
    }

    #ifdef WIN32

    void ProfileEngine::printVirtualMemoryUsed(){

        MEMORYSTATUS memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUS);
        GlobalMemoryStatus(&memInfo);
        DWORDLONG totalVirtualMem = memInfo.dwTotalPageFile;

        DWORDLONG virtualMemUsed = memInfo.dwTotalPageFile - memInfo.dwAvailPageFile;

        PROCESS_MEMORY_COUNTERS pmc;
        GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
        SIZE_T virtualMemUsedByMe = pmc.PagefileUsage;

        log->debug("\ttotVirtMem:\t%011d\tbytes\tvirtMemUsed:\t%011d\tbytes\tvirtMemUsedByMe:\t%011d\tbytes",totalVirtualMem,virtualMemUsed,virtualMemUsedByMe);

    }

    void ProfileEngine::printRAMMemoryUsed(){
        MEMORYSTATUS memInfo;
        memInfo.dwLength = sizeof(MEMORYSTATUS);
        GlobalMemoryStatus(&memInfo);

        DWORDLONG totalPhysMem = memInfo.dwTotalPhys;

        DWORDLONG physMemUsed = memInfo.dwTotalPhys - memInfo.dwAvailPhys;

        PROCESS_MEMORY_COUNTERS pmc;
        GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));

        SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

        log->debug("\ttotPhysMem:\t%011d\tbytes\tphysMemUsed:\t%011d\tbytes\tphysMemUsedByMe:\t%011d\tbytes",totalPhysMem,physMemUsed,physMemUsedByMe);

    }

    void ProfileEngine::printCPUUsed(){

        ULARGE_INTEGER lastCPU, lastSysCPU, lastUserCPU;
        int numProcessors;
        HANDLE self;

        SYSTEM_INFO sysInfo;
        FILETIME ftime, fsys, fuser;
        ULARGE_INTEGER now, sys, user;
        double percent;

        GetSystemInfo(&sysInfo);
        numProcessors = sysInfo.dwNumberOfProcessors;

        GetSystemTimeAsFileTime(&ftime);
        memcpy(&lastCPU, &ftime, sizeof(FILETIME));

        self = GetCurrentProcess();
        GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
        memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
        memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));

        GetSystemTimeAsFileTime(&ftime);
        memcpy(&now, &ftime, sizeof(FILETIME));

        GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
        memcpy(&sys, &fsys, sizeof(FILETIME));
        memcpy(&user, &fuser, sizeof(FILETIME));
        percent = (sys.QuadPart - lastSysCPU.QuadPart) +
            (user.QuadPart - lastUserCPU.QuadPart);
        percent /= (now.QuadPart - lastCPU.QuadPart);
        percent /= numProcessors;
        lastCPU = now;
        lastUserCPU = user;
        lastSysCPU = sys;

        log->debug("\tPercentCPUUsedByMe:\t\t%011f\tpercent",(percent*100));
    }

    #endif // WIN32
}
