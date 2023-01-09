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

    int from, delta, size;
    cin >> from >> delta >> size;

    vector<int> a(size);
    a[0] = from;
    for (int i = 1; i < a.size(); i++)
        a[i] = a[i - 1] + delta;
    reverse(a.begin(), a.end());

    for (int value : a)
        cout << value << " ";
}