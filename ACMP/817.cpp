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

    long long rows, cols, width, length;
    cin >> rows >> cols >> width >> length;

    cout << (rows + cols) * width * length - rows * cols * width * width;
}