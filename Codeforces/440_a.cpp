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

    long long size;
    cin >> size;

    long long sum = size * (size + 1) / 2;
    for (int i = 0; i < size - 1; i++) {
        int value;
        cin >> value;

        sum -= value;
    }

    cout << sum;
}