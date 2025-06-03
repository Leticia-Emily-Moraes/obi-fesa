#include "bits/stdc++.h"
#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> compra;
    deque<int> descarte;

    for (int i = 0; i < n; ++i) {
        int carta;
        cin >> carta;
        compra.push_back(carta);
    }

    int proxima = 1;
    int rodadas = 1;

    while (proxima <= n) {
        while (!compra.empty()) {
            int topo = compra.front();
            compra.pop_front();

            if (topo == proxima) {
                proxima++;
                break;
            } else {
                descarte.push_back(topo);
            }
        }

        if (compra.empty() && proxima <= n) {
            compra = descarte;
            descarte.clear();
            rodadas++;
        }
    }

    cout << rodadas << endl;
    return 0;
}
