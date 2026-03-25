#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);

    int size;
    cin >> size;

    vector<int> permutation(size + 1);

    for (int i = 1; i <= size; i++) {
        int index;
        cin >> index;
        permutation[index] = i;
    }

    for (int i = 1; i <= size; i++)
        cout << permutation[i] << " ";
}