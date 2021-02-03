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

    vector<int> numbers;
    map<int, int> numberCount;
    int number;

    while (cin >> number) {
        if (!numberCount.count(number))
            numbers.push_back(number);
        numberCount[number]++;
    }

    for (int number : numbers)
        cout << number << " " << numberCount[number] << "\n";
}