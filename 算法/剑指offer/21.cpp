class Solution {
	stack<int> data;
	stack<int> min_num;
public:
    void push(int value) {
        data.push(value);
        if (min_num.empty())
        {
        	min_num.push(value);
        }else if(value < min_num.top()){
        	min_num.push(value);
        }else{
        	min_num.push(min_num.top());
        }
    }
    void pop() {
        if (!data.empty())
        {
        	data.pop();
        	min_num.pop();
        }
    }
    int top() {
    	if (data.empty()) return -1;
        return data.top();
    }
    int min() {
    	if (data.empty()) return -1;
        return min_num.top();
    }
};