二分查找 cheatsheet
=======

##二分查找的适用情况

* 在数组有序或者局部有序(Search in Rotated Sorted Array)时使用

##二分查找模版

    int BinarySearch(vector<int>& nums, int target) {
    	if (nums.empty()) return false;

        int left = 0, right = nums.size()-1;
        
        while(left <= right)
        {
        	int middle = (left + right)/2;

        	if (nums[middle] == target) {
        		return true;
        	} else if (nums[middle] > target) {
        		right = middle - 1;
        	} else {
				left = middle + 1;
        	}
        }
        return false;
    }


