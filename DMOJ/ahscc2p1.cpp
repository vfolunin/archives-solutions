#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x, y, z;
    cin >> x >> y >> z;

    vector<int> a(6);
    for (int &value : a)
        cin >> value;

    if (accumulate(a.begin(), a.end(), 0) >= x &&
        count(a.begin(), a.end(), 100) >= y &&
        a.size() - count(a.begin(), a.end(), 0) >= z)
        cout << "MASTER";
    else
        cout << "REJECTED AGAIN";
}