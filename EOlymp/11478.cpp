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

    int size;
    cin >> size;

    int aSum = 0, bSum = 0;
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        aSum += a;
        bSum += b;
    }

    cout << min(aSum, size - aSum) + min(bSum, size - bSum);
}