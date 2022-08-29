class Solution {
    int h, w;
    unordered_set<int> flipped;
    inline static minstd_rand generator;
    
public:
    Solution(int h, int w) : h(h), w(w) {}

    vector<int> flip() {
        int i;
        do {
            i = uniform_int_distribution(0, h * w - 1)(generator);
        } while (flipped.count(i));
        
        flipped.insert(i);
        return { i / w, i % w };
    }
    
    void reset() {
        flipped.clear();
    }
};