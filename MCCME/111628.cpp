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

    for (int i = 0; swapCount; i++) {
        for (int j = 1; swapCount && j < size; j++) {
            if (swapCount && a[j - 1] < a[j]) {
                swap(a[j - 1], a[j]);
                swapCount--;
            }
        }
    }

    for (int value : a)
        cout << value << " ";
}