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

    int maxValue, res = 0;
    for (int value; cin >> value; ) {
        if (!res || maxValue <= value) {
            maxValue = value;
            res++;
        }
    }

    cout << res;
}