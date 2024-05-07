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

    vector<int> a(8);
    for (int &value : a)
        cin >> value;

    vector<int> sum = { a[0] + a[1] + a[2], a[3] + a[4] + a[5], a[6] + a[7] };
    vector<string> name = { "Bus", "Metro", "Taxi" };

    cout << name[min_element(sum.begin(), sum.end()) - sum.begin()];
}