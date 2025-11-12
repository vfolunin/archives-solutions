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

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int average;
        cin >> average;

        int value = average * (i + 1) - sum;
        sum += value;

        cout << value << " ";
    }
}