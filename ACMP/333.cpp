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

    string a, b, c;
    cin >> a >> b >> c;

    vector<int> commonDigits;
    for (int digit = 0; digit < 10; digit++)
        if (a.find(digit + '0') != -1 && b.find(digit + '0') != -1 && c.find(digit + '0') != -1)
            commonDigits.push_back(digit);

    cout << commonDigits.size() << "\n";
    for (int digit : commonDigits)
        cout << digit << " ";
}