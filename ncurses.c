#include <ncurses.h>

char nameTemp[160];

void drawLogo() {
	mvprintw(8,8,"        /\\            \\            / /        /       #######");
	mvprintw(9,8,"       /  \\            \\          / /       _/_          ### ");
	mvprintw(10,8,"      /____\\    ___ ___ \\        / /__  __  /  ____  ######  ");
	mvprintw(11,8,"     /      \\  /  //  /  \\  /\\  / /  / __/ /  /_    ##       ");
	mvprintw(12,8,"    /        \\/__//__/    \\/  \\/ /  / /_/ /_ __/   #######   ");
	mvprintw(13,8,"             /   /                                           ");
	mvprintw(14,8,"____________/   /____________________________________________");
	mvprintw(15,8,"_______________PRESS ANY KEY TO CHAT...NOW :v________________");
}

int main()
{
	initscr();
	raw();
	start_color();
	WINDOW* local_win = newwin(24, 80, 0, 0);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	drawLogo();
	attroff(COLOR_PAIR(1));
	
	attron(COLOR_PAIR(2));
	getch(); //Press any key 2 advance
	wborder(local_win, '{', '}', '^','v','*','*','*','*'); //Draw interface
	wbkgd(local_win, COLOR_PAIR(2));
	mvprintw(0, 14, "== AppWhats 2 TM - Just plain chatting, literally =="); //Draws title
	mvprintw(18, 1, "==============================================================================");
	attroff(COLOR_PAIR(2));
	
	attron(COLOR_PAIR(1)); //Black background for user writing.
	mvprintw(19, 1, "                                                                              ");
	mvprintw(20, 1, "                                                                              ");
	mvprintw(21, 1, "                                                                              ");
	mvprintw(22, 1, "                                                                              ");
	attroff(COLOR_PAIR(1));
	wrefresh(local_win);

	move(19, 3);
    getstr(nameTemp); //Start chatting

	endwin();

	printf("%s\n", nameTemp); //Do whatever you want with the str.

	return 0;
}