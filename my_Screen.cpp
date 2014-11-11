#include <iostream>
#include <string>
#include <vector>
#include "my_Screen.h"
#include "my_Windowmgr.h"
using namespace std;



int main()
{
	vector<Screen> screens{Screen(3, 10, 'a')};
	//Screen s1, s2(3, 10), s3(3, 10, 'a');
	Screen myScreen(5, 5, 'X');
	myScreen.move(4,0).set('#').display(cout);
	cout << '\n';
	myScreen.display(cout);
	cout << endl;
	return 0;
}