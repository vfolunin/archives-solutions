#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    cout << "Case " << test << ": ";
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "-1\n";
        return 1;
    }
    
    vector<int> p(n);
    int x = 1;
    for (int i = 0; i < n; i += 2)
        p[i] = x++;
    for (int i = n - 1; i >= 0; i--)
        if (!p[i])
            p[i] = x++;

    int v = (n + 1) / 4 * 3 + (n % 2 == 0);
    for (int i = 0; i < n; i++)
        p[i] += p[i] >= v;

    for (int i = 0; i < n; i++)
        cout << p[i] << (i + 1 < n ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}