#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetNumber;
    cin >> targetNumber;

    vector<int> minMoves(targetNumber + 1, 1e9);
    minMoves[0] = 0;

    for (int number = 1; number <= targetNumber; number++)
        for (int n = number; n; n /= 10)
            if (n % 10)
                minMoves[number] = min(minMoves[number], minMoves[number - n % 10] + 1);
    
    cout << minMoves[targetNumber];
}