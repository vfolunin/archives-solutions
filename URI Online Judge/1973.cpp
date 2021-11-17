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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int farmCount;
    cin >> farmCount;

    vector<int> cowCount(farmCount);
    long long remainingCows = 0;

    for (int &c : cowCount) {
        cin >> c;
        remainingCows += c;
    }

    set<int> attackedFarms;
    int pos = 0;

    while (1) {
        if (pos < 0 || pos >= farmCount)
            break;

        attackedFarms.insert(pos);
        if (cowCount[pos])
            remainingCows--;

        if (cowCount[pos]-- % 2)
            pos++;
        else
            pos--;
    }

    cout << attackedFarms.size() << " " << remainingCows << "\n";
}