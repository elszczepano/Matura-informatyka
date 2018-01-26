#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <sstream>

using namespace std;

int c_min = 9999999, c_max = 0;

bool check_a(string line) {
    if(line[0]==line[line.length()-1]) return true;
    else return false;
}
int octalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}
bool check_c(string line) {
    for(int i=1; i<line.length(); i++) {
        if(line[i-1]>line[i]) return false;
    }
    if(atoi(line.c_str())>c_max) c_max = atoi(line.c_str());
    if(atoi(line.c_str())<c_min) c_min = atoi(line.c_str());
    return true;
}
int main()
{
    fstream file;
    string line = "";
    int a_counter = 0, b_counter = 0, c_counter = 0;
    file.open("dane.txt", ios::in);
    while (getline(file, line)) {
        int decimalValue = 0, numArr[10];
        if(check_a(line)) a_counter++;
        decimalValue = octalToDecimal(atoi(line.c_str()));
        cout << decimalValue << endl;
        int decimalValueStr = decimalValue;
        ostringstream ss;
        ss << decimalValueStr;
        string str = ss.str();
        if(check_a(str)) b_counter++;
        if(check_c(line)) c_counter++;
    }
    cout << a_counter << endl;
    cout << b_counter << endl;
    cout << c_counter << endl;
    cout << "Maksymalna: " << c_max << " Minimalna: " << c_min << endl;
    return 0;
}
