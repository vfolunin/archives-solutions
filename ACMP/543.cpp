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

    int pileCount, weight, delta, sum;
    cin >> pileCount >> weight >> delta >> sum;

    int res = ((pileCount - 1) * pileCount / 2 * weight - sum) / delta;

    cout << (res ? res : pileCount);
}