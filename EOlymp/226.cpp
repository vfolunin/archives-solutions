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

    int need, size;
    cin >> need >> size;
    need--;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > 1)
            need -= value - 1;
    }

    cout << max(need, 0);
}