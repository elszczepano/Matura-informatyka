#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
string linia,strmin,strmax;
int liczba,licznik_parzystych,temp_a=0,wynik,najw=0,najm=1000000000,suma,temp_b=0;
string character;
int main()
{
    //Otwarcie pliku
    fstream plik;
    plik.open("cyfry.txt",ios::in);
    while(getline(plik,linia))
    {
        for(int i=0; i<linia.length(); i++)
        {
            //Zamiana kaødej cyfry z liczby na int oraz dodanie ich do siebie
            character=linia[i];
            temp_a=atoi(character.c_str());
            wynik=wynik+temp_a;
            //Sprawdza czy kolejna cyfra jest wiÍksza od poprzedniej
            if(temp_b<temp_a)
            {
                temp_b=temp_a;
                    suma++;
            }
        }
        temp_b=0;
        //Sprawdzenie czy zachodzi warunek wymagany w podpunkcie c)
        if (suma==linia.length()) cout<<"c) "<<linia<<" ";
        //Podstawia pod storage odpowiedzialny za przechowywanie obecnie najwiÍkszej i najmniejszej liczby
         if(najm>wynik)
        {
           najm=wynik;
           strmin=linia;
        }
        if(wynik>najw)
        {
            najw=wynik;
            strmax=linia;
        }
        //Sprawdü czy parzysta i dodaj do licznika parzystych
        liczba=atoi(linia.c_str());
        if(liczba%2==0) licznik_parzystych++;
        wynik=0;
        suma=0;
    }
    plik.close();
    cout<<endl<<"a) "<<licznik_parzystych<<endl;
    cout<<"b) "<<strmax<<endl;
    cout<<"b) "<<strmin<<endl;
    return 0;
}
