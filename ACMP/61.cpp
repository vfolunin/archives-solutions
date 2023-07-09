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
 
    int aSum = 0, bSum = 0;
    for (int i = 0; i < 4; i++) {
        int a, b;
        cin >> a >> b;
        aSum += a;
        bSum += b;
    }
 
    if (aSum > bSum)
        cout << 1;
    else if (aSum == bSum)
        cout << "DRAW";
    else
        cout << 2;
}