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

    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        value--;
    }

    vector<long long> factorial(size, 1);
    for (int i = 1; i < factorial.size(); i++)
        factorial[i] = factorial[i - 1] * i;

    long long res = 1;
    for (int i = 0; i < a.size(); i++) {
        res += a[i] * factorial[a.size() - 1 - i];
        for (int j = i + 1; j < a.size(); j++)
            a[j] -= a[j] > a[i];
    }

    cout << res;
}