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

    long long movieLength, introLength, limit, skip;
    cin >> movieLength >> introLength >> limit >> skip;

    long long skipLength = (introLength + limit - 1) / limit * limit;
    if (skipLength - introLength <= skip)
        cout << movieLength - (skipLength - introLength);
    else
        cout << movieLength;
}