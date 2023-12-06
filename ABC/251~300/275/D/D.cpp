// #include <bits/stdc++.h>
# include <../cpp/book/all.h>
using namespace std;

long long naive_f(long long n, long long a[]) {
  if (n<100000000){
    return a[n];
  } else {
    return naive_f(n/2, a) + naive_f(n/3, a);
  }
}

int main() {
  long long n;
  cin >> n;
  long long N = 100000000;
  long long *a = (long long *)malloc(sizeof(long long) * N);
  a[0] = 1;
  for (int i = 1; i < N; i ++) {
    a[i] = a[i/2] + a[i/3];
  }
  long long out = naive_f(n, a);
  cout << out << endl;
  
}