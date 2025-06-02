#função que analisa se um ponto está contido na circunferência de raio 'r'
def esta_contido(cord, r):
    x, y = cord
    if x*x + y*y > r*r:
        return False
    else:
        return True


c, t = list(map(int, input().split()))

raios = []
for i in range(0, c):
    raios.append(int(input()))

tiros = []
for i in range(0, t):
    tiros.append(list(map(int, input().split())))

#para cada tiro e círculo verifica
pontos = 0
for tiro in tiros:
    for raio in raios:
        if esta_contido(tiro, raio):
            pontos += 1

print(pontos)