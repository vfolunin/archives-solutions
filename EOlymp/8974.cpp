#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    unordered_map<int, int> count;

    for (int &value : a) {
        cin >> value;
        count[value]++;
    }

    vector<int> res;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (count[a[i]] > 1) {
            res.push_back(a[i]);
            count[a[i]] = 0;
        }
    }
    reverse(res.begin(), res.end());

    if (!res.empty()) {
        for (int value : res)
            cout << value << " ";
    } else {
        cout << "NO";
    }
}