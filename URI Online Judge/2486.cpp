#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int itemCount;
    cin >> itemCount;

    if (!itemCount)
        return 0;

    static map<string, int> c = {
        { "suco de laranja", 120 },
        { "morango fresco", 85 },
        { "mamao", 85 },
        { "goiaba vermelha", 70 },
        { "manga", 56 },
        { "laranja", 50 },
        { "brocolis", 34 }
    };

    int totalC = 0;
    for (int i = 0; i < itemCount; i++) {
        int amount;
        cin >> amount;
        string name;
        getline(cin, name);
        totalC += amount * c[name.substr(1)];
    }

    if (totalC > 130)
        cout << "Menos " << totalC - 130 << " mg\n";
    else if (totalC < 110)
        cout << "Mais " << 110 - totalC << " mg\n";
    else
        cout << totalC << " mg\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}