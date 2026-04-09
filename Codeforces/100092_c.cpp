#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("apbtest.in", "r", stdin);
    freopen("apbtest.out", "w", stdout);

    long long sum;
    cin >> sum;

    long long a = sum / 2, b = sum - a;

    cout << a << " " << b;
}