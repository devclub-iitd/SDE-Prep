from collections import defaultdict

def dep(adj, depth, node, par):
    for i in adj[node]:
        if i == par:
            continue
        dep(adj, depth, i, node)
        depth[node] = max(depth[node], 1 + depth[i])

def dia(adj, depth, diameter, node, par):
    m1, m2 = 0, 0
    for i in adj[node]:
        if i == par:
            continue
        dia(adj, depth, diameter, i, node)
        diameter[node] = max(diameter[node], diameter[i])
        if depth[i] >= m1:
            m2 = m1
            m1 = depth[i]
        elif depth[i] > m2:
            m2 = depth[i]
    diameter[node] = max(diameter[node], m1 + m2 + 1)

def main():
    n = int(input())
    adj = defaultdict(list)
    diameter = [0] * (n + 1)
    depth = [1] * (n + 1)
    
    for _ in range(n - 1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    
    dep(adj, depth, 1, 0)
    dia(adj, depth, diameter, 1, 0)
    
    print(diameter[1] - 1)

if __name__ == "__main__":
    main()
