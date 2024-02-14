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

    int heads1 = 1, legs1, heads2, legs2 = 1, totalHeads, totalLegs;
    cin >> legs1 >> heads2 >> totalHeads >> totalLegs;

    for (int count1 = 1; count1 * heads1 <= totalHeads && count1 * legs1 <= totalLegs; count1++) {
        if ((totalHeads - count1 * heads1) % heads2)
            continue;

        int count2 = (totalHeads - count1 * heads1) / heads2;
        if (!count2 || (totalLegs - count1 * legs1) % count2)
            continue;
        
        cout << (totalLegs - count1 * legs1) / count2;
        return 0;
    }

    cout << -1;
}