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

    vector<double> nums(3);
    for (double &num : nums)
        cin >> num;

    vector<double> dens(7);
    for (double &den : dens)
        cin >> den;

    vector<pair<double, pair<int, int>>> a;
    for (int numI = 0; numI < nums.size(); numI++)
        for (int denI = 0; denI < dens.size(); denI++)
            a.push_back({ nums[numI] / dens[denI], { numI + 1, denI + 1 } });

    sort(a.begin(), a.end());

    cout.precision(2);
    for (auto &[ratio, indexes] : a)
        cout << fixed << ratio << " " << indexes.first << " " << indexes.second << "\n";
}