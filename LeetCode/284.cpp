class PeekingIterator : public Iterator {
    int nextValue;
    
public:
	PeekingIterator(const vector<int> &a) : Iterator(a) {
        nextValue = Iterator::hasNext() ? Iterator::next() : -1;
	}
	
	int peek() {
        return nextValue;
	}
	
	int next() {
        int res = nextValue;
	    nextValue = Iterator::hasNext() ? Iterator::next() : -1;
        return res;
	}
	
	bool hasNext() const {
	    return nextValue != -1;
	}
};