//Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
//
//Note :
//	 Elements in a quadruplet(a, b, c, d) must be in non - descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
//	 The solution set must not contain duplicate quadruplets.
//	 For example, given array S = { 1 0 - 1 0 - 2 2 }, and target = 0.
//
//	 A solution set is :
//(-1, 0, 0, 1)
//(-2, -1, 1, 2)
//(-2, 0, 0, 2)

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> result;
//         if(nums.size()<4)
//         {
//             return result;
//         }
        
//         sort(nums.begin(),nums.end());
        
//         unordered_multimap<int, pair<int, int>> cache;
//         int size_nums = nums.size();
//         for(int i = 0; i+1 < size_nums; ++i)
//         {
//             for (int j = i+1; j < size_nums; ++j)
//             {
//             	/* code */
//             	cache.insert(make_pair((nums[i]+nums[j]),make_pair(i,j)));
//             }
//         }
        
//         for (auto i = cache.begin(); i != cache.end(); ++i)
//         {
//         	int temp = target - i->first;
//         	auto range = cache.equal_range(temp);
//         	for(auto j = range.first; j!=range.second; ++j)
//         	{
//         		auto a = i->second.first;
//         		auto b = i->second.second;
//         		auto c = j->second.first;
//         		auto d = j->second.second;
//         		if (a != c && a != d && b != c && b != d) 
//         		{
// 	                vector<int> vec = { nums[a], nums[b], nums[c], nums[d] };
// 	                sort(vec.begin(), vec.end());
// 	                result.push_back(vec);
//             	}
//         	} 

//         }
//         sort(result.begin(), result.end());
// 		result.erase(unique(result.begin(), result.end()), result.end());
//         return result;
//     }
// };

// class Solution {
// public:
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
// vector<vector<int>> result;
// if (nums.size() < 4) return result;
// sort(nums.begin(), nums.end());
// unordered_multimap<int, pair<int, int>> cache;
// for (int i = 0; i + 1 < nums.size(); ++i)
// for (int j = i + 1; j < nums.size(); ++j)
// cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
// for (auto i = cache.begin(); i != cache.end(); ++i) {
// int x = target - i->first;
// auto range = cache.equal_range(x);
// for (auto j = range.first; j != range.second; ++j) {
// auto a = i->second.first;
// auto b = i->second.second;
// auto c = j->second.first;
// auto d = j->second.second;
// if (a != c && a != d && b != c && b != d) {
// vector<int> vec = { nums[a], nums[b], nums[c], nums[d] };
// sort(vec.begin(), vec.end());
// result.push_back(vec);
// }
// }
// }
// sort(result.begin(), result.end());
// result.erase(unique(result.begin(), result.end()), result.end());
// return result;
// }
// };

class Solution {
public:
vector<vector<int> > fourSum(vector<int> &nums, int target) {
vector<vector<int>> result;
if (nums.size() < 4) return result;
sort(nums.begin(), nums.end());
unordered_map<int, vector<pair<int, int> > > cache;
for (size_t a = 0; a < nums.size(); ++a) {
for (size_t b = a + 1; b < nums.size(); ++b) {
cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
}
}
for (int c = 0; c < nums.size(); ++c) {
for (size_t d = c + 1; d < nums.size(); ++d) {
const int key = target - nums[c] - nums[d];
if (cache.find(key) == cache.end()) continue;
const auto& vec = cache[key];
for (size_t k = 0; k < vec.size(); ++k) {
if (c <= vec[k].second)
continue; 
result.push_back( { nums[vec[k].first],
nums[vec[k].second], nums[c], nums[d] });
}
}
}
sort(result.begin(), result.end());
result.erase(unique(result.begin(), result.end()), result.end());
return result;
}
};