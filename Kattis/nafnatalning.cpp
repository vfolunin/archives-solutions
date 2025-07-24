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

    int size, den;
    cin >> size >> den;

    vector<int> a(size);
    long long sum = 0;
    for (int &value : a) {
        cin >> value;
        sum += value;
    }

    long long num = 0;
    for (int value : a)
        num += (sum - value) * value;
    num /= 2;
    
    cout << (num + den - 1) / den;
}