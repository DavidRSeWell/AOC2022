#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string text = "Hey you guy";

    int len = sizeof(text) / sizeof(text[0]);

    cout << text[0] << endl;
    cout << text[4] << endl;

    return 0;
    
}