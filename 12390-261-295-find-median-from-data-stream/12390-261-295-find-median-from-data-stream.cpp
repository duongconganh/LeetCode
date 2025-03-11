class MedianFinder {
    priority_queue<int> left;
    priority_queue<int , vector<int>, greater<int>> right;
    int l = 0;
    int r = 0;
public:
    MedianFinder() {
        left = {};
        right = {};
    }
    
    void addNum(int num) {
        if(!l){
            left.push(num);
            l ++;
            return;
        }
        if(num <= left.top()){
            left.push(num);
            l ++;
            if(l - r > 1){
                l--;
                r++;
                right.push(left.top());
                left.pop();
            }
        }else{
            right.push(num);
            r++;
            if( r > l){
                r --;
                l ++;
                left.push(right.top());
                right.pop();               
            }
        }

    }
    
    double findMedian() {
        if((l + r) % 2 == 0){
            return 1.0 *(left.top() + right.top()) / 2;
        }else{
            return left.top();
        }
    }
};

