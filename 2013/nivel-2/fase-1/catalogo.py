def setref(lista, ref):
    cat = [sublista.copy() for sublista in lista]
    msc_ref = list()
    for i, local in enumerate(cat):
        for j, pasta in enumerate(local):
            if pasta == ref:
                antes = cat[i][:j]
                cat[i] = cat[i][j + 1:]
                grauref = j
                msc_ref.append(cat[i])
    for i, local in enumerate(cat):
        grau = grauref + 1
        esta = False
        if local in msc_ref:
            esta = True
        if not esta:
            for pasta in local:
                if pasta in antes:
                    grau -= 1
            for c in range(grau):
                cat[i].insert(0, '..')
    for i, local in enumerate(cat):
        for j, pasta in enumerate(local):
            if pasta in antes:
                cat[i].remove(pasta)
    return cat


def formata(cat):
    string = ""
    for i in cat:
        for n, j in enumerate(i):
            if n == 0:
                string += j
            else:
                string += "/" + j
    return string


N = int(input())
catalogo = list()
for i in range(N):
    msc = list(input().split('/'))
    catalogo.append(msc)

referencias = list()
for local in catalogo:
    for j, pasta in enumerate(local):
        if not (pasta == '..' or pasta in referencias or j == len(local) -1):
            referencias.append(pasta)

caracteres = list()
for r in referencias:
    numero_car = len(formata(setref(catalogo, r)))
    caracteres.append(numero_car)
menor_car = min(caracteres)

print(menor_car)
