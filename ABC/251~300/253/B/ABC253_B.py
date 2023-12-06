h,w = map(int, input().split())
a1=[0,0]
a2=[0,0]
next=1
for i in range(h):
    s=input()
    for j in range(w):
        if s[j] == "o":
            if next == 1:
                a1[0] = i
                a1[1] = j
                next = 2
            elif next == 2:
                a2[0] = i
                a2[1] = j

print(abs(a1[0] - a2[0]) + abs(a1[1] - a2[1]))