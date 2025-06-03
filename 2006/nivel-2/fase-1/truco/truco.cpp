#include "bits/stdc++.h"
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> forca;
    int ordem[] = {4, 5, 6, 7, 12, 11, 13, 1, 2, 3};
    for (int i = 0; i < 10; ++i) {
        forca[ordem[i]] = i;
    }

    int N;
    cin >> N;

    int vitoriasAdalberto = 0;
    int vitoriasBernardete = 0;

    for (int i = 0; i < N; ++i) {
        int A[3], B[3];
        for (int j = 0; j < 3; ++j) cin >> A[j];
        for (int j = 0; j < 3; ++j) cin >> B[j];

        int pontosA = 0, pontosB = 0;

        for (int j = 0; j < 3; ++j) {
            int fa = forca[A[j]];
            int fb = forca[B[j]];
            if (fa > fb) pontosA++;
            else if (fa < fb) pontosB++;
            else pontosA++;
        }

        if (pontosA >= 2) vitoriasAdalberto++;
        else vitoriasBernardete++;
    }

    cout << vitoriasAdalberto << " " << vitoriasBernardete << "\n";
    return 0;
}
