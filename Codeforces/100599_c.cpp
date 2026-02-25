#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int size;
    cin >> size;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
    }

    cout << sum / 100;
}