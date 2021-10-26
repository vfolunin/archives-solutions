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

    int childCount;
    cin >> childCount;

    vector<string> names(childCount);
    int goodCount = 0;

    for (string &name : names) {
        char type;
        cin >> type >> name;
        goodCount += type == '+';
    }

    sort(names.begin(), names.end());

    for (string &name : names)
        cout << name << "\n";
    cout << "Se comportaram: " << goodCount;
    cout << " | Nao se comportaram: " << childCount - goodCount << "\n";
}