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

    int size1, size2;
    cin >> size1 >> size2;

    int sum1 = 0;
    for (int i = 0; i < size1; i++) {
        int value;
        cin >> value;

        sum1 += value;
    }

    int sum2 = 0;
    for (int i = 0; i < size2; i++) {
        int value;
        cin >> value;

        sum2 += value;
    }

    if (sum1 > sum2)
        cout << "Button 1";
    else if (sum1 < sum2)
        cout << "Button 2";
    else
        cout << "Oh no";
}