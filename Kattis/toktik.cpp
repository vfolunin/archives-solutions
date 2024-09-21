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

    unordered_map<string, int> count;
    string bestName;

    for (int i = 0; i < size; i++) {
        string name;
        int delta;
        cin >> name >> delta;

        count[name] += delta;

        if (bestName.empty() || count[bestName] < count[name])
            bestName = name;
    }

    cout << bestName;
}