#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, maxX, degree;
    if (!(cin >> n >> maxX >> degree))
        return 0;
    
    vector<long long> p(degree + 1);
    for (long long &coeff : p)
        cin >> coeff;
    reverse(p.begin(), p.end());

    vector<int> seen(n + 1);
    for (int x = 0; x <= maxX; x++) {
        long long pos = 0;
        for (long long coeff : p)
            pos = (pos * x + coeff) % (n + 1);
        seen[pos] = 1;
    }

    cout << count(seen.begin(), seen.end(), 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}