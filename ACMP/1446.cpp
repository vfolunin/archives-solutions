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

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    long long sum = a.back();
    for (int i = size - 2, factor = -1; i >= 0; i--, factor *= -1) {
        a[i] -= factor * sum;
        sum += factor * a[i];
    }

    for (long long value : a)
        cout << value << " ";
}