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

    int aScore = 100, bScore = 100;
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        if (a < b)
            aScore -= b;
        else if (a > b)
            bScore -= a;
    }

    cout << aScore << "\n" << bScore;
}