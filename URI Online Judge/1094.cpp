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

    map<char, int> typeCount;
    int totalCount = 0;

    for (int i = 0; i < n; i++) {
        int amount;
        char type;
        cin >> amount >> type;

        typeCount[type] += amount;
        totalCount += amount;
    }

    cout << "Total: " << totalCount << " cobaias\n";
    cout << "Total de coelhos: " << typeCount['C'] << "\n";
    cout << "Total de ratos: " << typeCount['R'] << "\n";
    cout << "Total de sapos: " << typeCount['S'] << "\n";
    cout.precision(2);
    cout << "Percentual de coelhos: " << fixed << 100.0 * typeCount['C'] / totalCount << " %\n";
    cout << "Percentual de ratos: " << fixed << 100.0 * typeCount['R'] / totalCount << " %\n";
    cout << "Percentual de sapos: " << fixed << 100.0 * typeCount['S'] / totalCount << " %\n";
}