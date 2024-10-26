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

    int limit, factor, size;
    cin >> limit >> factor >> size;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (sum + value * factor > limit) {
            cout << i;
            return 0;
        }

        sum += value * factor;
    }

    cout << size;
}