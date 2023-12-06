S=input()
K=int(input())
o_counter=0
rem_flag=False
rem_l=-1
rem_r=-1
rem=[False]*(len(S))
rem_max=K
i=0
o_stack=[]
internal_o_stack=[]
while i<len(S):
    if not rem_flag:
        if S[i]=="o":
            o_counter+=1
            o_stack.append(i)
        elif S[i]=="f" and o_counter>0:
            o_counter-=1
            rem_flag=True
            rem_max=K
            rem[i]=True
            j=o_stack.pop()
            rem[j]=True
            rem_l=i+1
        else:
            o_counter=0
    else:
        if S[i]=="o" and i<len(S)-1 and (S[i+1]=="f" or S[i+1]=="o"):
            if S[i+1]=="o":
                internal_o_counter=0
                for j in range(i,min(i+rem_max,len(S))):
                    if S[j]=="o":
                        internal_o_counter+=1
                        rem[j]=2
                        internal_o_stack.append(j)
                    elif S[j]=="f":
                        o_counter+=internal_o_counter
                        rem_max=0
                        for k in range(internal_o_counter):
                            o_stack.append(internal_o_stack[k])
                        break
                    else:
                        internal_o_counter=0
                        for k in range(i,min(len(S),j+1)):
                            rem[i]=True
                            rem_max-=1
                        i=j+1
                        break
            elif S[i+1]=="f":
                rem_max=0
                o_counter+=1
        elif S[i]=="f" and o_counter>0:
            o_counter-=1
            rem_max=K
            rem[i]=True
            j=o_stack.pop()
            rem[j]=True
            rem_l=i+1
        else:
            if rem_max>0:
                rem[i]=True
                rem_max-=1
            if rem_max==0:
                rem_flag=False
            
    i+=1
ans=0
for i in range(len(S)):
    ans+=(rem[i]==0)
print(ans)
print(rem)