#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getPhi() {
    const int N = 200001;

    vector<long long> phi(N);
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++)
        if (phi[i] == i)
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;

    return phi;
}

vector<long long> prepare() {
    vector<long long> phi = getPhi();
    for (int i = 1; i < phi.size(); i++)
        phi[i] += phi[i - 1];
    return phi;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;
    n--;

    static vector<long long> phi = prepare();
    
    int l = 0, r = 200000;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (phi[m] < n)
            l = m;
        else
            r = m;
    }

    int num = 0, den = r;
    n -= phi[r - 1];
    while (n) {
        num++;
        n -= gcd(num, den) == 1;   
    }

    cout << num << "/" << den << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}