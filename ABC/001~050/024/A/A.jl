A,B,C,K=parse.(Int64,split(readline()))
S,T=parse.(Int64,split(readline()))
println(A*S+B*T-(S+T>=K)*(S+T)*C)