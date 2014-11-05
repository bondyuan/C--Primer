#include <iostream>
#include <vector>
using namespace std;

void show(vector<int>::iterator it1, vector<int>::iterator it2)
{
	if (it1 == it2)
		return;
	else
	{
		cout << *it1 << ' ';
		show(++it1,it2);
	}

}

string (&shows(vector<string> vec1)) [10]
{
	string s1[10];
	int i = 0;
	for (auto c : vec1)
	{
		s1[i++] = c;
	}
	return s1;
}

int main()
{
	vector<int> vint = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	show(vint.begin(), vint.end());
	vector<string> vstring = { "Hello", "world", "how", "are", "you", "thans", "you", "I'm", "do", "you"};
	string (&s)[10] = shows(vstring);
	for (auto c : s)
	{
		cout << c << ' ';
	}
	cout<<endl;
	return 0;
}