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

    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i * i;

    cout << sum;
}