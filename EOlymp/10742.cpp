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

    int count1 = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count1 += value == 1;
    }

    cout << min(count1, size - count1);
}