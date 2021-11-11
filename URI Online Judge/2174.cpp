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

    set<string> names;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        names.insert(name);
    }

    cout << "Falta(m) " << 151 - names.size() << " pomekon(s).\n";
}