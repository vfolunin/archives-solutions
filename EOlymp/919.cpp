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

    int count = 0;
    double sum = 0;

    for (int i = 1; i <= size; i++) {
        double value;
        cin >> value;

        if (i % 3 == 0 && value > 0) {
            count++;
            sum += value;
        }
    }

    cout.precision(2);
    cout << count << " " << fixed << sum;
}