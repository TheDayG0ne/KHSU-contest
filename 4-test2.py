n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
 
cards = {}
for i in range(n):
    cards[a[i]] = i + 1
    cards[b[i]] = i + 1
 
chosen = set()
for i in range(1, n+1):
    if i not in chosen:
        chosen.add(cards[i])
 
print(len(chosen))
print(" ".join(map(str, chosen)))