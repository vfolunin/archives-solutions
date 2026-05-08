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

    double numSum = 0, denSum = 0;
    for (int i = 0; i < size; i++) {
        int num, den;
        cin >> num >> den;

        numSum += num;
        denSum += den;
    }

    cout.precision(2);
    cout << fixed << numSum / denSum * 100;
}