#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    long long a, b, m, x;
    cin >> a >> b >> m >> x;
    
    if (!m)
        return 0;

    map<int, int> seen;
    for (int i = 0; 1; i++) {
        if (seen.count(x)) {
            cout << "Case " << test << ": " << i - seen[x] << "\n";
            return 1;
        }
        seen[x] = i;
        x = (a * x + b) % m;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}