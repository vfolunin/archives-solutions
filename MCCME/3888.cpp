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

    int curBalance = 0, minBalance = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value == 5)
            curBalance += value;
        else
            curBalance -= value - 5;
        
        minBalance = min(minBalance, curBalance);
    }

    cout << -minBalance / 5;
}