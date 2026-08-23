#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("coins.in", "r", stdin);
    freopen("coins.out", "w", stdout);

    int size;
    cin >> size;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        sum += value;
    }

    cout << min(sum, size - sum);
}