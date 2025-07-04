#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(const string &sa, const string &op, const string &sb, const string &sc) {
    long long a = stoll(sa), b = stoll(sb);
    return (op == "+" ? a + b : a * b) == stoll(sc);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, op, b, eq, c;
    cin >> a >> op >> b >> eq >> c;

    for (int ai = 0; ai < a.size(); ai++) {
        for (int bi = 0; bi < b.size(); bi++) {
            for (int ci = 0; ci < c.size(); ci++) {
                vector<string> l = { a.substr(0, ai), b.substr(0, bi), c.substr(0, ci) };
                vector<string> r = { a.substr(ai), b.substr(bi), c.substr(ci) };
                sort(l.begin(), l.end());
                do {
                    if (check(l[0] + r[0], op, l[1] + r[1], l[2] + r[2])) {
                        cout << l[0] + r[0] << " " << op << " " << l[1] + r[1] << " = " << l[2] + r[2];
                        return 0;
                    }
                } while (next_permutation(l.begin(), l.end()));
            }
        }
    }
}