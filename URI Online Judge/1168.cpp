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

    int n;
    cin >> n;

    vector<int> leds = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int res = 0;
        for (char c : s)
            res += leds[c - '0'];

        cout << res << " leds\n";
    }
}