#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    iota(a.begin(), a.end(), 1);

    do {
        for (int value : a)
            cout << value << " ";
        cout << "\n";
    } while (next_permutation(a.begin(), a.end()));
}