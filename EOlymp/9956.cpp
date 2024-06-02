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

    int maxEven = -101;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value % 2 == 0 && maxEven < value)
            maxEven = value;
    }

    if (maxEven != -101)
        cout << maxEven;
    else
        cout << "NO";
}