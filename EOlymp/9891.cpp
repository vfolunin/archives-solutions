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

    vector<long long> ways = { 1, 0 };
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        vector<long long> nextWays(2);
        for (int value : {a, b}) {
            if (value % 2) {
                nextWays[0] += ways[1];
                nextWays[1] += ways[0];
            } else {
                nextWays[0] += ways[0];
                nextWays[1] += ways[1];
            }
        }

        ways.swap(nextWays);
    }

    cout << ways[1];
}