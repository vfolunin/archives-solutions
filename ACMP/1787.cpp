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

    int limit, size;
    cin >> limit >> size;

    int aSum = 0, bSum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (aSum + value <= limit)
            aSum += value;
        else
            bSum += value;
    }

    cout << aSum << " " << bSum;
}