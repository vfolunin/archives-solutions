interface Arrayable<T> {
    void push_back(T x);
    T pop_back();
    T min();
    T max();
    T sum();
    boolean Empty();
    int size();
}

class MyArray<T extends Number & Comparable<T>> implements Arrayable<T> {
    ArrayList<T> m;
    
    public MyArray() {
    	m = new ArrayList<T>();
    }
    
    public void push_back(T value) {
    	m.add(value);
    }
    
    public T pop_back() {
    	return m.remove(m.size() - 1);
    }
    
    public T min() {
    	T res = m.get(0);
        for (T value : m)
    		if (res.compareTo(value) > 0)
    			res = value;
    	return res;
    }
    
    public T max() {
    	T res = m.get(0);
        for (T value : m)
    		if (res.compareTo(value) < 0)
    			res = value;
    	return res;
    }
    
    public T sum() {
        Double res = new Double(0);
        for (T value : m)
            res += value.doubleValue();
        return (T)res;
    }
    
    public boolean Empty() {
    	return m.isEmpty();
    }
    
    public int size() {
    	return m.size();
    }
}