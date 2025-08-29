#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    set<int> codes;
    for (int code = 1; code < (1 << 10); code++)
        codes.insert(code);
    
    vector<int> res = { 0 };
    while (1) {
        bool found = 0;
        for (int code : codes) {
            int diff = 0;
            for (int bit = 0; bit < 10; bit++)
                diff += (res.back() >> bit) % 2 != (code >> bit) % 2;

            if (diff % 2 == 0) {
                res.push_back(code);
                codes.erase(code);
                found = 1;
                break;
            }
        }
        if (!found)
            break;
    }
    return res;
}

string toBin(int value) {
    string res;
    for (int i = 0; i < 10; i++) {
        res += value % 2 + '0';
        value /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int index;
    cin >> index;

    static vector<int> res = prepare();

    cout << toBin(res[index]) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}