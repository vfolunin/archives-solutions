class Solution {
public:
    int rand10() {
        while (1) {
            int x = (rand7() - 1) * 7 + rand7() - 1;
            if (x < 40)
                return x / 4 + 1;
        }
    }
};