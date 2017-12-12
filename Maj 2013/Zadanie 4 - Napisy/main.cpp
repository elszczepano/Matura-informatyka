#include <iostream>
#include <fstream>

using namespace std;
int even = 0, odd = 0, equalCharsCounter = 0 , zeroCounter = 0, oneCounter = 0;
int kNumbers[17];
void if_even(string line) {
    if(line.length()%2==0){
            even++;
        }
        else {
            odd++;
        }
}
void equalChars(string line) {
    int zero = 0, one = 0;
    int length = line.length();
    for(int i=0; i<length; i++) {
        if(line[i]=='0'){
            zero++;
        }
        else {
            one++;
        }
    }
    if(zero==one) {
        equalCharsCounter++;
    }
    if(zero == length) {
        zeroCounter++;
    }
    if(one == length) {
        oneCounter++;
    }
}
int main()
{
    fstream file;
    string line;
    file.open("napisy.txt", ios::in);
    while(getline(file, line)) {
        if_even(line);
        equalChars(line);
        kNumbers[line.length()]++;
    }
    cout << "A) Parzyste: " << even << " Nieparzyste: " << odd << endl;
    cout << "B) Jest: " << equalCharsCounter << " takich napisow " << endl;
    cout << "C) Jest: " << zeroCounter << " z samymi zerami " << endl;
    cout << "C) Jest: " << oneCounter << " z samymi jedynkami " << endl;
    cout << "D) " << endl;
    for(int i=2; i<17; i++) {
        cout << "Dlugosc: " << i << " ilosc wystapien: " << kNumbers[i] << endl;
    }
    return 0;
}
