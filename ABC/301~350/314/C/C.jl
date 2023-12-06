N,M=parse.(Int64,split(readline()))
S=readline()
C=parse.(Int64,split(readline()))

Cl=[[] for _=1:M]
for i=1:N
    append!(Cl[C[i]],i)
end

Sl=[0 for _=1:N]
for i=1:M
    for j=1:length(Cl[i])
        Sl[Cl[i][j]]=Cl[i][(j+length(Cl[i])-2)%length(Cl[i])+1]
    end
end

for i=1:N
    print(S[Sl[i]])
end
println()