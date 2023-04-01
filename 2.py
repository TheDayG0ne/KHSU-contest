import itertools
 
def count_possible_cells(l1, l2, l3):
    lengths = [l1, l2, l3]
    combs = list(itertools.product(*lengths))
 
    combs = filter(lambda x: x[0] % 2 == x[1] % 2 == x[2] % 2 == 1, combs)
    combs = filter(lambda x: x[0] * x[1] * x[2] % 3 == 0, combs)
 
    return len(list(combs))
 
l1 = list(map(int, input().split()))[1:]
l2 = list(map(int, input().split()))[1:]
l3 = list(map(int, input().split()))[1:]

print(count_possible_cells(l1, l2, l3))