#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int a_counter=0, b_counter=0, c_counter=0;

bool if_multiple(int first,int second) {
    if(second%first==0||first%second==0) a_counter++;
    return false;
}

unsigned GCD(unsigned first, unsigned second) {
    while ( second != 0) {
        unsigned r = first % second;
        first = second;
        second = r;
    }
    return first;
}
int sum(int number) {
    int sum=0;
    char temp[5];
    itoa(number,temp,10);
    for(int i=0; i<5; i++) {
        if(temp[i] == 0)
            break;
        sum+=temp[i] - '0';
    }
    return sum;
}
int main()
{
    string fileLine;
    fstream file;
    int first=0, second=0;
    file.open("PARY_LICZB.TXT", ios::in);
    while(file >> first >> second) {
        if_multiple(first,second);
        if(GCD(first, second)==1) b_counter++;
        if(sum(first)==sum(second)) c_counter++;
    }
    cout << a_counter << endl;
    cout << b_counter << endl;
    cout << c_counter << endl;
    return 0;
}
