class MyStack {
public:
    // Initialise two queues
    // Note : It's not possible to achieve all four operations in O(1) as in stack
    // We will have following 
    // Time Complexities 
    // Push : O(n)
    // Pop : O(1)
    // Top : O(1)
    // Empty : O(1)
    // Space Complexity : O(n)


    // We maintain the stack in queue 1 and use queue 2 to faciliate the process
    // For the push operation, we want to add element at the front of the queue, for this we add the element to queue2 and trannsfer all elements from queue1 to the end of queue2 and swap the queueus. 

    queue<int>q1 ;
    queue<int>q2 ;
    MyStack() {
    }
    
    void push(int x) {
        q2.push(x);
        // Move all elements from q1 to q2
        while(!q1.empty())
        {
            int x = q1.front();
            q2.push(x);
            q1.pop();
        }
        queue<int>temp = q1 ;
        q1 = q2 ;
        q2 = temp ;
    }
    
    int pop() {
        // Top of stack is always maintaned at the front of q1
        int x = q1.front() ;
        q1.pop();
        return x ;
    }
    
    int top() {
        // Top of stack is always maintaned at the front of q1
        return q1.front();
    }
    
    bool empty() {
        // Stack is stored in q1
        return q1.empty();
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
