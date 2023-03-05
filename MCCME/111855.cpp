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

    vector<int> a(10);
    int sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }
    sum /= 10;

    int res = 0;
    for (int value : a)
        res += value > sum;

    cout << res;
}