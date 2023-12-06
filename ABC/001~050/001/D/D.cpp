#include<bits/stdc++.h>
using namespace std;

int n;
int T[289];

string operator*(const string& s,int k){
    if(k == 0) return "";
    string p = (s+s)*(k/2);
    if(k%2 == 1) p+=s;
    return p;
}


string cut(string s) {
    string a=s.substr(0,2);
    string b=to_string(stoi(s.substr(2,2))-stoi(s.substr(2,2))%5);
    b="0"s*(2-(int)b.length())+b;
    return a+b;
}

string cut2(string s) {
    int a=stoi(s.substr(0,2));
    int b=stoi(s.substr(2,2));
    int c=(5-b%5)%5;
    b+=c;
    if (b>60) {
        b-=60;
        a+=1;
    }
    string d=to_string(a);
    d="0"s*(2-(int)d.length())+d;
    string e=to_string(b);
    e="0"s*(2-(int)e.length())+e;
    return d+e;
}

string toTime(int i) {
    return "0"s*(2-(int)(to_string(i/12).length()))+to_string(i/12)+"0"s*(2-(int)(to_string(i%12*5).length()))+to_string(i%12*5);
}

int toi(string s) {
    return stoi(s.substr(0,2))*12+stoi(s.substr(2,2))/5;
}

int main() {
    string a, s, e;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        s=cut(a.substr(0,4));
        e=cut2(a.substr(5,4));
        for (int j=toi(s); j<=toi(e); j++) {
            if (j==toi(s) && (T[j]==0 || T[j]==1)) {
                T[j]=1;
            } else if (j==toi(e) && (T[j]==0 || T[j]==2)) {
                T[j]=2;
            } else {
                T[j] =3;
            }
        }
    }
    int x,y;
    for (int i=0; i<289; i++) {
        if (T[i]==1) {
            x=i;
        } else if (T[i]==2) {
            y=i;
            cout << toTime(x) << "-" << toTime(y) << endl;
        }
    }
    // for(int i:T){
    //     cout << i;
    // }
    // cout <<endl;
}