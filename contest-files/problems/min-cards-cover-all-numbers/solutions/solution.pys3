n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

id = [0] * (n + 1)
nx = [0] * (n + 1)
for i in range(n): 
    id[a[i]] = i + 1
    nx[a[i]] = b[i]

ans = []
used = [False] * (n+1)
for i in range(1, n+1): 
    if used[i]: continue
    cur = []
    x = i
    while True:
        used[x] = True
        cur.append(id[x])
        x = nx[x]
        if used[x]: break
    for k in range(0, len(cur), 2): ans.append(cur[k])

print(len(ans))
print(*ans)
        
