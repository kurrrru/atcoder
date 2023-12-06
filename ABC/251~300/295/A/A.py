n = int(input())
w = input().split()
if "and" in w or "not" in w or "that" in w or "the" in w or "you" in w:
    print("Yes")
else:
    print("No")