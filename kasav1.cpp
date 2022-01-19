#include <iostream>
using namespace std;


void UI();
void stanKasy();
float zaplata();
void zerowanieIlosciNominalu(int DoZerowania[]);
void wydawanieReszty(float SumaPieniedzyKlientaR, float  DoZaplaty);

float Pieniadze[2][15] = { {500, 200, 100 , 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01}, // tabela do obliczania wartosci
                        {3, 6, 6, 15, 21, 16, 7, 5, 16, 8, 10, 10, 8, 7, 15}}; //poczatkowa ilosc monet i banknotow w kasie

string Templatka[15] = {"500zl","200zl","100zl","50zl","20zl","10zl","5zl","2zl","1zl","50gr","20gr","10gr","5gr","2gr","1gr"}; //tabela do pokazyweania wartosci
int IloscNominalu[15];  //tabela z iloscia monet i banknotow jaka klient daje kasie ORAZ ilosc monet i banknotow jaka kasa daje klientowi (zaleznie od funkcji)

int main() //main wywołujący funkcje
{ 
    float KwotaDoZaplaty = 100; //wprowadzic ile pieniedzy ma zaplacic klient
    stanKasy();
    //zaplata();
    float SumaPieniedzyKlienta = zaplata();
    wydawanieReszty(SumaPieniedzyKlienta, KwotaDoZaplaty);

}

void UI()  //
{
    cout<<"=========================================="<<endl;
    cout<<"               Aplikacja kasa             "<<endl;
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
    float SumaPieniedzyKlienta = 0;
    string OdKlienta;
    int Flaga;   //flaga zeby oznaczyc kiedy zakonczyc funkcje, dac blad wprowadzenia lub spytac ile pieniedzy o jakim nominale dal klient
    cout<<"Podaj osobno nominaly ktore wprowadzasz (np 50zl, 20gr)"<<endl;

    while(true)
    {       
        zerowanieIlosciNominalu(IloscNominalu);
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
                SumaPieniedzyKlienta+=Pieniadze[0][i]*IloscNominalu[i];     //sumuje ile klient dal nam pieniedzy
                Pieniadze[1][i]+=IloscNominalu[i];               //"daje" pieniadze do kasy
                Flaga = 0;
                break;
            }

            else if(OdKlienta == "n") //jezeli wpisze sie "n" to nastapi przerwanie petli 
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
    cout<<endl<<"Klient dal "<<SumaPieniedzyKlienta<<"zl";
    return SumaPieniedzyKlienta;
}

void wydawanieReszty(float SumaPieniedzyKlientaR, float KwotaDoZaplaty ) //algorytm zachłanny
{   
  //  float DoOddania = SumaPieniedzyKlientaR - KwotaDoZaplaty; 



}

void zerowanieIlosciNominalu(int DoZerowania[])
{
    for(int i = 0; i<=14; i++)
    {
        DoZerowania[i]=0;
    }
}