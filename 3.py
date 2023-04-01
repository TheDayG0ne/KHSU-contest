a = int(input())
b = []
for i in range(a):
    x, d = map(int, input().split())
    b.append((x, d, i))
b.sort()
c = [0] * a
y = ([], [])
for x, d, i in b:
    s = y[x%2]
    if d == -1:
        if s:
            j, xj = s.pop()
            c[i] = c[j] = (x - xj) // 2
    else:
        s.append((i, x))
for t in c: print(t)