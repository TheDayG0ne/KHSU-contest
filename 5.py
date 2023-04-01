from bisect import *
import sys
input = sys.stdin.readline
b = int(input())
a = list(map(int, input().split()))

pos = {}
for i in range(b): 
	if a[i] not in pos: pos[a[i]] = []
	pos[a[i]].append(i)

for x in sorted(pos.keys()):
	z = 0
	p = pos[x]
	
	xs = list(2*i-p[i] for i in range(len(p)))
	xs.sort()
	
	f = [b] * len(xs)
	
	'''
	fix j:
	(j-i+1)*2 > p[j]-p[i]+1
	2j - p[j] + 2 > 2i - p[i] + 1
	2j - p[j] >= 2i - p[i]
	need min i
	'''
	for j in range(len(p)):
		k = bisect_left(xs, 2*j - p[j])
		
		v = k
		while v < len(f):
			f[v] = min(f[v], j)
			v = v | (v + 1)
		
		v = k
		i = j
		while v >= 0:
			i = min(i, f[v])
			v = (v & (v + 1)) - 1
		
		z = max(z, min(b, (j - i + 1) * 2 - 1))
	
	print(x, z)