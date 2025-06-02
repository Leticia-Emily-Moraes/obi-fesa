#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M; //numrero de faixas e numero de ogros
    cin >> N >> M;

    vector<int> A(N - 1);  //limites de faixas no vetor A
    for (int i = 0; i < N - 1; ++i) { //Ler os valores dos limites da faixa
        cin >> A[i];
    }

    vector<int> F(N);  //Vetor F com uma premiacao por faixa
    for (int i = 0; i < N; ++i) { //Ler premiacoes
        cin >> F[i];
    }

    vector<int> O(M);  //Forca para cada ogro
    for (int i = 0; i < M; ++i) {
        cin >> O[i];
    }

    for (int i = 0; i < M; ++i) { //
        int forca = O[i];

        auto it = lower_bound(A.begin(), A.end(), forca); //Le as forcas do comeco ao fim

        int faixa = it - A.begin(); //indice faixas

        cout << F[faixa] << " ";
    }

    cout << endl;

    return 0;
}
