class Solution {
public:
  //   int Fibonacci(int n) {
  //       if(n==0)
  //       {
  //           return 0;
  //       }
		// if(n==1)
  //       {
  //           return 1;
  //       }

  //       return Fibonacci(n-1)+Fibonacci(n-2);
  //   }
	int Fibonacci(int n) {
        if(n==0)
        {
            return 0;
        }
		if(n==1)
        {
            return 1;
        }
        int a = 0, b=1, c = 0;
        for (int i = 2; i <= n; ++i)
        {
        	c = a + b;
        	a = b;
        	b = c;
        }
        return c;
    }
};

// class Solution {
// public:
//     int jumpFloor(int n) {
//         if(n==0)
//         {
//             return 0;
//         }
// 		if(n==1)
//         {
//             return 1;
//         }
//         int a = 0, b=1, c = 0;
//         for (int i = 2; i <= n+1; ++i)
//         {
//         	c = a + b;
//         	a = b;
//         	b = c;
//         }
//         return c;
//     }
// };


// class Solution {
// public:
//     int jumpFloorII(int n) {
//     	if (n==0)
//     	{
//     		return 0;
//     	}
// 		// int a[n+1] = {0};
//   //       a[0] = 1;
//   //       a[1] = 1;
//   //       for(int i = 2; i <= n; i++)
//   //       {
//   //           for (int j = 0; j < i; ++j)
//   //           {
//   //           	a[i] = a[i] + a[j];
//   //           }
//   //       }
//   //       return a[n];
//     	return 1<<(n-1);
//     }
// };