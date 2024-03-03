class MyStack {
public:
    queue<int>q;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int s = q.size();
        int tmp;
        for(int i=1;i<=s;i++){
            if(i==s){
                tmp = q.front();
                q.pop();
            }else{
                tmp = q.front();
                q.pop();
                q.push(tmp);
            }
        }
        return tmp;
    }
    
    int top() {
        int s = q.size();
        int tmp;
        for(int i=1;i<=s;i++){
            if(i==s){
                tmp = q.front();
                q.pop();
                q.push(tmp);
            }else{
                tmp = q.front();
                q.pop();
                q.push(tmp);
            }
        }
        return tmp;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */