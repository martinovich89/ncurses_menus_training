#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(void)
{
	initscr();
	noecho();
	curs_set(0);
	cbreak();
	timeout(10);

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	WINDOW *win = newwin(yMax - 5, xMax, 5, 0);
	WINDOW *win2 = newwin(4, xMax, 0, 0);
	box(win, 0, 0);
	box(win2, 0, 0);

	mvwprintw(win, 0, 2, "File");
	mvwprintw(win, 0, 7, "Edit");
	mvwprintw(win, 0, 12, "Options");

	keypad(win, 1);
	set_escdelay(10);
//	wrefresh(win);

	int ch = -1;
	int ch_display = 0;
	while ((ch = getch()) != 27)
	{
		ch_display = (ch != -1) ? ch : ch_display;
		if (ch_display)
			mvwprintw(win, 20, 2, "%d\n", ch_display);
		box(win, 0, 0);
		box(win2, 0, 0);
		switch(ch_display)
		{
			case 'f':
				wattron(win, A_STANDOUT);
				mvwprintw(win, 0, 2, "File");
				wattroff(win, A_STANDOUT);
				mvwprintw(win, 0, 7, "Edit");
				mvwprintw(win, 0, 12, "Options");
				break;
			case 'e':
				wattron(win, A_STANDOUT);
				mvwprintw(win, 0, 7, "Edit");
				wattroff(win, A_STANDOUT);
				mvwprintw(win, 0, 2, "File");
				mvwprintw(win, 0, 12, "Options");
				break;
			case 'o':
				wattron(win, A_STANDOUT);
				mvwprintw(win, 0, 12, "Options");
				wattroff(win, A_STANDOUT);
				mvwprintw(win, 0, 2, "File");
				mvwprintw(win, 0, 7, "Edit");
				break;
			default:
				mvwprintw(win, 0, 2, "File");
				mvwprintw(win, 0, 7, "Edit");
				mvwprintw(win, 0, 12, "Options");
				break;
		}

		mvwprintw(win2, 1, 1, "Player");
		mvwprintw(win2, 1, xMax / 2, "|%12d|%12d|%12d|", 1, 2, 10);

		wrefresh(win);
		wrefresh(win2);
	}
//	clear();
//	wclear(win);
	ch = -1;
	ch_display = 0;
	while ((ch = getch()) != 27)
	{
		ch_display = (ch != -1) ? ch : ch_display;
		if (ch_display)
			mvwprintw(win, 20, 2, "%d\n", ch_display);
		box(win, 0, 0);
		switch(ch_display)
		{
			case 'f':
				wattron(win, A_STANDOUT);
				mvwprintw(win, 0, 2, "Galaxy");
				wattroff(win, A_STANDOUT);
				mvwprintw(win, 0, 25, "System");
				mvwprintw(win, 0, 40, "Planet");
				break;
			case 'e':
				wattron(win, A_STANDOUT);
				mvwprintw(win, 0, 9, "System");
				wattroff(win, A_STANDOUT);
				mvwprintw(win, 0, 2, "Galaxy");
				mvwprintw(win, 0, 16, "Planet");
				break;
			case 'o':
				wattron(win, A_STANDOUT);
				mvwprintw(win, 0, 16, "Planet");
				wattroff(win, A_STANDOUT);
				mvwprintw(win, 0, 2, "Galaxy");
				mvwprintw(win, 0, 9, "System");
				break;
			default:
				mvwprintw(win, 0, 2, "Galaxy");
				mvwprintw(win, 0, 9, "System");
				mvwprintw(win, 0, 16, "Planet");
				break;
		}
		wrefresh(win);
	}

/*	while ((ch = wgetch(win)) != 'p')
	{
		mvwprintw()
	}*?
	keypad(win, 0);*/


	endwin();

	return (0);
}
