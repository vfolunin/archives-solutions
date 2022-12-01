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

    map<int, int> count;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        count[value]++;
    }

    for (auto &[value, count] : count)
        cout << value << " " << count << "\n";
}