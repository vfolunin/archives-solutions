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

    vector<int> count(6);
    while (1) {
        int value;
        cin >> value;

        if (value == -1)
            break;

        count[min<int>(value / 10000, count.size() - 1)]++;
    }

    for (int count : count)
        cout << count << "\n";
}