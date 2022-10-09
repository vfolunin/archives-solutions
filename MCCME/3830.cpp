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

    int value, positiveCount = 0;
    
    while (cin >> value)
        positiveCount += value > 0;

    cout << positiveCount;
}