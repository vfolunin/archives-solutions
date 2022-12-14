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

    int resIndex = -1, resValue;
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        if (b && (resIndex == -1 || resValue < a)) {
            resIndex = i + 1;
            resValue = a;
        }
    }

    cout << resIndex;
}