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

    int sum = 100, res = 0;
    while (sum < targetSum) {
        sum += sum / 100;
        res++;
    }

    cout << res;
}