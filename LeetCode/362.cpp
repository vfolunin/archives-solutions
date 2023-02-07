class HitCounter {
    queue<int> hits;

public:    
    void hit(int time) {
        hits.push(time);
    }
    
    int getHits(int time) {
        while (!hits.empty() && hits.front() + 300 <= time)
            hits.pop();
        return hits.size();
    }
};