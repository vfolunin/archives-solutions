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

    vector<int> res;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value % 5 == 0)
            res.push_back(value);
    }

    if (res.empty()) {
        cout << "NO";
    } else {
        cout << res.size() << "\n";
        for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << " ";
    }
}