from collections import Counter

S = input()
C = Counter(S)
for c in C:
	if C[c] == 1:
		print(S.find(c) + 1)
		exit()