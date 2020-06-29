//Tic Tac No by: Jonatan@9998 jonatan.gud.hum@gmail.com https://github.com/Jonatan6/Tic-Tac-DS Jonatan1
#include <nds.h>
#include <stdio.h>

void draw_board(char board[], PrintConsole* pc) {
	char border[] =
"--------- --------- --------- "
"|       | |       | |       | "
"|       | |       | |       | "
"|   %c   | |   %c   | |   %c   | "
"|       | |       | |       | "
"|       | |       | |       | "
"--------- --------- --------- "
"--------- --------- --------- "
"|       | |       | |       | "
"|       | |       | |       | "
"|   %c   | |   %c   | |   %c   | "
"|       | |       | |       | "
"|       | |       | |       | "
"--------- --------- --------- "
"--------- --------- --------- "
"|       | |       | |       | "
"|       | |       | |       | "
"|   %c   | |   %c   | |   %c   | "
"|       | |       | |       | "
"|       | |       | |       | "
"--------- --------- --------- ";
	consoleSetWindow(pc, 1,1,30,21);
	consoleSelect(pc);
	
	iprintf(border, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

bool touch_clicked(touchPosition* touch) {
	if(touch->px == 0 && touch->py == 0) {
		return false;
	} else {
		return true;
	}
}

//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	PrintConsole topScreen;
	PrintConsole bottomScreen;
	
	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankA(VRAM_A_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);

	consoleInit(&topScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottomScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true); 
	
	touchPosition touch;
	
	bool touch_down = false;
	
	bool xturn = true;
	char *border;
	char board[] = "         ";
	
	int box_w = 72;
	int box_h = 62;
	int xborder = 10;
	int yborder = 5;
	
	int xscore = 0;
	int oscore = 0;

	while(1) {
		touchRead(&touch);
		draw_board(board, &bottomScreen);
		
		consoleSelect(&topScreen);
		consoleSetWindow(&topScreen, 1,1,30,21);
		iprintf("          TIC TAC DS");
		consoleSetWindow(&topScreen, 1,2,30,21);
		iprintf("          BY JONATAN");
		consoleSetWindow(&topScreen, 1,18,30,21);
		iprintf("X HAS A SCORE OF: %d", xscore);
		consoleSetWindow(&topScreen, 1,19,30,21);
		iprintf("O HAS A SCORE OF: %d", oscore);
		
				if (xturn) {
					consoleSetWindow(&topScreen, 1,22,30,21);
		iprintf("X'S TURN");
			
				} else {
					consoleSetWindow(&topScreen, 1,22,30,21);
		iprintf("O'S TURN");
				}
		
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX		
		if(board[8] == 'X' && board[7] == 'X' && board[6] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[5] == 'X' && board[4] == 'X' && board[3] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[2] == 'X' && board[1] == 'X' && board[0] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO	
	if(board[8] == 'O' && board[7] == 'O' && board[6] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; oscore = oscore+1;
			}
		if(board[5] == 'O' && board[4] == 'O' && board[3] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; oscore = oscore+1;
			}
		if(board[2] == 'O' && board[1] == 'O' && board[0] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; oscore = oscore+1;
			}
		if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;	
			}
		if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;									}
		if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;									}
if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;									}
		if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;									}
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
if(board[0] == ' ' || board[1] == ' ' || board[2] == ' ' || board[3] == ' ' || board[4] == ' ' || board[5] == ' ' || board[6] == ' ' || board[7] == ' ' || board[8] == ' ') {consoleSetWindow(&topScreen, 1,2,30,21);
		iprintf("          BY JONATAN");
		}
else {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("          ITS A TIE!");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';			}
//END OF MADNESS		
		if(touch_clicked(&touch) && !touch_down) {
			touch_down = true;
			
	/*0*/	        	if(touch.px > (0*box_w + 0*xborder) && 
                       	touch.px < (1*box_w + 0*xborder) && 
                       	touch.py > (0*box_h + 0*yborder) && 
                       	touch.py < (1*box_h + 0*yborder) &&
                       	board[0] == ' ')
			{
				if (xturn) {
					board[0] = 'X';
				xturn = !xturn;
				} else {
					board[0] = 'O';
				xturn = !xturn;
				}
				
			}
	/*1*/       		if(touch.px > (1*box_w + 1*xborder) && 
                       	touch.px < (2*box_w + 1*xborder) && 
                       	touch.py > (0*box_h + 0*yborder) && 
                       	touch.py < (1*box_h + 0*yborder) &&
                       	board[1] == ' ')
			{
				if (xturn) {
					board[1] = 'X';
				xturn = !xturn;
				} else {
					board[1] = 'O';
				xturn = !xturn;
				}
			}
	/*2*/				if(touch.px > (2*box_w + 2*xborder) && 
                       	touch.px < (3*box_w + 2*xborder) && 
                       	touch.py > (0*box_h + 0*yborder) && 
                       	touch.py < (1*box_h + 0*yborder) &&
                       	board[2] == ' ')
			{
				if (xturn) {
					board[2] = 'X';
				xturn = !xturn;
				} else {
					board[2] = 'O';
				xturn = !xturn;
				}
			}
	/*3*/				if(touch.px > (0*box_w + 0*xborder) && 
                       	touch.px < (1*box_w + 0*xborder) && 
                       	touch.py > (1*box_h + 1*yborder) && 
                       	touch.py < (2*box_h + 1*yborder) &&
                       	board[3] == ' ')
			{
				if (xturn) {
					board[3] = 'X';
				xturn = !xturn;
				} else {
					board[3] = 'O';
				xturn = !xturn;
				}
			}
	/*4*/				if(touch.px > (1*box_w + 1*xborder) && 
                       	touch.px < (2*box_w + 1*xborder) && 
                       	touch.py > (1*box_h + 1*yborder) && 
                       	touch.py < (2*box_h + 1*yborder) &&
                       	board[4] == ' ')
			{
				if (xturn) {
					board[4] = 'X';
				xturn = !xturn;
				} else {
					board[4] = 'O';
				xturn = !xturn;
				}
			}
	/*5*/				if(touch.px > (2*box_w + 2*xborder) && 
                       	touch.px < (3*box_w + 2*xborder) && 
                       	touch.py > (1*box_h + 1*yborder) && 
                       	touch.py < (2*box_h + 1*yborder) &&
                       	board[5] == ' ')
			{
				if (xturn) {
					board[5] = 'X';
				xturn = !xturn;
				} else {
					board[5] = 'O';
				xturn = !xturn;
				}
			}
	/*6*/				if(touch.px > (0*box_w + 0*xborder) && 
                       	touch.px < (1*box_w + 0*xborder) && 
                       	touch.py > (2*box_h + 2*yborder) && 
                       	touch.py < (3*box_h + 2*yborder) &&
                       	board[6] == ' ')
			{
				if (xturn) {
					board[6] = 'X';
				xturn = !xturn;
				} else {
					board[6] = 'O';
				xturn = !xturn;
				}
			}
	/*7*/				if(touch.px > (1*box_w + 1*xborder) && 
                       	touch.px < (2*box_w + 1*xborder) && 
                       	touch.py > (2*box_h + 2*yborder) && 
                       	touch.py < (3*box_h + 2*yborder) &&
                       	board[7] == ' ')
			{
				if (xturn) {
					board[7] = 'X';
				xturn = !xturn;
				} else {
					board[7] = 'O';
				xturn = !xturn;
				}
			}
	/*8*/				if(touch.px > (2*box_w + 2*xborder) && 
                       	touch.px < (3*box_w + 2*xborder) && 
                       	touch.py > (2*box_h + 2*yborder) && 
                       	touch.py < (3*box_h + 2*yborder) &&
                       	board[8] == ' ')
			{
				if (xturn) {
					board[8] = 'X';
				xturn = !xturn;
				} else {
					board[8] = 'O';
				xturn = !xturn;
				}
			}
			
			
		} else if (!touch_clicked(&touch)){
			touch_down = false;
		}
		swiWaitForVBlank();
	}
	return 0;
}
