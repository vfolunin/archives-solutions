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

    vector<int> coeff(4);
    for (int &c : coeff)
        cin >> c;

    for (int i = 0; i <= 1000; i++) {
        int sum = 0;
        for (int c : coeff)
            sum = sum * i + c;

        if (!sum)
            cout << i << " ";
    }
}