#include <iostream>
using namespace std;


void UI();
void stanKasy();
void zaplata();
void reszta();

float pieniadze[2][15] = { {500, 200, 100 , 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01},
                        {1, 3, 6, 15, 21, 16, 7, 5, 16, 8, 10, 10, 8, 7, 15}};

string templatka[15] = {"500zl","200zl","100zl","50zl","20zl","10zl","5zl","2zl","1zl","50gr","20gr","10gr","5gr","2gr","1gr"};

int main() //main wywołujący funkcje
{ 
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
            //templatka[i] = pieniadze[0][i] + "zl";
            cout << pieniadze[0][i] << "zl: " << pieniadze[1][i] << endl;
        }
        else
        cout<<pieniadze[0][i]*100<<"gr: "<<pieniadze[1][i]<<endl;
    }
}

void zaplata()
{
 cout<<"Ile do zapłaty?";
}

