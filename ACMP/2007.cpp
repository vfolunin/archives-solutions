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

    vector<long long> a(size);
    for (long long &value : a)
        cin >> value;

    for (int i = 1; i <= size; i++)
        for (int j = i * 2 - 1; j <= i * 2 + 1; j++)
            if (i < j && j <= a.size())
                a[i - 1] += a[j - 1] * (j % 2 ? 1 : 2);

    int maxI = max_element(a.begin(), a.end()) - a.begin();

    cout << a[maxI] << "\n" << maxI + 1;
}