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

    vector<int> a;
    int value, minIndex = 0, maxIndex = 0;

    for (int i = 0; cin >> value; i++) {
        a.push_back(value);
        if (a[minIndex] > a[i])
            minIndex = i;
        if (a[maxIndex] <= a[i])
            maxIndex = i;
    }

    swap(a[minIndex], a[maxIndex]);

    for (int value : a)
        cout << value << " ";
}