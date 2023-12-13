#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, sum;
    cin >> size >> sum;

    for (int i = 0; i < 1e6; i++)
        if (to_string(i).size() == size && digitSum(i) == sum)
            cout << i << "\n";
}