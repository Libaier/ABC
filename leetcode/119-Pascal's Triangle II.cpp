//Given an index k, return the kth row of the Pascal's triangle.
//
//For example, given k = 3,
//Return[1, 3, 3, 1].
//

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		rowIndex = rowIndex + 1;
		vector<int> result(rowIndex);
		result[0] = 1;
		for (int i = 1; i < rowIndex; i++)
		{
			for (int j = rowIndex - 2; j >0; j--)
			{
				result[j] = result[j - 1] + result[j];
			}
			result[rowIndex - 1] = 1;
		}
		return result;
	}
};