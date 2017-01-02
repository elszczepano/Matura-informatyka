#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>

using namespace std;

string linia;
int t,h,c;
float d;

int main()
{
    fstream wejscie;
    wejscie.open("liczby.txt", ios::in);
    fstream zamknij;
    zamknij.open("zad_5.txt", ios::out|ios::app);
    while(getline(wejscie, linia))
    {
        t = atoi(linia.c_str());
        d = sqrt(t);
        c = d;
        if(d-c==0)
        {

            for(int i=1; i<=c; i++)
        {
            if(c%i==0)
            {
                h++;
            }
        }
        if(h==2)
        {
            zamknij << t << endl;
        }
        }
        h=0;
    }
    wejscie.close();
    zamknij.close();
    return 0;
}
