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

    int resultCount;
    cin >> resultCount;

    double num = 0, den = 0;
    for (int i = 0; i < resultCount; i++) {
        int result;
        cin >> result;

        if (result != -1) {
            num += result;
            den++;
        }
    }

    cout << fixed << num / den;
}