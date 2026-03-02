struct Counter {
    unordered_map<int, int> count;
    multiset<int> counts;

    void add(int value, int delta) {
        if (count[value])
            counts.erase(counts.find(count[value]));
        count[value] += delta;
        if (count[value])
            counts.insert(count[value]);
        else
            count.erase(value);
    }
};

class Solution {
public:
    long long countSubarrays(vector<int> &a, int count, int threshold) {
        Counter counter1, counter2;
        long long res = 0;

        for (int l1 = 0, l2 = 0, r = 0; r < a.size(); r++) {
            counter1.add(a[r], 1);
            counter2.add(a[r], 1);

            while (counter1.count.size() > count)
                counter1.add(a[l1++], -1);
            while (counter2.count.size() > count || counter2.count.size() == count && *counter2.counts.begin() >= threshold)
                counter2.add(a[l2++], -1);
            
            res += l2 - l1;
        }

        return res;
    }
};