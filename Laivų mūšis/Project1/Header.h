#pragma once
class laivas
{
protected:
	vector <int> length{ 4,3,2,2,1,1,1,1 };
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
				//cout << "Laivo statyti negalima! bandykite is naujo." << endl;
				//system("pause");
				//system("cls");
				return 0;
				break;
			}
			if ((y <= 9) && (y >= 0))
				brow.push_back(y);
			else
			{
				bcol.clear();
				brow.clear();
				//cout << "Laivo statyti negalima! bandykite is naujo." << endl;
				//system("pause");
				//system("cls");
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