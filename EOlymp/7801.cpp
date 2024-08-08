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

    int sum, count;
    cin >> sum >> count;

    if (sum < count || sum > count * 3) {
        cout << "Impossible";
        return 0;
    }

    vector<int> res(count, 1);
    sum -= count;

    for (int &value : res) {
        int delta = min(sum, 2);
        sum -= delta;
        value += delta;
    }

    for (int value : res)
        cout << value << " ";
}