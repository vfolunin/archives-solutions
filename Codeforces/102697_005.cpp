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

    int value;
    cin >> value;

    if (value % 15 == 0)
        cout << "FizzBuzz";
    else if (value % 3 == 0)
        cout << "Fizz";
    else if (value % 5 == 0)
        cout << "Buzz";
}