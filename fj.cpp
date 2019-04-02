#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int position_x,position_y; 
int bullet_x,bullet_y; 
int enemy_x,enemy_y; 
int high,width; 
int score;

void startup() 
{
	high = 20;
	width = 30;
	position_x = high/2;
	position_y = width/2;
	bullet_x = -2;
	bullet_y = position_y;
	enemy_x = 0;
	enemy_y = position_y;
	score = 0;
}

void show()  
{
	system("cls");   
	int i,j;
	for (i=0;i<high;i++)
	{
		for (j=0;j<width;j++)
		{
			if ((i==position_x) && (j==position_y))
				printf("*"); 
			else if ((i==enemy_x) && (j==enemy_y))
				printf("@"); 
			else if ((i==bullet_x) && (j==bullet_y))
				printf("|");  
			else
				printf(" ");  
		}
		printf("\n");
	}
	printf("µÃ·Ö£º%d\n",score);
}	

void updateWithoutInput()  
{	
	if (bullet_x>-1)
		bullet_x--; 

	if ((bullet_x==enemy_x) && (bullet_y==enemy_y))  
	{
		score++;                
		enemy_x = -1;           
		enemy_y = rand()%width;
		bullet_x = -2;         
	}
	if (enemy_x>high)   
	{
		enemy_x = -1;           
		enemy_y = rand()%width;
	}

	
	static int speed = 0;  
	if (speed<10)
		speed++;
	if (speed == 10)
	{
		enemy_x++;			
		speed = 0;
	}
}

void updateWithInput()  
{
	char input;
	if(kbhit())  
	{
		input = getch(); 
		if (input == 'A')   
			position_y--;  
		if (input == 'D')
			position_y++;  
		if (input == 'W')
			position_x--;  
		if (input == 'S')
			position_x++;  
		if (input == ' ')  
		{
			bullet_x = position_x-1;  
			bullet_y = position_y;
		}
		
	}
}

void main()
{
	startup();  	
	while (1) 
	{
		show();  
		updateWithoutInput();  
		updateWithInput();  
	}
}