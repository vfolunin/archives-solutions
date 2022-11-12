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

    for (int i = 1; i < size; i++) {
        if (a[i - 1] <= a[i])
            continue;

        int j = i;
        while (j && a[j - 1] > a[j]) {
            swap(a[j - 1], a[j]);
            j--;
        }

        for (int value : a)
            cout << value << " ";
        cout << "\n";
    }
}