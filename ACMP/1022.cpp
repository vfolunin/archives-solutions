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

    long long p, num, den, n;
    cin >> p >> num >> den >> n;

    while (n * p % 100 || n * num % den)
        n++;

    cout << n;
}