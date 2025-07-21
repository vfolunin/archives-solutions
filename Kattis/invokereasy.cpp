#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <complex>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    double aRe, aIm, bRe, bIm;
    cin >> aRe >> aIm >> bRe >> bIm;

    complex<double> a(aRe, aIm);
    complex<double> b(bRe, bIm);
    a /= b;

    cout << fixed << a.real() << " " << a.imag();
}