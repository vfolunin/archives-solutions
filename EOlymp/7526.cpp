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

    int size, sumLimit;
    cin >> size >> sumLimit;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (sum + value > sumLimit) {
            cout << i;
            return 0;
        }

        sum += value;
    }

    cout << size;
}