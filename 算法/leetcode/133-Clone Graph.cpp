// 133. Clone Graph My Submissions QuestionEditorial Solution
// Total Accepted: 69961 Total Submissions: 281112 Difficulty: Medium
// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


// OJ's undirected graph serialization:
// Nodes are labeled uniquely.

// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.

// The graph has a total of three nodes, and therefore contains three parts as separated by #.

// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
// Visually, the graph looks like the following:

//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//  The hash map has two functionalities: 1. judge if the vertex has been visited 2. build the connection between the vertex in the original graph and the new graph

// if(mp.find(node) != mp.end()) you should not return NULL, but return the vertex in the new graph, that is hash_map(vertex)
class Solution {
public:
	// unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> result;
 //    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
 //    	if (node==NULL)
 //    	{
 //    		return node;
 //    	}
 //    	if (result.find(node)==result.end())
 //    	{
 //    		result[node] = new UndirectedGraphNode(node->label);
 //    		for (auto n:node->neighbors)
 //    		{
 //    			result[node]->neighbors.push_back(cloneGraph(n));
 //    		}
 //    	}
 //    	return result[node];
 //    }

    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (node==NULL)
    	{
    		return node;
    	}
    	unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> result;
    	queue<UndirectedGraphNode *> q;
    	q.push(node);
    	result[q.front()] = new UndirectedGraphNode(q.front()->label);
    	while(!q.empty())
    	{
// 			if (result.find(q.front())==result.end())
// 			{
//     			result[q.front()] = new UndirectedGraphNode(q.front()->label);
//     		}
    		for (auto n:q.front()->neighbors)
    		{
    			if (result.find(n)==result.end())
    			{
    				result[n] = new UndirectedGraphNode(n->label);
    				q.push(n);
    			}
    			result[q.front()]->neighbors.push_back(result[n]);
    		}
	    	q.pop();
    	}

    	return result[node];
    }
};