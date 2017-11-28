#include <iostream>
#include <fstream>

using namespace std;

bool isPalindrom(string line){
    for(int i=0; i<line.length(); i++){
        if(line[i]==line[line.length()-1-i]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

int main()
{
    string fileLine;
    fstream passwords;
    int odd=0, even=0;
    passwords.open("hasla.txt", ios::in);
    while(getline(passwords, fileLine)) {
        if(fileLine.length()%2==0) {
            even++;
        }
        else {
            odd++;
        }
        if(isPalindrom(fileLine)){
            //cout<<fileLine<<endl;
        }
        for(int i=1; i<fileLine.length(); i++) {
            if(fileLine[i-1]+fileLine[i]==220) {
                cout<<fileLine<<endl;
                break;
            }
        }
    }
    cout << "parzyste: " << even << " nieparzyste: " << odd << endl;
    return 0;
}
