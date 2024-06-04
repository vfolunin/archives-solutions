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
    
    int size, sum;
    cin >> size >> sum;

    int cur = 0, res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        cur += value;
        if (cur <= sum)
            res = max(res, cur);
    }

    cout << res;
}