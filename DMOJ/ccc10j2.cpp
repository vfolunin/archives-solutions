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

    int aForward, aBackward, bForward, bBackward, count;
    cin >> aForward >> aBackward >> bForward >> bBackward >> count;

    int aPos = 0, bPos = 0;
    for (int i = 0; i < count; i++) {
        aPos += i % (aForward + aBackward) < aForward ? 1 : -1;
        bPos += i % (bForward + bBackward) < bForward ? 1 : -1;
    }

    if (abs(aPos) == abs(bPos))
        cout << "Tied";
    else if (abs(aPos) < abs(bPos))
        cout << "Byron";
    else
        cout << "Nikky";
}