#include "bits/stdc++.h"
#define MAX 1000
#define INF 2000000
using namespace std;

int grafo[MAX][MAX];
int tempo[MAX];

int main()
{
    int s, c, o, d, t;
    int max = INF;

    cin >> s >> c;

    for (int i = 0; i < s; i++)
    {
        cin >> tempo[i];
        for (int j = 0; j < s; j++)
        {
            grafo[i][j] = INF;
        }
    }

    for (int i = 0; i < c; i++)
    {
        cin >> o >> d >> t;
        o--;
        d--;
        grafo[o][d] = t + tempo[d];
    }

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < s; k++)
            {
                if(grafo[i][j] > grafo[i][k] + grafo[k][j]){
                    grafo[i][j] = grafo[i][k] = grafo[k][j];
                }
            }
        }
    }
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if(max > grafo[i][j] + grafo[j][i]){
                max = grafo[i][j] + grafo[j][i];
            }
        }
    }

    cout << max << endl;
}