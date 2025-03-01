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

    int aSize;
    cin >> aSize;

    int aSum = 0;
    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;
        aSum += value;
    }

    int bSize;
    cin >> bSize;

    int bSum = 0;
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;
        bSum += value;
    }

    if (aSum > bSum)
        cout << "We win :)";
    else if (aSum == bSum)
        cout << "Peace <3";
    else
        cout << "We fail :(";
}