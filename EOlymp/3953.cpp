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

    string a = s.substr(0, 1) + s.substr(4);
    sort(a.begin(), a.end());

    string b = s.substr(1, 3);
    sort(b.begin(), b.end());

    vector<string> res;
    do {
        do {
            res.push_back(a[0] + b + a.substr(1));
        } while (next_permutation(b.begin(), b.end()));
    } while (next_permutation(a.begin(), a.end()));

    cout << res.size() << "\n";
    for (string &s : res)
        cout << s << "\n";
}