Deg,Dis=map(int,input().split())

Dir=["N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N"]

def dire(Deg):
    return Dir[(Deg*10+1125)//2250]

def W(Dis):
    Wind=[0,15,15,93,93,201,201,327,327,477,477,645,645,831,831,1029,1029,1245,1245,1467,1467,1707,1707,1959,1959,float("inf")]
    for i in range(13):
        if Wind[i*2]<=Dis<Wind[i*2+1]:
            return i

ans=["",0]
ans[0]=dire(Deg)
ans[1]=W(Dis)
if ans[1]==0:
    ans[0]="C"
print(ans[0],ans[1])