m, d = map(int, input().split())
a, b = map(int, input().split())
if a == b:
    print(0)
elif a == 0 or b == 0:
    print(m)
elif a %b == 0 or b %a == 0:
    print(min(m, d))
else:
    print(min(m, d) * 2)