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

    int houseCount;
    cin >> houseCount;

    vector<int> houses(houseCount);
    for (int &house : houses)
        cin >> house;

    int sum;
    cin >> sum;

    set<int> seen;
    for (int house : houses) {
        if (seen.count(sum - house)) {
            cout << sum - house << " " << house << "\n";
            return 0;
        }
        seen.insert(house);
    }
}