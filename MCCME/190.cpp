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
    long long index;
    cin >> size >> index;
    index--;

    vector<long long> factorial = { 1 };
    for (int i = 1; i < size; i++)
        factorial.push_back(factorial.back() * i);

    vector<int> digits(size);
    for (int i = 0; i < size; i++)
        digits[i] = i + 1;

    for (int i = 0; i < size; i++) {
        int d = 0;
        while (index >= factorial[size - 1 - i]) {
            index -= factorial[size - 1 - i];
            d++;
        }
        cout << digits[d] << " ";
        digits.erase(digits.begin() + d);
    }
}