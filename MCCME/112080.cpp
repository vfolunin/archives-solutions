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

    int sum = 0;

    for (int i = 1e4; i < 1e5; i++)
        if (to_string(i).find('0') != -1)
            sum += i;

    cout << sum;
}