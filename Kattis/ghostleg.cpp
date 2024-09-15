#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, swapCount;
    cin >> size >> swapCount;

    vector<int> a(size);
    iota(a.begin(), a.end(), 1);

    for (int i = 0; i < swapCount; i++) {
        int index;
        cin >> index;

        swap(a[index - 1], a[index]);
    }

    for (int value : a)
        cout << value << "\n";
}