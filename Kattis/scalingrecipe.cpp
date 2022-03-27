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

    int itemCount, den, num;
    cin >> itemCount >> den >> num;

    for (int i = 0; i < itemCount; i++) {
        int amount;
        cin >> amount;
        cout << amount * num / den << "\n";
    }
}