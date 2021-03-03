#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <nds/input.h>
#include <nds/touch.h>

bool xturn = true;
bool title_screen = true;
bool ninja_mode = false;

void draw_board(char board[], PrintConsole *pc)
{
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
	consoleSetWindow(pc, 1, 1, 30, 21);
	consoleSelect(pc);

	if (ninja_mode == false)
	{
		iprintf(border, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
	}
	else
	{
		iprintf(border, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	}
}

bool touch_clicked(touchPosition *touch)
{
	if (touch->px == 0 && touch->py == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool board_is_full(char *board)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			return false;
		}
	}
	return true;
}

void draw_random_o(char *board)
{
	int n = rand() % 9;

	if (board_is_full(board) || xturn)
	{
		return;
	}

	if (board[n] == ' ')
	{
		board[n] = 'O';
	}
	else
	{
		draw_random_o(board);
	}
}

void draw_random_o2(char *board)
{
	if (board_is_full(board) || xturn)
	{
		return;
	}

	if (board[0] == 'X' && board[1] == 'X' && board[2] == ' ')
	{
		board[2] = 'O';
	}
	else if (board[0] == 'X' && board[1] == ' ' && board[2] == 'X')
	{
		board[1] = 'O';
	}
	else if (board[0] == ' ' && board[1] == 'X' && board[2] == 'X')
	{
		board[0] = 'O';
	}
	else if (board[3] == 'X' && board[4] == 'X' && board[5] == ' ')
	{
		board[5] = 'O';
	}
	else if (board[3] == 'X' && board[4] == ' ' && board[5] == 'X')
	{
		board[4] = 'O';
	}
	else if (board[3] == ' ' && board[4] == 'X' && board[5] == 'X')
	{
		board[3] = 'O';
	}
	else if (board[6] == 'X' && board[7] == 'X' && board[8] == ' ')
	{
		board[8] = 'O';
	}
	else if (board[6] == 'X' && board[7] == ' ' && board[8] == 'X')
	{
		board[7] = 'O';
	}
	else if (board[6] == ' ' && board[7] == 'X' && board[8] == 'X')
	{
		board[6] = 'O';
	}
	else if (board[0] == 'X' && board[3] == 'X' && board[6] == ' ')
	{
		board[6] = 'O';
	}
	else if (board[0] == 'X' && board[3] == ' ' && board[6] == 'X')
	{
		board[3] = 'O';
	}
	else if (board[0] == ' ' && board[3] == 'X' && board[6] == 'X')
	{
		board[0] = 'O';
	}
	else if (board[1] == 'X' && board[4] == 'X' && board[7] == ' ')
	{
		board[7] = 'O';
	}
	else if (board[1] == 'X' && board[4] == ' ' && board[7] == 'X')
	{
		board[3] = 'O';
	}
	else if (board[1] == ' ' && board[4] == 'X' && board[7] == 'X')
	{
		board[1] = 'O';
	}
	else if (board[2] == 'X' && board[5] == 'X' && board[8] == ' ')
	{
		board[8] = 'O';
	}
	else if (board[2] == 'X' && board[5] == ' ' && board[8] == 'X')
	{
		board[5] = 'O';
	}
	else if (board[2] == ' ' && board[5] == 'X' && board[8] == 'X')
	{
		board[2] = 'O';
	}
	else if (board[0] == 'X' && board[4] == 'X' && board[8] == ' ')
	{
		board[8] = 'O';
	}
	else if (board[0] == 'X' && board[4] == ' ' && board[8] == 'X')
	{
		board[4] = 'O';
	}
	else if (board[0] == ' ' && board[4] == 'X' && board[8] == 'X')
	{
		board[0] = 'O';
	}
	else if (board[2] == 'X' && board[4] == 'X' && board[6] == ' ')
	{
		board[6] = 'O';
	}
	else if (board[2] == 'X' && board[4] == ' ' && board[6] == 'X')
	{
		board[4] = 'O';
	}
	else if (board[2] == ' ' && board[4] == 'X' && board[6] == 'X')
	{
		board[2] = 'O';
	}
	else
	{
		draw_random_o(board);
	}
}

void draw_random_o3(char *board)
{
	if (board_is_full(board) || xturn)
	{
		return;
	}

	if (board[0] == 'X' && board[1] == ' ' && board[2] == ' ' && board[3] == ' ' && board[4] == ' ' && board[5] == ' ' && board[6] == ' ' && board[7] == ' ' && board[8] == ' ')
	{
		board[4] = 'O';
	}
	else if (board[0] == ' ' && board[1] == ' ' && board[2] == 'X' && board[3] == ' ' && board[4] == ' ' && board[5] == ' ' && board[6] == ' ' && board[7] == ' ' && board[8] == ' ')
	{
		board[4] = 'O';
	}
	else if (board[0] == 'X' && board[1] == ' ' && board[2] == ' ' && board[3] == ' ' && board[4] == ' ' && board[5] == ' ' && board[6] == ' ' && board[7] == ' ' && board[8] == 'X')
	{
		board[4] = 'O';
	}
	else if (board[0] == 'X' && board[1] == ' ' && board[2] == ' ' && board[3] == ' ' && board[4] == ' ' && board[5] == ' ' && board[6] == 'X' && board[7] == ' ' && board[8] == ' ')
	{
		board[4] = 'O';
	}
	else if (board[0] == 'O' && board[1] == 'O' && board[2] == ' ')
	{
		board[2] = 'O';
	}
	else if (board[0] == 'O' && board[1] == ' ' && board[2] == 'O')
	{
		board[1] = 'O';
	}
	else if (board[0] == ' ' && board[1] == 'O' && board[2] == 'O')
	{
		board[0] = 'O';
	}
	else if (board[3] == 'O' && board[4] == 'O' && board[5] == ' ')
	{
		board[5] = 'O';
	}
	else if (board[3] == 'O' && board[4] == ' ' && board[5] == 'O')
	{
		board[4] = 'O';
	}
	else if (board[3] == ' ' && board[4] == 'O' && board[5] == 'O')
	{
		board[3] = 'O';
	}
	else if (board[6] == 'O' && board[7] == 'O' && board[8] == ' ')
	{
		board[8] = 'O';
	}
	else if (board[6] == 'O' && board[7] == ' ' && board[8] == 'O')
	{
		board[7] = 'O';
	}
	else if (board[6] == ' ' && board[7] == 'O' && board[8] == 'O')
	{
		board[6] = 'O';
	}
	else if (board[0] == 'O' && board[3] == 'O' && board[6] == ' ')
	{
		board[6] = 'O';
	}
	else if (board[0] == 'O' && board[3] == ' ' && board[6] == 'O')
	{
		board[3] = 'O';
	}
	else if (board[0] == ' ' && board[3] == 'O' && board[6] == 'O')
	{
		board[0] = 'O';
	}
	else if (board[1] == 'O' && board[4] == 'O' && board[7] == ' ')
	{
		board[7] = 'O';
	}
	else if (board[1] == 'O' && board[4] == ' ' && board[7] == 'O')
	{
		board[3] = 'O';
	}
	else if (board[1] == ' ' && board[4] == 'O' && board[7] == 'O')
	{
		board[1] = 'O';
	}
	else if (board[2] == 'O' && board[5] == 'O' && board[8] == ' ')
	{
		board[8] = 'O';
	}
	else if (board[2] == 'O' && board[5] == ' ' && board[8] == 'O')
	{
		board[5] = 'O';
	}
	else if (board[2] == ' ' && board[5] == 'X' && board[8] == 'O')
	{
		board[2] = 'O';
	}
	else if (board[0] == 'O' && board[4] == 'O' && board[8] == ' ')
	{
		board[8] = 'O';
	}
	else if (board[0] == 'O' && board[4] == ' ' && board[8] == 'O')
	{
		board[4] = 'O';
	}
	else if (board[0] == ' ' && board[4] == 'O' && board[8] == 'O')
	{
		board[0] = 'O';
	}
	else if (board[2] == 'O' && board[4] == 'O' && board[6] == ' ')
	{
		board[6] = 'O';
	}
	else if (board[2] == 'O' && board[4] == ' ' && board[6] == 'O')
	{
		board[4] = 'O';
	}
	else if (board[2] == ' ' && board[4] == 'O' && board[6] == 'O')
	{
		board[2] = 'O';
	}
	else
	{
		draw_random_o2(board);
	}
}

// If touch is clicked, wait forever until touch is released.
void read_touch(touchPosition *touch)
{
	touchPosition a, b;
	touchRead(&a);
	touchRead(&b);

	while (touch_clicked(&a))
	{
		touchRead(&a);
	}

	*touch = b;
}

int main(void)
{

	PrintConsole topScreen;
	PrintConsole bottomScreen;

	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	consoleInit(&topScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
	consoleInit(&bottomScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);

	touchPosition touch;

	bool cent_block = false;
	bool settings = false;
	bool backup_unlock = true;
	bool d_d = false;
	bool aimode = false;
	bool clear_screen = false;
	bool sub_title_screen = false;
	bool globglo = false;

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
	int difficulty = 0;

	while (1)
	{
		rand();	// "seeds" by number of turns in the while loop
		if (title_screen)
		{

			scanKeys();
			int keys = keysDown();
			if (keys &KEY_B && settings == false)
			{
				title_screen = true;
				clear_screen = false;
				sub_title_screen = false;
				strcpy(board, "         ");
				aimode = false;
				globglo = true;
				difficulty = 0;
				continue;
			}

			read_touch(&touch);
			if (clear_screen == false && sub_title_screen == false)
			{
				consoleSelect(&topScreen);
				consoleClear();
				consoleSelect(&bottomScreen);
				consoleClear();
				clear_screen = true;
				consoleSelect(&topScreen);
				consoleSetWindow(&topScreen, 1, 10, 100, 100);
				iprintf("      TOUCH TO CONTINUE!");

				consoleSetWindow(&topScreen, 1, 18, 30, 21);
				iprintf("                            ", xscore);
				consoleSetWindow(&topScreen, 1, 19, 30, 21);
				iprintf("                            ", oscore);
				consoleSetWindow(&topScreen, 1, 7, 30, 21);
				iprintf("                    ");

				consoleSelect(&bottomScreen);
				consoleSetWindow(&bottomScreen, 1, 15, 30, 30);
				iprintf("       VS OTHER PLAYER");
				consoleSetWindow(&bottomScreen, 1, 10, 30, 30);
				iprintf("------------------------------");
				consoleSetWindow(&bottomScreen, 1, 5, 30, 30);
				iprintf("         VS COMPUTER");
			}
			if (globglo)
			{
				clear_screen = false;
				globglo = false;
			}

			if (touch.px > 0 && touch.py > 97 && sub_title_screen == false)
			{
				title_screen = false;
			}
			else if (touch.px > 0 && touch.py < 97 && sub_title_screen == false)
			{
				sub_title_screen = true;
				consoleSelect(&topScreen);
				consoleSetWindow(&topScreen, 1, 10, 100, 100);
				iprintf("                              ");
				consoleSelect(&bottomScreen);
				consoleSetWindow(&bottomScreen, 1, 15, 30, 30);
				iprintf("                              ");
				consoleSetWindow(&bottomScreen, 1, 10, 30, 30);
				iprintf("                              ");
				consoleSetWindow(&bottomScreen, 1, 5, 30, 30);
				iprintf("                              ");
				consoleSelect(&topScreen);
				consoleSetWindow(&topScreen, 1, 10, 30, 30);
				iprintf("      CHOOSE DIFFICULTY");
				consoleSelect(&bottomScreen);
				consoleSetWindow(&bottomScreen, 1, 6, 30, 30);
				iprintf("            EASY              ");
				consoleSetWindow(&bottomScreen, 1, 9, 30, 30);
				iprintf("------------------------------");
				consoleSetWindow(&bottomScreen, 1, 12, 30, 30);
				iprintf("           MEDIUM             ");
				consoleSetWindow(&bottomScreen, 1, 15, 30, 30);
				iprintf("------------------------------");
				consoleSetWindow(&bottomScreen, 1, 18, 30, 30);
				iprintf("            HARD              ");
			}
			else if (touch.px > 0 && touch.py < 64 && sub_title_screen)
			{
				difficulty = 1;
				title_screen = false;
				sub_title_screen = false;
			}
			else if (touch.px > 0 && touch.py < 128 && sub_title_screen)
			{
				difficulty = 2;
				title_screen = false;
				sub_title_screen = false;
			}
			else if (touch.px > 0 && touch.py < 192 && sub_title_screen)
			{
				difficulty = 3;
				title_screen = false;
				sub_title_screen = false;
			}
		}
		else
		{
			if (difficulty == 1 && !xturn)
			{
				draw_random_o(board);
				xturn = true;
			}
			else if (difficulty == 2 && !xturn)
			{
				draw_random_o2(board);
				xturn = true;
			}
			else if (difficulty == 3 && !xturn)
			{
				draw_random_o3(board);
				xturn = true;
			}

			draw_board(board, &bottomScreen);
			read_touch(&touch);
			if (settings == false)
			{
				consoleSelect(&topScreen);
				consoleSetWindow(&topScreen, 1, 1, 30, 21);
				iprintf("VER 3.0   TIC TAC DS");
				consoleSetWindow(&topScreen, 1, 2, 30, 21);
				iprintf("          BY JONATAN");
				consoleSetWindow(&topScreen, 1, 10, 30, 21);
				iprintf("                             ");
				consoleSetWindow(&topScreen, 1, 18, 30, 21);
				iprintf("X HAS A SCORE OF: %d        ", xscore);
				consoleSetWindow(&topScreen, 1, 19, 30, 21);
				iprintf("O HAS A SCORE OF: %d        ", oscore);
				consoleSetWindow(&topScreen, 1, 20, 30, 21);
				iprintf("                               ");
				consoleSetWindow(&topScreen, 1, 21, 30, 21);
				iprintf("                               ");
				consoleSetWindow(&topScreen, 1, 22, 30, 21);
				iprintf("                               ");
				consoleSetWindow(&topScreen, 1, 10, 20, 21);
				iprintf("                                  ");

				if (xturn)
				{
					consoleSetWindow(&topScreen, 1, 22, 30, 21);
					iprintf("X'S TURN");
				}
				else
				{
					consoleSetWindow(&topScreen, 1, 22, 30, 21);
					iprintf("O'S TURN");
				}
			}

			scanKeys();
			int keys = keysDown();
			if (keys &KEY_B && settings == false)
			{
				title_screen = true;
				sub_title_screen = false;
				clear_screen = false;
				strcpy(board, "         ");
				aimode = false;
				difficulty = 0;
				continue;
			}

			if (keys &KEY_START || keys &KEY_SELECT)
			{
				settings = !settings;
				board[4] = ' ';
				consoleSetWindow(&topScreen, 1, 10, 30, 21);
				iprintf("                              ");
				consoleSetWindow(&topScreen, 1, 18, 30, 21);
				iprintf("PRESS START/SELECT TO EXIT", xscore);
				consoleSetWindow(&topScreen, 1, 19, 30, 21);
				iprintf("PRESS A TO RESET SCORES", oscore);
				consoleSetWindow(&topScreen, 1, 20, 30, 21);
				iprintf("PRESS B TO CLEAR BOARD");
				consoleSetWindow(&topScreen, 1, 21, 30, 21);
				iprintf("PRESS X TO BLOCK CENTER SQUARE");
				consoleSetWindow(&topScreen, 1, 22, 30, 21);
				iprintf("PRESS Y TO TURN NINJA MODE ON");
				consoleSetWindow(&topScreen, 1, 7, 30, 21);
				iprintf("                                                                      ");
				if (backup_unlock)
				{
					board_b[0] = board[0];
					board_b[1] = board[1];
					board_b[2] = board[2];
					board_b[3] = board[3];
					board_b[4] = board[4];
					board_b[5] = board[5];
					board_b[6] = board[6];
					board_b[7] = board[7];
					board_b[8] = board[8];
					backup_unlock = false;
				}
				board[0] = 'O';
				board[1] = 'P';
				board[2] = 'T';
				board[3] = 'I';
				board[4] = 'O';
				board[5] = 'N';
				board[6] = 'S';
				board[7] = '‎';	// Hidden unicode charecter '‎' needed for unclickable field
				board[8] = '‎';	// The same here
			}
			if (settings)
			{
				if (d_d)
				{
					consoleSelect(&topScreen);
					consoleSetWindow(&topScreen, 1, 7, 20, 21);
					iprintf("             DONE!");
					d_d = false;
				}

				if (keys & KEY_A)
				{
					d_d = true;
					xscore = 0;
					oscore = 0;
				}

				if (keys & KEY_B)
				{
					d_d = true;
					board_b[0] = ' ';
					board_b[1] = ' ';
					board_b[2] = ' ';
					board_b[3] = ' ';
					board_b[4] = ' ';
					board_b[5] = ' ';
					board_b[6] = ' ';
					board_b[7] = ' ';
					board_b[8] = ' ';
				}

				if (keys & KEY_Y)
				{
					d_d = true;
					ninja_mode = !ninja_mode;
				}

				if (keys & KEY_X)
				{
					d_d = true;
					cent_block = !cent_block;
				}
			}
			// X Won
			if (settings == false)
			{
				if (board[8] == 'X' && board[7] == 'X' && board[6] == 'X')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           X WON!!! ");
					strcpy(board, "         ");
					xscore = xscore + 1;
				}
				if (board[5] == 'X' && board[4] == 'X' && board[3] == 'X')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           X WON!!! ");
					strcpy(board, "         ");
					xscore = xscore + 1;
				}
				if (board[2] == 'X' && board[1] == 'X' && board[0] == 'X')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           X WON!!! ");
					strcpy(board, "         ");
					xscore = xscore + 1;
				}
				if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           X WON!!! ");
					strcpy(board, "         ");
					xscore = xscore + 1;
				}
				if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           X WON!!! ");
					strcpy(board, "         ");
					xscore = xscore + 1;
				}
				if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           X WON!!! ");
					strcpy(board, "         ");
					xscore = xscore + 1;
				}
				if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           X WON!!! ");
					strcpy(board, "         ");
					xscore = xscore + 1;
				}
				if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           X WON!!! ");
					strcpy(board, "         ");
					xscore = xscore + 1;
				}
				// O won
				if (board[8] == 'O' && board[7] == 'O' && board[6] == 'O')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           O WON!!! ");
					strcpy(board, "         ");
					oscore = oscore + 1;
				}
				if (board[5] == 'O' && board[4] == 'O' && board[3] == 'O')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           O WON!!! ");
					strcpy(board, "         ");
					oscore = oscore + 1;
				}
				if (board[2] == 'O' && board[1] == 'O' && board[0] == 'O')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           O WON!!! ");
					strcpy(board, "         ");
					oscore = oscore + 1;
				}
				if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           O WON!!! ");
					strcpy(board, "         ");
					oscore = oscore + 1;
				}
				if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           O WON!!! ");
					strcpy(board, "         ");
					oscore = oscore + 1;
				}
				if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           O WON!!! ");
					strcpy(board, "         ");
					oscore = oscore + 1;
				}
				if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           O WON!!! ");
					strcpy(board, "         ");
					oscore = oscore + 1;
				}
				if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("           O WON!!! ");
					strcpy(board, "         ");
					oscore = oscore + 1;
				}

				// If the center block is activated the center gets blocked
				if (cent_block)
				{
					board[4] = '=';
				}

				// Its a tie
				if (board[0] == ' ' || board[1] == ' ' || board[2] == ' ' || board[3] == ' ' || board[4] == ' ' || board[5] == ' ' || board[6] == ' ' || board[7] == ' ' || board[8] == ' ')
				{
					consoleSetWindow(&topScreen, 1, 2, 30, 21);
					iprintf(" ");
				}
				else
				{
					consoleSetWindow(&topScreen, 1, 7, 30, 21);
					iprintf("          ITS A TIE!");
					board[0] = board_b[0];
					board[1] = board_b[1];
					board[2] = board_b[2];
					board[3] = board_b[3];
					board[4] = board_b[4];
					board[5] = board_b[5];
					board[6] = board_b[6];
					board[7] = board_b[7];
					board[8] = board_b[8];
					board_b[0] = ' ';
					board_b[1] = ' ';
					board_b[2] = ' ';
					board_b[3] = ' ';
					board_b[4] = ' ';
					board_b[5] = ' ';
					board_b[6] = ' ';
					board_b[7] = ' ';
					board_b[8] = ' ';
					backup_unlock = true;
				}
				// End of madness
			}
			if (touch_clicked(&touch))
			{

				/*0*/
				if (touch.px > (0 *box_w + 0 *xborder) &&
					touch.px < (1 *box_w + 0 *xborder) &&
					touch.py > (0 *box_h + 0 *yborder) &&
					touch.py < (1 *box_h + 0 *yborder) &&
					board[0] == ' ')
				{
					if (xturn)
					{
						board[0] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[0] = 'O';
						xturn = !xturn;
					}
				}
				/*1*/
				if (touch.px > (1 *box_w + 1 *xborder) &&
					touch.px < (2 *box_w + 1 *xborder) &&
					touch.py > (0 *box_h + 0 *yborder) &&
					touch.py < (1 *box_h + 0 *yborder) &&
					board[1] == ' ')
				{
					if (xturn)
					{
						board[1] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[1] = 'O';
						xturn = !xturn;
					}
				}
				/*2*/
				if (touch.px > (2 *box_w + 2 *xborder) &&
					touch.px < (3 *box_w + 2 *xborder) &&
					touch.py > (0 *box_h + 0 *yborder) &&
					touch.py < (1 *box_h + 0 *yborder) &&
					board[2] == ' ')
				{
					if (xturn)
					{
						board[2] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[2] = 'O';
						xturn = !xturn;
					}
				}
				/*3*/
				if (touch.px > (0 *box_w + 0 *xborder) &&
					touch.px < (1 *box_w + 0 *xborder) &&
					touch.py > (1 *box_h + 1 *yborder) &&
					touch.py < (2 *box_h + 1 *yborder) &&
					board[3] == ' ')
				{
					if (xturn)
					{
						board[3] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[3] = 'O';
						xturn = !xturn;
					}
				}
				/*4*/
				if (touch.px > (1 *box_w + 1 *xborder) &&
					touch.px < (2 *box_w + 1 *xborder) &&
					touch.py > (1 *box_h + 1 *yborder) &&
					touch.py < (2 *box_h + 1 *yborder) &&
					board[4] == ' ')
				{
					if (xturn)
					{
						board[4] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[4] = 'O';
						xturn = !xturn;
					}
				}
				/*5*/
				if (touch.px > (2 *box_w + 2 *xborder) &&
					touch.px < (3 *box_w + 2 *xborder) &&
					touch.py > (1 *box_h + 1 *yborder) &&
					touch.py < (2 *box_h + 1 *yborder) &&
					board[5] == ' ')
				{
					if (xturn)
					{
						board[5] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[5] = 'O';
						xturn = !xturn;
					}
				}
				/*6*/
				if (touch.px > (0 *box_w + 0 *xborder) &&
					touch.px < (1 *box_w + 0 *xborder) &&
					touch.py > (2 *box_h + 2 *yborder) &&
					touch.py < (3 *box_h + 2 *yborder) &&
					board[6] == ' ')
				{
					if (xturn)
					{
						board[6] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[6] = 'O';
						xturn = !xturn;
					}
				}
				/*7*/
				if (touch.px > (1 *box_w + 1 *xborder) &&
					touch.px < (2 *box_w + 1 *xborder) &&
					touch.py > (2 *box_h + 2 *yborder) &&
					touch.py < (3 *box_h + 2 *yborder) &&
					board[7] == ' ')
				{
					if (xturn)
					{
						board[7] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[7] = 'O';
						xturn = !xturn;
					}
				}
				/*8*/
				if (touch.px > (2 *box_w + 2 *xborder) &&
					touch.px < (3 *box_w + 2 *xborder) &&
					touch.py > (2 *box_h + 2 *yborder) &&
					touch.py < (3 *box_h + 2 *yborder) &&
					board[8] == ' ')
				{
					if (xturn)
					{
						board[8] = 'X';
						xturn = !xturn;
					}
					else
					{
						board[8] = 'O';
						xturn = !xturn;
					}
				}
			}
			swiWaitForVBlank();
		}
	}
	return 0;
}
