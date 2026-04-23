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

    int sum = 0;
    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    int res = 0;
    for (int value : a)
        res += value % 2 == sum % 2;

    cout << res;
}