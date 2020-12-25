#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    if (!n)
        return 0;

    vector<int> k(101);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        k[x]++;
    }

    bool first = 1;
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < k[i]; j++) {
            if (first)
                first = 0;
            else
                cout << " ";
            cout << i;
        }
    }
    cout << "\n";
    
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);

    while (solve());
}