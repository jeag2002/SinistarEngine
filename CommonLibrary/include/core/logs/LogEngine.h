#include "Stdafx.h"

#ifndef LOGENGINE_H_INCLUDED
#define LOGENGINE_H_INCLUDED

#define TO_FILE 0
#define TO_FILE_COUT 1

#define DEBUG_LOG 1
#define INFO_LOG 2
#define WARN_LOG 3
#define ERROR_LOG 4
#define FATAL_LOG 5

#define SIZE 500
#define SIZE_SCREEN 550
#define SIZE_BUFFER 3580
#define SIZE_TIME 50

#define DEFAULT_FILE "DEFAULT.log"


namespace core{

class DLL_EXPORT LogEngine{

    public:

       /*0=all, 1=debug, 2=info, 3=warn, 4=error, 5=fatal*/
       LogEngine();
       void deleteLogFile();
       void startUp(int level, int typeLog);
       void shutDown();

       void printLogFlag();

       void setOwnFile(char *_file);
       void debug(const std::string fmt, ...);
       void info(const std::string fmt, ...);
       void warn(const std::string fmt, ...);
       void error(const std::string fmt, ...);


    private:

       int level;
       int typeLog;
       void message(int type, const char *msg);
       char buffer_logs[SIZE_BUFFER];
       char *ownFile;
       SDL_mutex *push_log;
       int pointer;

       std::string getDateTime(void);
       std::string tagLevel(int level);
       std::string toChannel(int level);
};

}

#endif // LOGMANAGER_H_INCLUDED
