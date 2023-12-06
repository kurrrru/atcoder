x,a,d,n = map(int, input().split())
min_num = 0
max_num = 0
if d == 0:
    min_num = a
    max_num = a
if d > 0:
    min_num = a
    max_num = a + (n - 1) * d
if d < 0:
    min_num = a + (n - 1) * d
    max_num = a
d = abs(d)
#min_numとmax_num及び公差dで考える
if x <= min_num:
    print(min_num-x)
elif x >= max_num:
    print(x - max_num)
else:
    xa = x%d
    xb = x//d
    #x = d*xb + xa
    min_num_a = min_num%d
    if xa == min_num_a:
        print(0)
    elif xa < min_num_a:
        if xa - (min_num_a - d) < min_num_a - xa:
            print(xa - (min_num_a - d))
        else:
            print(min_num_a - xa)
    else:
        if (min_num_a + d) - xa < xa - min_num_a:
            print((min_num_a + d) - xa)
        else:
            print(xa - min_num_a)
