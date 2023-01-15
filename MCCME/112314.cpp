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

    for (int i = 0; i < 3; i++) {
        auto it = min_element(a.begin() + i, a.end());
        cout << *it << " ";
        a.erase(it);
    }

    for (int value : a)
        cout << value << " ";
}