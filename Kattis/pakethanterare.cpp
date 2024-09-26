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

    int itemCount, shopCount;
    cin >> itemCount >> shopCount;

    vector<int> shopItemCount(shopCount);
    for (int &count : shopItemCount)
        cin >> count;

    unordered_map<string, int> latest;
    for (int i = 0; i < itemCount; i++) {
        string name;
        int version;
        cin >> name >> version;

        latest[name] = version;
    }

    for (int itemCount : shopItemCount) {
        int res = 0;

        for (int i = 0; i < itemCount; i++) {
            string name;
            int version;
            cin >> name >> version;

            res += latest[name] - version;
        }

        cout << res << "\n";
    }
}