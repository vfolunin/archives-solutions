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

    vector<long long> perfect = { 6, 28, 496, 8128, 33550336, 8589869056, 137438691328 };

    long long n;
    cin >> n;

    long long res = *prev(lower_bound(perfect.begin(), perfect.end(), n));
    
    int bit = 63;
    while (!(res & (1LL << bit)))
        bit--;
    for (; bit >= 0; bit--)
        cout << ((res >> bit) & 1);
}