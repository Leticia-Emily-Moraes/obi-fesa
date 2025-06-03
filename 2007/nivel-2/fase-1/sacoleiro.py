import heapq
from itertools import product

def dijkstra(grafo, custos, start):
    N = len(grafo)
    dist = [float('inf')] * N
    dist[start] = 0
    heap = [(0, start)]
    while heap:
        d, u = heapq.heappop(heap)
        if d > dist[u]:
            continue
        for v in grafo[u]:
            if dist[v] > dist[u]:
                dist[v] = dist[u]
                heapq.heappush(heap, (dist[v], v))
    return dist

def resolver(N, T, cidades):
    grafo = [[] for _ in range(N)]
    presentes = [[] for _ in range(N)]
    grupos = [[] for _ in range(2)]

    for info in cidades:
        X, P, C, G, K, *viz = info
        X = int(X)
        P = int(P)
        K = int(K)
        viz = list(map(int, viz))
        grafo[X] = viz
        valor = int(P)
        grupo = 0 if G == 'A' else 1
        presentes[X].append((valor, grupo))
        grupos[grupo].append((X, valor))

    dist = dijkstra(grafo, presentes, 0)

    possiveis = []
    for i in range(N):
        custo = dist[i]
        if custo == float('inf'):
            continue
        for valor, grupo in presentes[i]:
            total = custo + valor
            if total <= T:
                possiveis.append((total, valor, grupo))

    melhores = float('inf')
    for comb in product([0, 1], repeat=len(possiveis)):
        total = sum(possiveis[i][1] for i in range(len(possiveis)) if comb[i])
        custo = sum(possiveis[i][0] - possiveis[i][1] for i in range(len(possiveis)) if comb[i])
        if custo > T:
            continue
        a = sum(possiveis[i][1] for i in range(len(possiveis)) if comb[i] and possiveis[i][2] == 0)
        b = sum(possiveis[i][1] for i in range(len(possiveis)) if comb[i] and possiveis[i][2] == 1)
        if a > 0 and b > 0:
            melhores = min(melhores, abs(a - b))

    return melhores if melhores != float('inf') else -1

N = int(input())
T = int(input())
cidades = []

for _ in range(N):
    partes = input().split()
    cidades.append(partes)

print(resolver(N, T, cidades))