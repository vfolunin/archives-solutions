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
    
    int stoneCount, frogCount;
    cin >> stoneCount >> frogCount;

    vector<int> stones(stoneCount);

    for (int i = 0; i < frogCount; i++) {
        int stone, jump;
        cin >> stone >> jump;

        for (int j = (stone - 1) % jump; j < stoneCount; j += jump)
            stones[j] = 1;
    }

    for (int stone : stones)
        cout << stone << "\n";
}