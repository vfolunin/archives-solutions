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

    vector<string> a(3);
    int maxSize = 0;

    for (string &s : a) {
        cin >> s;
        maxSize = max<int>(maxSize, s.size());
    }

    for (string &s : a)
        if (s.size() == maxSize)
            cout << s << "\n";
}