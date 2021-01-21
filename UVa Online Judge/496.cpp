#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<int> readSet() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    set<int> s;
    int x;
    while (ss >> x)
        s.insert(x);
    return s;
}

bool solve() {
    set<int> a = readSet();
    set<int> b = readSet();
    if (a.empty() || b.empty())
        return 0;
    
    int aInB = 0, bInA = 0;
    for (int x : a)
        aInB += b.count(x);
    for (int x : b)
        bInA += a.count(x);

    if (aInB == a.size() && bInA == b.size())
        cout << "A equals B\n";
    else if (aInB == a.size())
        cout << "A is a proper subset of B\n";
    else if (bInA == b.size())
        cout << "B is a proper subset of A\n";
    else if (!aInB && !bInA)
        cout << "A and B are disjoint\n";
    else
        cout << "I'm confused!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}