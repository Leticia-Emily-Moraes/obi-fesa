lista = []
total = 0
cortes = int(input())
etapas = input()
for c in range(0, cortes):
    lista.append(int(etapas.split()[c]))
    total += (lista[c] - 1)
print(total)