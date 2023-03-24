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
    cin >> size;

    vector<int> a(size);
    iota(a.begin(), a.end(), 1);

    for (int i = 2; i < size; i++)
        swap(a[i], a[i / 2]);

    for (int value : a)
        cout << value << " ";
}