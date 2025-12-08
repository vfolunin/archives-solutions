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

    char d;
    int l, r;
    cin >> d >> l >> r;

    string s = "NESW";
    
    cout << s[((s.find(d) + r - l) % s.size() + s.size()) % s.size()];
}