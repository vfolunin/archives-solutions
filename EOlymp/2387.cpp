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

    vector<long long> factorial = { 1 };
    for (int i = 1; i < size; i++)
        factorial.push_back(factorial.back() * i);

    vector<int> values(size);
    iota(values.begin(), values.end(), 1);

    for (int i = 0; i < size; i++) {
        int j = index / factorial[size - 1 - i];
        index %= factorial[size - 1 - i];
        cout << values[j] << " ";
        values.erase(values.begin() + j);
    }
}