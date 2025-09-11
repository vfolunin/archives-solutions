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

    int size, targetSum;
    cin >> size >> targetSum;
    targetSum -= 2;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        targetSum += a - 2;
        sum += b;
    }

    if (sum <= targetSum)
        cout << targetSum - sum;
    else
        cout << "Big Bang!";
}