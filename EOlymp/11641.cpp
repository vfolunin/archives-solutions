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

    vector<int> res(4);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res[(value - 1) / 3]++;
    }

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << " ";
}