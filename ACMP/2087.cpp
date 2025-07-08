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

    string s;
    cin >> s;

    vector<int> res(s.size() + 1);
    for (int i = 1; i <= s.size(); i++) {
        if (i >= 2 && s.substr(i - 2, 2) == "PC")
            res[i] = max(res[i], res[i - 2] + 2);
        if (i >= 4 && s.substr(i - 4, 4) == "CSGO")
            res[i] = max(res[i], res[i - 4] + 4);
    }

    cout << *max_element(res.begin(), res.end());
}