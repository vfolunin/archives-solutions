#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> kollatz(long long n) {
    vector<long long> path;
    while (1) {
        path.push_back(n);
        if (n == 1)
            break;
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
    };
    return path;
}

bool solve() {
    int a, b;
    cin >> a >> b;

    if (!a && !b)
        return 0;

    vector<long long> aPath = kollatz(a), bPath = kollatz(b);
    long long meetPoint = 1;
    while (!aPath.empty() && !bPath.empty() && aPath.back() == bPath.back()) {
        meetPoint = aPath.back();
        aPath.pop_back();
        bPath.pop_back();
    }

    cout << a << " needs " << aPath.size() << " steps, ";
    cout << b << " needs " << bPath.size() << " steps, ";
    cout << "they meet at " << meetPoint << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}