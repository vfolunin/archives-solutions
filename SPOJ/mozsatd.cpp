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

    long long sum = 0;
    int minOddValue = 1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        if (value % 2)
            minOddValue = min(minOddValue, value);
    }

    if (sum % 2)
        sum -= minOddValue;

    cout << sum / 2;
}