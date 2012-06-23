/*** James Donner 6/23/12 ***
 *** Tic Tac Toe game from course in C prog 94/95ish ***
 *** #include<graph.h> no longer avail for graphics ***/

#include<stdio.h>

void instructions(void);
void drawBoard(void);
void initialize(void);
void getusermove(void);
void computermove(void);
int checkifwon(char);
int winpossible(char);
//void drawX(int row,int column,int backcolor);
//void drawO(int row, int column,int backcolor);
//void drawgrid(void);

char tictac[3][3];

main()
{
int count;
char playagain;

instructions();

while(1)
{
  //paintscreen(1);
  //drawgrid(); 
  initialize();  // Clear board '-'
  getusermove(); 
  computermove();
  drawBoard(); 

  count = 2;
  do
  {
    getusermove();
    drawBoard();
    printf("-----------------\n");

    count++;
    if (checkifwon('X') == 1)  {
        printf("X wins\n");
        drawBoard();
        break;
        }
    else 
      if (winpossible('O') == 1) {
  	     //drawO(10,38,0);  /* if won draw O and tell user O wins */
         printf("O WINS\n");
         drawBoard();
         break;
      }
    else 
      if (winpossible('X') == 0) {  
         /* if opponent does not have to be blocked make move */
         computermove();           
      }
    count++;
    drawBoard();
  }
  while (count < 9);  /* end while loop */

  //_settextposition(24,1);
  printf("Play again (y n) ==> ");
  scanf(" %c",&playagain);

  if (playagain != 'y' && playagain != 'Y')
      break;   /* end game ? */
  }
}


void instructions(void)
{
  char dummy;

  printf("\n\tWELCOME to the Tic Tac Toe game");
  printf("\n\tYou will play X and I will play O ");
  printf("\n\tthe board is arranged as follows");
  printf("\n\n\t            COLUMN");
  printf("\n\t          1   2   3");
  printf("\n\t       1  -   -   -");
  printf("\n\t  ROW  2  X   -   -");
  printf("\n\t       3  -   -   O");
  printf("\n\n\t  O is at ROW 3 COLUMN 3");
  printf("\n\t  X is at ROW 2 COLUMN 1");
  printf("\n\tYou will prompted to enter a row # and a column # ");
  printf("\n\tPress any key to begin => ");
  dummy = getchar();
}

/****************************8
void drawgrid(void)
{
int i,row;

row = 2;
 _settextposition(row,33);    //draw 1st vertical line 
 _setbkcolor(5);
     for (i=0;i<17;i++) {
       _settextposition(row++,33);
       _outtext("  ");  }
row = 2;
 _settextposition(row,46);
    for (i=0;i<17;i++) {
       _settextposition(row++,46);  // draw 2nd vertical line 
       _outtext("  ");  }

 _settextposition(7,22);
     for(i=0;i<36; i++)
       _outtext(" ");   // draw 1st horizontal line 
 _settextposition(13,22);
     for(i=0;i<36; i++)
       _outtext(" ");   // draw 2nd horizontal line 
}


void drawX(int row,int column,int backcolor)
{
 int i,j;
   _setbkcolor(backcolor);
   _settextposition(row,column);   // procedure to draw x 
      for (i=0;i<5;i++)            // row and column are passed to it 
      {                            // for set textposition 
	  for(j=0;j<5; j++)        // backcolor for color 
	  {
	   _settextposition(row+i,column+j);
	   if(i==j)
	      _outtext("  ");
	   else if (i == 4 - j)
	       _outtext("  ");
	  }
      }
}

void drawO (int row, int col,int backcolor)
{
 int i;

    if(row == 0)
       if(col == 0) {
	  row = 2;  col = 24;  }
       else if (col == 1) {
	  row = 2; col = 37; }
       else if (col == 2)  {
	  row = 2;   col = 50;  }
       else;
     if (row == 1)
	 if (col == 0) {
	    row =8;  col =24;  }
	 else if (col == 1) {
	     row = 8; col = 37;  }
	 else if (col == 2)  {
	     row = 8;  col = 50;  }
	 else;
     if (row ==2)
	  if (col == 0) {
	      row =14;   col = 24;  }
	  else if (col ==1)  {
	      row =14; col = 37;  }
	  else if (col == 2)  {
	      row =14; col =50;
	      }
	  else;

    _setbkcolor(backcolor);
    _settextposition(row,col);
    _outtext("      ");            // horiz 1 
       for (i=0;i<5;i++)   {
	  _settextposition(row+i,col);     //vert 1 
	  _outtext("  ");  }

       for(i =0; i<5; i++) {                   // vert 2 
	  _settextposition(row+i,col+6);
	  _outtext("  ");  }
    _settextposition(row+4,col);
    _outtext("      ");             // horizon 2 _  O done 
}

**************************/


void drawBoard() 
{
  int i, j;

  for (i=0;i<3;i++) {
    for(j=0;j<3;j++)
        printf("%c\t", tictac[i][j]);
    printf("\n\n\n");   
  }   
}



void initialize(void)
{
  int i, j;

  for (i=0;i<3;i++)   /* set elements = to dash - */
    for(j=0;j<3;j++)
	      tictac[i][j] = '-';
}



void getusermove(void)
{
  int row,col;

  while (1)   /* while invalid move loop back and get new move */
  {
     printf("\n");
     printf("Enter row # ==> ");
     scanf("%d",&row);
     printf("\nEnter column # ==> ");
     scanf("%d",&col);
     if (row <= 3 && row >= 1 && col <= 3 && col >= 1 && tictac[--row][--col] == '-')
  	     break;  /* if valid entry && array cell empty stop reading */
  }   /* end loop */

  tictac[row][col] = 'X';  /* make move for 'X' */

  /******
      if (row == 0)
         if (col == 0)
  	  drawX(2,24,6);
         else if(col ==1)
  	  drawX(2,37,6);
         else if(col == 2)   // print X on screen 
  	  drawX(2,50,6);
         else; else;
      if (row == 1)
  	if (col == 0)
  	   drawX(8,24,6);
  	else if (col == 1)
  	   drawX(8,37,6);
  	else if (col ==2)
  	   drawX(8,50,6);
  	else;   else;
       if (row == 2)
  	 if (col == 0)
  	    drawX(14,24,6);
  	 else if (col == 1)
  	    drawX(14,37,6);
  	 else if (col == 2)
  	    drawX(14,50,6);
  	  else; else;
   ****************/
}

void computermove(void)  /* if no win or block make a move */
{
  if(tictac[2][1] == 'X' && tictac [1][2] =='X' && tictac[2][2] == '-') {
      tictac[2][2] = 'O';
     // drawO(2,2,2);
  }
  else if(tictac[1][1] == '-')  {
      tictac[1][1] = 'O';
      // drawO(1,1,2);         
  }
  else if(tictac[0][0] == '-' && (tictac[0][2] != 'X' || tictac[2][0] != 'X'))  {
      tictac[0][0] = 'O';
      // drawO(0,0,2);              
  }
  else if (tictac[2][2] == '-' && (tictac[0][2] !='X' || tictac[2][0] !='X'))   {
	    tictac[2][2] = 'O';
	    //drawO(2,2,2);       
  }
  else if (tictac[2][0] == '-'&& (tictac[0][0] != 'X' || tictac[2][2] != 'X')) {
	    tictac[2][0] = 'O';
	    //drawO(2,0,2);         
  }
  else if (tictac[0][2] == '-' && (tictac[0][0] !='X' || tictac[2][2] !='X')) {
	    tictac[0][2] = 'O';
      // drawO(0,2,2);            
  }
  else if (tictac[1][0] == '-') {
	    tictac[1][0] = 'O';
      // drawO(1,0,2);    
  }
  else if (tictac[2][1] == '-') {
	     tictac[2][1] = 'O';
	     // drawO(2,1,2);    
  }
  else if (tictac[1][2] == '-') {
	     tictac[1][2] = 'O';
	     // drawO(1,2,2);    
  }
  else if (tictac[0][1] == '-')  {
	     tictac[0][1] = 'O';
	     // drawO(0,1,2);    
  }
  else
	     printf("TIE GAME\n");

}


int checkifwon(char letter)
{
  int i, j, winner = 0;   /* did someone win ? */

  for (i=0; i<3; i++)
    if (tictac[i][0]==letter && tictac[i][1]==letter && tictac[i][2]==letter)
        winner = 1;

  for (j=0;j<3;j++)
    if(tictac[0][j]==letter && tictac[1][j]==letter && tictac[2][j]==letter)
       winner = 1;

  if(tictac[0][0]==letter && tictac[1][1]==letter && tictac[2][2]==letter)
     winner = 1;
  if(tictac[0][2]==letter && tictac[1][1]==letter && tictac[2][0] == letter)
     winner = 1;

  return (winner);
}

int winpossible(char letter)
{
  int row,col;

  for(row =0; row<3; row++)
  {
	  for(col=0; col<3; col++)
	  {
	    if (tictac[row][col] == '-')
		  {
		    tictac[row][col] = letter;
		    if(checkifwon(letter) == 0)
		       tictac[row][col] = '-';
		    else
		    {
		       tictac[row][col] = 'O';
		       // drawO(row,col,2);
		       return (1);
		    }
		  }
  	}
  } 

  return(0);
}
