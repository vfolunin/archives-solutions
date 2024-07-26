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

    int digitCount;
    cin >> digitCount;
    
    for (int page = 4; 1; page++) {
        digitCount -= to_string(page).size();
        if (digitCount <= 0) {
            cout << page;
            return 0;
        }
    }
}