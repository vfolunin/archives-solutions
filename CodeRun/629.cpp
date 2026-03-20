#include <algorithm>
using namespace std;

int solution(int a, int b) {
    if (a > b)
        swap(a, b);

    int res = 0;
    while (1) {
        long long area = (res + 1LL) * (res + 1);
        long long needA = area / 2, needB = area - needA;
        if (a >= needA && b >= needB)
            res++;
        else
            return res;
    }
}
