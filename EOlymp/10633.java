interface Stackable<T> {
    void push(T value);
    T pop();
    T peek();
    boolean Empty();
    int size();
}

class MyStack<T> implements Stackable<T> {
    public ArrayList<T> s;
    
    public MyStack() {
        s = new ArrayList<T>();
    }
    
    public void push(T value) {
    	s.add(value);
    }
    
    public T pop() {
    	return s.remove(s.size() - 1);
    }
    
    public T peek() {
    	return s.get(s.size() - 1);
    }
    
    public boolean Empty() {
    	return s.isEmpty();
    }
    
    public int size() {
    	return s.size();
    }
}