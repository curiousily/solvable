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

std::string BuildFunctionErrorMessage(const std::string & functionName, int line) {
    std::stringstream out;
    out << line;
    return "[" + functionName + ":" + out.str() + "] ";
}

std::string ToInt(int number) {
    std::stringstream out;
    out << number;
    return out.str();
}

void tsNotNegative(int num, const std::string & functionName, int line) {
    if(num < 0) {
        std::stringstream out;
        out << num;
        std::string errorMessage = BuildFunctionErrorMessage(functionName, line) + out.str() + " expected: POSITIVE. actual: NEGATIVE";
        WriteError(errorMessage);
    }
}
