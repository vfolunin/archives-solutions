#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    int index;
    if (!(cin >> s >> index))
        return 0;

    cout << s << " " << index << " = ";

    index--;

    vector<int> factorial(s.size(), 1);
    for (int i = 2; i < factorial.size(); i++)
        factorial[i] = factorial[i - 1] * i;

    string res;
    for (int i = 0; i < factorial.size(); i++) {
        int count = factorial[factorial.size() - 1 - i];
        if (index / count >= s.size()) {
            cout << "No permutation\n";
            return 1;
        }

        res += s[index / count];
        s.erase(s.begin() + index / count);
        index %= count;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}