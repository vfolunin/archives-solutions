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

    double border, diff, value;
    int size;
    cin >> border >> diff >> size >> value;

    int type = value <= border, res = 0;
    for (int i = 1; i < size; i++) {
        cin >> value;

        int needType = value <= border;
        if (type && value >= border + diff || !type && value <= border - diff)
            type = !type;
        res += needType != type;
    }

    cout << res;
}