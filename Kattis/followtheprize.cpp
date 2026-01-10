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

    int size, index, swapCount;
    cin >> size >> index >> swapCount;

    vector<int> a(size);
    a[index - 1] = 1;

    for (int i = 0; i < swapCount; i++) {
        int index1, index2;
        cin >> index1 >> index2;

        swap(a[index1 - 1], a[index2 - 1]);
    }

    cout << find(a.begin(), a.end(), 1) - a.begin() + 1;
}