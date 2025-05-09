#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_set<string> values;
    for (string value; cin >> value; ) {
        sort(value.begin(), value.end());
        values.insert(value);
    }

    cout << values.size();
}