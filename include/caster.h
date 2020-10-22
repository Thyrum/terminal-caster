#pragma once

#include <ncurses.h>
#include <vector>

class Caster
{
public:
	enum Field
	{
		EMPTY, WALL, PLAYER
	};

	Caster(unsigned int width, unsigned int height);
	WINDOW *& CastWindow();
	WINDOW *& TopWindow();

	void draw();
	void keyboard(char key);

private:

	WINDOW * m_castWindow;
	WINDOW * m_topWindow;

	std::vector<std::vector<Field> > m_board;
};
