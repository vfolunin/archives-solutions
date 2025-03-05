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

    int size;
    long long index;
    cin >> size >> index;
    index--;

    vector<long long> factorial(size, 1);
    for (int i = 2; i < factorial.size(); i++)
        factorial[i] = factorial[i - 1] * i;

    vector<int> a(size);
    iota(a.begin(), a.end(), 1);

    for (int i = 0; i < factorial.size(); i++) {
        long long count = factorial[factorial.size() - 1 - i];
        cout << a[index / count] << " ";
        a.erase(a.begin() + index / count);
        index %= count;
    }
}