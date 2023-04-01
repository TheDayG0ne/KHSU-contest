def count_ways(a, b, c):
    if a % 2 == 0 or b % 2 == 0 or c % 2 == 0:
        return 0
        return (a * b * c + 1) // 2

n1 = int(input())
sticks1 = list(map(int, input().split()))

n2 = int(input())
sticks2 = list(map(int, input().split()))

n3 = int(input())
sticks3 = list(map(int, input().split()))

count = 0

for a in sticks1:
    for b in sticks2:
        for c in sticks3:
            if a * b * c % 3 == 0:
                count += count_ways(a, b, c)

print(count)