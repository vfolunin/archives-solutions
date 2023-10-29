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
    for (int i = 0; i < size; i++) {
        int inversionCount;
        cin >> inversionCount;
        
        a[i] = i + 1 - inversionCount;

        for (int j = 0; j < i; j++)
            a[j] += a[j] >= a[i];
    }

    for (int value : a)
        cout << value << " ";
}