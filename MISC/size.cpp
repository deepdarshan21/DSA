#include <iostream>
using namespace std;

int main()
{
    cout << "Size of \"int\" data type is " << sizeof(int) << " bytes" << endl;
    cout << "Size of \"short int\" data type is " << sizeof(short int) << " bytes" << endl;
    cout << "Size of \"char\" data type is " << sizeof(char) << " bytes" << endl;
    cout << "Size of \"long int\" data type is " << sizeof(long int) << " bytes" << endl;
    cout << "Size of \"long long int\" data type is " << sizeof(long long int) << " bytes" << endl;
    /* cout << "Size of \"long long long int\" data type is " << sizeof(long long long int) << " bytes" << endl; */ //its error bcz more than 2 long not defined in C++
    return 0;
}