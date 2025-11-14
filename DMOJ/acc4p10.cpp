#include <cmath>
using namespace std;

bool f(int sum) {
    for (int a = 0; a * a <= sum; a++) {
        int b = sqrt(sum - a * a);
        if (a * a + b * b == sum)
            return 1;
    }
    return 0;
}