#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetDivisor;
    cin >> size >> targetDivisor;

    vector<int> res;
    int divisor = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value % targetDivisor == 0) {
            res.push_back(value);
            divisor = gcd(divisor, value);
        }
    }

    if (divisor == targetDivisor) {
        cout << res.size() << "\n";
        for (int value : res)
            cout << value << " ";
    } else {
        cout << -1;
    }
}