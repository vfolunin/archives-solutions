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

    int res = 3, sum = 0;
    while (sum < targetSum) {
        res++;
        sum += to_string(res).size();
    }

    cout << res;
}