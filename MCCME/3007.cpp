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

    int targetSize, targetDepth;
    cin >> targetSize >> targetDepth;

    const long long MOD = 1e9 + 7;
    vector<vector<long long>> ways(targetSize + 1, vector<long long>(targetDepth + 1));
    ways[0][0] = 1;

    for (int size = 1; size <= targetSize; size++) {
        for (int depth = 1; depth <= size && depth <= targetDepth; depth++) {
            for (int lSize = 0; lSize + depth <= size; lSize++) {
                for (int lDepth = 0; lDepth <= lSize && lDepth <= depth; lDepth++) {
                    for (int rSize = 0; lSize + rSize + depth <= size; rSize++) {
                        for (int rDepth = 0; rDepth <= rSize && rDepth < depth; rDepth++) {
                            int mSize = size - lSize - rSize - 1;
                            ways[size][depth] = (ways[size][depth] + ways[lSize][lDepth] * ways[mSize][depth - 1] % MOD * ways[rSize][rDepth] % MOD) % MOD;
                        }
                    }
                }
            }
        }
    }

    cout << ways[targetSize][targetDepth];
}