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

    int teamCount, roomSize;
    cin >> teamCount >> roomSize;

    int aSum = 0, bSum = 0;
    for (int i = 0; i < teamCount; i++) {
        int a, b;
        cin >> a >> b;

        aSum += a;
        bSum += b;
    }

    cout << (aSum + roomSize - 1) / roomSize + (bSum + roomSize - 1) / roomSize;
}