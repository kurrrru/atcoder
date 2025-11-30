#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

double euclid(double x1, double y1, double x2, double y2) {
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double dist(ll tsx, ll tsy, ll tgx, ll tgy, ll asx, ll asy, ll agx, ll agy, double t) {
    double td = euclid(tsx, tsy, tgx, tgy);
    double tx, ty;
    if (t > td) {
        tx = tgx;
        ty = tgy;
    } else {
        tx = tsx + (tgx - tsx) * t / td;
        ty = tsy + (tgy - tsy) * t / td;
    }

    double ad = euclid(asx, asy, agx, agy);
    double ax, ay;
    if (t > ad) {
        ax = agx;
        ay = agy;
    } else {
        ax = asx + (agx - asx) * t / ad;
        ay = asy + (agy - asy) * t / ad;
    }

    // cout << "(t, td, ad)=(" << t << ", " << td << ", " << ad << ")" << endl;

    return euclid(tx, ty, ax, ay);
} 



int main() {
    ll T;
    cin >> T;
    while (T--) {
        ll tsx, tsy, tgx, tgy, asx, asy, agx, agy;
        cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;
        double td = euclid(tsx, tsy, tgx, tgy);
        double ad = euclid(asx, asy, agx, agy);
        double shorter = min(td, ad);
        double longer = max(td, ad);
        double left = 0, right = shorter;
        while (right - left > 1e-10) {
            double m1 = (left * 2 + right) / 3;
            double m2 = (left + right * 2) / 3;
            // cout << m1 << m2 << endl;
            double d1 = dist(tsx, tsy, tgx, tgy, asx, asy, agx, agy, m1);
            double d2 = dist(tsx, tsy, tgx, tgy, asx, asy, agx, agy, m2);
            if (d1 < d2) {
                right = m2;
            } else {
                left = m1;
            }
            // cout << "left: " << left << ", right: " << right << endl;
            // cout << "d1: " << d1 << ", d2: " << d2 << ", m1: " << m1 << ", m2: " << m2 << endl;
            // cout << min(d1, d2)  <<" "<< dist(tsx, tsy, tgx, tgy, asx, asy, agx, agy, right)<< endl;
        }
        double can1 = right;
        if (shorter == longer) {
            cout << dist(tsx, tsy, tgx, tgy, asx, asy, agx, agy, can1) << endl;
            continue;
        }
        left = shorter, right = longer;
        while (right - left > 1e-10) {
            double m1 = (left * 2 + right) / 3;
            double m2 = (left + right * 2) / 3;
            double d1 = dist(tsx, tsy, tgx, tgy, asx, asy, agx, agy, m1);
            double d2 = dist(tsx, tsy, tgx, tgy, asx, asy, agx, agy, m2);
            if (d1 < d2) {
                right = m2;
            } else {
                left = m1;
            }
        }
        double can2 = right;
        cout << fixed << setprecision(10) << min(dist(tsx, tsy, tgx, tgy, asx, asy, agx, agy, can1), dist(tsx, tsy, tgx, tgy, asx, asy, agx, agy, can2)) << endl;
    }

    
}
