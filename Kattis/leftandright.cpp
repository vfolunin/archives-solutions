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

    int lCount = 0;
    while (lCount < s.size() && s[lCount] == 'L')
        lCount++;

    int from = 1 + lCount;
    for (int i = 0; i <= lCount; i++)
        cout << from - i << "\n";
    
    for (int i = lCount; i < s.size(); i += 1 + lCount) {
        lCount = 0;
        while (i + 1 + lCount < s.size() && s[i + 1 + lCount] == 'L')
            lCount++;

        from += 1 + lCount;
        for (int j = 0; j <= lCount; j++)
            cout << from - j << "\n";
    }
}