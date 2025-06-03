arvore = []
tudo_certo = True

def verificar(no):
    global tudo_certo
    filhos = len(arvore[no])
    total = 1

    peso = None
    for i in range(filhos):
        atual = verificar(arvore[no][i])
        if i == 0:
            peso = atual
        elif atual != peso:
            tudo_certo = False
        total += atual

    return total

n = int(input())
arvore = [[] for _ in range(n + 1)]

for _ in range(n):
    u, v = map(int, input().split())
    arvore[v].append(u)

verificar(0)

print("bem" if tudo_certo else "mal")
