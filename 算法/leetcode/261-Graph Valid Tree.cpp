// 261. Graph Valid Tree My Submissions QuestionEditorial Solution
// Total Accepted: 13628 Total Submissions: 40886 Difficulty: Medium
// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

// For example:

// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

// Show Hint 
// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(edges.size()!=n-1)
        {
        	return false;
        }
        vector<int> ufs(n,0);
        for (int i = 0; i < n; ++i)
        {
        	ufs[i] = i;
        }
        for (int i = 0; i < edges.size(); ++i)
        {
        	int a = edges[i].first;
        	int b = edges[i].second;

        	while(ufs[a]!= a) {a = ufs[a];}
        	while(ufs[b]!= b) {b = ufs[b];}

        	if (a == b)
        	{
        		return false;
        	}
        	ufs[a] = b;
        }
        return true;
    }
};