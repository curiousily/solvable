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

#define NNegative(number) NotNegative(number, __FUNCTION__, __LINE__)

void WriteError(const std::string & message);
void WriteSuccess(const std::string & message);
void WriteSuccess();

template <typename Element>
void NotEmpty(const std::vector<Element> & v, const std::string & functionName, int line) {
    if(v.size() == 0)
        return;
}

void NotNegative(int num, const std::string & functionName, int line);

#endif // TESTER_HPP_INCLUDED
