#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long sum;
    cin >> sum;

    long long count = sqrt(sum);
    while (count * (count + 1) / 2 < sum)
        count++;

    long long skippedValue = count * (count + 1) / 2 - sum;

    cout << count - (bool)skippedValue << "\n";
    for (int value = 0; value <= count; value++)
        if (value && value != skippedValue)
            cout << value << " ";
}