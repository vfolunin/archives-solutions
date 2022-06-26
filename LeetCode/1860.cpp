class Solution {
public:
    vector<int> memLeak(int m1, int m2) {        
        for (int i = 1; 1; i++) {
            int &m = m1 >= m2 ? m1 : m2;
            if (m < i)
                return { i, m1, m2 };
            m -= i;
        }
    }
};