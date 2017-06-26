#ifndef STDAFX_H_INCLUDED
#define STDAFX_H_INCLUDED

#ifdef WIN32
#include <windows.h>
#include <process.h>
#include <stddef.h>
#include <tchar.h>
#include <winbase.h>
#include <psapi.h>
#include <tchar.h>
#endif // WIN32

#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <time.h>

#include <algorithm>
#include "sqlite3.h"

#include <SDL.h>
#undef main

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif



using namespace std;

//funciones macro comunes
#define DEBUGLOG(X)(gLogEngine->debug(X))
#define DEBUGLOGPONE(X,Y)(gLogEngine->debug(X,Y))
#define DEBUGLOGPTWO(X,Y,Z)(gLogEngine->debug(X,Y,Z))
#define DEBUGLOGPTHREE(X,Y,Z,Q)(gLogEngine->debug(X,Y,Z,Q))
#define DEBUGLOGPFOUR(X,Y,Z,Q,R)(gLogEngine->debug(X,Y,Z,Q,R))
#define DEBUGLOGPFIVE(X,Y,Z,Q,R,S)(gLogEngine->debug(X,Y,Z,Q,R,S))
#define DEBUGLOGPSIX(X,Y,Z,Q,R,S,T)(gLogEngine->debug(X,Y,Z,Q,R,S,T))
#define DEBUGLOGPSEVEN(X,Y,Z,Q,R,S,T,U)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U))
#define DEBUGLOGPEIGHT(X,Y,Z,Q,R,S,T,U,V)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U,V))
#define DEBUGLOGPNINE(X,Y,Z,Q,R,S,T,U,V,W)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U,V,W))
#define DEBUGLOGPTEN(X,Y,Z,Q,R,S,T,U,V,W,A)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U,V,W,A))
#define DEBUGLOGPELEVEN(X,Y,Z,Q,R,S,T,U,V,W,A,B)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U,V,W,A,B))
#define DEBUGLOGPTWELVE(X,Y,Z,Q,R,S,T,U,V,W,A,B,C)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U,V,W,A,B,C))
#define DEBUGLOGPTHIRTEEN(X,Y,Z,Q,R,S,T,U,V,W,A,B,C,D)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U,V,W,A,B,C,D))

#define INFOLOG(X)(gLogEngine->info(X))
#define INFOLOGPONE(X,Y)(gLogEngine->info(X,Y))
#define INFOLOGPTWO(X,Y,Z)(gLogEngine->info(X,Y,Z))
#define INFOLOGPTHREE(X,Y,Z,Q)(gLogEngine->info(X,Y,Z,Q))
#define INFOLOGPFOUR(X,Y,Z,Q,R)(gLogEngine->info(X,Y,Z,Q,R))
#define INFOLOGPFIVE(X,Y,Z,Q,R,S)(gLogEngine->info(X,Y,Z,Q,R,S))
#define INFOLOGPSIX(X,Y,Z,Q,R,S,T)(gLogEngine->info(X,Y,Z,Q,R,S,T))
#define INFOLOGPSEVEN(X,Y,Z,Q,R,S,T,U)(gLogEngine->info(X,Y,Z,Q,R,S,T,U))
#define INFOLOGPEIGHT(X,Y,Z,Q,R,S,T,U,V)(gLogEngine->info(X,Y,Z,Q,R,S,T,U,V))
#define INFOLOGPNINE(X,Y,Z,Q,R,S,T,U,V,W)(gLogEngine->info(X,Y,Z,Q,R,S,T,U,V,W))
#define INFOLOGPTEN(X,Y,Z,Q,R,S,T,U,V,W,A)(gLogEngine->info(X,Y,Z,Q,R,S,T,U,V,W,A))
#define INFOLOGPELEVEN(X,Y,Z,Q,R,S,T,U,V,W,A,B)(gLogEngine->info(X,Y,Z,Q,R,S,T,U,V,W,A,B))
#define INFOLOGPTWELVE(X,Y,Z,Q,R,S,T,U,V,W,A,B,C)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U,V,W,A,B,C))
#define INFOLOGPTHIRTEEN(X,Y,Z,Q,R,S,T,U,V,W,A,B,C,D)(gLogEngine->debug(X,Y,Z,Q,R,S,T,U,V,W,A,B,C,D))

#define WARNLOG(X)(gLogEngine->warn(X))
#define WARNLOGPONE(X,Y)(gLogEngine->warn(X,Y))
#define WARNLOGPTWO(X,Y,Z)(gLogEngine->warn(X,Y,Z))

#define ERRORLOG(X)(gLogEngine->error(X))
#define ERRORLOGP(X,Y)(gLogEngine->error(X,Y))

#define btoa(x) ((x)?"true":"false")1

#endif // STDAFX_H_INCLUDED
