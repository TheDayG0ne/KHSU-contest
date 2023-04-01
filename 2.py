def count_possible_cells(a, b, c):
    count = 0
    for x in a:
        if x % 2 == 1:
            for y in b:
                if y % 2 == 1:
                    for z in c:
                        if z % 2 == 1 and x * y * z % 3 == 0:
                            count += 1
    return count
 
n1, *a = map(int, input().split())
n2, *b = map(int, input().split())
n3, *c = map(int, input().split())
 
if n1 % 3 == 0 and n2 % 3 == 0 and n3 % 3 == 0:
    print(count_possible_cells(a, b, c))
else:
    print(0)