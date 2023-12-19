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

    int weightLimit;
    cin >> weightLimit;

    vector<int> canMake(weightLimit + 1);
    canMake[0] = 1;

    for (int itemWeight; cin >> itemWeight; )
        for (int weight = weightLimit; weight >= itemWeight; weight--)
            canMake[weight] |= canMake[weight - itemWeight];
    
    int res = weightLimit;
    while (!canMake[res])
        res--;

    cout << res;
}