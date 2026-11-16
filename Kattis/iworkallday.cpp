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

    int divisorCount;
    cin >> divisorCount;

    vector<int> divisors(divisorCount);
    for (int &divisor : divisors)
        cin >> divisor;

    int value;
    cin >> value;

    int bestI = 0;
    for (int i = 1; i < divisors.size(); i++)
        if (value % divisors[bestI] > value % divisors[i])
            bestI = i;

    cout << divisors[bestI];
}