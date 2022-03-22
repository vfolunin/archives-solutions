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

    int seatCount, groupCount;
    cin >> seatCount >> groupCount;

    int rejectedGroupCount = 0;

    for (int i = 0; i < groupCount; i++) {
        int groupSize;
        cin >> groupSize;

        if (seatCount >= groupSize)
            seatCount -= groupSize;
        else
            rejectedGroupCount++;
    }

    cout << rejectedGroupCount;
}