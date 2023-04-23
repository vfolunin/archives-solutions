#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Hasher {
    long long x = 1e6 + 3, mod = 1e9 + 7;
    vector<long long> p, h;

    Hasher(const vector<int> &visibleCubes) {
        p.resize(visibleCubes.size());
        h.resize(visibleCubes.size());

        p[0] = 1;
        h[0] = visibleCubes[0];

        for (int i = 1; i < visibleCubes.size(); i++) {
            p[i] = p[i - 1] * x % mod;
            h[i] = (h[i - 1] * x % mod + visibleCubes[i]) % mod;
        }
    }

    long long getHash(int l, int r) {
        long long res = h[r];
        if (l)
            res = (res - p[r - l + 1] * h[l - 1] % mod + mod) % mod;
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int visibleCubeCount, colorCount;
    cin >> visibleCubeCount >> colorCount;

    vector<int> visibleCubes(visibleCubeCount);
    for (int &value : visibleCubes)
        cin >> value;

    Hasher h1(visibleCubes);
    Hasher h2({ visibleCubes.rbegin(), visibleCubes.rend() });

    for (int cubeCount = (visibleCubeCount + 1) / 2; cubeCount < visibleCubeCount; cubeCount++) {
        int realCubeCount = visibleCubeCount - cubeCount;
        if (h1.getHash(0, realCubeCount - 1) == h2.getHash(cubeCount - realCubeCount, cubeCount - 1))
            cout << cubeCount << " ";
    }
    cout << visibleCubeCount;
}