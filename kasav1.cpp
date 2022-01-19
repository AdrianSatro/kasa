#include <iostream>
using namespace std;


void UI();
void stanKasy();
float zaplata();
//void reszta(float x);

float Pieniadze[2][15] = { {500, 200, 100 , 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01},
                        {1, 3, 6, 15, 21, 16, 7, 5, 16, 8, 10, 10, 8, 7, 15}};

string Templatka[15] = {"500zl","200zl","100zl","50zl","20zl","10zl","5zl","2zl","1zl","50gr","20gr","10gr","5gr","2gr","1gr"};
int IloscNominalu[15]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main() //main wywołujący funkcje
{ 
    stanKasy();
    zaplata();
   // float SumaDoZaplaty = zaplata();
    //reszta(SumaDoZaplaty);
    stanKasy();

}

void UI()  //
{
    cout<<"=========================================="<<endl;
    cout<<"           Aplikacja kasa v1.0            "<<endl;
    cout<<"=========================================="<<endl<<endl;
    cout<<"STAN KASY"<<endl;
}

void stanKasy()
{
    UI();

    for(int i=0; i<=14; i++)
    {
        if (i <= 8) 
        {
            //Templatka[i] = Pieniadze[0][i] + "zl";
            cout << Pieniadze[0][i] << "zl: " << Pieniadze[1][i] << endl;
        }
        else
        cout<<Pieniadze[0][i]*100<<"gr: "<<Pieniadze[1][i]<<endl;
    }
}

float zaplata()
{
    float SumaDoZaplaty=0;
    string OdKlienta;
    int Flaga;
    cout<<"Podaj osobno nominaly ktore wprowadzasz (np 50zl, 20gr)"<<endl;

    while(true)
    {       
        int Ilosc = 0; //
        Flaga = 0;
        cout<<endl<<"Podaj nominal ktory dajesz (jezeli skonczyles wydawac pieniadze wpisz 'n': ";   
        cin>>OdKlienta;

        for(int i = 0; i<15; i++) 
        {
            if(OdKlienta == Templatka[i])    //sprawdza czy wprowadzona wartosc jest w tabeli z nominalami polskimi
            {

                cout<<endl<<"Ile nominalow?: ";
                cin>>Ilosc;
                IloscNominalu[i]+=Ilosc;
                //cout<<" "<<Templatka[i]<<" "<<OdKlienta;
                SumaDoZaplaty+=Pieniadze[0][i]*IloscNominalu[i];
                Pieniadze[1][i]+=IloscNominalu[i]; 
                Flaga = 0;
                break;
            }

            else if(OdKlienta == "n")
            {
                Flaga = 1; 
                break;
            }
            else Flaga = 2;
        }

        if(Flaga == 1)  break;
        else if(Flaga == 2) cout<<endl<<"Bledne wprowadzenie";    
        else continue;
    }
    return SumaDoZaplaty;
}

