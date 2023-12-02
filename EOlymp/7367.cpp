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

    int targetSum;
    cin >> targetSum;

    double sum = 0, cur = 10;
    int res = 0;
    while (sum < targetSum) {
        sum += cur;
        cur *= 1.1;
        res++;
    }

    cout << res;
}