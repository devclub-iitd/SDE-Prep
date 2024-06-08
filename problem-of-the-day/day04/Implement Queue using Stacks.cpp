class MyQueue {
public:
    // Initialise two stacks
    // Time Complexities
    // Push : O(1)
    // Pop : O(n) (amortised time complexity is O(1) as we move all elements from s1 to s2 only once in n elements)
    // Peek : O(1)
    // Empty : O(1)

    // Space Complexity : O(n)

    stack<int>s1;
    stack<int>s2;
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);   
    }
    
    int pop() {
        // If s2 is not empty, then top of queue is at the top of s2
        if(!s2.empty())
        {
            int x = s2.top() ;
            s2.pop();
            return x;
        }

        // Move all elements from s1 to s2
        while(!s1.empty())
        {
            int x = s1.top();
            s2.push(x);
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        return ans ;
    }
    
    int peek() {
        // If s2 is not empty, then top of queue is at the top of s2
        if(!s2.empty())
        {
            return s2.top();
        }

        // Move all elements from s1 to s2

        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }
    
    bool empty() {
        // Queue is empty if both stacks are empty
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */