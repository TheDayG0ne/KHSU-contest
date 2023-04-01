n = int(input())

f = []
for i in range(n):
    x, d = map(int, input().split())
    f.append((x, d, i))

f.sort()
ans = [0] * n
st = ([], [])
for x, d, i in f:
    s = st[x%2]
    if d == -1:
        if s:
            j, xj = s.pop()
            ans[i] = ans[j] = (x - xj) // 2
    else:
        s.append((i, x))

for t in ans: print(t)
        
