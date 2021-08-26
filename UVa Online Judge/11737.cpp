#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int rectCount;
    if (!(cin >> rectCount))
        return 0;

    vector<int> h(rectCount), w(rectCount);
    int res = 1e9;

    for (int i = 0; i < rectCount; i++) {
        cin >> h[i] >> w[i];
        if (h[i] == w[i])
            res = 0;
    }

    sort(h.begin(), h.end());
    sort(w.begin(), w.end());

    for (int hi = 0, wi = 0; hi < h.size() && wi < w.size(); ) {
        res = min(res, max(1, (abs(h[hi] - w[wi]) + 1) / 2));
        if (h[hi] < w[wi])
            hi++;
        else
            wi++;
    }

    cout << "Case " << test << " : " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}