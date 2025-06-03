MAX = 1000
frequencia = [0] * MAX

quantidade_posicoes, quantidade_pastas = map(int, input().split())

for _ in range(quantidade_pastas):
    etiqueta = int(input())
    frequencia[etiqueta - 1] += 1

maximo = frequencia[0]
ajuste = 0
tudo_certo = True

for i in range(1, quantidade_posicoes):
    if not tudo_certo:
        break
    if frequencia[i] != maximo:
        if frequencia[i] == maximo - 1 and ajuste == 0:
            maximo -= 1
            ajuste = 1
        else:
            tudo_certo = False

if tudo_certo:
    print("S")
else:
    print("N")
