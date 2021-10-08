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

    int from, n;
    cin >> from;
    do
        cin >> n;
    while (n <= 0);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += from + i;

    cout << sum << "\n";
}