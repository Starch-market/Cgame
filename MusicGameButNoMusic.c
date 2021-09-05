#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int score;
short int heart;
int sra1(int x)//随机数区间为[0,x]
{
	int result;
	srand((unsigned)time(NULL));
	result = rand() % (x++);
	return result;
}
int sra2(int a, int b)//随机数区间为[b,a+b-1]
{
	int result;
	srand((unsigned)time(NULL));
	result = rand() % a + b;
	return result;
}
int START()
{
	short int j = 1;
	char input;
	while (1)
	{
		system("cls");
		printf("                         #MUSIC GAME BUT NO MUSIC#\n                            -----------------\n");
		printf("                              Classic Mode");
		if (j == 1) printf("   @\n");
		else printf("\n");
		printf("                               Level Mode");
		if (j == 2) printf("    @\n");
		else printf("\n");
		printf("                               Custom Mode");
		if (j == 3) printf("  @\n");
		else printf("\n");
		printf("                              How To Play It");
		if (j == 4) printf(" @\n");
		else printf("\n");
		printf("\n\n\n\n                            -----------------\n");
		printf("                            |VERSION  1.5.0|\n                            |MADE BY STARCH|\n                            |  RUN BY BUG  |");
		input = getch();
		if (input == 13 && j<4) j++;
		else if (input == 13 && j == 4)
		{
			j = 1;
		}
		else if (input == ' ' && j == 1)
		{
			j = 1;
			score = 0;
			return 1;
		}
		else if (input == ' ' && j == 2)
		{
			j = 1;
			score = 0;
			return 2;
		}
		else if (input == ' ' && j == 3)
		{
			j = 1;
			score = 0;
			return 3;
		}
		else if (input == ' ' && j == 4)
		{
			return 4;
		}
	}
}
int HOW()
{
	system("cls");
	printf("基本：\n");
	printf("摁DFGHJK来得分\n");
	printf("若未扣中目标键则扣一心,并进行到下一个目标\n");
	printf("关于CUSTOM_MODE(即自定义模式)：\n");
	printf("要在同一等级路径上新建文本文档\n");
	printf("最多指定三个自定义关卡game1,game2,game3(新建的文本文档同样要如此命名\n");
	printf("在文件中编辑'j'即摁下J键得分，以'e'结尾\n");
	system("pause");
	return 4;
}
int E()
{
	system("cls");
	printf("哦，抱歉这里出错了哦\n");
	printf("我也不知道出什么情况了呢\n");
	printf("这里建议换台电脑或重装系统  :D\n");
	system("pause");
	printf("(JOKE)XD\n");
	system("pause");
}
int CLASSIC_MODE()
{
	short int k = 1, i,goal;
	char temp, input;
	heart = 3;
	score = 0;
	while (1)
	{
		system("cls");
		if (k == 1)
		{
			k--;
			heart = 3;
		}
		goal = sra2(6, 1);
		printf("\n\n\n\n\n\n\n				 Heart:%d Score:%d", heart, score);
		printf("\n				-----------------\n				");
		for (i = 0; i < 6; i++)
		{
			if ((i + 1) == goal)
			{
				printf("@@");
			}
			else
			{
				printf("##");
			}
			printf(" ");
			if (i == 5) printf("\n");
		}
		printf("				D |F |G |H |J |K |\n				-----------------");
		switch (goal)
		{
			case 1:temp = 'd'; break;
			case 2:temp = 'f'; break;
			case 3:temp = 'g'; break;
			case 4:temp = 'h'; break;
			case 5:temp = 'j'; break;
			case 6:temp = 'k'; break;
		}
		input = getch();
		if (input != temp)
		{
			heart--;
			if (heart <= 0)
			{
				system("cls");
				printf("\n\n\n\n\n\n                              You hava DEAD!\n");
				printf("                           Press '1' To Play Again.\n");
				printf("                           Press Other Key To Hub.\n");
				input = getch();
				if (input == '1')
				{
					heart = 3;
					return 1;//返回游戏
				}
				else
				{
					return 2;//大厅
				}
			}
		}
		else
		{
			score++;
		}
	}
}
int LEVEL_MODE()
{
	short int k = 1, j = 1, i, goal, level;
	int arr_1[7] = { 1, 2, 3, 4, 5, 6, 0 };
	int arr_2[36] = { 2, 3, 4, 6, 1, 1, 2, 5, 4, 3, 1, 5, 6, 4, 2, 1, 5, 4, 3, 6, 4, 5, 2, 1, 3, 6, 4, 5, 6, 4, 5, 6, 4, 5, 3, 0 };
	int level_bar = 0;
	char input, temp;
	LEVEL_START:
	while (1)
	{
		system("cls");
		printf("LEVEL 1");
		if (j == 1) printf(" @\n");
		else printf("\n");
		printf("LEVEL 2");
		if (j == 2) printf(" @\n");
		else printf("\n");
		printf("BACK");
		if (j == 3) printf("  @\n");
		else printf("\n");
		input = getch();
		if (input == 13 && j<3) j++;
		else if (input == 13 && j >= 3) j = 1;
		else if (input == ' ' && j == 1)
		{
			heart = 3;
			level_bar = 0;
			level = 1;
			goto LEVEL_GAME;
		}
		else if (input == ' ' && j == 2) 
		{
			heart = 3;
			level_bar = 0;
			level = 2;
			goto LEVEL_GAME;
		}
		else if(input==' ' && j==3) return 0;
	}
	LEVEL_GAME:
	while (1)
	{
		system("cls");
		switch (level)
		{
			case 1:goal = arr_1[level_bar]; break;
			case 2:goal = arr_2[level_bar]; break;
			case 3:return -1;
		}
		if (goal == 0) goto LEVEL_OVER_WIN;//--------------------TEMP----------------------
		else level_bar++;
		printf("\n\n\n\n\n\n\n				 Heart:%d Score:%d", heart, score);
		printf("\n				-----------------\n				");
		for (i = 0; i < 6; i++)
		{
			if ((i + 1) == goal)
			{
				printf("@@");
			}
			else
			{
				printf("##");
			}
			printf(" ");
			if (i == 5) printf("\n");
		}
		printf("				D |F |G |H |J |K |\n				-----------------");
		switch (goal)
		{
			case 1:temp = 'd'; break;
			case 2:temp = 'f'; break;
			case 3:temp = 'g'; break;
			case 4:temp = 'h'; break;
			case 5:temp = 'j'; break;
			case 6:temp = 'k'; break;
		}
		input = getch();
		if (input != temp)
		{
			heart--;
			if (heart <= 0)
			{
				goto LEVEL_OVER_LOSE;
			}
		}
		else
		{
			score++;
		}
	}
	LEVEL_OVER_WIN:
	while (1)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("                       You Are WINNIN In The Level!\n");
		printf("                     Prees '1' To Play This Level Again.\n");
		printf("                         Press Other Key To Back.\n");
		input = getch();
		if (input == 1)
		{
			heart = 3;
			level_bar = 0;
			goto LEVEL_GAME;
		}
		else goto LEVEL_START;
	}
	LEVEL_OVER_LOSE:
	while (1)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("                                 LOSER!\n");
		printf("                       Press '1' To Play Again.\n");
		printf("                       Press Other Key To Back.\n");
		input = getch();
		if (input == 1)
		{
			heart = 3;
			goto LEVEL_GAME;
		}
		else goto LEVEL_START;
	}
}
int CUSTOM_MODE()
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	FILE *fp3 = NULL;
	fp1 = fopen("game1.txt", "r");
	fp2 = fopen("game2.txt", "r");
	fp3 = fopen("game3.txt", "r");
	short int k = 1, i, j = 1, temp = 0;
	char input, goal;
	heart = 3;
	score = 0;
	CUSTOM_START:
	while (1)
	{
		system("cls");
		printf("CUSTOM_1");
		if (j == 1) printf(" @\n");
		else printf("\n");
		printf("CUSTOM_2");
		if (j == 2) printf(" @\n");
		else printf("\n");
		printf("CUSTOM_3");
		if (j == 3) printf(" @\n");
		else printf("\n");
		printf("BACK");
		if (j == 4) printf(" @\n");
		else printf("\n");
		input = getch();
		if (j<4 && input == 13) j++;
		else if (j >= 4 && input == 13) j = 0;
		else if (j == 1 && input == ' ') goto CUSTOM_GAME;
		else if (j == 2 && input == ' ') goto CUSTOM_GAME;
		else if (j == 3 && input == ' ') goto CUSTOM_GAME;
		else if (j == 4 && input == ' ') return 0;
	}
	CUSTOM_GAME:
	while (1)
	{
		system("cls");
		if (k == 1)
		{
			k--;
			heart = 3;
		}
		if (j == 1) goal = fgetc(fp1);
		else if (j == 2) goal = fgetc(fp2);
		else if (j == 3) goal = fgetc(fp3);
		else return -1;
		if (goal == 'e') goto CUSTOM_WIN;
		printf("\n\n\n\n\n\n\n				 Heart:%d Score:%d", heart, score);
		printf("\n				-----------------\n				");
		switch (goal)
		{
			case'd':temp = 1; break;
			case'f':temp = 2; break;
			case'g':temp = 3; break;
			case'h':temp = 4; break;
			case'j':temp = 5; break;
			case'k':temp = 6; break;
		}
		for (i = 0; i < 6; i++)
		{
			if ((i + 1) == temp)
			{
				printf("@@");
			}
			else
			{
				printf("##");
			}
			printf(" ");
			if (i == 5) printf("\n");
		}
		printf("				D |F |G |H |J |K |\n				-----------------");
		input = getch();
		if (input == goal)
		{
			score++;
		}
		else
		{
			heart--;
			if (heart <= 0)
			{
				goto CUSTOM_LOSE;
			}
		}
	}
	CUSTOM_WIN:
	while (1)
	{
		system("cls");
		printf("\n\n\n\n\n\n                              You Are The Winer!\n");
		printf("                           Press '1' To Play Again.\n");
		printf("                           Press Other Key To Hub.\n");
		input = getch();
		if (input == '1')
		{
			heart = 3;
			if (j == 1) goal = fclose(fp1);
			else if (j == 2) goal = fclose(fp2);
			else if (j == 3) goal = fclose(fp3);
			goto CUSTOM_GAME;//返回游戏
		}
		else
		{
			if (j == 1) goal = fclose(fp1);
			else if (j == 2) goal = fclose(fp2);
			else if (j == 3) goal = fclose(fp3);
			goto CUSTOM_START;//大厅
		}
	}
	CUSTOM_LOSE:
	while (1)
	{
		system("cls");
		system("cls");
		printf("\n\n\n\n\n\n                                LOSER!\n");
		printf("                           Press '1' To Play Again.\n");
		printf("                           Press Other Key To Hub.\n");
		input = getch();
		if (input == '1')
		{
			heart = 3;
			if (j == 1) goal = fclose(fp1);
			else if (j == 2) goal = fclose(fp2);
			else if (j == 3) goal = fclose(fp3);
			goto CUSTOM_GAME;//返回游戏
		}
		else
		{
			if (j == 1) goal = fclose(fp1);
			else if (j == 2) goal = fclose(fp2);
			else if (j == 3) goal = fclose(fp3);
			goto CUSTOM_START;//大厅
		}
	}
}
void main()
{
	short int sys = 1;
	short int CL_i, LE_i, CU_i;
	MAIN:
	while (1)
	{
		sys = START();
		if (sys == 1)
		{
			while (1)
			{
				CL_i = CLASSIC_MODE();
				if (CL_i == 1) continue;
				else if (CL_i == 2) goto MAIN;
			}
		}
		else if (sys == 2)
		{
			while (1)
			{
				LE_i = LEVEL_MODE();
				if (LE_i == 0) goto MAIN;
				else if (LE_i == -1) E();
			}
		}
		else if (sys == 3)
		{
			while (1)
			{
				CU_i = CUSTOM_MODE();
				if (CU_i == 0) goto MAIN;
				else if (CU_i == -1) E();
			}
		}
		else if (sys == 4)
		{
			HOW();
		}
	}
}
