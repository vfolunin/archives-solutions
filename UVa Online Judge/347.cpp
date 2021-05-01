#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isRunaround(string s) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[pos] == 'X')
            return 0;

        int val = s[pos] - '0';
        s[pos] = 'X';
        pos = (pos + val) % s.size();
    }
    return !pos;
}

set<int> prepare() {
    set<int> runaround;
    string s = "123456789";
    do {
        for (int len = 1; len <= 9; len++)
            if (isRunaround(s.substr(0, len)))
                runaround.insert(stoi(s.substr(0, len)));
    } while (next_permutation(s.begin(), s.end()));
    return runaround;
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    static set<int> runaround = prepare();

    cout << "Case " << test << ": " << *runaround.lower_bound(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}