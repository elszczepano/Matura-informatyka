#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int a_counter = 0;

bool if_even(int number) {
    if(number%2==0) return true;
    else return false;
}

int main()
{
    fstream file;
    string file_line;
    file.open("liczby.txt", ios::in);
    while(getline(file, file_line)) {
        unsigned long long number_line=0;
        number_line = atoi(file_line.c_str());
        if(if_even(number_line)) a_counter++;
    }
    cout << a_counter << endl;
    file.close();
    return 0;
}
