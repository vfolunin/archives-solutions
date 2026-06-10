#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("dices.in", "r", stdin);
    freopen("dices.out", "w", stdout);

    long long n;
    cin >> n;

    cout << n / 6 + (n % 6 ? 7 - n % 6 : 0) << " " << n * 6;
}