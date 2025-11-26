#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dislikedCount;
    cin >> dislikedCount;

    bitset<100> dislikedMask;
    for (int i = 0; i < dislikedCount; i++) {
        int index;
        cin >> index;

        dislikedMask.set(index - 1);
    }

    int offerCount;
    cin >> offerCount;

    int res = 0;
    for (int i = 0; i < offerCount; i++) {
        int toppingCount;
        cin >> toppingCount;

        bitset<100> offerMask;
        for (int i = 0; i < toppingCount; i++) {
            int index;
            cin >> index;

            offerMask.set(index - 1);
        }
        res += !(offerMask & dislikedMask).any();
    }

    cout << res;
}