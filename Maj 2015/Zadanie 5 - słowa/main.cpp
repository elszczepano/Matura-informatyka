#include <iostream>
#include <fstream>
using namespace std;


string reverseString(string line) {
    string reversed="";
    for(int i=line.length()-1; i>=0; i--) {
        reversed+=line[i];
    }
    return reversed;
}

int main()
{
    int charLength[13] = {0}, wordsIterator=0;
    string words[1000];
    fstream file, newFile;
    string line;
    file.open("slowa.txt", ios::in);
    newFile.open("nowe.txt", ios::in);
    while(getline(file,line)) {
        words[wordsIterator] = line;
        wordsIterator++;
        charLength[line.length()]++;

    }
    file.close();

    //5.1
    for(int i=1; i<=12; i++) {
        cout << i <<". " << charLength[i] << " wystapien" << endl;
    }

    while(getline(newFile,line)) {
        int reverseCount=0, sameCount=0;
        for(int i=0; i<1000; i++) {
            if(line==words[i]) sameCount++;
            if(reverseString(line)==words[i]) reverseCount++;
        }
    //5.2
    cout << line << " " << sameCount << " " << reverseCount << endl;
    }
    newFile.close();
    return 0;
}
