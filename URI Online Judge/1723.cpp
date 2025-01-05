#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int seqCount, seqSize;
    cin >> seqCount >> seqSize;

    if (!seqCount && !seqSize)
        return 0;

    vector<string> seq(seqCount);
    for (string &s : seq)
        cin >> s;

    string res(seqSize, 25);
    int resCost = 0;

    vector<int> tree(seqCount * 2);
    for (int i = 0; i < seqSize; i++) {
        for (int v = 0; v < seqCount; v++)
            tree[seqCount - 1 + v] = 1 << (seq[v][i] - 'A');
        for (int v = seqCount - 2; v >= 0; v--) {
            tree[v] = tree[2 * v + 1] & tree[2 * v + 2];
            if (!tree[v]) {
                resCost++;
                tree[v] = tree[2 * v + 1] | tree[2 * v + 2];
            }
        }
        while (!(tree[0] & (1 << res[i])))
            res[i]--;
        res[i] += 'A';
    }

    cout << res << " " << resCost << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}