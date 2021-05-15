#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const int N = 1e6 + 1;

vector<double> getP() {    
    vector<double> p(N);
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        double prob = (1.0 / i) * (1.0 / (i + 1));
        p[i] = p[i - 1] * (1 - prob);
    }
    return p;
}

vector<int> getZ() {
    vector<int> z(N);
    double fraction = 5;
    for (int i = 2; i < N; i++) {
        double prob = (1.0 / i) * (1.0 / (i + 1));
        fraction *= prob;
        z[i] = z[i - 1];
        while (fraction < 1) {
            fraction *= 10;
            z[i]++;
        }
    }
    return z;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<double> p = getP();
    static vector<int> z = getZ();

    cout.precision(6);
    cout << fixed << 1 - p[n] << " " << z[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}