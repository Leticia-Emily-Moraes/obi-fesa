#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N >= 1 && N <= 10000)
    {
        int blocos[N];
        int somaDosBlocos = 0;
        int movimentos = 0;
        int altura = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> blocos[i];
            somaDosBlocos += blocos[i];
        }
        
        somaDosBlocos -= (N*N + N)/2;

        if(somaDosBlocos >= 0 && somaDosBlocos % N == 0){

            altura =(somaDosBlocos / N) + 1;
            for (int i = 0; i < N; i++)
            {
                if (blocos[i] > altura)
                {
                    movimentos += (blocos[i] - altura);
                    altura++;
                }
            }
            cout << movimentos << endl;
        }else{
            cout << -1 <<  endl;
        }
    }
    return 0;
}
