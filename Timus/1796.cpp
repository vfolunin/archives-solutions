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

    vector<int> value = { 10, 50, 100, 500, 1000, 5000 };
    int minValue = 0, sum = 0;
    for (int value : value) {
        int count;
        cin >> count;

        if (count && !minValue)
            minValue = value;
        sum += value * count;
    }

    int price;
    cin >> price;

    int l = (sum - minValue) / price + 1;
    int r = sum / price;

    cout << r - l + 1 << "\n";
    for (int i = l; i <= r; i++)
        cout << i << " ";
}