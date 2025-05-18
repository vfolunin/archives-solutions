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

    cout << "Please enter a number divisible by 5 but not divisible by 3:";

    int n;
    cin >> n;

    if (n % 5 == 0 && n % 3)
        cout << "Thank you.";
    else
        cout << n << " isn't a number divisible by 5 but not divisible by 3.";
}