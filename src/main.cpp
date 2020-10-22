#include <ncurses.h>
#include <csignal>

#include <iostream>

#include "caster.h"

Caster caster(5,5);

void resizeHandler(int)
{
	int width, height;
	getmaxyx(stdscr, height, width);

	wresize(caster.CastWindow(),height, width/2);
	wmove(caster.CastWindow(), 0, 0);

	wresize(caster.TopWindow(),height, width/2);
	wmove(caster.TopWindow(), 0, width/2);

	caster.draw();
}

int main()
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	refresh();

	signal(SIGWINCH, resizeHandler);


	int width, height;
	getmaxyx(stdscr, height, width);

	caster.CastWindow() = newwin(height, width/2, 0, width/2);
	caster.TopWindow()  = newwin(height, width/2, 0, 0);

	caster.draw();

	while (getch() != 'q');

	endwin();
}
