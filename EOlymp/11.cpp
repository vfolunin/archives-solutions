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

    int num, den, size;
    cin >> num >> den >> size;

    cout << num / den << ".";
    num %= den;

    for (int i = 0; i < size; i++) {
        cout << num * 10 / den;
        num = num * 10 % den;
    }
}