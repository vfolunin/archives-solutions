#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isDivisible(string &num, int den) {
    int remainder = 0;
    for (char d : num)
        remainder = (remainder * 10 + d - '0') % den;
    return !remainder;
}

void rec(string &num, int targetSize, int &res) {
    if (num.size() == targetSize) {
        res++;
        return;
    }
    num.push_back('0');
    for (; num.back() <= '9'; num.back()++)
        if (num[0] != '0' && isDivisible(num, num.size()))
            rec(num, targetSize, res);
    num.pop_back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetSize;
    cin >> targetSize;

    int res = 0;
    if (targetSize <= 25) {
        string num;
        rec(num, targetSize, res);
    }

    cout << res;
}