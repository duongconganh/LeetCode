class MinStack {
public:
   int arr[10000] = {0};
   int m[10000] = {0};
   int size = 0;
    MinStack() {
        
    }
    
    void push(int val) {
        if(size == 0){
            m[size] = val;
        }else{
            m[size] = min(val,m[size - 1]);
        }
        arr[size ++] = val;

    }
    
    void pop() {
        if(size == 0){
            return;
        }
       --size;
    }
    
    int top() {
        return arr[size - 1];
    }
    
    int getMin() {
        return m[size -1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */