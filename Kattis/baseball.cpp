#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int readMask() {
    string name;
    cin >> name;

    vector<string> types = { "1B", "2B", "SS", "3B", "C", "P", "LF", "CF", "RF" };
    int mask = 1 << 9;

    while (1) {
        string type;
        cin >> type;

        if (type == "X")
            break;
        if (type.back() == ',')
            type.pop_back();

        mask |= 1 << find(types.begin(), types.end(), type) - types.begin();
    }

    return mask;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> masks(10);
    for (int &mask : masks)
        mask = readMask();

    sort(masks.begin(), masks.end());

    do {
        bool ok = 1;
        for (int i = 0; i < masks.size() && ok; i++)
            ok &= (masks[i] & (1 << i)) != 0;

        if (ok) {
            cout << "True";
            return 0;
        }
    } while (next_permutation(masks.begin(), masks.end()));

    cout << "False";
}