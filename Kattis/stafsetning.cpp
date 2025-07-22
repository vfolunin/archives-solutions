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
    
    int size, den, num;
    cin >> size >> den >> num;

    int count = num / den;
    if (!count) {
        cout << ":(";
        return 0;
    }

    long long sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
    }

    cout << (sum + count - 1) / count;
}