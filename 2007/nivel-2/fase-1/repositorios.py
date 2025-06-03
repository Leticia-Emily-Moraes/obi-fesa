lista_pacotes = []

instalados, disponiveis = map(int, input().split())

for _ in range(instalados):
    identificador, versao = map(int, input().split())
    lista_pacotes.append([identificador, versao, 1])

for _ in range(disponiveis):
    identificador, versao = map(int, input().split())
    lista_pacotes.append([identificador, versao, 0])

def chave_ordenacao(pacote):
    return (pacote[0], -pacote[1], -pacote[2])

lista_pacotes = sorted(lista_pacotes, key=chave_ordenacao)

ultimo_identificador = -1
for pacote in lista_pacotes:
    if pacote[0] != ultimo_identificador:
        if pacote[2] == 0:
            print(pacote[0], pacote[1])
        ultimo_identificador = pacote[0]
