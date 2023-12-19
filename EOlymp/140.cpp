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

    long long eaten = 2, debt = 2;
    for (int i = 2; i <= n; i++) {
        long long taken = 1LL << i;
        debt += taken;
        eaten = taken - debt / 2;
        debt -= debt / 2;
    }

    cout << eaten << " " << debt;
}