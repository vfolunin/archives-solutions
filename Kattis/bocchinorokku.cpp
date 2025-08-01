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

    vector<int> sortedA = a;
    sort(sortedA.begin(), sortedA.end());

    for (int value : a)
        cout << lower_bound(sortedA.begin(), sortedA.end(), value) - sortedA.begin() << " ";
}