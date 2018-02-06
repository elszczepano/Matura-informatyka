#include <iostream>
#include <fstream>

using namespace std;

int nwd(int a,int b) {
    int temp;
    while (b!=0)
   {
       temp=b;
       b=a % b;
       a=temp;
   }
   return a;
}
int main()
{
    int a_counter = 0, b_sum = 0, c_counter35 = 0, c_counter_max = 0, c_max = 0;
    fstream file;
    string line;
    int a, b, c;
    file.open("liczby.txt");
    while(file>>a>>b>>c) {
        //4.1
        if(b>a&&c>b) a_counter++;
        //4.2

        b_sum += nwd(c,nwd(a,b));

    }
    file.close();
    //4.3
    file.open("liczby.txt");
    while(getline(file, line)) {
        int c_sum = 0;
        for(int i=0; i<line.length(); i++) {
            if(line[i]!=' ') {
                line[i] = line[i] - '0';
            c_sum += line[i];
            }
        }
        if(c_sum==35) c_counter35++;
        if(c_max==c_sum) c_counter_max++;
        if(c_max<c_sum) {
            c_counter_max = 1;
            c_max=c_sum;
        }

    }
    file.close();
    cout << "4.1 Warunek spelnia tyle liczb: " << a_counter << endl;
    cout << "4.2 Suma NWD to: " << b_sum << endl;
    cout << "4.3 35 wystepuje tyle razy: " << c_counter35 << " Max liczba to: " << c_max << " Wystepuje tyle razy: " << c_counter_max << endl;
    return 0;
}
