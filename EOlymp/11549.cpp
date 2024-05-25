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
    for (int &value : a)
        cin >> value;

    vector<int> prefixMax(size);
    prefixMax[0] = a[0];
    for (int i = 1; i < size; i++)
        prefixMax[i] = max(prefixMax[i - 1], a[i]);

    vector<int> suffixMax(size);
    suffixMax[size - 1] = a[size - 1];
    for (int i = size - 2; i >= 0; i--)
        suffixMax[i] = max(suffixMax[i + 1], a[i]);

    long long res = 0;
    for (int i = 0; i < size; i++)
        res += max(0, min(prefixMax[i], suffixMax[i]) - a[i]);

    cout << res;
}