#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int commonLength(string &a, string &b) {
    int res = 0;
    for (int len = 1; len <= a.size() && len <= b.size(); len++)
        if (a.substr(a.size() - len) == b.substr(0, len))
            res = len;
    return res;
}

void solve(int test) {
    int sceneCount;
    cin >> sceneCount;

    vector<string> scenes(sceneCount);
    for (string &scene : scenes)
        cin >> scene;

    sort(scenes.begin(), scenes.end());
    int res = 1e9;
    do {
        string s = scenes[0];
        for (int i = 1; i < sceneCount; i++)
            s += scenes[i].substr(commonLength(s, scenes[i]));
        res = min<int>(res, s.size());
    } while (next_permutation(scenes.begin(), scenes.end()));

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}