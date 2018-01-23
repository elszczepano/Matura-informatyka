#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int primeCounter = 0;
int primeArr[236];

bool ifPrime(int number) {
    int counter = 0;
    for(int i=1; i<=number; i++) {
        if(number%i==0) counter++;
    }
    if(counter == 2) return true;
    else return false;
}
void minPrime() {
    int minimal = 9999999;
    for(int i=0; i<236; i++) {
        if(primeArr[i]<minimal) minimal=primeArr[i];
    }
    cout << "Minimalna: " << minimal << endl;
}
void maxPrime() {
    int maximal = 0;
    for(int i=0; i<236; i++) {
        if(primeArr[i]>maximal) maximal=primeArr[i];
    }
    cout << "Maksymalna: " << maximal << endl;
}
void ifTwin() {
    for(int i=1; i<236; i++) {
        int a = primeArr[i]-primeArr[i-1];
        int b = primeArr[i]+primeArr[i-1];
        if(a==2||a==-2||b==2||b==-2) {
            cout << primeArr[i] << " " << primeArr[i-1] << endl;
        }
    }
}

int main()
{
    fstream file;
    string line;
    file.open("dane4.txt", ios::in);
    while(getline(file,line)) {
        int intLine = atoi(line.c_str());
        if(ifPrime(intLine)) {
            primeArr[primeCounter] = intLine;
            primeCounter++;
        }
    }
    file.close();
    cout << "Jest " << primeCounter << " liczb pierwszych" << endl;
    minPrime();
    maxPrime();
    ifTwin();
    return 0;
}
