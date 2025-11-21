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

    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    int count;
    cin >> count;

    for (int value : a) {
        int delta = min(value, count);
        count -= delta;

        cout << value - delta << " ";
    }
}