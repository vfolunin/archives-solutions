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

    long long targetSum;
    cin >> targetSum;

    long long last = 0, sum = 0;
    int res = 0;
    for (int i = 1; sum < targetSum; i++) {
        last = last * 2 + i;
        sum += last;
        res++;
    }

    cout << res;
}