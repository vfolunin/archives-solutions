#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int gearCount, num;
    cin >> gearCount >> num;

    for (int i = 1; i < gearCount; i++) {
        int den;
        cin >> den;
        int g = gcd(num, den);
        cout << num / g << "/" << den / g << "\n";
    }
}