class Solution {
    bool can(int eggs, int floors, int drops) {
        long long product = 1, sum = 0;
        for (int i = 1; i <= eggs && sum < floors; i++) {
            product *= drops - i + 1;
            product /= i;
            sum += product;
        }
        return sum >= floors;
    }
    
public:
    int superEggDrop(int eggs, int floors) {
        int l = 0, r = floors;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(eggs, floors, m))
                r = m;
            else
                l = m;
        }
        return r;
    }
};
