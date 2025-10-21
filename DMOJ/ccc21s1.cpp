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

    vector<int> h(size + 1);
    for (int &value : h)
        cin >> value;

    vector<int> w(size);
    for (int &value : w)
        cin >> value;

    double res = 0;
    for (int i = 0; i < size; i++)
        res += (h[i] + h[i + 1]) / 2.0 * w[i];

    cout << fixed << res;
}