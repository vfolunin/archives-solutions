struct Counter {
    unordered_map<int, int> count;
    
    void add(int i, int delta) {   
        count[i] += delta;
        if (!count[i])
            count.erase(i);
    }
};

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &a, int k) {
        Counter counter1, counter2;
        int res = 0;
        
        for (int l1 = 0, l2 = 0, r = 0; r < a.size(); r++) {
            counter1.add(a[r], 1);
            counter2.add(a[r], 1);

            while (counter1.count.size() > k) {
                counter1.add(a[l1], -1);
                l1++;
            }

            while (counter2.count.size() >= k) {
                counter2.add(a[l2], -1);
                l2++;
            }
            
            if (counter1.count.size() == k)
                res += l2 - l1;
        }
        
        return res;
    }
};