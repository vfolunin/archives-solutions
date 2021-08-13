#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string a, b, c, d;
    if (!(cin >> a >> b >> c >> d))
        return 0;

    int pa = 0;
    while (pa < a.size() && b.find(a[pa]) == -1)
        pa++;

    int pc = 0;
    while (pc < c.size() && d.find(c[pc]) == -1)
        pc++;

    if (test)
        cout << "\n";

    if (pa == a.size() || pc == c.size()) {
        cout << "Unable to make two crosses\n";
        return 1;
    }

    int pb = b.find(a[pa]);
    int pd = d.find(c[pc]);

    vector<string> res(30, string(30, ' '));
    res[15] = a + "   " + c;
    for (int i = 0; i < b.size(); i++)
        res[15 - pb + i][pa] = b[i];
    for (int i = 0; i < d.size(); i++)
        res[15 - pd + i][a.size() + 3 + pc] = d[i];

    for (string &row : res)
        while (!row.empty() && row.back() == ' ')
            row.pop_back();
    res.erase(remove(res.begin(), res.end(), ""), res.end());

    for (string &row : res)
        cout << row << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}