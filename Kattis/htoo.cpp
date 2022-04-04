#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<char, int> readMolecule() {
    string s;
    cin >> s;

    stringstream ss(s);
    map<char, int> molecule;

    for (char c; ss >> c; ) {
        int count = 1;
        if (isdigit(ss.peek()))
            ss >> count;
        molecule[c] += count;
    }

    return molecule;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<char, int> moleculeA = readMolecule();

    int factor;
    cin >> factor;

    for (auto &[c, count] : moleculeA)
        count *= factor;

    map<char, int> moleculeB = readMolecule();

    int res = 1e9;
    for (auto &[c, count] : moleculeB)
        res = min(res, moleculeA[c] / count);

    cout << res;
}