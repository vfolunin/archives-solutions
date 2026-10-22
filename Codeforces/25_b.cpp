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
    cin >> s >> s;

    int i = 0;
    for (; i + 3 < s.size(); i += 2)
        cout << s.substr(i, 2) << "-";
    cout << s.substr(i);
}