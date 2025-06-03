def tesouro_encontrado(k, n, pistas):
    # Inicializa o mapa com zeros
    mapa = [[0 for i in range(n)] for j in range(n)]

    # Define os locais das pistas
    for x, y, d in pistas:
        mapa[x][y] = d
    # Pistas = [(x, y, d), (x, y, d)]
    for x, y, d in pistas:
        # Define quais são as coordenadas dos possíveis tesouros
        for i in range(max(0, x - d), min(n, x + d + 1)):
            for j in range(max(0, y - d), min(n, y + d + 1)):
                # Descobrir os possíveis tesouros
                if abs(i - x) + abs(j - y) == d:
                    if (i, j, mapa[i][j]) not in pistas:
                        mapa[i][j] += 1

    # Verifica se há apenas um tesouro e anota suas coordenadas
    cont = 0
    for i in range(n):
        for j in range(n):
            if mapa[i][j] > 1:
                if (i, j, mapa[i][j]) not in pistas:
                    cont += 1
                    tesouro = (i, j)
    if cont == 1:
        return (f"{tesouro[0]} {tesouro[1]}")
    else:
        return "-1 -1"


# Entrada de dados
n, k = map(int, input().split())
pistas = []
for _ in range(k):
    x, y, d = map(int, input().split())
    pistas.append((x, y, d))

# Saída e cálculo de dados
print(tesouro_encontrado(k, n, pistas))
