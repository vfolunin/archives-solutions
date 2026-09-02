#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long factorial(int n) {
    static vector<long long> memo(21);
    long long &res = memo[n];
    if (res)
        return res;

    if (n <= 1)
        return res = 1;

    return res = factorial(n - 1) * n;
}

void permutationByIndex() {
    int size;
    long long index;
    cin >> size >> index;
    index--;

    vector<int> values(size);
    iota(values.begin(), values.end(), 1);

    vector<int> permutation;
    for (int i = 0; i < size; i++) {
        auto it = values.begin() + index / factorial(size - 1 - i);
        index %= factorial(size - 1 - i);
        permutation.push_back(*it);
        values.erase(it);
    }

    for (int value : permutation)
        cout << value << " ";
    cout << "\n";
}

void indexByPermutation() {
    int size;
    cin >> size;

    vector<int> permutation(size);
    for (int &value : permutation)
        cin >> value;

    vector<int> values(size);
    iota(values.begin(), values.end(), 1);

    long long index = 0;
    for (int i = 0; i < size; i++) {
        auto it = find(values.begin(), values.end(), permutation[i]);
        index += (it - values.begin()) * factorial(size - 1 - i);
        values.erase(it);
    }
    
    cout << index + 1 << "\n";
}

void solve() {
    int type;
    cin >> type;

    if (type == 1)
        permutationByIndex();
    else
        indexByPermutation();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}