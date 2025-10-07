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

    int size;
    cin >> size;

    unordered_map<string, int> value;
    value["temperature"] = -30;

    for (int i = 0; i < size; i++) {
        string parameter;
        int delta;
        cin >> parameter >> delta;

        value[parameter] += delta;
    }

    cout << (value["ocean"] >= 9 && value["oxygen"] >= 14 &&
             value["temperature"] >= 8 ? "liveable" : "not liveable");
}