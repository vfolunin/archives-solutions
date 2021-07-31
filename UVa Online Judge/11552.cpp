#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int chunkSize;
    string s;
    cin >> chunkSize >> s;

    int chunkCount = s.size() / chunkSize;
    vector<vector<int>> flops(chunkCount, vector<int>(26, 1e9));

    set<int> chunk;
    for (int i = 0; i < chunkSize; i++)
        chunk.insert(s[i] - 'a');
    for (int r : chunk)
        flops[0][r] = chunk.size();

    for (int i = 1; i < chunkCount; i++) {
        map<int, int> chunk;
        for (int j = 0; j < chunkSize; j++)
            chunk[s[chunkSize * i + j] - 'a']++;

        for (auto &[r, k] : chunk) {
            for (int pr = 0; pr < 26; pr++)
                flops[i][r] = min<int>(flops[i][r], flops[i - 1][pr] + chunk.size());

            for (auto &[l, _] : chunk)
                if (l != r || chunk.size() == 1)
                    flops[i][r] = min<int>(flops[i][r], flops[i - 1][l] + chunk.size() - 1);
        }
    }

    cout << *min_element(flops.back().begin(), flops.back().end()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}