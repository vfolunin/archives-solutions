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

    vector<int> has(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value <= size)
            has[value - 1] = 1;
    }

    auto it = find(has.begin(), has.end(), 0);

    cout << (it != has.end() ? it - has.begin() + 1 : 0);
}