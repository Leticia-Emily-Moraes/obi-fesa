from collections import deque


def bfs(start, adj):
    visited = [-1] * len(adj)
    visited[start] = 0
    queue = deque([start])
    farthest_node = start

    while queue:
        u = queue.popleft()
        for v in adj[u]:
            if visited[v] == -1:
                visited[v] = visited[u] + 1
                queue.append(v)
                if visited[v] > visited[farthest_node]:
                    farthest_node = v

    return farthest_node, visited[farthest_node]


def main():
    N = int(input())
    adj = [[] for _ in range(N + 1)]

    for _ in range(N - 1):
        A, B = map(int, input().split())
        adj[A].append(B)
        adj[B].append(A)

    far_node, _ = bfs(1, adj)
    _, diameter = bfs(far_node, adj)

    print(diameter)


if __name__ == "__main__":
    main()
