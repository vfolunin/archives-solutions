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

    vector<int> count(26);
    char c;
    while (cin >> c)
        if (islower(c))
            count[c - 'a']++;

    for (int i = 0; i < count.size(); i++)
        if (count[i])
            cout << (char)('a' + i) << " " << count[i] << "\n";
}