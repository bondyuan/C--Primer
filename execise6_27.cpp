#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;

int sum(initializer_list<int> ii)
{
	int sum=0;
	for (auto i = ii.begin(); i != ii.end(); ++i)
	{
		sum += *i;
	}
	return sum;
}

int main()
{
	cout << "请输入你要计算的数字：";
	initializer_list<int> num = { 5, 6, 8, 7, 9, 3 };
	cout << "数字的和为： " << sum(num) << endl;
	return 0;
}