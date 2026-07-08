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

    vector<int> den(5);
    for (int &value : den)
        cin >> value;

    vector<int> num(5);
    for (int &value : num)
        cin >> value;

    int res = 1e9;
    for (int i = 0; i < num.size(); i++)
        res = min(res, num[i] / den[i]);

    cout << res;
}