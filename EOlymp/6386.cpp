#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int size;
    string s;
    if (!(cin >> size >> s))
        return 0;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    sort(a.begin(), a.end(), [&](string &lhs, string &rhs) {
        for (int i = 0; i < lhs.size() && i < rhs.size(); i++)
            if (lhs[i] != rhs[i])
                return s.find(lhs[i]) < s.find(rhs[i]);
        return lhs.size() < rhs.size();
    });

    cout << "year " << test << "\n";
    for (string &s : a)
        cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}