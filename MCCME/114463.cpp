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

    sort(a.begin(), a.end());

    long long sum = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        sum += a[i];

    if (sum + 1 < a.back())
        cout << sum * 2 + 1;
    else
        cout << sum + a.back();
}