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

    int negativeCount = 0;
    for (int value; cin >> value && value; )
        negativeCount += value < 0;

    cout << negativeCount;
}