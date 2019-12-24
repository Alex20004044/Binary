#include <iostream>
#include <Binary.h>

using namespace std;
using namespace binary;
#pragma warning(disable : 4996)
enum GetNumMode
{
	all, positive0, negaive0
};
void GetBin(Binary &b);
void GetTwoBins(Binary& b1, Binary&b2);
bool GetInt(int &num, GetNumMode mode);
bool GetFloat(float &num, GetNumMode mode);
int GetIntLine(int *&mas, int l, GetNumMode mode);
int main()
{
	int num;
	while (true)
	{
		cout << "---Binary Calculator---" << endl;
		cout << "0) Exit" << endl;
		cout << "1) Addition" << endl;
		cout << "2) Subtraction" << endl;
		cout << "3) Info" << endl;
		cout << "---" << endl;
		cout << "Enter command: ";
		GetInt(num, positive0);
		if (num == 0)
		{
			break;
		}
		switch (num)
		{
		case 1:
		{		Binary b1, b2;
				GetTwoBins(b1, b2);
					
				cout << "Result is: " << (b1 + b2) << endl;
				break;
		}
		case 2:
		{
				  Binary b1, b2;
				  GetTwoBins(b1, b2);

				  cout << "Result is: " << (b1 - b2) << endl;
				  break;
				  break;
		}
		case 3:
		{
				  system("cls");
				  system("color 0a");
				  cout << "---Info---" << endl;

				  cout << "You can ADD and SUB 2 digits in binary code" << endl;
				  cout << "Binary can be writed in several ways:" << endl;
				  cout << "Example 1: 5" << endl;
				  cout << "+101" << endl;
				  cout << "0101" << endl;
				  cout << "Example 1: -5" << endl;
				  cout << "-101" << endl;
				  cout << "1101" << endl;

				  cout << "------" << endl;
				  //cout << "Press any button to continue";
				  system("pause");
				  system("color 07");
				  break;
		}
		default:
			{
				   cout << "Unknown command. Try again" << endl;
			}
		}
	}

}
void GetTwoBins(Binary& b1, Binary&b2)
{
	cout << "Enter first binary digit: " << endl;
	GetBin(b1);
	cout << "Enter second binary digit: " << endl;
	GetBin(b2);
	return;
}
void GetBin(Binary &b)
{
	string str;
	while (true)
	{
		
		cin >> str;
		if (Binary::IsCorrectDigits(str.c_str()))
		{
			try{
				b = Binary(str.c_str());
			}
			catch (bad_alloc x)
			{
				//do something
			}

			break;
		}
		else
		{
			cout << "Input Error! Try again" << endl;
		}
	}

}

int GetIntLine(int *&mas, int l, GetNumMode mode)
{
	int num;
	mas = new int(l);

	for (int i = 0; i < l; i++)
	{
		GetInt(num, mode);
		mas[i] = num;
	}

	return 0;
}

bool GetInt(int &num, GetNumMode mode)
{
	int temp;
	bool isAllRight = false;

	while (!isAllRight)
	{
		cin >> temp;
		if (cin.good())
		{
			switch (mode)
			{
			case all:
			{
						//cout << "Enter int: " << endl;
						isAllRight = true;
						break;
			}
			case positive0:
			{
							  //cout << "Enter positive int (or 0): " << endl;
							  if (temp >= 0)
							  {
								  isAllRight = true;
							  }
							  break;
			}
			case negaive0:
			{
							 //cout << "Enter negative int (or 0): " << endl;
							 if (temp <= 0)
							 {
								 isAllRight = true;
							 }
							 break;
			}
			}
		}
		else
		{
			cin.clear();
			while (getchar() != '\n');
			//cout << flush;
		}
		if (!isAllRight)
		{
			cout << "Input Error! Try again" << endl;
		}
	}
	num = temp;

	return true;
}

bool GetFloat(float &num, GetNumMode mode)
{
	float temp;
	bool isAllRight = false;

	while (!isAllRight)
	{
		cin >> temp;
		if (cin.good())
		{
			switch (mode)
			{
			case all:
			{
						//cout << "Enter int: " << endl;
						isAllRight = true;
						break;
			}
			case positive0:
			{
							  //cout << "Enter positive int (or 0): " << endl;
							  if (temp >= 0)
							  {
								  isAllRight = true;
							  }
							  break;
			}
			case negaive0:
			{
							 //cout << "Enter negative int (or 0): " << endl;
							 if (temp <= 0)
							 {
								 isAllRight = true;
							 }
							 break;
			}
			}
		}
		else
		{
			cin.clear();
			while (getchar() != '\n');
			//cout << flush;
		}
		if (!isAllRight)
		{
			cout << "Input Error! Try again" << endl;
		}
	}
	num = temp;

	return true;
}


