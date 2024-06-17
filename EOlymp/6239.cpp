#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_map<string, int> count;
    int totalCount = 0;

    for (string s; cin >> s; ) {
        count[s]++;
        totalCount++;
    }

    cout.precision(2);
    for (const string &s : { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" })
        cout << s << " " << count[s] << " " << fixed << (double)count[s] / totalCount << "\n";
    cout << "Total " << totalCount << " 1.00";
}