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

    int size, delta;
    cin >> size >> delta;

    vector<int> excluded(size);
    for (int index = (delta - 1) % size; !excluded[index]; index = (index + delta) % size)
        excluded[index] = 1;

    cout << count(excluded.begin(), excluded.end(), 0);
}