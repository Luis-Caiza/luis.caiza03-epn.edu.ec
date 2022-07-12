#include<iostream>
#include<fstream>
#include"../lib/ProgressBar.h"

using namespace std;

void EscribirDocumento(string mail, string path)
{
    fstream file;

    file.open(path, ios::out);

    if(!(file.is_open())){
        cout<<"No se pudo abrir el archivo.";
        exit(1);
    }
    char caracter = '#';
    for(int i = 1; i <= mail.size(); i++){
        file<<"[";
        for(int j = 1; j <= mail.size(); j++){  
            if(j == i)
                file<<caracter;
            if(j < i)
                file<<'#';
            if(j > i)
                file<<' ';              
        }
        file<<"] "<<i*100/23<<"%"; 
        file<<'\t';
        color(0, 10);
        file<<"Loading: "<<i<<" de "<<mail.size();
        file<<'\t';
        color(0, 5);
        for(int x = 0; x < i; x++)
            file<<mail[x];
        file<<endl;
        color(0, 15);
    }
}

int main()
{
    string mail = "lUIs.cAIzA03@epn.edu.ec";
    string pathfile = "E:\\Programacion\\semanas\\luis.caiza03@eon.edu.ec\\notas\\log.txt";
    showProgressBar_u(mail);
    EscribirDocumento(mail, pathfile); //Procedimiento donde se imprime el showProgressBar_u en log.txt
    return 0;
}
