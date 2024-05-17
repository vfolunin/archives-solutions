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

    int size, volume;
    cin >> size >> volume;

    vector<int> a(size);
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    sort(a.rbegin(), a.rend());
    int count = (sum + volume - 1) / volume;

    int delta = 0;
    for (int i = count; i < a.size(); i++)
        delta += a[i];

    cout << count << " " << delta;
}