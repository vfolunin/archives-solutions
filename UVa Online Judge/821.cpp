#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    const int INF = 1e9;
    vector<vector<int>> d(100, vector<int>(100, INF));
    for (int i = 0; i < 100; i++)
        d[i][i] = 0;

    map<int, int> m;
    while (1) {
        int a, b;
        cin >> a >> b;

        if (!a && !b)
            break;

        if (!m.count(a))
            m[a] = m.size();
        if (!m.count(b))
            m[b] = m.size();
        d[m[a]][m[b]] = 1;
    }

    if (m.empty())
        return 0;

    for (int v = 0; v < m.size(); v++)
        for (int a = 0; a < m.size(); a++)
            for (int b = 0; b < m.size(); b++)
                d[a][b] = min(d[a][b], d[a][v] + d[v][b]);

    double avg = 0;
    for (int a = 0; a < m.size(); a++)
        for (int b = 0; b < m.size(); b++)
            if (a != b)
                avg += d[a][b];
    avg /= m.size() * (m.size() - 1);
    
    cout << "Case " << test << ": average length between pages = ";
    cout.precision(3);
    cout << fixed << avg << " clicks\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}