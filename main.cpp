#include <iostream>
#include "tester.hpp"

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
//    NotNegative(-1, __FUNCTION__, __LINE__);
    NotNegative(-1);
    vector<int> v;
    NotEmpty(v);
    WriteSuccess();
    return 0;
}
