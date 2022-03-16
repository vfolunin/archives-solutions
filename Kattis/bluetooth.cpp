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

    int toothCount;
    cin >> toothCount;

    int leftUpperM = 0, leftLowerM = 0, leftB = 0;
    int rightUpperM = 0, rightLowerM = 0, rightB = 0;
    for (int i = 0; i < toothCount; i++) {
        string tooth, type;
        cin >> tooth >> type;

        if (isdigit(tooth[0])) {
            rightLowerM += tooth[1] == '-' && type == "m";
            rightUpperM += tooth[1] == '+' && type == "m";
            rightB += type == "b";
        } else {
            leftLowerM += tooth[0] == '-' && type == "m";
            leftUpperM += tooth[0] == '+' && type == "m";
            leftB += type == "b";
        }
    }

    if (leftLowerM < 8 && leftUpperM < 8 && !leftB)
        cout << 0;
    else if (rightLowerM < 8 && rightUpperM < 8 && !rightB)
        cout << 1;
    else
        cout << 2;
}