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

    int typeCount, totalNutCount;
    cin >> typeCount >> totalNutCount;

    vector<int> nutCount(typeCount);
    for (int &count : nutCount)
        cin >> count;

    int goodTypeCount;
    cin >> goodTypeCount;

    int res = totalNutCount + 1;
    for (int i = 0; i < goodTypeCount; i++) {
        int type;
        cin >> type;

        res -= nutCount[type - 1];
    }

    cout << res;
}