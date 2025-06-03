N, K = list(map(int, input().split()))
distancias = list(map(int, input().split()))
distancias.sort()
#cria vários subconjuntos de 'N-K' elementos
subconjs = list()
for i in range(0, K+1):
    subconjs.append(distancias[i:N-K+i])
#cria uma lista e acha a menor distância no subconjunto entre o primeiro e ultimo predio de cada subconjunto
minimas_dist = list()
for conj in subconjs:
    n = max(conj) - min(conj)
    minimas_dist.append(n)
print(min(minimas_dist))
