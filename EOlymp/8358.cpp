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

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    int minValue = *min_element(a.begin(), a.end());
    a.erase(remove(a.begin(), a.end(), minValue), a.end());
    int maxValue = *max_element(a.begin(), a.end());
    a.erase(remove(a.begin(), a.end(), maxValue), a.end());

    double sum = 0;
    for (int value : a)
        sum += value;

    cout.precision(0);
    cout << fixed << sum / a.size();
}