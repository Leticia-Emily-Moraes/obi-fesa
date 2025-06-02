#include <iostream> //entrada e saída
#include <vector> //vetores dinamicos
#include <queue> //fila de prioridade
#include <algorithm> //funcoes max e min
using namespace std; //remove o uso de std

const int INF = 1e9;

int main() {
    int S, C; //S numero salas e C numero corredores
    cin >> S >> C;

    vector<vector<pair<int, int>>> grafo(S + 1); //cada vetor (array) tem um vetor dentro, e esse tem pares inteiros. 

    for (int i = 0; i < C; ++i) { //ler salas e corredores
        int A, B, D; //A e B sao salas com D metros de distancia
        cin >> A >> B >> D;
        grafo[A].push_back({ B, D }); //Da sala A a B existem D metros
        grafo[B].push_back({ A, D }); //Da sala B a A existem D metros (ida e volta)
    }

    int menor_max_dist = INF;

    for (int inicio = 1; inicio <= S; ++inicio) { //inicio primeira sala
        vector<int> dist(S + 1, INF); //dist = vetor que guarda a menor distancia entre salas
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //fila de prioridade para buscar sempre o menor valor

        dist[inicio] = 0;
        pq.push({ 0, inicio });

        while (!pq.empty()) { //algoritmo Dijkstra
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto viz : grafo[u]) {
                int v = viz.first;
                int peso = viz.second;
                if (dist[v] > dist[u] + peso) {
                    dist[v] = dist[u] + peso;
                    pq.push({ dist[v], v });
                }
            }
        }

        int max_dist = 0; 
        for (int i = 1; i <= S; ++i) { //descobrir distancia minima
            max_dist = max(max_dist, dist[i]);
        }

        menor_max_dist = min(menor_max_dist, max_dist);
    }

    cout << menor_max_dist << endl; //retornar valor

    return 0;
}
