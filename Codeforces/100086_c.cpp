#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("success.in", "r", stdin);
    freopen("success.out", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    next_permutation(a.begin(), a.end());

    for (int value : a)
        cout << value << " ";
}