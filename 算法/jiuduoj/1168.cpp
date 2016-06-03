// #include<iostream>
// #include<string>
// using namespace std;
// int main()
// {
// 	string s1;
// 	char s[1000];
// 	cin>>s1;//输入待删除短字符串

// 	int j;
// 	string s2;//用于保存待删除字符串
// 	string::iterator i;//迭代器，其实就是数组下标
	
// 	cin.ignore();//一直PE，搞了半天才知道原来是输入流有残留，如果你也PE了，记得输入是写scanf("%d\n", &n);忽略掉一个回车，或者cin>>n;cin.ignore();忽略掉一个字符。这种情况往往发生在下一个输入是准备输入一整行时。

// 	while(cin.getline(s,1000))
// 	{
// 		s2=s;
// 		//循环删除s2中的s1
// 		while(s2.find(s1)!=string::npos)//如果s2.find(s1)==string::npos则说明s2中不包含s1
// 		{
// 			i=s2.begin()+s2.find(s1);//找到s1位置
// 			s2.erase(i,i+s1.length());//删除s1
// 		}

// 		//循环删除s2中的空格，与删除s1同理
// 		while(s2.find(' ')!=string::npos)
// 		{
// 			i=s2.begin()+s2.find(' ');
// 			s2.erase(i);
// 		}
// 		//输出删除后的字符串
// 		cout<<s2<<endl;
// 	}
// 	return 0;
// }

#include<iostream>
#include<string>
using namespace std;

void toLowerCase(string& str)
{
	for (int i = 0; i < str.length(); ++i)
		str[i] = tolower(str[i]);
}

int main()
{
	string s1;
	cin >> s1;
	int j;
	string s2;
	int i = 0;
	cin.ignore();
	string s1l = s1;
	toLowerCase(s1l);
	int length = s1l.length();

	while (getline(cin, s2))
	{
		string s2l = s2;
		toLowerCase(s2l);
		i = -length;
		int n = 0;
		while (s2l.find(s1l, i + length) != string::npos)
		{
			i = s2l.find(s1l, i + length);
			s2.erase(i - n*length, length);
			n++;
		}
		while (s2.find(' ') != string::npos)
		{
			i = s2.find(' ');
			s2.erase(i, 1);
		}
		cout << s2 << endl;
	}
	return 0;
}