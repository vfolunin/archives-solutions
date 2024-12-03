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

    int n, a, b;
    cin >> n >> a >> b;

    int countA = 0, countB = 0, countAB = 0;
    for (int i = 1; i <= n; i++) {
        if (i % a == 0 && i % b == 0)
            countAB++;
        else if (i % a == 0)
            countA++;
        else if (i % b == 0)
            countB++;
    }
    
    cout << countA << " " << countB << " " << countAB;
}