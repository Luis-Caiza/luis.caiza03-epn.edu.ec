#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

enum Colors 
{
    BLACK      = 0,
    BLUE       = 1,
    GREEN      = 2,
    CYAN       = 3,
    RED        = 4,
    MAGENTA    = 5,
    BROWN      = 6,
    LGREY      = 7,
    DGREY      = 8,
    LBLUE      = 9,
    LGREEN     = 10,
    LCYAN      = 11,
    LRED       = 12,
    LMAGENTA   = 13,
    YELLOW     = 14,
    WHITE      = 15
};

void color(int Background, int Text)
{ 
    int colorTexto= Text + (Background * 16);         // los colores van del 0 al 255 por eso se multiplica por 16
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);   // referenciamos a la consola.
    SetConsoleTextAttribute(terminal, colorTexto); 
}

void showProgressBar_u(string mail)
{
    for(int i = 1; i <= mail.size(); i++)
    {
        char caracter = '#';
        color(BLACK, YELLOW);
        cout<<"\r[";
        for(int j = 1; j <= mail.size(); j++)
        {
            if(j == i)
                cout<< caracter;
            if(j < i)
                cout<<'#';
            if(j > i)
                cout<<' ';
            if(i == mail.size())
            { 
				cout<<"\r[";
				for(int m = 1; m <= mail.size(); m++)
					cout<<'#';
			}     
        }
        cout<<"] "<<i*100/23<<"%"; //se mostrara el porcentaje en 100%
        cout<<"\t     ";
        color(BLACK, BLUE);
        cout<<"Loading: "<<i<<" de "<<mail.size();
        cout<<'\t';
        color(BLACK, RED);
        for(int x = 0; x < i; x++)
            cout<<mail[x];
        Sleep(200);
        cout<<endl;
        color(BLACK, RED);
    }
}