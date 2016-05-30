class Solution {
public:
     int  NumberOf1(int n) {
         int result = 0;
         for (int i = 1; i <= 32; ++i)
         {
         	if (n&(1<<i))
         	{
         		result++;
         	}
         }
         return result;
     }

    // int  NumberOf1(int n) {
    //      int result = 0;
    //      while(n)
    //      {
    //           n = n&(n-1);
    //           result++;
    //      }
    //      return result;
    //  }
};