
N, S = map(int, input().split())
delta = S - N * (1 + N * N) // 2
current = 1

for i in range(N):
    for j in range(N):
        if i == 0 and delta < 0:
            print(current + delta, end=' ')
            current += 1
        elif i == N - 1 and delta > 0:
            print(current + delta, end=' ')
            current += 1
        else:
            print(current, end=' ')
            current += 1
    print()

