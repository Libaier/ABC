// 223. Rectangle Area My Submissions QuestionEditorial Solution
// Total Accepted: 34422 Total Submissions: 115977 Difficulty: Easy
// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

// Rectangle Area
// Assume that the total area is never beyond the maximum possible value of int.
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total = (C-A) * (D-B) + (G-E) * (H-F);

	    if (C<=E || A>=G || B>=H || D<=F )
	        return total;
	    else
	    {
	        vector <int> h;
	        h.push_back(A);
	        h.push_back(C);
	        h.push_back(E);
	        h.push_back(G);

	        vector <int> v;
	        v.push_back(B);
	        v.push_back(D);
	        v.push_back(F);
	        v.push_back(H);

	        sort(h.begin(), h.end());
	        sort(v.begin(), v.end());

	        total = total - (h[2] - h [1]) * (v[2] - v[1]);
	        return total;
	    }
    }
};