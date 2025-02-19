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

    int delta, size;
    cin >> delta >> size;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        sum = max(sum - delta, 0);
    }

    cout << sum;
}