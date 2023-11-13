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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> res;
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] < 0)
            res.push_back(a[i]);

    if (!res.empty()) {
        cout << res.size() << "\n";
        for (int value : res)
            cout << value << " ";
    } else {
        cout << "NO";
    }
}