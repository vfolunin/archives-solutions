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

    vector<int> a(size), b(size);
    for (int i = size - 1; i >= 0; i--)
        cin >> a[i] >> b[i];

    vector<int> res(size);
    for (int i = 0, carry = 0; i < res.size(); i++) {
        int sum = a[i] + b[i] + carry;
        res[i] = sum % 10;
        carry = sum / 10;
    }

    for (int i = size - 1; i >= 0; i--)
        cout << res[i];
}