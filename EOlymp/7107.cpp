#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getTime(int a, int b) {
    return abs(a - b) * (a > b ? 31.0 / 47 : 1);
}

double getTime(vector<int> &a, int b) {
    double res = 0;
    for (int a : a)
        res = max(res, getTime(a, b));
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(3);
    for (int &value : a)
        cin >> value;
    
    int res = a[0];
    double resTime = getTime(a, a[0]);
    for (int i : a) {
        double time = getTime(a, i);
        if (resTime > time) {
            res = i;
            resTime = time;
        }
    }

    cout << res;
}