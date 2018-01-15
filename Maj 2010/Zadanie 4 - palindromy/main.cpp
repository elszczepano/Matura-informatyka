#include <iostream>
#include <fstream>

using namespace std;

bool ifPalindrom(string test)
{
    string reverseString;
    for(int i=0; i<test.length(); i++)
    {
        reverseString+=test[test.length()-(i+1)];
    }
    if(reverseString==test) return cout<<test<<endl;
    else return false;
}

int main()
{
    string fileLine;
    fstream palindroms;
    palindroms.open("dane.txt", ios::in);
    while(getline(palindroms, fileLine))
    {
        ifPalindrom(fileLine);
    }
    return 0;
}
