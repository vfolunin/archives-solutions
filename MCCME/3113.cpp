#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

template<typename F>
void print(vector<string> &a, F f) {
    cout << "[";
    for (int i = 0; i < a.size(); i++)
        cout << f(a[i]) << (i + 1 < a.size() ? ", " : "");
    cout << "]\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a;
    for (string s; cin >> s; )
        a.push_back(s);

    print(a, [](string &s) { return s; });
    print(a, [](string &s) { return s[0] == '-' ? s.substr(1) : s; });
    print(a, [](string &s) { return s.size(); });
}