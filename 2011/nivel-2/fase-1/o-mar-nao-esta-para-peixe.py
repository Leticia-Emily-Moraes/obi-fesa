def calcular_area_aproveitada(n, redes):
    # Criamos uma grade 2D representando o mar, com 101x101 para incluir até o
    # ponto 100
    mar = [[0 for _ in range(101)] for _ in range(101)]

    # Para cada rede, marcamos as células cobertas
    for xi, xf, yi, yf in redes:
        for x in range(xi, xf):
            for y in range(yi, yf):
                mar[x][y] = 1  # Marca que esta célula está coberta

    # Agora somamos todas as células cobertas
    area_total = sum(sum(linha) for linha in mar)
    return area_total


# Leitura da entrada
n = int(input("Digite o número de redes: "))
redes = []
for _ in range(n):
    xi, xf, yi, yf = map(int, input().split())
    redes.append((xi, xf, yi, yf))

# Cálculo e saída
print(calcular_area_aproveitada(n, redes))
