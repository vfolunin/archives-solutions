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

    int size, queryCount;
    cin >> size >> queryCount;

    vector<unordered_set<string>> values(size);
    for (int i = 0; i < queryCount; i++) {
        int type, index;
        string value;
        cin >> type >> index >> value;
        index--;

        if (type == 1)
            cout << (values[index].count(value)) << "\n";
        else
            values[index].insert(value);
    }
}