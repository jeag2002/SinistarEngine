#include "core/db/DBConnection.h"


namespace core{
void DBConnection::createConn(std::string DB){

   if ( sqlite3_open(DB.c_str(), &dbfile) == SQLITE_OK ){
        logger->info("[DBConnection::createConn] connection successfully to local database [%s]",DB.c_str());
   }else{
        logger->warn("[DBConnection::createConn] connection error to local database [%s]",DB.c_str());
   }

}

void DBConnection::deleteConn(){
    sqlite3_close(dbfile);
}


char **DBConnection::queryConn(const char *queryData){
    int rc = 0;
    int res = 0;

    char **data;

    rc = sqlite3_prepare_v2(dbfile, queryData, -1, &statement, &zErrMsg);

    if ( rc == SQLITE_OK){

        logger->debug("[DBConnection::queryConnection] Get DATA Query [%s] ", queryData);

        int ctotal = sqlite3_column_count(statement);
        data = new char *[ctotal];
        res = sqlite3_step(statement);
        if ( res == SQLITE_ROW ){
            for ( int i = 0; i < ctotal; i++ ){
                std::string s = (char*)sqlite3_column_text(statement, i);
                data[i] = (char *)s.c_str();
                logger->debug("[DBConnection::queryConnection] col[%d] data[%s]",i,s.c_str());
             }
         }
         logger->debug("[DBConnection::queryConnection] --END DATA");


    }else{
        logger->warn("[DBConnection::queryConnection] Query [%s] errMsg [%s]", queryData, zErrMsg);
        data = new char *[1];
        data[0] = "";
    }

    logger->debug("[DBConnection::queryConnection] Get data size (col) [%d]",sizeof(data)/sizeof(data[0]));

    return data;
}

}
