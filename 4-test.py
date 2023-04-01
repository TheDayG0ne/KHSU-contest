n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a_sets = [set() for _ in range(n)]
b_sets = [set() for _ in range(n)]
for i in range(n):
    a_sets[a[i]-1].add(i+1)
    b_sets[b[i]-1].add(i+1)
selected = []
for i in range(n):
    num = i+1
    card = a_sets[num-1].pop()
    selected.append(card)
    b_sets[b[card-1]-1].remove(card)
    for j in range(num, n):
        if not a_sets[j] & b_sets[j]:
            break
        card = (a_sets[j] & b_sets[j]).pop()
        selected.append(card)
        a_sets[j].remove(card)
        b_sets[j].remove(card)
print(len(selected))
print(*selected)