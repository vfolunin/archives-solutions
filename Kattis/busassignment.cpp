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

    int stopCount;
    cin >> stopCount;

    int capacity = 0, res = 0;
    for (int i = 0; i < stopCount; i++) {
        int out, in;
        cin >> out >> in;

        capacity += in - out;
        res = max(res, capacity);
    }

    cout << res;
}