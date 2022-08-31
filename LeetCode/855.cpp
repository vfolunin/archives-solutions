class ExamRoom {
    int size;
    set<int> taken;
    
public:
    ExamRoom(int n) : size(n) {}
    
    int seat() {
        if (taken.empty()) {
            taken.insert(0);
            return 0;
        }
        
        int pos = 0, dist = *taken.begin();
        
        for (auto l = taken.begin(), r = next(l); r != taken.end(); l++, r++) {
            int candidateDist = (*r - *l) / 2;
            int candidate = *l + candidateDist;
            
            if (dist < candidateDist) {
                dist = candidateDist;
                pos = candidate;
            }
        }
        
        if (dist < size - 1 - *prev(taken.end()))
            pos = size - 1;
        
        taken.insert(pos);
        return pos;
    }
    
    void leave(int pos) {
        taken.erase(pos);
    }
};