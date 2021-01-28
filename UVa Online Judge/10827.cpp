#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<vector<int>> p(size * 2, vector<int>(size * 2));
    for (int i = 0; i < size * 2; i++) {
        for (int j = 0; j < size * 2; j++) {
            if (i < size && j < size)
                cin >> p[i][j];
            else if (i >= size)
                p[i][j] = p[i - size][j];
            else
                p[i][j] = p[i][j - size];
        }
    }
    for (int i = 0; i < size * 2; i++)
        for (int j = 1; j < size * 2; j++)
            p[i][j] += p[i][j - 1];

    int res = p[0][0];
    for (int l = 0; l <= size; l++) {
        for (int r = l; r < l + size; r++) {
            
            vector<int> v(size * 2);
            for (int i = 0; i < size * 2; i++) {
                v[i] = p[i][r] - (l ? p[i][l - 1] : 0);
                if (i)
                    v[i] += v[i - 1];
            }

            multiset<int> q;
            for (int i = 0; i < size * 2; i++) {
                res = max(res, v[i] - (q.empty() ? 0 : *q.begin()));
                if (i >= size)
                    q.erase(q.find(v[i - size]));                
                q.insert(v[i]);
            }

        }
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}