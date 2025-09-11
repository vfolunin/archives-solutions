#include <iostream>
#include <algorithm>
#include <cmath>
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
    
    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    sort(a.rbegin(), a.rend());

    double res = a[0];
    for (int i = 1; i < a.size(); i++)
        res = 2 * sqrt(res * a[i]);

    cout << fixed << res;
}