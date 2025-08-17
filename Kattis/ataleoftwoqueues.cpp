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

    int sizeA, sizeB;
    cin >> sizeA >> sizeB;

    int sumA = 0;
    for (int i = 0; i < sizeA; i++) {
        int value;
        cin >> value;

        sumA += value;
    }

    int sumB = 0;
    for (int i = 0; i < sizeB; i++) {
        int value;
        cin >> value;

        sumB += value;
    }

    if (sumA < sumB)
        cout << "left";
    else if (sumA == sumB)
        cout << "either";
    else
        cout << "right";
}