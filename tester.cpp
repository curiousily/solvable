#include "tester.hpp"

const char * colorTemplate = "\E[%dm\E[%dm\E[%dm%s\n";
const char * resetColors = "\E[0m";

void WriteError(const std::string & message) {
    printf(colorTemplate, 1, 31, 40, message.c_str());
    printf("%s", resetColors);
//    printf("%s\n", message.c_str());
}

void WriteSuccess(const std::string & message) {
    printf(colorTemplate, 1, 32, 40, message.c_str());
    printf("%s", resetColors);
}

void WriteSuccess() {
    WriteSuccess("Success!");
}

void NotNegative(int num, const std::string & functionName, int line) {
    if(num < 0) {
        std::stringstream out;
        out << num;
        std::stringstream lineOut;
        lineOut << line;
        std::string errorMessage = "[" + functionName + ":" + lineOut.str() + "] " + out.str() + " expected: POSITIVE. actual: NEGATIVE";
        WriteError(errorMessage);
    }
}
