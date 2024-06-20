#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<sstream>
#include<string>
#include<windows.h>
using namespace std;

char board_value[9] = {'1','2','3','4','5','6','7','8','9'},ex[1]={},transfer_value[1]={},userchoice[1]={},turn='X',for_value[1];
int inc{0},temp,tr{},tr1={},index_value{},again,a{1},br_x{0},br_y{0},br_x1{0},br_y1{0},c=1,b{1},choice{},x{560},y{200};
char player1_name[50] = "";
char player2_name[50] = "";


						

void menu();
int all();
int loading_bar();
int images(); 
int board_values();
int print_line_board();
int players_turn();
int game_over();
void players_name();
int checkDraw();
int menu_option();

void players_name()
{
    cleardevice();
    setcolor(GREEN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
     // Input for Player 1 Name
    outtextxy(150, 200, "Enter Player 1 Name: ");
    int i = 0;
    while (true) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 13) break; // Enter key pressed
            if (ch == 8) { // Backspace key pressed
                if (i > 0) {
                    i--;
                    player1_name[i] = '\0';
                    cleardevice();
                    outtextxy(150, 200, "Enter Player 1 Name: ");
                    outtextxy(450, 200, player1_name);
                }
            } else if (ch >= 32 && ch <= 126) { // Printable characters
                player1_name[i++] = ch;
                player1_name[i] = '\0';
                outtextxy(450, 200, player1_name); // Display the name as it's being typed
            }
        }
    }

    // Input for Player 2 Name
    outtextxy(150, 300, "Enter Player 2 Name: ");
    i = 0;
    while (true) {
        if (kbhit()) {
            char ch = getch();
            if (ch == 13) break; // Enter key pressed
            if (ch == 8) { // Backspace key pressed
                if (i > 0) {
                    i--;
                    player2_name[i] = '\0';
                    cleardevice();
                    outtextxy(150, 300, "Enter Player 2 Name: ");
                    outtextxy(450, 300, player2_name);
                }
            } else if (ch >= 32 && ch <= 126) { // Printable characters
                player2_name[i++] = ch;
                player2_name[i] = '\0';
                outtextxy(450, 300, player2_name); // Display the name as it's being typed
            }
        }
    }

}




int menu_option()
{
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3/50);
    outtextxy(250, 450, "ENTER YOUR CHOICE[1/2] :");
    while(1)
    {
        if(kbhit)
        {
            choice = getch();
            break;
        }
    }

    switch(choice)
    {
        case 50:
        {
            outtextxy(500, 450, "2");
            getch();
            cleardevice();
            readimagefile("goodbye.bmp", 10, 190, 780, 310);
            delay(2500);
            exit(0);
        }
        case 49:
        {
            outtextxy(500, 450, "1");
            getch();
            cleardevice();
            for(int i{0}; i<3; i++)
            {
                setcolor(GREEN);
                settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
                outtextxy(90, 200, "YOUR GAME IS LOADING ");
                setcolor(WHITE);
                x = 550;
                for(int j{0}; j<3; j++)
                {
                    x = x + 20;
                    outtextxy(x, y, ".");
                    delay(1000);
                }
                cleardevice();
            }
            players_name();  // Call the function to get player names
            break;
        }
    }
}


void menu()
{
	readimagefile("back.bmp",10,10,780,590);
	readimagefile("menu.bmp",180,10,580,590);
//	readimagefile("new game.bmp",230,250,530,300);
//	readimagefile("exit game.bmp",290,330,470,300);
	setcolor(YELLOW);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	outtextxy(290,250,"NEW GAME");
	outtextxy(330,300,"EXIT");
}

int checkDraw() {
    for (int i = 0; i < 9; ++i) {
        if (board_value[i] != 'X' && board_value[i] != 'O') {
            return 0; 
        }
    }
    return 1; 
}

int game_over()
{
	setcolor(WHITE);
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
	if(board_value[0]=='X' && board_value[1]=='X' && board_value[2]=='X')//first hor. line
		{
			 
			line(70,170,715,170);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100, 250," GAME OVER : Player 1 win");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
		}
		if(board_value[3]=='X' && board_value[4]=='X' && board_value[5]=='X')//second hor. line
		{
			setcolor(WHITE);
			line(70,350,715,350);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 1 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[6]=='X' && board_value[7]=='X' && board_value[8]=='X')//third hor line
		{
				line(70,520,715,520);
				delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 1 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[0]=='X' && board_value[4]=='X' && board_value[8]=='X')//first cross line starting from left side
		{
			line(70,140,715,545);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 1 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[2]=='X' && board_value[4]=='X' && board_value[6]=='X')//second cross line starting from right side
		{
				line(90,530,700,150);
				delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 1 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[0]=='X' && board_value[3]=='X' && board_value[6]=='X')//first line ver. line
		{
			line(120,120,120,550);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 1 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[1]=='X' && board_value[4]=='X' && board_value[7]=='X')//second ver. line
		{
			line(390,120,390,550);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 1 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[2]=='X' && board_value[5]=='X' && board_value[8]=='X')//third ver. line
		{
			line(670,120,670,550);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 1 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
	
	
	
	
	if(board_value[0]=='O' && board_value[1]=='O' && board_value[2]=='O')//first hor. line
		{
			
			line(70,170,715,170);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 2 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[3]=='O' && board_value[4]=='O' && board_value[5]=='O')//second hor. line
		{
			setcolor(WHITE);
			line(70,350,715,350);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 2 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[6]=='O' && board_value[7]=='O' && board_value[8]=='O')//third hor line
		{
			line(70,520,715,520);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 2 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[0]=='O' && board_value[4]=='O' && board_value[8]=='O')//first cross line starting from left side
		{
			line(70,140,715,545);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 2 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[2]=='O' && board_value[4]=='O' && board_value[6]=='O')//second cross line starting from right side
		{
				line(90,530,700,150);
				delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 2 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[0]=='O' && board_value[3]=='O' && board_value[6]=='O')//first line ver. line
		{
			line(120,120,120,550);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 2 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[1]=='O' && board_value[4]=='O' && board_value[7]=='O')//second ver. line
		{
			line(390,120,390,550);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 2 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
		if(board_value[2]=='O' && board_value[5]=='O' && board_value[8]=='O')//third ver. line
		{
			line(670,120,670,550);
			delay(2000);
			cleardevice();
			setcolor(GREEN);
		outtextxy(100,250," GAME OVER : PLAYER 2 WIN ");
		delay(2000);
		while(1)
		{
			if(kbhit)
			{
				getch();
				break;
			}
		}
		exit(0);
		
	}
	
	
	int isDraw = checkDraw();
    if (isDraw) {
        cleardevice();
        setcolor(GREEN);
        outtextxy(100, 250, " GAME OVER : DRAW ");
        delay(2000);
        while (1) {
            if (kbhit) {
                getch();
                break;
            }
        }
        exit(0);
    }
	
	
	
		
	
	
}

int all()
{
		while(1)
	{
		main:
		print_line_board();
		board_values();
		players_turn();
		board_values();
		game_over();
		checkDraw();

	}
}

int players_turn()
{
    again:
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

    char display_text[100];
    if (turn == 'X') {
        snprintf(display_text, sizeof(display_text), "%s [X] turn: ", player1_name);
        outtextxy(180, 50, display_text);
    } else if (turn == 'O') {
        snprintf(display_text, sizeof(display_text), "%s [O] turn: ", player2_name);
        outtextxy(180, 50, display_text);
    }

    while (true) {
        if (kbhit()) {
            temp = getch();
            sprintf(for_value, "%c", temp);
            break;
        }
    }

    for (int i = 49, index = 0; i <= 59; i++, index++) {
        if (temp == i)
            temp = index;
    }

    switch (temp) {
        case 0: index_value = 0; break;
        case 1: index_value = 1; break;
        case 2: index_value = 2; break;
        case 3: index_value = 3; break;
        case 4: index_value = 4; break;
        case 5: index_value = 5; break;
        case 6: index_value = 6; break;
        case 7: index_value = 7; break;
        case 8: index_value = 8; break;
        default:
            setcolor(GREEN);
            outtextxy(10, 50, "Invalid Choice : ");
            break;
    }
    if (turn == 'X' && (board_value[index_value] != 'X' && board_value[index_value] != 'O')) {
        board_value[index_value] = 'X';
        turn = 'O';
    } else if (turn == 'O' && (board_value[index_value] != 'X' && board_value[index_value] != 'O')) {
        board_value[index_value] = 'O';
        turn = 'X';
    } else {
        cleardevice();
        setcolor(GREEN);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(150, 200, "Invalid Choice, Index Already Filled ");
        delay(1500);
        cleardevice();
        all();
    }
    cout << temp;
    cout << tr1;
}



int print_line_board()
{
	setcolor(GREEN);
	line(10,250,790,250);//first horizontal line
	line(10,440,790,440);//second horizontal line
	line(230,100,230,600);//first vertical line
	line(550,100,550,600);//second vertical line
	
}
int board_values()
{
	setcolor(14);
	int x{0},y{0};
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
	for(int i{0};i<=8;i++)
	{
			inc=inc+100;  
			sprintf(transfer_value,"%c",board_value[i]);//convert int array into char array
			if(i==0||(i==1||i==2))
			{
				if(i==0)
				x=100;
				else if(i==1)
				x=370;
				else if(i==2)
				x=650;
				outtextxy(x,150,transfer_value);//print char array
			}
			if(i==3||(i==4||i==5))
			{
				if(i==3)
				x=100;
				else if(i==4)
				x=370;
				else if(i==5)
				x=650;
				outtextxy(x,330,transfer_value);//print char array
	
			}
			if(i==6||(i==7||i==8))
			{
				if(i==6)
				x=100;
				else if(i==7)
				x=370;
				else if(i==8)
				x=650;
				outtextxy(x,500,transfer_value);
			}
			
	}
	
	
}
int loading_bar()
{
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 3/50);
	outtextxy(300,500,"LOADING...");
	rectangle(200,450,520,480);
	for(int i{0};i<=316;i++)
	{
		setcolor(BLUE);
		rectangle(202,452,202+i,478);
		delay(10);
	}	

}
int images()
{
	readimagefile("original.bmp",280,150,440,200);
	readimagefile("unnamed.bmp",220,210,500,440);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    initwindow(800, 600);
    images(); // for calling images tic tac and main image
   loading_bar(); // for calling loading bar and loading message
    cleardevice();
    menu();
   menu_option();
    cleardevice();
    while(1)
    {
        main:
        print_line_board();
        board_values();
        players_turn();
      board_values();
     game_over();
   }
}

