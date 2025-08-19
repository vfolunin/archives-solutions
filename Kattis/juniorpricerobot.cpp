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
    
    int size, threshold;
    cin >> size >> threshold;

    for (int i = 1; i < size; i++) {
        int value;
        cin >> value;

        if (value <= threshold) {
            cout << i;
            return 0;
        }
    }

    cout << "infinity";
}