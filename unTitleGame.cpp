#include<iostream>
#include<conio.h>

using namespace std;

const int coordinateX = 30;
const int coordinateY = 18;
isGameOver = false;

int i, j;

int scorePlayer1th = 0;
int scorePlayer2nd = 0;

bool isGameOver;
bool isChosen;

int count = 1;

enum keyboard { UP, DOWN, LEFT, RIGHT, STOP };

keyboard pointerMoving;

int pointerX = coordinateX / 2;
int pointerY = coordinateY / 2;

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'W':
		case'w':
			pointerMoving = UP;
			break;
		case 'S':
		case's':
			pointerMoving = DOWN;
			break;
		case 'A':
		case'a':
			pointerMoving = LEFT;
			break;
		case 'D':
		case'd':
			pointerMoving = RIGHT;
			break;
		case 'X':
		case'x':
			pointerMoving = STOP;
			break;
		default:
			break;
		}
	}
}

void logic()
{
	switch (pointerMoving)
	{
	case UP:
		pointerY -= 3;
		break;
	case DOWN:
		pointerY += 3;
		break;
	case LEFT:
		pointerX -= 5;
		break;
	case RIGHT:
		pointerX += 5;
		break;
	case STOP:
		isGameOver = true;
	default:
		break;
	}
	if (pointerX==coordinateX){
	  if (pointerY == coordinateY || pointerY == 0){
	  isGameOver = true;
	  }
	}
	else if (pointerY == coordinateY){
	 if (pointerX == coordinateX || pointerX==0)
		 isGameOver = true;
	}
}

void draw()
{
	system("cls");
	for (i = 0; i <= coordinateX; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (i = 0; i < coordinateY; i++)
	{
		for (j = 0; j <= coordinateX; j++)
		{
			if ((j == 0 || j == 10 || j == 20 || j == coordinateX) || (i == 6 || i == 12 || i == 18)) cout << "#";
			else if (i == pointerY && j == pointerX) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}

	for (i = 0; i <= coordinateX; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "       " << "Player One\t" << "Player Two" << endl
		<< "Score:     " << scorePlayer1th <<"                 "<< scorePlayer2nd << endl;

}

int main()
{
	draw();
	while (!isGameOver)
	{
		input();
		logic();
	}
	_getch();
	return 0;
}
