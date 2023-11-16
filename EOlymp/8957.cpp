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

        if (value % 2 == 0)
            res.push_back(value);
    }

    reverse(res.begin(), res.end());

    if (!res.empty()) {
        cout << res.size() << "\n";
        for (int value : res)
            cout << value << " ";
    } else {
        cout << "NO";
    }
}