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

    while (s.size() > 2) {
        string nextS;
        for (int i = 0; i < s.size(); i++)
            if (i % 3 != 2)
                nextS += s[i];

        s.swap(nextS);

        if (s.size() > 2)
            reverse(s.begin(), s.end());
    }

    cout << s;
}