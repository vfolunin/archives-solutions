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

    if (a.size() > 1) {
        rotate(a.begin(), a.begin() + size/ 2 - 1, a.begin() + size / 2);
        rotate(a.rbegin(), a.rbegin() + size / 2 - 1, a.rbegin() + size / 2);
    }

    for (int value : a)
        cout << value << " ";
}