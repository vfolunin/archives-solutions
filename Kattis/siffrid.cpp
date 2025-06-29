#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getMinValue(int size, int digitSum) {
    string res;
    for (int i = 0; i < size; i++) {
        for (int digit = !i; 1; digit++) {
            if (digitSum - digit <= (size - i - 1) * 9) {
                digitSum -= digit;
                res += '0' + digit;
                break;
            }
        }
    }
    return res;
}

string getMaxValue(int size, int digitSum) {
    string res;
    for (int i = 0; i < size; i++) {
        int digit = min(digitSum, 9);
        digitSum -= digit;
        res += '0' + digit;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int digitSum = 0;
    for (char c : s)
        digitSum += c - '0';

    cout << getMinValue(s.size(), digitSum) << " " << getMaxValue(s.size(), digitSum);
}