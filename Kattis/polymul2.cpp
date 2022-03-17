#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <complex>
using namespace std;

using Complex = complex<double>;

void fft(vector<Complex> &p, Complex x) {
    size_t n = p.size();
    if (n == 1)
        return;

    vector<Complex> a(n / 2), b(n / 2);
    for (int i = 0; i < n / 2; i++) {
        a[i] = p[2 * i];
        b[i] = p[2 * i + 1];
    }

    fft(a, x * x);
    fft(b, x * x);

    Complex xPow = 1;
    for (int i = 0; i < n / 2; i++) {
        p[i] = a[i] + xPow * b[i];
        p[n / 2 + i] = a[i] - xPow * b[i];
        xPow *= x;
    }
}

const double PI = acos(-1);

vector<Complex> fixSize(vector<int> &p, int targetSize) {
    vector<Complex> res(p.begin(), p.end());
    while (res.size() < targetSize || (res.size() & (res.size() - 1)))
        res.push_back(0);
    return res;
}

vector<Complex> evaluate(vector<int> &p, int targetSize) {
    vector<Complex> res = fixSize(p, targetSize);
    fft(res, polar(1.0, 2 * PI / res.size()));
    return res;
}

vector<int> interpolate(vector<Complex> &p) {
    int n = p.size();
    fft(p, polar(1.0, -2 * PI / n));

    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = round(real(p[i]) / n);

    while (res.size() > 1 && !res.back())
        res.pop_back();
    return res;
}

vector<int> multiply(vector<int> &pa, vector<int> &pb) {
    int targetSize = pa.size() + pb.size();
    vector<Complex> a = evaluate(pa, targetSize);
    vector<Complex> b = evaluate(pb, targetSize);

    for (int i = 0; i < a.size(); i++)
        a[i] *= b[i];

    return interpolate(a);
}

void solve() {
    int aDegree;
    cin >> aDegree;

    vector<int> a(aDegree + 1);
    for (int &coeff : a)
        cin >> coeff;

    int bDegree;
    cin >> bDegree;

    vector<int> b(bDegree + 1);
    for (int &coeff : b)
        cin >> coeff;
    
    vector<int> res = multiply(a, b);
    
    cout << res.size() - 1 << "\n";
    for (int coeff : res)
        cout << coeff << " ";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}