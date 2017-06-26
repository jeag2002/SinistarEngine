#include "Stdafx.h"
#include "core/logs/LogEngine.h"

#ifndef DBCONNECTION_H
#define DBCONNECTION_H

namespace core
{

class DLL_EXPORT DBConnection{

public:

DBConnection(LogEngine *_logger){
    logger = _logger;
};

~DBConnection(){
};

void createConn(std::string DB);
void deleteConn();

char **queryConn(const char *query);

private:

LogEngine *logger;
sqlite3 *dbfile;
sqlite3_stmt *statement;
const char *zErrMsg;

};

}
#endif // DBCONNECTION_H
