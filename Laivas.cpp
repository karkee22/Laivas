#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int y, x2, y2;
char x;
bool gameover;
enum eDirection { LEFT, RIGHT, UP, DOWN };
eDirection dir;
void input()
{
	switch (_getch())
	{
	case 'a':
		dir = LEFT;
		break;
	case 'd':
		dir = RIGHT;
		break;
	case 'w':
		dir = UP;
		break;
	case 's':
		dir = DOWN;
		break;
	}
}

void put()
{
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
}

class lentac;

class laivas
{
protected:
	vector <int> length{ 4, 3, 2, 2, 1, 1, 1, 1 };
	vector <vector <int>> boatrow;
	vector <vector <int>> boatcol;
public:
	bool statytil(int i)
	{
			int lth = length.at(i);
			vector <int> brow;
			vector <int> bcol;
			cout << "Iveskite " << lth << " dydzio laivo priekio koordinates" << endl;
			cin >> x >> y;
			cout << "Iveskite krypti, kuria statysit laiva" << endl;
			input();
			system("cls");
			while (lth > brow.size())
			{
				if ((9 - ('j' - x) <= 9) && (9 - ('j' - x) >= 0))
					bcol.push_back(9 - ('j' - x));
				else
				{
					bcol.clear();
					brow.clear();
					x = ' ';
					return 0;
					break;
				}
				if ((y <= 9) && (y >= 0))
					brow.push_back(y);
				else
				{
					y = -1;
					bcol.clear();
					brow.clear();
					return 0;
					break;
				}
				put();
			}
			length.at(i) = lth;
			boatrow.push_back(brow);
			boatcol.push_back(bcol);
			return 1;
	}
};

class lenta : public laivas
{
private:
	int board[10][10];	
public:
	int gautiboard(int xx, int yy) { return board[xx][yy]; }
	void keistiboard(int xx, int yy) { board[xx][yy] = 9; }
	void keistiboardmiss(int xx, int yy) { board[xx][yy] = -1; }
	void keistiboardtoo(int xx, int yy) { board[xx][yy] = -2; }
	void laivupalikimas()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (board[i][j] == 5)
					board[i][j] = 0;

			}
		}
	}
	void showboard()
	{
			cout << "  " << "a" << " " << "b" << " " << "c" << " " << "d" << " " << "e" << " " << "f" << " " << "g" << " " << "h" << " " << "i" << " " <<"j" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i << " ";
			for (int j = 0; j < 10; j++)
			{
				if ((board[i][j] >= 1) && (board[i][j] <= 4))
					cout << "@ ";
				else if (board[i][j] == 9)
					cout << "X ";
				else if (board[i][j] == -1)
					cout << "~ ";
				else 
					cout << ". ";
			}
			cout << endl;
		}
	}
	bool tikrinti(int i)
	{
		int laik=0;
		{
			for (int j = 0; j < laivas::length.at(i); j++)
			{
				{
					if ((board[laivas::boatrow.at(i).at(j)][laivas::boatcol.at(i).at(j)] < 1) || (board[laivas::boatrow.at(i).at(j)][laivas::boatcol.at(i).at(j)] >5))
						laik++;
				}
			}
		}
		if (laik == laivas::length.at(i))
		    return 1;
		else
		{
			laivas::boatrow.erase(laivas::boatrow.begin()+i);
			laivas::boatcol.erase(laivas::boatcol.begin()+i);
			return 0;
		}
	}
	void board1(int i)
	{
		for (int j = 0; j < laivas::length.at(i); j++)
		{
			board[laivas::boatrow.at(i).at(j)][laivas::boatcol.at(i).at(j)] = laivas::length.at(i);
			for (int jj = -1; jj <=1; jj++)
			{
				for (int jjj = -1; jjj <=1; jjj++)
				{
					if ((laivas::boatrow.at(i).at(j)+jj>=0)&&(laivas::boatrow.at(i).at(j) + jj <= 9)&& (laivas::boatcol.at(i).at(j) + jjj >= 0) && (laivas::boatcol.at(i).at(j) + jjj <= 9))
					{
						if ((board[laivas::boatrow.at(i).at(j)+jj][laivas::boatcol.at(i).at(j) + jjj] <1)||(board[laivas::boatrow.at(i).at(j) + jj][laivas::boatcol.at(i).at(j) + jjj] >4))
							board[laivas::boatrow.at(i).at(j)+jj][laivas::boatcol.at(i).at(j) + jjj] = 5;
					}
				}
			}

		}
		
	}
};

class laivasc
{
protected:
	vector <int> lengthc{ 4, 3, 2, 2, 1, 1, 1, 1};
	vector <vector <int>> boatrowc;
	vector <vector <int>> boatcolc;
public:
	bool statytilc(int i)
	{
		int lthc = lengthc.at(i);
		vector <int> browc;
		vector <int> bcolc;
		int kryptis;
		x2 = 1+rand()%10;
		y2 = 1+rand()%10;
		kryptis = 1 + rand() % 4;
		while (lthc > browc.size())
		{
			if ((x2 <= 9) && (x2 >= 0))
				bcolc.push_back(x2);
			else
			{
				bcolc.clear();
				browc.clear();
				return 0;
				break;
			}
			if ((y2 <= 9) && (y2 >= 0))
				browc.push_back(y2);
			else
			{
				bcolc.clear();
				browc.clear();
				return 0;
				break;
			}
			if (kryptis == 1)
				x2++;
			else if (kryptis == 2)
				x2--;
			else if (kryptis == 3)
				y2++;
			else y2--;
		}
		lengthc.at(i) = lthc;
		boatrowc.push_back(browc);
		boatcolc.push_back(bcolc);
		return 1;
	}
};

class lentac : public laivasc
{
private:
	int boardc[10][10];
public:
	int gautiboardc(int xxc, int yyc) { return boardc[xxc][yyc]; }
	void keistiboardc(int xxc, int yyc) { boardc[xxc][yyc] = 9;}
	void keistiboardcmiss(int xx, int yy) { boardc[xx][yy] = -1; }
	void laivupalikimasc()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (boardc[i][j] == 5)
					boardc[i][j] = 0;

			}
		}
	}
	void showboardc()
	{
		cout << "  " << "a" << " " << "b" << " " << "c" << " " << "d" << " " << "e" << " " << "f" << " " << "g" << " " << "h" << " " << "i" << " " << "j" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << i << " ";
			for (int j = 0; j < 10; j++)
			{
			    if (boardc[i][j] == 9)
					cout << "X ";
				else if (boardc[i][j] == -1)
					cout << "~ ";
				else
					cout << ". ";
			}
			cout << endl;
		}
	}
	bool tikrintic(int i)
	{
		int laikc = 0;
		{
			for (int j = 0; j < laivasc::lengthc.at(i); j++)
			{
				{
					if ((boardc[laivasc::boatrowc.at(i).at(j)][laivasc::boatcolc.at(i).at(j)] < 1)||(boardc[laivasc::boatrowc.at(i).at(j)][laivasc::boatcolc.at(i).at(j)] > 5))
						laikc++;
				}
			}
		}
		if (laikc == laivasc::lengthc.at(i))
			return 1;
		else
		{
			laivasc::boatrowc.erase(laivasc::boatrowc.begin() + i);
			laivasc::boatcolc.erase(laivasc::boatcolc.begin() + i);
			return 0;
		}
	}
	void board1c(int i)
	{
		for (int j = 0; j < laivasc::lengthc.at(i); j++)
		{
			boardc[laivasc::boatrowc.at(i).at(j)][laivasc::boatcolc.at(i).at(j)] = laivasc::lengthc.at(i);
			for (int jj = -1; jj <= 1; jj++)
			{
				for (int jjj = -1; jjj <= 1; jjj++)
				{
					if ((laivasc::boatrowc.at(i).at(j) + jj >= 0) && (laivasc::boatrowc.at(i).at(j) + jj <= 9) && (laivasc::boatcolc.at(i).at(j) + jjj >= 0) && (laivasc::boatcolc.at(i).at(j) + jjj <= 9))
					{
						if ((boardc[laivasc::boatrowc.at(i).at(j) + jj][laivasc::boatcolc.at(i).at(j) + jjj] <1)|| (boardc[laivasc::boatrowc.at(i).at(j) + jj][laivasc::boatcolc.at(i).at(j) + jjj] >4))
							boardc[laivasc::boatrowc.at(i).at(j) + jj][laivasc::boatcolc.at(i).at(j) + jjj] = 5;
					}
				}
			}

		}

	}
};


void setup()
{
	gameover = false;
}


void ataka(lentac *lentc, lenta *lent, int *du, int *trys, int *keturi, int *sunaikintip);
void atakac(lentac *lentc, lenta *lent, int *duc, int *trysc, int *keturic, int *sunaikintic, int *laik, int *xc, int *yc, char *kryptis)
{
	if (*laik == -1)
	{
		do {
			*xc = rand() % 10;
			*yc = rand() % 10;
		} while ((lent->gautiboard(*yc, *xc) == 9) || (lent->gautiboard(*yc, *xc) == -1) || ((lent->gautiboard(*yc, *xc) == -2)));
        
		if (lent->gautiboard(*yc, *xc) == 0)
		{
			lent->keistiboardmiss(*yc, *xc);
		}

		else if (lent->gautiboard(*yc, *xc) == 1)
		{
			lent->keistiboard(*yc, *xc);
			for (int i = *yc - 1; i <= *yc + 1; i++)
			{
				for (int j = *xc - 1; j <= *xc + 1; j++)
				{
					if ((i <= 9) && (i >= 0) && (j <= 9) && (j >= 0))
					{
						if((lent->gautiboard(i, j) != 9) && (lent->gautiboard(i, j) != -1))
						lent->keistiboardtoo(i, j);
					}
				}
			}
			*sunaikintic = *sunaikintic + 1;
		}
		else if (lent->gautiboard(*yc, *xc) == 2)
		{
			lent->keistiboard(*yc, *xc);
			if ((*xc + 1 <= 9) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc + 1) != -1))
				lent->keistiboardtoo(*yc + 1, *xc + 1);
			if ((*xc - 1 >= 0) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc - 1) != -1))
				lent->keistiboardtoo(*yc - 1, *xc - 1);
			if ((*xc + 1 <= 9) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc + 1) != -1))
				lent->keistiboardtoo(*yc - 1, *xc + 1);
			if ((*xc - 1 >= 0) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc - 1) != -1))
				lent->keistiboardtoo(*yc + 1, *xc - 1);
			*laik = *laik + 1;
			*duc = *duc + 1;
		}
		else if (lent->gautiboard(*yc, *xc) == 3)
		{
			lent->keistiboard(*yc, *xc);
			if ((*xc + 1 <= 9) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc + 1) != -1))
				lent->keistiboardtoo(*yc + 1, *xc + 1);
			if ((*xc - 1 >= 0) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc - 1) != -1))
				lent->keistiboardtoo(*yc - 1, *xc - 1);
			if ((*xc + 1 <= 9) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc + 1) != -1))
				lent->keistiboardtoo(*yc - 1, *xc + 1);
			if ((*xc - 1 >= 0) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc - 1) != -1))
				lent->keistiboardtoo(*yc + 1, *xc - 1);
			*laik = *laik + 1;
			*trysc = *trysc + 1;
		}
		else if (lent->gautiboard(*yc, *xc) == 4)
		{
			lent->keistiboard(*yc, *xc);
			if ((*xc + 1 <= 9) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc + 1) != -1))
				lent->keistiboardtoo(*yc + 1, *xc + 1);
			if ((*xc - 1 >= 0) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc - 1) != -1))
				lent->keistiboardtoo(*yc - 1, *xc - 1);
			if ((*xc + 1 <= 9) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc + 1) != -1))
				lent->keistiboardtoo(*yc - 1, *xc + 1);
			if ((*xc - 1 >= 0) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc - 1) != -1))
				lent->keistiboardtoo(*yc + 1, *xc - 1);
			*laik = *laik + 1;
			*keturic = *keturic + 1;
		}
	}
	else if(*laik==0)
	{  
		int brk=0;
		
		for (int i = *yc - 1; i <= *yc + 1; i++)
		{
			for (int j = *xc - 1; j <= *xc + 1; j++)
			{
				if ((i >= 0) && (i <= 9) && (j >= 0) && (j <= 9) && (lent->gautiboard(i, j) != -2) && (lent->gautiboard(i, j) != -1))
				{
					if ((*xc==0) && (*kryptis == 'x'))
					{
						*xc = *xc + *trysc + *keturic - 1;
					}
					else if ((*yc == 0) && (*kryptis == 'y'))
					{
						*yc = *yc + *trysc + *keturic - 1;
					}
					else if ((*xc == 9) && (*kryptis == 'x'))
					{
						*xc = *xc - *trysc - *keturic + 1;
					}
					else if ((*yc == 9) && (*kryptis == 'y'))
					{
						*yc = *yc - *trysc - *keturic + 1;
					}
					if (lent->gautiboard(i, j) == 2)
					{
						lent->keistiboard(i, j);
						for (int ii = *yc - 1; ii <= *yc + 1; ii++)
						{
							for (int jj = *xc - 1; jj <= *xc + 1; jj++)
							{
								if ((ii >= 0) && (ii <= 9) && (jj >= 0) && (jj <= 9) && (lent->gautiboard(ii, jj) != 9) && (lent->gautiboard(ii, jj) != -1))
								{
									lent->keistiboardtoo(ii, jj);
								}
							}
						}

						for (int ii = i - 1; ii <= i + 1; ii++)
						{
							for (int jj = j - 1; jj <= j + 1; jj++)
							{
								if ((ii >= 0) && (ii <= 9) && (jj >= 0) && (jj <= 9) && (lent->gautiboard(ii, jj) != 9) && (lent->gautiboard(ii, jj) != -1))
								{
									lent->keistiboardtoo(ii, jj);
								}
							}
						}
						*sunaikintic = *sunaikintic + 1;
						brk = 1;
						*laik = -1;
					}
				    else if (((lent->gautiboard(i, j) == 0) || (lent->gautiboard(i, j) == -1)) && (*kryptis=='x'))
					{
						if (lent->gautiboard(i, j + 1) == 9)
						{
							lent->keistiboardmiss(i, j);
							*xc = *xc + *trysc + *keturic - 1;
							brk = 1;
							break;
						}
						else
						{
							lent->keistiboardmiss(i, j);
							*xc = *xc - *trysc - *keturic + 1;
							brk = 1;
							break;
						}
					}
					else if (((lent->gautiboard(i, j) == 0) || (lent->gautiboard(i, j) == -1)) && (*kryptis == 'y'))
					{

						if (lent->gautiboard(i+1, j) == 9)
						{
							lent->keistiboardmiss(i, j);
							*yc = *yc + *trysc + *keturic - 1;
							brk = 1;
							break;
						}
						else
						{
							lent->keistiboardmiss(i, j);
							*yc = *yc - *trysc - *keturic + 1;
							brk = 1;
							break;
						}
					}
					else if (lent->gautiboard(i, j) == 0)
					{
						lent->keistiboardmiss(i, j);
						brk = 1;
						break;
					}
					else if (lent->gautiboard(i, j) == 3)
					{
						lent->keistiboard(i, j);
						if ((*yc > i) || (*yc < i))
							*kryptis = 'y';
						else if ((*xc > j) || (*xc < j))
							*kryptis = 'x';
						*xc = j; *yc = i;
						if ((*xc + 1 <= 9) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc + 1) != -1))
							lent->keistiboardtoo(*yc + 1, *xc + 1);
						if ((*xc - 1 >= 0) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc - 1) != -1))
							lent->keistiboardtoo(*yc - 1, *xc - 1);
						if ((*xc + 1 <= 9) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc + 1) != -1))
							lent->keistiboardtoo(*yc - 1, *xc + 1);
						if ((*xc - 1 >= 0) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc - 1) != -1))
							lent->keistiboardtoo(*yc + 1, *xc - 1);
						*trysc = *trysc + 1;
						if (*trysc == 3)
						{
							if (*kryptis == 'x')
							{
								if (lent->gautiboard(i, j + 1) == 9)
								{
									if ((*xc + 3 <= 9) && (lent->gautiboard(*yc, *xc + 3) != -1))
										lent->keistiboardtoo(*yc, *xc + 3);
									if ((*xc - 1 >= 0) && (lent->gautiboard(*yc, *xc - 1) != -1))
										lent->keistiboardtoo(*yc, *xc - 1);
								}
								else
								{
									if ((*xc + 1 <= 9) && (lent->gautiboard(*yc, *xc + 1) != -1))
										lent->keistiboardtoo(*yc, *xc + 1);
									if ((*xc - 3 >= 0) && (lent->gautiboard(*yc, *xc - 3) != -1))
										lent->keistiboardtoo(*yc, *xc - 3);
								}

							}
							else if (*kryptis == 'y')
							{
								if (lent->gautiboard(i + 1, j) == 9)
								{
									if ((*yc + 4 <= 9) && (lent->gautiboard(*yc + 4, *xc) != -1))
										lent->keistiboardtoo(*yc + 4, *xc);
									if ((*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc) != -1))
										lent->keistiboardtoo(*yc - 1, *xc);
								}
								else
								{
									if ((*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc) != -1))
										lent->keistiboardtoo(*yc + 1, *xc);
									if ((*yc - 4 >= 0) && (lent->gautiboard(*yc - 4, *xc) != -1))
										lent->keistiboardtoo(*yc - 4, *xc);
								}
							}
							*kryptis = 'n';
							*laik = -1;
					      	*trysc = 0;
							*sunaikintic = *sunaikintic + 1;
						}
						brk = 1;
						break;
					}
					else if (lent->gautiboard(i, j) == 4)
					{
						lent->keistiboard(i, j);
						if ((*yc > i) || (*yc < i))
							*kryptis = 'y';
						else if ((*xc > j) || (*xc < j))
							*kryptis = 'x';
						*yc = i; *xc = j;
						if ((*xc + 1 <= 9) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc + 1) != -1))
							lent->keistiboardtoo(*yc + 1, *xc + 1);
						if ((*xc - 1 >= 0) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc - 1) != -1))
							lent->keistiboardtoo(*yc - 1, *xc - 1);
						if ((*xc + 1 <= 9) && (*yc - 1 >= 0) && (lent->gautiboard(*yc - 1, *xc + 1) != -1))
							lent->keistiboardtoo(*yc - 1, *xc + 1);
						if ((*xc - 1 >= 0) && (*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc - 1) != -1))
							lent->keistiboardtoo(*yc + 1, *xc - 1);
						*keturic = *keturic + 1;
						if (*keturic == 4)
						{
							if (*kryptis == 'x')
							{
								if (lent->gautiboard(i, j + 1) == 9)
								{
									if ((*xc + 4 <= 9) && (lent->gautiboard(*yc, *xc + 4) != -1))
										lent->keistiboardtoo(*yc, *xc + 4);
									if ((*xc - 1 >= 0) && (lent->gautiboard(*yc, *xc - 1) != -1))
										lent->keistiboardtoo(*yc, *xc - 1);
								}
								else
								{
									if ((*xc + 1 <= 9) && (lent->gautiboard(*yc, *xc + 1) != -1))
										lent->keistiboardtoo(*yc, *xc + 1);
									if ((*xc - 4 >= 0) && (lent->gautiboard(*yc, *xc - 4) != -1))
										lent->keistiboardtoo(*yc, *xc - 4);
								}
								
							}
							else if (*kryptis == 'y')
							{
								if (lent->gautiboard(i+1, j ) == 9)
								{
									if ((*yc + 4 <= 9) && (lent->gautiboard(*yc + 4 , *xc) != -1))
										lent->keistiboardtoo(*yc + 4, *xc);
									if ((*yc - 1 >= 0) && (lent->gautiboard(*yc - 1 , *xc) != -1))
										lent->keistiboardtoo(*yc - 1, *xc);
								}
								else
								{
									if ((*yc + 1 <= 9) && (lent->gautiboard(*yc + 1, *xc) != -1))
										lent->keistiboardtoo(*yc + 1 , *xc);
									if ((*yc - 4 >= 0) && (lent->gautiboard(*yc - 4, *xc) != -1))
										lent->keistiboardtoo(*yc - 4, *xc);
								}
							}
							*kryptis = 'n';
							*laik = -1;
							*keturic = 0;
							*sunaikintic=*sunaikintic+1;
						}
						brk = 1;
						break;
					}
					else
					{
						if ((lent->gautiboard(*yc, *xc) == 9) && (((lent->gautiboard(*yc, *xc + 1) == -1) && (lent->gautiboard(*yc, *xc - 1) == 9))|| ((lent->gautiboard(*yc, *xc - 1) == -1))&& (lent->gautiboard(*yc, *xc + 1) == 9)) && (*kryptis == 'x'))
						{
							if (lent->gautiboard(*yc, *xc + 1) == 9)
							{
								*xc = *xc + *trysc + *keturic - 1;
								i = *yc - 1;
								j = *xc ;
							}
							else
							{
								*xc = *xc - *trysc - *keturic + 1;
								i = *yc - 1;
								j = *xc ;
							}
						}
						else if ((lent->gautiboard(*yc, *xc) == 9) && (((lent->gautiboard(*yc + 1, *xc) == -1) && (lent->gautiboard(*yc - 1, *xc) == 9))||((lent->gautiboard(*yc + 1, *xc) == 9) && (lent->gautiboard(*yc - 1, *xc) == -1))) && (*kryptis == 'y'))
						{

							if (lent->gautiboard(*yc + 1, *xc) == 9)
							{
								*yc = *yc + *trysc + *keturic - 1;
								i = *yc ;
								j = *xc - 1;
							}
							else
							{
								*yc = *yc - *trysc - *keturic + 1;
								i = *yc ;
								j = *xc - 1;
							}
						}
						
					}
				}
			}
			if (brk == 1)
			    break;
		}
	}
	else
		{

		}
	
}


int main()
{
	lenta lent;
	lentac lentc;
	int i = 0, du = 0, trys = 0, keturi = 0, sunaikintip = 0, sunaikintic = 0, duc = 0, trysc = 0, keturic = 0, laik = -1, xc = 0, yc=0;
	char kryptis;

	while (i < 8)
	{
		if (lentc.statytilc(i) == 1)
		{
			if (lentc.tikrintic(i) == 1)
			{
				lentc.board1c(i);
				i++;
			}
		}
	}
	lentc.laivupalikimasc();
	i = 0;

	while (i < 8)
	{
		lentc.showboardc();
		cout << endl;
		lent.showboard();

		if (lent.statytil(i) == 1)
		{
			if (lent.tikrinti(i) == 1)
			{
				lent.board1(i);
				i++;
			}
			else
			{
				lentc.showboardc();
				cout << endl;
				lent.showboard();
				cout << "laivo statyti negalima! veskite is naujo" << endl;
				Sleep(2000);
				system("cls");
			}
		}
		else
		{
			lentc.showboardc();
			cout << endl;
			lent.showboard();
			cout << "laivo statyti negalima! veskite is naujo" << endl;
			Sleep(2000);
			system("cls");
		}
	}
	lent.laivupalikimas();
	

	while (!gameover)
	{
		ataka(&lentc, &lent, &du, &trys, &keturi, &sunaikintip);
		if (sunaikintip == 8)
		{
			cout << "Jus laimejote!";
			Sleep(3000);
			break;
		}
		system("cls");
		lentc.showboardc();
		cout << endl;
		lent.showboard();
		atakac(&lentc, &lent, &duc, &trysc, &keturic, &sunaikintic, &laik, &xc, &yc, &kryptis);
		if (sunaikintic == 8)
		{
			system("cls");
			lentc.showboardc();
			cout << endl;
			lent.showboard();
			cout << "Jus pralaimejote!";
			Sleep(3000);
			break;
		}
		
		
	}
	cin >> x;

	return 0;
}

void ataka(lentac *lentc, lenta *lent, int *du, int *trys, int *keturi, int *sunaikintip)
{
	int atty;
	char attx;
	system("cls");
	lentc->showboardc();
	cout << endl;
	lent->showboard();
	cout << "Iveskite puolimo koordinates" << endl;
	cin >> attx >> atty;
	attx = 9 - ('j' - attx);
	if (lentc->gautiboardc(atty, attx) == 1)
	{
		lentc->keistiboardc(atty, attx);
		system("cls");
		lentc->showboardc();
		cout << endl;
		lent->showboard();
		cout << "Jus sunaikinote laiva!" << endl;
		*sunaikintip = *sunaikintip + 1;
		Sleep(2000);
	}
	else if (lentc->gautiboardc(atty, attx) == 2)
	{
		lentc->keistiboardc(atty, attx);
		*du = *du + 1;
		if (*du == 2)
		{
			*du = 0;
			system("cls");
			lentc->showboardc();
			cout << endl;
			lent->showboard();
			cout << "Jus sunaikinote laiva!" << endl;
			*sunaikintip = *sunaikintip + 1;
			Sleep(2000);
		}
		else
		{
			system("cls");
			lentc->showboardc();
			cout << endl;
			lent->showboard();
			cout << "Jus pataikete!" << endl;
			Sleep(2000);
		}

	}
	else if (lentc->gautiboardc(atty, attx) == 3)
	{
		lentc->keistiboardc(atty, attx);
		*trys = *trys + 1;
		if (*trys == 3)
		{
			*trys = 0;
			system("cls");
			lentc->showboardc();
			cout << endl;
			lent->showboard();
			cout << "Jus sunaikinote laiva!" << endl;
			*sunaikintip = *sunaikintip + 1;
			Sleep(2000);
		}
		else
		{
			system("cls");
			lentc->showboardc();
			cout << endl;
			lent->showboard();
			cout << "Jus pataikete!" << endl;
			Sleep(2000);
		}
	}
	else if (lentc->gautiboardc(atty, attx) == 4)
	{
		lentc->keistiboardc(atty, attx);
		*keturi = *keturi + 1;
		if (*keturi == 4)
		{
			*keturi = 0;
			system("cls");
			lentc->showboardc();
			cout << endl;
			lent->showboard();
			cout << "Jus sunaikinote laiva!" << endl;
			*sunaikintip = *sunaikintip + 1;
			Sleep(2000);
		}
		else
		{
			system("cls");
			lentc->showboardc();
			cout << endl;
			lent->showboard();
			cout << "Jus pataikete!" << endl;
			Sleep(2000);
		}
	}
	else if (lentc->gautiboardc(atty, attx) == 0)
	{
		lentc->keistiboardcmiss(atty, attx);
		system("cls");
		lentc->showboardc();
		cout << endl;
		lent->showboard();
		cout << "Jus nepataikete!" << endl;
		Sleep(2000);
	}
	else
	{
		system("cls");
		lentc->showboardc();
		cout << endl;
		lent->showboard();
		cout << "Jus i sitas koordinates jau sovete!" << endl;
		Sleep(2000);
	}
}
