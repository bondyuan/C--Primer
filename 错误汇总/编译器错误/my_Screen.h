#ifndef _MY_SCREEN_H_
#define _MY_SCREEN_H_
#include <iostream>
#include <string>
using namespace std;

class Screen
{
	typedef unsigned int uint;
public:
	friend class Window_mgr;
	Screen() = default;
	Screen(uint wd, uint hg) : width(wd), height(hg), content(wd * hg, ' ') {}
	Screen(uint wd, uint hg, char a) : width(wd), height(hg), content(wd * hg, a) {}
	Screen &set(char);
	Screen &set(uint, uint, char);
	Screen &display(ostream &os) {do_display(os); return *this;}
	const Screen &display(ostream &os) const {do_display(os); return *this;}
	Screen &move(uint, uint);
	char get(uint, uint);
private:
	uint width = 0, height = 0, cursor = 0;
	string content;
	void do_display(ostream &os) const;
};

inline Screen &Screen::set(char c)
{
	content[cursor] = c;
	return *this;
}
inline Screen &Screen::set(uint wd, uint hg, char ch)
{
	content[wd*width+hg] = ch;
	return *this;
}	
inline Screen &Screen::move(uint r, uint c)
{
	uint row = (r-1) * width;
	cursor = row + c;
	return *this;
}
inline char Screen::get(uint r, uint c)
{
	uint row = r * width;
	return content[row + c];
}
void Screen::do_display(ostream &os) const 
{
	for (uint i = 0; i < height; ++i)
	{
		for (uint j = 0; j < width; ++j)
			os << content[i * width + j];
		os << endl;
	}
	os << "The current cursor is " << cursor << endl;
}

#endif