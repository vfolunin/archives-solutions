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
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > 0 && value % 6 == 0) {
            count++;
            sum += value;
        }
    }

    cout << count << " " << sum;
}