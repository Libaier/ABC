// 225. Implement Stack using Queues My Submissions QuestionEditorial Solution
// Total Accepted: 36295 Total Submissions: 118818 Difficulty: Easy
// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Notes:
// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
// Update (2015-06-11):
// The class name of the Java function had been updated to MyStack instead of Stack.

class Stack {
public:
	queue<int> input;
    // Push element x onto stack.
    void push(int x) {
        input.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> temp;
        while(input.size()!=1)
        {
        	temp.push(temp.top());
        	input.pop();
        }
        input = temp;
    }

    // Get the top element.
    int top() {
    	queue<int> temp = input;
        while(temp.size()!=1)
        {
        	temp.pop();
        }
        return temp.top();
    }

    // Return whether the stack is empty.
    bool empty() {
        return input.empty();
    }
};