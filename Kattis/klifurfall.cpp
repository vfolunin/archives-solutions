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

    int size;
    cin >> size;

    map<string, map<int, int>> count;
    for (int i = 0; i < size; i++) {
        string s;
        int value;
        cin >> s >> value;

        count[s][value]++;
    }

    for (auto &[s, count] : count) {
        int maxValue = count.begin()->first;
        for (auto &[value, valueCount] : count)
            if (count[maxValue] < valueCount)
                maxValue = value;

        cout << s << " " << maxValue << "\n";
    }
}