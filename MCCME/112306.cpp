#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sign(int value) {
    if (value > 0)
        return 1;
    else if (value == 0)
        return 0;
    else
        return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    stable_sort(a.begin(), a.end(), [](int lhs, int rhs) {
        return sign(lhs) > sign(rhs);
    });

    for (int value : a)
        cout << value << " ";
}