#include <iostream>
#include<string.h>
using namespace std;
class player
{
private:
	char symbol;
	string name;
public:
	player()
	{
		symbol = ' ';
		name = "Unnamed";
	}
	player(char sym, string nm)
	{
		symbol = sym;
		name = nm;
	}
	char getsymbol() const
	{
		return symbol;
	}
	string getname() const
	{
		return name;
	}
};
class board
{
private:
	char game[3][3];
	int occupiedcells;
public:
	board()
	{
		occupiedcells=0;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{
				game[i][j]=' ';
			}
		}
	}
	void drawboard() const
	{
		cout<<"-------------\n";
		for(int i=0; i<3; i++)
		{
			cout<<"|";
			for(int j=0; j<3; j++)
			{
				cout<<game[i][j]<<" | ";
			}
			cout<<"\n";
			cout<<"-------------\n";
		}
	}
	void reset()
	{
		occupiedcells = 0;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				game[i][j] = ' ';
			}
		}
	}

	bool validmove(int row,int col) const
	{
		return((row<3)&&(row>=0)&&(col<3)&&(col>=0)&&(game[row][col]==' '));
	}
	void makemove(int row,int col,char symbol)
	{
		if(validmove(row,col)) {
			game[row][col]=symbol;
			occupiedcells++;
		}
	}
	bool checkingwin(char symbol)
	{
		for(int i=0; i<3; i++) {
			if(game[i][0]==symbol&&game[i][1]==symbol&&game[i][2]==symbol)
			{
				return true;
			}
		}
		for(int i=0; i<3; i++)
		{
			if(game[0][i]==symbol&&game[1][i]==symbol&&game[2][i]==symbol)
			{
				return true;
			}
		}
		if(game[0][0]==symbol&&game[1][1]==symbol&&game[2][2]==symbol)
		{
			return true;
		}
		if(game[0][2]==symbol&&game[1][1]==symbol&&game[2][0]==symbol)
		{
			return true;
		}
		return false;
	}
	bool full() const
	{
		return occupiedcells==9;
	}
	int cellscount() const
	{
		return occupiedcells;
	}
};

class tictactoegame
{
	player players[2];
	board gameboard;
	int playerindex;
public:
	tictactoegame():playerindex(0)
	{
		players[0]=player('X',"Player X");
		players[1]=player('O',"Player O");
	}
	player& currentplayer()
	{
		return players[playerindex];
	}
	void changeturn()
	{
		playerindex=(playerindex+1)%2;
	}
	void gameplay()
	{
		gameboard.reset();
		int row,col;
		cout<<"|| WELCOME TO THE TICTACTOE GAME ||\n";
		while(!gameboard.full())
		{
			gameboard.drawboard();
			player& currentplayer1=currentplayer();
			while(true) {
				cout<<currentplayer1.getname()<<" {"<<currentplayer1.getsymbol()<<"}\n";
				while (true) {
					cout << "Enter row {1-3} = ";
					if (cin >> row && row >= 1 && row <= 3) {
						break;
					} else {
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Invalid input! Please enter a number between 1 and 3.\n";
					}
				}
				while (true) {
					cout << "Enter column {1-3} = ";
					if (cin >> col && col >= 1 && col <= 3) {
						break;
					} else {
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Invalid input! Please enter a number between 1 and 3.\n";
					}
				}
				row--;
				col--;
				if(gameboard.validmove(row,col))
				{
					break;
				}
				else
				{
					cout<<"invlid entry!!! TRY AGAIN\n";
				}
			}
			gameboard.makemove(row,col,currentplayer1.getsymbol());
			if(gameboard.checkingwin(currentplayer1.getsymbol())) {
				gameboard.drawboard();
				cout<<currentplayer1.getname()<<" wins!!\n";
				return;
			}
			changeturn();
		}
		gameboard.drawboard();
		cout<<"ITS A DRAW TRY AGAIN!!!!\n\n";
	}
};
int main()
{
	tictactoegame gameobj;
	char ch='y';
	while(ch=='y'||ch=='Y') {
		gameobj.gameplay();
		cout<<"enter Y to play again=";
		cin>>ch;
	}
}