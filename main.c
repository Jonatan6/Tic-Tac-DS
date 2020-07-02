//Tic Tac DS by: Jonatan#9998 Jonatan1 jonatan.gud.hum@gmail.com https://github.com/Jonatan6/Tic-Tac-DS
#include <nds.h>
#include <stdio.h>
#include <nds/input.h>
#include <nds/touch.h>
#include "font.h"

bool title_screen = true;
bool ninja_mode = false;

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
	
	if (ninja_mode == false) {
	iprintf(border, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);}

	else {iprintf(border, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');}
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

	consoleInit(&topScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottomScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true); 
	
	touchPosition touch;
	
	bool touch_down = false;
	bool xturn = true;
	bool cent_block = false;
	bool settings = false;
	bool backup_unlock =true;
	bool d_d = false;
	
	bool board_clickable = false;
	
	char *border;
	char board[] = "         ";
	char board_b[] = "         ";
	char board_n[] = "         ";
	
	int box_w = 72;
	int box_h = 62;
	int xborder = 10;
	int yborder = 5;
	
	int xscore = 0;
	int oscore = 0;


	/*for custom fonts
	
	const int tile_base = 0;
	const int map_base = 20;
	
	//videoSetModeSub(MODE_0_2D);	
	vramSetBankC(VRAM_C_SUB_BG); 

	PrintConsole *console = consoleInit(0,0, BgType_Text4bpp, BgSize_T_256x256, map_base, tile_base, false, false);

	ConsoleFont font;

	font.gfx = (u16*)fontTiles;
	font.pal = (u16*)fontPal;
	font.numChars = 95;
	font.numColors =  fontPalLen / 2;
	font.bpp = 4;
	font.asciiOffset = 32;
	font.convertSingleColor = false;
	
	consoleSetFont(console, &font);*/


	while(1) {
		
		if(title_screen){
			touchRead(&touch);
			//scanKeys();
			consoleSelect(&topScreen);
			consoleSetWindow(&topScreen, 1,10,100,100);
			iprintf("      TOUCH TO CONTINUE!");
			consoleSelect(&bottomScreen);
			consoleSetWindow(&bottomScreen, 1,10,30,30);
			iprintf("      TOUCH TO CONTINUE!");
			if (touch.px > 0 && touch.py > 0) { title_screen = false; }
		}		
		else {
			draw_board(board, &bottomScreen);
			touchRead(&touch);
			if (settings == false) {
				
		consoleSelect(&topScreen);
		consoleSetWindow(&topScreen, 1,1,30,21);
		iprintf("VER 2.5   TIC TAC DS");
		consoleSetWindow(&topScreen, 1,2,30,21);
		iprintf("          BY JONATAN");
		consoleSetWindow(&topScreen, 1,10,30,21);
		iprintf("                             ");
		consoleSetWindow(&topScreen, 1,18,30,21);
		iprintf("X HAS A SCORE OF: %d        ", xscore);
		consoleSetWindow(&topScreen, 1,19,30,21);
		iprintf("O HAS A SCORE OF: %d        ", oscore);
		consoleSetWindow(&topScreen, 1,20,30,21);
		iprintf("                               ");
		consoleSetWindow(&topScreen, 1,21,30,21);
		iprintf("                               ");
		consoleSetWindow(&topScreen, 1,22,30,21);
		iprintf("                               ");
		consoleSetWindow(&topScreen, 1,10,20,21);
			iprintf("                                  ");
		
				if (xturn) {
					consoleSetWindow(&topScreen, 1,22,30,21);
		iprintf("X'S TURN");
			
				} else {
					consoleSetWindow(&topScreen, 1,22,30,21);
		iprintf("O'S TURN");
				}
			}
				
		scanKeys();
		int keys = keysDown();
		if (keys & KEY_START || keys & KEY_SELECT) {settings = !settings; board[4] = ' ';
		//consoleSetWindow(&topScreen, 1,1,30,21);
		//iprintf("                    ");
		//consoleSetWindow(&topScreen, 1,2,30,21);
		//iprintf("                    ");
		consoleSetWindow(&topScreen, 1,10,30,21);
		iprintf("                              ");
		consoleSetWindow(&topScreen, 1,18,30,21);
		iprintf("PRESS START/SELECT TO EXIT", xscore);
		consoleSetWindow(&topScreen, 1,19,30,21);
		iprintf("PRESS A TO RESET SCORES", oscore);
		consoleSetWindow(&topScreen, 1,20,30,21);
		iprintf("PRESS B TO CLEAR BOARD");
		consoleSetWindow(&topScreen, 1,21,30,21);
		iprintf("PRESS X TO BLOCK CENTER SQUARE");
		consoleSetWindow(&topScreen, 1, 22,30,21);
		iprintf("PRESS Y TO TURN NINJA MODE ON");
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("                                                                      ");		
		if (backup_unlock){
		board_b[0] = board[0]; board_b[1] = board[1]; board_b[2] = board[2]; board_b[3] = board[3]; board_b[4] = board[4]; board_b[5] 			= board[5]; 			board_b[6] = board[6];board_b[7] = board[7]; board_b[8] = board[8];	backup_unlock = false;	}
		board[0] = 'O'; board[1] = 'P'; board[2] = 'T'; board[3] = 'I'; board[4] = 'O'; board[5] = 'N'; board[6] = 'S'; board[7] = '‎'						; 			board[8] = '‎'; //hiden unicode charecter '‎' needed for unclickable field
	}	if (settings){
		if (d_d) {
		consoleSelect(&topScreen);
		consoleSetWindow(&topScreen, 1,7,20,21);
		iprintf("             DONE!"); d_d = false;
		}
		
		if (keys & KEY_A) {d_d = true; xscore = 0; oscore = 0;}
		
		if (keys & KEY_B) {
		d_d = true;
		board_b[0] = ' '; board_b[1] = ' '; board_b[2] = ' '; board_b[3] = ' '; board_b[4] = ' '; board_b[5] = ' '; 							board_b[6] = ' '; board_b[7] = ' '; board_b[8] = ' ';}
		
		if (keys & KEY_Y) {d_d = true;
		ninja_mode = !ninja_mode;}
	
		if (keys & KEY_X) {d_d = true; cent_block = !cent_block;}
	}
//X WON
if (settings == false) {
		if(board[8] == 'X' && board[7] == 'X' && board[6] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!! ");
strcpy(board, "         ");
 xscore = xscore+1;
			}
		if(board[5] == 'X' && board[4] == 'X' && board[3] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[2] == 'X' && board[1] == 'X' && board[0] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
		if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           X WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; xscore = xscore+1;
			}
//O WON
	if(board[8] == 'O' && board[7] == 'O' && board[6] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; oscore = oscore+1;
			}
		if(board[5] == 'O' && board[4] == 'O' && board[3] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; oscore = oscore+1;
			}
		if(board[2] == 'O' && board[1] == 'O' && board[0] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' '; oscore = oscore+1;
			}
		if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;	
			}
		if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;									}
		if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;									}
if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;									}
		if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("           O WON!!! ");
board[0] = ' '; board[1] = ' '; board[2] = ' '; board[3] = ' '; board[4] = ' '; board[5] = ' '; board[6] = ' '; board[7] = ' '; board[8] = ' ';	oscore = oscore+1;									}
if (cent_block){ board[4] = '=';} 
//ITS A TIE
if(board[0] == ' ' || board[1] == ' ' || board[2] == ' ' || board[3] == ' ' || board[4] == ' ' || board[5] == ' ' || board[6] == ' ' || board[7] == ' ' || board[8] == ' ') {consoleSetWindow(&topScreen, 1,2,30,21);
		iprintf(" ");
		}
else {
		consoleSetWindow(&topScreen, 1,7,30,21);
		iprintf("          ITS A TIE!");
board[0] = board_b[0]; board[1] = board_b[1]; board[2] = board_b[2]; board[3] = board_b[3]; board[4] = board_b[4]; board[5] = board_b[5]; board[6] = board_b[6]; board[7] = board_b[7]; board[8] = board_b[8];
board_b[0] = ' '; board_b[1] = ' '; board_b[2] = ' '; board_b[3] = ' '; board_b[4] = ' '; board_b[5] = ' '; board_b[6] = ' '; board_b[7] = ' '; board_b[8] = ' '; backup_unlock =true;
			}
//END OF MADNESS
}		
		if(touch_clicked(&touch) && !touch_down && board_clickable) {
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
			board_clickable = true;
		}
		swiWaitForVBlank();
		}
	
	}
	return 0;
}
