#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    //leitura das dimensões do colchão
    int A, B, C;
    cin >> A >> B >> C;

    //leitura das dimensões da porta
    int H, L;
    cin >> H >> L;

    //garante que a altura da porta vai ser sempre maior que a largura
    if(H<L) {
        swap(H,L);
    }

    //colocando as dimensões do colchão dentro de um vetor e ordenando as dimensões da maior para a menor
    int dimensoes[3] = {A, B, C};
    sort(dimensoes, dimensoes + 3);

    int menorDimensao = dimensoes[0]; //menor dimensao do colchao
    int menorDimensao2 = dimensoes[1]; //segunda menor dimensão do colchão

    if((menorDimensao <= L) && (menorDimensao2 <= H)){ 
        cout << "S";
    } else {
        cout << "N";
    }

    return 0;
}