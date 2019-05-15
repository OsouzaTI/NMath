#include <ncurses.h>
#include <string.h>
#include <locale.h>
//Prototipos
void menu(WINDOW * w);
char janelaAtual[] = "main";
int main(){
    setlocale(LC_ALL,"Portuguese");
    //inicializar o ncurses
    initscr();
    while(true){
        printw("oi");
    }
    //noecho();
    //cbreak();
    //cores do terminal
    use_default_colors();
    start_color();
    init_pair(1,COLOR_WHITE, -1); // default color do terminal
    init_pair(2,COLOR_BLACK,COLOR_WHITE);// pair da janela
    init_pair(3,COLOR_WHITE,COLOR_BLACK);
    bkgd(COLOR_PAIR(1));
    // Janela main
    int w, h, x, y;
    char titleMain[] =  "NMath - Sistema matematico";
    int tamTitleMain =  strlen(titleMain)/2;
    w = 50;
    h = 30;
    x = y = 0;
    WINDOW * main_ = newwin(h,w,x,y);
    //bordas da janela
    box(main_,0,0);
    //atualizar tela
    refresh();
    //cor da janela e titulo
    wbkgd(main_,COLOR_PAIR(2));
    mvwprintw(main_,1,w/2-tamTitleMain,titleMain);
    if(strcmp(janelaAtual,"main")==1)
    {
        //atualizar janela main
        wrefresh(main_);
        //Menu de seleção
        menu(main_);
    }
    else
    {
        printw("A janela atual não é a main!");
        getch();
    }
    //fim do ncurses
    endwin();

    return 0;
}


void menu(WINDOW * w){
    WINDOW * aviso = newwin(3,40,4,1);
    box(aviso,0,0);
    refresh();
    mvwprintw(aviso,1,1,"Digite um dos numeros para escolher:");
    wbkgd(aviso,COLOR_PAIR(3));
    wrefresh(aviso);
    mvwprintw(w,7,1,"1 - Calculos Matematicos");
    mvwprintw(w,8,1,"2 - Calculos Fisicos");
    wrefresh(w);
    move(5,38);
    refresh();
    char n = wgetch(aviso);
    switch(n){
        case('1'):
            mvwprintw(w,1,1,"M");
            wrefresh(w);
            getch();
            break;
        case('2'):
            wprintw(w,"F");
            break;

    }
}






