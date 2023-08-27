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

    set<string> values;

    for (int i = 0; i < 5; i++) {
        string value;
        cin >> value;

        values.insert(value);
    }

    cout << values.size();
}