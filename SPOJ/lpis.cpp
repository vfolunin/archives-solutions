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

    vector<int> res(1e6 + 1);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res[value] = max(res[value], res[value - 1] + 1);
    }

    cout << *max_element(res.begin(), res.end());
}