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
    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        count += value < 30;
    }

    cout << (count * 2 + 8) / 9 << " " << count;
}