#include <iostream>
using namespace std;
int &get(int *, int);

int main()
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
	{
		cout << get(ia, i) << ' ';
		get(ia, i) = i;
		cout << get(ia, i) << ' ';
	}
	return 0;
}

int &get(int *arry, int index)
{
	return arry[index];
}