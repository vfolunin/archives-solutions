#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> count(3);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value % 2)
            count[1]++;
        else
            count[value % 4]++;
    }

    cout << *max_element(count.begin(), count.end()) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}