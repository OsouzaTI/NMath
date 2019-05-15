#include <ncurses.h>
#include <string.h>
#include "/home/ozeias/Documentos/C scripts/Project NMath/testeInclude.h"
int main(){
    initscr();
    if (has_colors()){
        //printw("Supported colors");
        getch();
        clear();
    }
    //cbreak();
    //noecho();
    start_color();
    init_pair(1,COLOR_CYAN,COLOR_BLACK);
    int height, width, start_x, start_y;
    height  = 30;
    width = 50;
    start_x = 0;
    start_y = 0;
    WINDOW * win = newwin(height,width,start_y,start_x);//janela nova
    char title_win[] = "NMATH - Sistema matemático";
    int tam_title = strlen(title_win)/2;
    refresh();// atualiza a janela nova no code
    //box(win,0,0);// cria uma caixa na janela nova
    wborder(win,'|','|','_','_','+','+','+','+');
    //attron();
    mvwprintw(win, 1, width/2-tam_title , title_win);// print dentro da janela
    //attroff();
    wrefresh(win); // refresh() na janela nova


    getch();
    getch();
    endwin();

    return 0;
}
