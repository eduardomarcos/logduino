#include <Logduino.h>

Logduino::Logduino(const char* logger) { this->logger = logger; }
Logduino::~Logduino() {}

void Logduino::debug(const char* msg) { this->debug(msg, ""); }
void Logduino::debug(const char* msg, const int arg1) {
#ifdef __AVR__
    Serial.print("[");
    Serial.print(millis(), DEC);
    Serial.print("][");
    Serial.print(this->logger);
    Serial.print("]\e[38;5;71m[DEBUG]\e[1;0m::");
    Serial.print(msg);
    Serial.println(arg1);
#else
    stringstream converted;
    converted << arg1;
    this->debug(msg, converted.str().c_str(), "");
#endif
}
void Logduino::debug(const char* msg, const char* arg1) { this->debug(msg, arg1, ""); }
void Logduino::debug(const char* msg, const char* arg1, const char* arg2) { this->debug(msg, arg1, arg2, ""); }
void Logduino::debug(const char* msg, const char* arg1, const char* arg2, const char* arg3) {
#ifdef __AVR__
    Serial.print("[");
    Serial.print(millis(), DEC);
    Serial.print("][");
    Serial.print(this->logger);
    Serial.print("]\e[38;5;71m[DEBUG]\e[1;0m::");
    Serial.print(msg);
    Serial.print(arg1);
    Serial.print(arg2);
    Serial.println(arg3);
#else
    time_t t = time(NULL);
    struct tm* lt = localtime(&t);
    char date[9];
    date[strftime(date, sizeof(date), "%H:%M:%S", lt)] = '\0';
    cout << "[" << date << "]"
         << "[" << std::setw(this->widthLoggerName) << this->logger << "]\e[38;5;71m["
         << std::setw(this->widthVerboseName) << "DEBUG]\e[1;0m::" << msg << arg1 << arg2 << arg3 << endl;
#endif
}

void Logduino::info(const char* msg) { this->info(msg, ""); }
void Logduino::info(const char* msg, const char* arg1) {
#ifdef __AVR__
    Serial.print("[");
    Serial.print(millis(), DEC);
    Serial.print("][");
    Serial.print(this->logger);
    Serial.print("]\e[38;5;214m[ INFO]\e[1;0m::");
    Serial.print(msg);
    Serial.println(arg1);
#else
    time_t t = time(NULL);
    struct tm* lt = localtime(&t);
    char date[9];
    date[strftime(date, sizeof(date), "%H:%M:%S", lt)] = '\0';
    cout << "[" << date << "]"
         << "[" << std::setw(this->widthLoggerName) << this->logger << "]\e[38;5;214m["
         << std::setw(this->widthVerboseName) << "INFO]::\e[1;0m" << msg << arg1 << endl;
#endif
}

void Logduino::error(const char* msg) {
#ifdef __AVR__
    Serial.print("[");
    Serial.print(millis(), DEC);
    Serial.print("][");
    Serial.print(this->logger);
    Serial.print("]\e[38;5;1m[ERROR]\e[1;0m::");
    Serial.println(msg);
#else
    time_t t = time(NULL);
    struct tm* lt = localtime(&t);
    char date[9];
    date[strftime(date, sizeof(date), "%H:%M:%S", lt)] = '\0';
    cout << "[" << date << "]"
         << "[" << std::setw(this->widthLoggerName) << this->logger << "]\e[38;5;1m["
         << std::setw(this->widthVerboseName) << "ERROR]\e[1;0m::" << msg << endl;
#endif
}