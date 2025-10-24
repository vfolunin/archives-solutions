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

    vector<string> a;
    for (string s; cin >> s; )
        a.push_back(s);

    for (int i = a.size() - 2; i; i -= 2)
        cout << "Turn " << (a[i] == "L" ? "RIGHT" : "LEFT") << " onto " << a[i - 1] << " street.\n";

    cout << "Turn " << (a[0] == "L" ? "RIGHT" : "LEFT") << " into your HOME.";
}