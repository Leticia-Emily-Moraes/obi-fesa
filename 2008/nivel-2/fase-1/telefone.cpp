#include <iostream>
#include <string>
using namespace std;

int main() {
    string telefone;
    cin >> telefone;

    for (int i = 0; i < telefone.size(); i++) {
        char c = telefone[i]; //guarda cada caractere

        if (c >= 'A' && c <= 'C') telefone[i] = '2'; //Condicional dos caracteres pelo numero ASCII
        else if (c >= 'D' && c <= 'F') telefone[i] = '3';
        else if (c >= 'G' && c <= 'I') telefone[i] = '4';
        else if (c >= 'J' && c <= 'L') telefone[i] = '5';
        else if (c >= 'M' && c <= 'O') telefone[i] = '6';
        else if (c >= 'P' && c <= 'S') telefone[i] = '7';
        else if (c >= 'T' && c <= 'V') telefone[i] = '8';
        else if (c >= 'W' && c <= 'Y') telefone[i] = '9';
        //Se for numero ou indice deixa como esta
    }

    cout << telefone << endl;

    return 0;
}
