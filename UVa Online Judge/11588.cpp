#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int height, width, bytesA, bytesB;
    cin >> height >> width >> bytesA >> bytesB;

    map<char, int> size;
    int maxSize = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c;
            cin >> c;
            size[c]++;
            maxSize = max(maxSize, size[c]);
        }
    }

    int res = 0;
    for (auto &[_, s] : size)
        res += s * (s == maxSize ? bytesA : bytesB);

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