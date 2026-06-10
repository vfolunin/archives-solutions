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

    int countA, countB, timeA, timeB;
    cin >> countA >> countB >> timeA >> timeB;

    cout << countA * timeA + countB * timeB;
}