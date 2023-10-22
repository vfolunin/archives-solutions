#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    char colon;
    cin >> a >> colon >> b;

    if (a > b)
        swap(a, b);

    if (b < 25 || b < a + 2) {
        cout << 0;
        return 0;
    }

    b--;
    vector<vector<long long>> ways(a + 1, vector<long long>(b + 1));
    ways[0][0] = 1;

    for (int ka = 0; ka <= a; ka++) {
        for (int kb = 0; kb <= b; kb++) {
            if (ka + 2 <= kb && kb >= 25 || kb + 2 <= ka && ka >= 25)
                continue;
            if (ka)
                ways[ka][kb] += ways[ka - 1][kb];
            if (kb)
                ways[ka][kb] += ways[ka][kb - 1];
        }
    }

    cout << ways[a][b];
}