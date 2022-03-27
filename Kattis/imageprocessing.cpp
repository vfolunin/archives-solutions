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

    int imgH, imgW, kernelH, kernelW;
    cin >> imgH >> imgW >> kernelH >> kernelW;

    vector<vector<int>> img(imgH, vector<int>(imgW));
    for (int y = 0; y < imgH; y++)
        for (int x = 0; x < imgW; x++)
            cin >> img[y][x];

    vector<vector<int>> kernel(kernelH, vector<int>(kernelW));
    for (int y = kernelH - 1; y >= 0; y--)
        for (int x = kernelW - 1; x >= 0; x--)
            cin >> kernel[y][x];

    for (int y = 0; y + kernelH <= imgH; y++) {
        for (int x = 0; x + kernelW <= imgW; x++) {
            int sum = 0;
            for (int dy = 0; dy < kernelH; dy++)
                for (int dx = 0; dx < kernelW; dx++)
                    sum += img[y + dy][x + dx] * kernel[dy][dx];
            cout << sum << " ";
        }
        cout << "\n";
    }
}