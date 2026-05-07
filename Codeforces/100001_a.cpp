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
 
    long long height, width, size;
    cin >> height >> width >> size;

    long long hCount = (height + size - 1) / size;
    long long wCount = (width + size - 1) / size;

    cout << hCount * wCount;
}