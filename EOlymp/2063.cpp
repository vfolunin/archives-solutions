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

    if (s == "1")
        cout << 1;
    else if (s == "10")
        cout << 46;
    else
        cout << 45 * (s.size() - 1) << string(s.size() - 3, '0') << 1;
}