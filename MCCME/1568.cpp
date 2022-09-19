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

    vector<int> count(9);

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        count[value - 1]++;
    }

    for (int count : count)
        cout << count << " ";
}