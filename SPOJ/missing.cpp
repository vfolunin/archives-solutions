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

    long long count, from;
    cin >> count >> from;

    long long sum = (from + from + count - 1) * count / 2;

    for (int i = 0; i < count - 1; i++) {
        long long value;
        cin >> value;

        sum -= value;
    }

    cout << sum;
}