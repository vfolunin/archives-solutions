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

    int upperCount = 0;
    for (char c : s)
        upperCount += (bool)isupper(c);

    if (!upperCount || upperCount == s.size())
        cout << "YES " << s.size();
    else
        cout << "NO " << min<int>(upperCount, s.size() - upperCount);
}