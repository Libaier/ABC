class Solution {
public:
int evalRPN(vector<string> &tokens) {
	int result = 0;
	int x = 0,y = 0;
	stack<int> data;
	for(int i = 0;i<tokens.size();i++)
	{
		switch (tokens.at(i).at(0))
		{
		case '+':
			x = data.top();
			data.pop();
			y = data.top();
			data.pop();
			result = y + x;
			data.push(result);
			break;
		case '-':
			if(1==tokens.at(i).size())
			{
				x = data.top();
				data.pop();
				y = data.top();
				data.pop();
				result = y - x;
				data.push(result);
			}else
			{
				data.push(atoi(tokens.at(i).c_str()));
			}
			break;
		case '*':
			x = data.top();
			data.pop();
			y = data.top();
			data.pop();
			result = y * x;
			data.push(result);
			break;
		case '/':
			x = data.top();
			data.pop();
			y = data.top();
			data.pop();
			result = y / x;
			data.push(result);
			break;
		default:
		    if(0==i)
		    {
		        result = atoi(tokens.at(i).c_str());
		    }
			data.push(atoi(tokens.at(i).c_str()));
			break;
		}
	}
	return result;
}
};