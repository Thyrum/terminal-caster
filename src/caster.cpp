#include "caster.h"

Caster::Caster(unsigned int width, unsigned int height) :
	m_castWindow(nullptr), m_topWindow(nullptr),
	m_board(width,std::vector<Field>(height))
{}

WINDOW *& Caster::CastWindow()
{
	return m_castWindow;
}

WINDOW *& Caster::TopWindow()
{
	return m_topWindow;
}

void Caster::draw()
{
	if (m_castWindow)
	{
		box(m_castWindow, 0, 0);
		waddstr(m_castWindow, "castWindow");

		wrefresh(m_castWindow);
	}

	if (m_topWindow)
	{
		box(m_topWindow, 0, 0);
		waddstr(m_topWindow, "topWindow");

		wrefresh(m_topWindow);
	}
}

void Caster::keyboard(char)
{

}
