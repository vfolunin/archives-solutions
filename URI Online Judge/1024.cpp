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

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        for (char &c : s)
            if (isalpha(c))
                c += 3;

        reverse(s.begin(), s.end());

        for (int j = s.size() / 2; j < s.size(); j++)
            s[j]--;

        cout << s << "\n";
    }
}