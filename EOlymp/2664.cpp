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
        int j = i;
        bool swapped = 0;

        while (j && a[j - 1] > a[j]) {
            swap(a[j - 1], a[j]);
            j--;
            swapped = 1;
        }

        if (swapped) {
            for (int value : a)
                cout << value << " ";
            cout << "\n";
        }
    }
}