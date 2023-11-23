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

    if (s.size() > 3)
        s = s.substr(s.size() - 3);

    int value = stoi(s);

    for (int d = 2; d <= 8; d *= 2)
        cout << (value % d ? "No\n" : "Yes\n");
}