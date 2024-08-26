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

    int size, index;
    cin >> size >> index;
    index--;

    vector<int> a(size);
    for (long long i = 1; i <= size; i++)
        a[i - 1] = (132 * i * i * i + 77 * i * i + 1345 * i + 1577) % 1743;

    nth_element(a.begin(), a.begin() + index, a.end());

    cout << a[index];
}