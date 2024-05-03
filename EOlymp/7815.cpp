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

    int num, den;
    cin >> num >> den;
    den++;

    int count = 1, sum = 0;
    while (num) {
        count++;
        sum += num % den;
        num /= den;
    }

    cout << count << " " << sum;
}