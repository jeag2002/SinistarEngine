#include "core/logs/LogEngine.h"

namespace core
{

LogEngine::LogEngine(){
    level = 0;
    typeLog = 0;
    pointer = 0;
    for(int i=0; i<SIZE_BUFFER; i++){buffer_logs[i]='\0';}
    push_log = SDL_CreateMutex();
    ownFile = DEFAULT_FILE;
};

std::string LogEngine::tagLevel(int level){

    std::string data;

    switch(level){
        case 1: data = "[DEBUG] "; break;
        case 2: data = "[INFO]  "; break;
        case 3: data = "[WARN]  "; break;
        case 4: data = "[ERROR] "; break;
        default:
                data = "[IDLE]  "; break;
    }
    return data;
}


std::string LogEngine::toChannel(int level){

    std::string data;

    switch(level){
        case 0: data = "[FILE] "; break;
        case 1: data = "[FILE][COUT] "; break;
        default:
                data = "[IDLE]  "; break;
    }

    return data;
}




void LogEngine::startUp(int level, int typeLog){
    this->level = level;
    this->typeLog = typeLog;

}

void LogEngine::setOwnFile(char *_file){
     ownFile = _file;
}

void LogEngine::shutDown(){

}

void LogEngine::deleteLogFile(){

    int flag = 0;
    flag = remove("./data/logs/Sin2DEng.log");

	if (flag!=0){
		std::cout << "error al borrar fichero de logs";
	}

}


std::string LogEngine::getDateTime(void){

  char buffer[SIZE_TIME];
  std::string output;
  time_t curtime;
  struct tm *loctime;

  curtime = time (NULL);
  loctime = localtime (&curtime);

  strftime (buffer, SIZE, "(%d/%m/%Y - %H:%M:%S) - ", loctime);

  output = buffer;

  return output;
}


void LogEngine::message(int type, const char *msg)
{
    std::string dateTime = getDateTime();
    FILE *f = fopen("./data/logs/Sin2DEng.log", "a");

    if (f) {
        fprintf(f, "\n%s%s - %s",tagLevel(type).c_str(), dateTime.c_str(),msg);
        fclose(f);
    }

    if (typeLog == TO_FILE_COUT){
        char buffer [SIZE_SCREEN];
        int value = sprintf (buffer, "\n%s%s - %s", tagLevel(type).c_str(), dateTime.c_str(), msg);
        if ((value > 0) && (value < SIZE_SCREEN)){
            std::cout << buffer;
        }
    }
}

void LogEngine::printLogFlag(){
          this->info("LogEngine - INITIALIZED! to %s Channel %s",tagLevel(level).c_str(), toChannel(typeLog).c_str());
};


void LogEngine::debug(const std::string fmt, ...){
    if (this->level <= DEBUG_LOG){

        SDL_LockMutex(push_log);

        va_list ap;
        char msg[SIZE];

        va_start(ap, fmt);
        int size_msg = vsnprintf(msg, (sizeof(msg)/sizeof(*msg))-1, fmt.c_str(), ap);

        if ((size_msg > 0) && (size_msg < SIZE)){
            message(DEBUG_LOG, msg);
        }

        SDL_UnlockMutex(push_log);
    }
}


void LogEngine::info(const std::string fmt, ...){
    if (this->level <= INFO_LOG){

        SDL_LockMutex(push_log);

        va_list ap;
        char msg[SIZE];

        va_start(ap, fmt);
        int size_msg = vsnprintf(msg, (sizeof(msg)/sizeof(*msg))-1, fmt.c_str(), ap);

        if ((size_msg > 0) && (size_msg < SIZE)){
            message(INFO_LOG, msg);
        }

        SDL_UnlockMutex(push_log);
    }
}


void LogEngine::warn(const std::string fmt, ...){
    if (this->level <= WARN_LOG){

        SDL_LockMutex(push_log);

        va_list ap;
        char msg[SIZE];

        va_start(ap, fmt);
        int size_msg = vsnprintf(msg, (sizeof(msg)/sizeof(*msg))-1, fmt.c_str(), ap);

        if ((size_msg > 0) && (size_msg < SIZE)){
            message(WARN_LOG, msg);
        }

        SDL_UnlockMutex(push_log);
    }
}


void LogEngine::error(const std::string fmt, ...){
    if (this->level <= ERROR_LOG){

        SDL_LockMutex(push_log);

        va_list ap;
        char msg[SIZE];

        va_start(ap, fmt);
        int size_msg = vsnprintf(msg, (sizeof(msg)/sizeof(*msg))-1, fmt.c_str(), ap);

        if ((size_msg > 0) && (size_msg < SIZE)){
            message(ERROR_LOG, msg);
        }

        SDL_UnlockMutex(push_log);
    }
}

}
