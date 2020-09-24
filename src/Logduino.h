#ifndef LOG_H
#define LOG_H

#ifdef __AVR__
#include <Arduino.h>
#include <stdio.h>
#include <time.h>
#else
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#endif

class Logduino {
   private:
    const char* logger;
    const uint8_t widthLoggerName = 8;
    const uint8_t widthVerboseName = 14;

   public:
    Logduino(const char* logger);
    ~Logduino();

    void debug(const char*);
    void debug(const char*, const int);
    void debug(const char*, const char*);
    void debug(const char*, const char*, const char*);
    void debug(const char*, const char*, const char*, const char*);

    void info(const char*);
    void info(const char*, const char*);

    void error(const char*);
};

#endif