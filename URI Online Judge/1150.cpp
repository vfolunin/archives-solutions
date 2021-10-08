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

    int from, limit;
    cin >> from;
    do
        cin >> limit;
    while (limit <= from);

    int sum = 0, res = 0;
    while (sum <= limit) {
        sum += from + res;
        res++;
    }

    cout << res << "\n";
}