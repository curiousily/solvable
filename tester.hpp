#ifndef TESTER_HPP_INCLUDED
#define TESTER_HPP_INCLUDED

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>

#define NotNegative(number) tsNotNegative(number, __FUNCTION__, __LINE__)
#define NotEmpty(vector) tsNotEmpty(vector, __FUNCTION__, __LINE__)
#define HasElements(vector, elementCount) tsHasElementCount(vector, elementCount, __FUNCTION__, __LINE__)

void WriteError(const std::string & message);
void WriteSuccess(const std::string & message);
void WriteSuccess();

std::string ToInt(int number);
std::string BuildFunctionErrorMessage(const std::string & functionName, int line);

template <typename Element>
void tsNotEmpty(const std::vector<Element> & v, const std::string & functionName, int line) {
    if(v.size() == 0) {
        std::string errorMessage = BuildFunctionErrorMessage(functionName, line) + "vector is empty expected: NOT EMPTY. actual: EMPTY";
        WriteError(errorMessage);
    }
}

template <typename Element>
void tsHasElementCount(const std::vector<Element> & v, int elementCount, const std::string & functionName, int line) {
    if(v.size() != elementCount) {
        std::string errorMessage = BuildFunctionErrorMessage(functionName, line) + "incorrect element count expected: " + ToInt(elementCount) + ". actual: " + ToInt(v.size());
        WriteError(errorMessage);
    }
}

void tsNotNegative(int num, const std::string & functionName, int line);

#endif // TESTER_HPP_INCLUDED
