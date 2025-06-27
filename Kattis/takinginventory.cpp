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
    for (int i = 0; i < size; i++) {
        string name;
        int value;
        cin >> name >> value;

        count[name] += value;
    }

    for (auto &[name, count] : count)
        cout << name << " " << (count + 63) / 64 << "\n";
}