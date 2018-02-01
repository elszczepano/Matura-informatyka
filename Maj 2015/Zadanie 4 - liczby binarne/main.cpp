#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int max_line = 1, min_line = 1, i=1;
string minimal ="111111111111", maximal;

bool checkZeros(string line) {
    int zeros=0, ones=0;
    for(unsigned i=0; i<line.length(); i++) {
        if(line[i]=='0') zeros++;
        else ones++;
    }
    if(zeros>ones) return true;
    else return false;
}
int toDecimal(string line) {
    int decimal = 0;
    for(unsigned i=0; i<line.length(); i++) {
        if(line[i]=='1') {
            decimal +=pow(2,line.length()-i-1);
        }
    }
    return decimal;
}
void minMax(string line) {
    if(line.size()>maximal.size()) {
        maximal = line;
        max_line = i;
    }
    if(line.size()==maximal.size()){
        if(line>maximal) {
            maximal = line;
            max_line = i;
        }
    }
    if(line.size()<minimal.size()) {
        minimal = line;
        min_line = i;
    }
    if(line.size()==minimal.size()) {
        if(line<minimal) {
            minimal = line;
            min_line = i;
        }
    }
    i++;
}
int main()
{
    fstream file;
    string line;
    int a_counter = 0, b_counter_2 = 0, b_counter_8 = 0;
    file.open("liczby.txt", ios::in);
    while(getline(file,line)) {
        if(checkZeros(line)) a_counter++;
        if(toDecimal(line)%2==0) b_counter_2++;
        if(toDecimal(line)%8==0) b_counter_8++;
        minMax(line);
    }
    file.close();
    cout << "A: " << endl;
    cout << "Wiecej zer niz jedynek: " << a_counter << endl;
    cout << "B: " << endl;
    cout << "Podzielne przez 2: " << b_counter_2 << endl;
    cout << "Podzielne przez 8: " << b_counter_8 << endl;
    cout << "C: " << endl;
    cout << "Najmniejsza(linia): " << min_line << endl;
    cout << "Najwieksza(linia): " << max_line << endl;
    return 0;
}
