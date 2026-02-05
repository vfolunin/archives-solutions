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

    int sum, size;
    cin >> sum >> size;

    for (int i = 1; i < size; i++) {
        cout << i << "\n";
        sum -= i;
    }
    cout << sum;
}