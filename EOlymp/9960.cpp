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
    int minIndex = -1;

    for (int i = 0; i < size; i++) {
        cin >> a[i];

        if (a[i] % 2 == 0 && (minIndex == -1 || a[minIndex] > a[i]))
            minIndex = i;
    }

    if (minIndex != -1)
        cout << minIndex << " " << a[minIndex];
    else
        cout << "NO";
}