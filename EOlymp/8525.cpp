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

    int count = 0, sum = 0;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            if (value < 0 && value % 2 == 0) {
                count++;
                sum += value;
            }
        }
    }

    cout << count << " " << sum;
}