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

    int swordCount;
    cin >> swordCount;

    vector<int> parts(2);

    for (int i = 0; i < swordCount; i++) {
        string sword;
        cin >> sword;

        for (int j = 0; j < sword.size(); j++)
            parts[j / 2] += !(sword[j] - '0');
    }

    int resSwordCount = min(parts[0] / 2, parts[1] / 2);
    
    cout << resSwordCount << " " << parts[0] - 2 * resSwordCount << " " << parts[1] - 2 * resSwordCount;
}