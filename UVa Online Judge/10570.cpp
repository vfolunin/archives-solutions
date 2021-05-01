#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int swapCount(const vector<int> &a) {
    vector<int> visited(a.size());
    int res = 0;

    for (int i = 0; i < a.size(); i++) {
        if (visited[i])
            continue;

        visited[i] = 1;
        int cycleLen = 1;

        for (int j = a[i]; j != i; j = a[j]) {
            visited[j] = 1;
            cycleLen++;
        }

        res += cycleLen - 1;
    }

    return res;
}

vector<int> make(vector<int> &a, vector<int> &b, int from) {
    vector<int> posInB(b.size());
    for (int i = 0; i < b.size(); i++)
        posInB[b[i]] = i;

    vector<int> res(a.size());
    for (int i = 0; i < a.size(); i++)
        res[i] = posInB[a[(from + i) % a.size()]];
    return res;
}

bool solve() {
    int alienCount;
    cin >> alienCount;

    if (!alienCount)
        return 0;

    vector<int> a(alienCount);
    for (int &pos : a) {
        cin >> pos;
        pos--;
    }

    vector<int> b(alienCount);
    for (int i = 0; i < alienCount; i++)
        b[i] = i;

    int res = 1e9;
    for (int from = 0; from < alienCount; from++)
        res = min(res, swapCount(make(a, b, from)));

    reverse(b.begin(), b.end());
    for (int from = 0; from < alienCount; from++)
        res = min(res, swapCount(make(a, b, from)));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}