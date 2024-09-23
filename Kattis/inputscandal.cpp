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
    for (string s; getline(cin, s); )
        a.push_back(s);

    cout << a.size() << "\n";
    for (string &s : a)
        cout << s << "\n";
}