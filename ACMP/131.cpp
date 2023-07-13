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

    int personCount;
    cin >> personCount;

    int res = 0, resAge = 0;
    for (int i = 0; i < personCount; i++) {
        int age, isMale;
        cin >> age >> isMale;

        if (isMale && resAge < age) {
            res = i + 1;
            resAge = age;
        }
    }

    cout << (res ? res : -1);
}