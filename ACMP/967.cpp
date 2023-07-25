#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n, int base) {
    int sum = 0;
    while (n) {
        sum += n % base;
        n /= base;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, base1, base2;
    cin >> size >> base1 >> base2;

    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        value = digitSum(value, base1) * digitSum(value, base2);
    }

    sort(a.begin(), a.end());

    for (int value : a)
        cout << value << " ";
}