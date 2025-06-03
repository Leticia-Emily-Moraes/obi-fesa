#função para ver se um retângulo cabe em outro
def cabe(x1,y1,x,y):
    if (x1 <= x and y1 <= y) or (x1 <= y and y1 <= x):
        return True
    else:
        return False

#função que retorna as medidas do retâgulo costurado (varia conforme as combinações de costura)
def costurado(x1,y1,x2,y2):
    x = x1 + x2
    if y1 < y2:
        y = y1
    else:
        y = y2
    return x, y

#Principal
medidas = list(map(int, input().split()))
a1,b1,a2,b2,a,b = medidas

#todas as possibilidades de costura
t1 = costurado(a1, b1, a2, b2)
t2 = costurado(a1, b1, b2, a2)
t3 = costurado(b1, a1, a2, b2)
t4 = costurado(b1, a1, b2, a2)

#testa se o retângulo 'a' x 'b' cabe nas diversas possibilidades de costura ou do tecido sozinho
lencol_possivel = (cabe(a,b,a1,b1) or cabe(a,b,a2,b2) or
                   cabe(a,b,t1[0],t1[1]) or cabe(a,b,t2[0],t2[1]) or
                   cabe(a,b,t3[0],t3[1]) or cabe(a,b,t4[0],t4[1]))
if lencol_possivel:
    print("S")
else:
    print("N")
