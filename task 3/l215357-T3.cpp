#include <iostream>
using namespace std;

class Roman_Numbers_ {
private:
	char roman_num[1000];
	int int_num;
public:
	int rem; char rem_roman[1000];
	Roman_Numbers_();
	Roman_Numbers_(char num[1000]);
	void romanToInt();
	void romanToIntforRem();
	void intToRoman();
	int getNextNum(int);
	bool isNum0();
	friend void Upper(Roman_Numbers_& obj);
	friend bool validation(Roman_Numbers_ obj);
	Roman_Numbers_ operator+(Roman_Numbers_);
	Roman_Numbers_ operator-(Roman_Numbers_);
	Roman_Numbers_ operator*(Roman_Numbers_);
	Roman_Numbers_ operator/(Roman_Numbers_);
	bool operator==(Roman_Numbers_);
	bool operator!=(Roman_Numbers_);
	bool operator<(Roman_Numbers_);
	bool operator>(Roman_Numbers_);
	Roman_Numbers_ operator++();
	Roman_Numbers_ operator++(int);
	Roman_Numbers_ operator--();
	Roman_Numbers_ operator--(int);
	friend ostream& operator<< (ostream&, const Roman_Numbers_&);
	friend istream& operator>> (istream&, Roman_Numbers_&);
	~Roman_Numbers_()
	{

		//delete[] roman_num;
		//delete[] rem_roman;
	}
};

//gloabl
char specialCharacters[7] = { 'M','D','C','L','X','V','I' };
int valuesSpecialChars[7] = { 1000,500,100,50,10,5,1 };

Roman_Numbers_::Roman_Numbers_()
{
	int_num = 0;
	rem = 0;
}

Roman_Numbers_::Roman_Numbers_(char num[1000])
{
	int i;
	for (i = 0; num[i] != '\0'; i++)
	{
		roman_num[i] = num[i];
	}
	roman_num[i] = '\0';
	int_num = 0; rem = 0;
	Upper(*this);
	romanToInt();
}

int Roman_Numbers_::getNextNum(int i)
{
	int nextnum=0;
	for (int j = 0; j < 7; j++)
	{
		if (roman_num[i + 1] == specialCharacters[j])
		{
			nextnum = valuesSpecialChars[j];
			break;
		}
	}
	return nextnum;
}

void Roman_Numbers_::romanToInt()
{
	//Symbol	I	V	X	L	C	D	M
	//Value  	1	5	10	50	100	500	1000
	char chk; int add, nextnum,limit=strlen(roman_num)-1;
	for (int i = 0; roman_num[i] != '\0'; i++)
	{
		chk = roman_num[i];
		if (chk == 'M' || chk == 'm')
		{
			add = 1000;
			//checking next num greater or small
			if (i != limit)
			{
				nextnum = getNextNum(i);
				if (add < nextnum)
				{
					int_num = int_num + (nextnum - add);
					i++;
				}
				else
				{
					int_num = int_num + add;
				}
			}
			else
				int_num = int_num + add;


		}
		else if (chk == 'D' || chk == 'd')
		{
			add = 500;
			//checking next num greater or small
			if (i != limit)
			{
				nextnum = getNextNum(i);
				if (add < nextnum)
				{
					int_num = int_num + (nextnum - add);
					i++;
				}
				else
				{
					int_num = int_num + add;
				}
			}
			else
				int_num = int_num + add;

		}
		else if (chk == 'C' || chk == 'c')
		{
			add = 100;
			//checking next num greater or small
			if (i != limit)
			{
				nextnum = getNextNum(i);
				if (add < nextnum)
				{
					int_num = int_num + (nextnum - add);
					i++;
				}
				else
				{
					int_num = int_num + add;
				}
			}
			else
				int_num = int_num + add;

		}
		else if (chk == 'L' || chk == 'l')
		{
			add = 50;
			//checking next num greater or small
			if (i != limit)
			{
				nextnum = getNextNum(i);
				if (add < nextnum)
				{
					int_num = int_num + (nextnum - add);
					i++;
				}
				else
				{
					int_num = int_num + add;
				}
			}
			else
				int_num = int_num + add;
		}
		else if (chk == 'X' || chk == 'x')
		{
			add = 10;
			//checking next num greater or small
			if (i != limit)
			{
				nextnum = getNextNum(i);
				if (add < nextnum)
				{
					int_num = int_num + (nextnum - add);
					i++;
				}
				else
				{
					int_num = int_num + add;
				}
			}
			else
				int_num = int_num + add;
		}
		else if (chk == 'V' || chk == 'v')
		{
			add = 5;
			//checking next num greater or small
			if (i != limit)
			{
				nextnum = getNextNum(i);
				if (add < nextnum)
				{
					int_num = int_num + (nextnum - add);
					i++;
				}
				else
				{
					int_num = int_num + add;
				}
			}
			else
				int_num = int_num + add;
		}
		else if (chk == 'I' || chk == 'i')
		{
			add = 1;
			//checking next num greater or small
			if (i != limit)
			{
				nextnum = getNextNum(i);
				if (add < nextnum)
				{
					int_num = int_num + (nextnum - add);
					i++;
				}
				else
				{
					int_num = int_num + add;
				}
			}
			else
				int_num = int_num + add;
		}
	}

}

void Roman_Numbers_::intToRoman()
{
	int dummy = int_num, i = 0;
	while (dummy > 0)
	{
		while (dummy/1000>0)
		{
			roman_num[i] = 'M'; i++;
			dummy -= 1000;
		}
		while (dummy / 900 > 0)
		{
			roman_num[i] = 'C'; i++;
			roman_num[i] = 'M'; i++;
			dummy -= 900;
		}
		while (dummy / 500 > 0)
		{
			roman_num[i] = 'D'; i++;
			dummy -= 500;
		}
		while (dummy / 400 > 0)
		{
			roman_num[i] = 'C'; i++;
			roman_num[i] = 'D'; i++;
			dummy -= 400;
		}
		while (dummy / 100 > 0)
		{
			roman_num[i] = 'C'; i++;
			dummy -= 100;
		}
		while (dummy / 90 > 0)
		{
			roman_num[i] = 'X'; i++;
			roman_num[i] = 'C'; i++;
			dummy -= 90;
		}
		while (dummy / 50 > 0)
		{
			roman_num[i] = 'L'; i++;
			dummy -= 50;
		}
		while (dummy / 40 > 0)
		{
			roman_num[i] = 'X'; i++;
			roman_num[i] = 'L'; i++;
			dummy -= 40;
		}
		while (dummy / 10 > 0)
		{
			roman_num[i] = 'X'; i++;
			dummy -= 10;
		}
		while (dummy / 9 > 0)
		{
			roman_num[i] = 'I'; i++;
			roman_num[i] = 'X'; i++;
			dummy -= 9;
		}
		while (dummy / 5 > 0)
		{
			roman_num[i] = 'V'; i++;
			dummy -= 5;
		}
		while (dummy / 4 > 0)
		{
			roman_num[i] = 'I'; i++;
			roman_num[i] = 'V'; i++;
			dummy -= 4;
		}
		while (dummy / 1 > 0)
		{
			roman_num[i] = 'I'; i++;
			dummy -= 1;
		}
	}
	roman_num[i] = '\0';
}

void Roman_Numbers_::romanToIntforRem()
{
	int dummy = rem, i = 0;
	while (dummy > 0)
	{
		while (dummy / 1000 > 0)
		{
			rem_roman[i] = 'M'; i++;
			dummy -= 1000;
		}
		while (dummy / 900 > 0)
		{
			rem_roman[i] = 'C'; i++;
			rem_roman[i] = 'M'; i++;
			dummy -= 900;
		}
		while (dummy / 500 > 0)
		{
			rem_roman[i] = 'D'; i++;
			dummy -= 500;
		}
		while (dummy / 400 > 0)
		{
			rem_roman[i] = 'C'; i++;
			rem_roman[i] = 'D'; i++;
			dummy -= 400;
		}
		while (dummy / 100 > 0)
		{
			rem_roman[i] = 'C'; i++;
			dummy -= 100;
		}
		while (dummy / 90 > 0)
		{
			rem_roman[i] = 'X'; i++;
			rem_roman[i] = 'C'; i++;
			dummy -= 90;
		}
		while (dummy / 50 > 0)
		{
			rem_roman[i] = 'L'; i++;
			dummy -= 50;
		}
		while (dummy / 40 > 0)
		{
			rem_roman[i] = 'X'; i++;
			rem_roman[i] = 'L'; i++;
			dummy -= 40;
		}
		while (dummy / 10 > 0)
		{
			rem_roman[i] = 'X'; i++;
			dummy -= 10;
		}
		while (dummy / 9 > 0)
		{
			rem_roman[i] = 'I'; i++;
			rem_roman[i] = 'X'; i++;
			dummy -= 9;
		}
		while (dummy / 5 > 0)
		{
			rem_roman[i] = 'V'; i++;
			dummy -= 5;
		}
		while (dummy / 4 > 0)
		{
			rem_roman[i] = 'I'; i++;
			rem_roman[i] = 'V'; i++;
			dummy -= 4;
		}
		while (dummy / 1 > 0)
		{
			rem_roman[i] = 'I'; i++;
			dummy -= 1;
		}
	}
	rem_roman[i] = '\0';
}

//operators
Roman_Numbers_ Roman_Numbers_::operator+(Roman_Numbers_ obj)
{
	Roman_Numbers_ _tempForAdditon_;
	_tempForAdditon_.int_num = int_num + obj.int_num;
	_tempForAdditon_.intToRoman();
	return _tempForAdditon_;
}

Roman_Numbers_ Roman_Numbers_::operator-(Roman_Numbers_ obj)
{
	Roman_Numbers_ _tempForSubtraction_;
	_tempForSubtraction_.int_num = int_num - obj.int_num;
	_tempForSubtraction_.intToRoman();
	return _tempForSubtraction_;
}

Roman_Numbers_ Roman_Numbers_::operator*(Roman_Numbers_ obj)
{
	Roman_Numbers_ _tempForMultiplication_;
	_tempForMultiplication_.int_num = int_num * obj.int_num;
	_tempForMultiplication_.intToRoman();
	return _tempForMultiplication_;
}

Roman_Numbers_ Roman_Numbers_::operator/(Roman_Numbers_ obj)
{
	Roman_Numbers_ _tempForDivision_;
	if (obj.int_num == 0)
	{
		_tempForDivision_.int_num = -1;
		return _tempForDivision_;
	}
	_tempForDivision_.int_num = int_num / obj.int_num;
	_tempForDivision_.rem = int_num % obj.int_num;
	_tempForDivision_.intToRoman();
	_tempForDivision_.romanToIntforRem();
	return _tempForDivision_;
}	

bool Roman_Numbers_::operator==(Roman_Numbers_ obj)
{
	if (int_num == obj.int_num)
	{
		return true;
	}
	else
		return false;
}

bool Roman_Numbers_::operator!=(Roman_Numbers_ obj)
{
	if (int_num != obj.int_num)
	{
		return true;
	}
	else
		return false;
}

bool Roman_Numbers_::operator<(Roman_Numbers_ obj)
{
	if (int_num < obj.int_num)
	{
		return true;
	}
	else
		return false;
}

bool Roman_Numbers_::operator>(Roman_Numbers_ obj)
{
	if (int_num > obj.int_num)
	{
		return true;
	}
	else
		return false;
}

Roman_Numbers_ Roman_Numbers_::operator++()
{
	int_num++;
	intToRoman();
	return *this;
}

Roman_Numbers_ Roman_Numbers_::operator++(int)
{
	Roman_Numbers_ _tempForincrement_=*this;
	int_num++;
	intToRoman();	
	return _tempForincrement_;
}

Roman_Numbers_ Roman_Numbers_::operator--()
{
	int_num--;
	intToRoman();
	return *this;
}

Roman_Numbers_ Roman_Numbers_::operator--(int)
{
	Roman_Numbers_ _tempForincrement_ = *this;
	int_num--;
	intToRoman();
	return _tempForincrement_;
}
//*************************************

//optional
void Upper(Roman_Numbers_& obj )
{
	for (int i = 0; obj.roman_num[i] != '\0'; i++)
	{
		if (obj.roman_num[i] >= 97 && obj.roman_num[i] <= 122)
		{
			obj.roman_num[i] = obj.roman_num[i] - 32;
		}
	}
}
ostream& operator<< (ostream& c, const Roman_Numbers_& obj)
{
	c << obj.roman_num;
	return c;
}

istream& operator>> (istream& c, Roman_Numbers_& obj)
{
	cin >> obj.roman_num;
	while (!validation(obj))
	{
		cout << "Wrong Input" << endl;
		cout << "Enter again " << endl;
		cin >> obj.roman_num;
	}
	Upper(obj);
	obj.romanToInt();
	return c;
}

bool Roman_Numbers_::isNum0()
{
	if (int_num == 0)
	{
		return true;
	}
	else
		return false;
}


bool validation(Roman_Numbers_ obj)
{
	int check = 0;
	for (int i = 0; obj.roman_num[i] != '\0'; i++)
	{
		if (obj.roman_num[i] != 'I' && obj.roman_num[i] != 'V' && obj.roman_num[i] != 'X' && obj.roman_num[i] != 'L'
		&& obj.roman_num[i] != 'C'&& obj.roman_num[i] != 'D' && obj.roman_num[i] != 'M' && obj.roman_num[i] != 'i'
			&& obj.roman_num[i] != 'v' && obj.roman_num[i] != 'x' && obj.roman_num[i] != 'l'
			&& obj.roman_num[i] != 'c' && obj.roman_num[i] != 'd' && obj.roman_num[i] != 'm')
		{
			check = 1; break;
		}
	}
	if (check == 0)
	{
		return true;
	}
	else
		return false;
}

bool validation(char num[100])
{
	int check = 0;
	for (int i = 0; num[i] != '\0'; i++)
	{
		if (num[i] != 'I' && num[i] != 'V' && num[i] != 'X' && num[i] != 'L' && num[i] != 'C'
			&& num[i] != 'D' && num[i] != 'M' && num[i] != 'i' && num[i] != 'v' && num[i] != 'x' && num[i] != 'l' && num[i] != 'x'
			&& num[i] != 'd' && num[i] != 'm')
		{
			check = 1; break;
		}

	}
	if (check == 0)
	{
		return true;
	}
	else
		return false;
}

int main()
{
	char num[100];
	cout << "Enter a roman number: " << endl;
	cin >> num;
	while (!validation(num))
	{
		cout << "Wrong Input" << endl;
		cout << "Enter again " << endl;
		cin >> num;
	}
	Roman_Numbers_ obj1(num);
	cout << "Your entered number is " << obj1<<endl;
	Roman_Numbers_ obj2;
	cout << "Enter a roman number: " << endl;
	cin >> obj2;
	cout << "Your entered number is " << obj2<<endl;

	cout << endl;
	Roman_Numbers_ forAdditon;
	cout << "ADDITION" << endl;
	forAdditon = obj1 + obj2;
	cout << obj1 << "+" << obj2 << "=";cout << forAdditon<<endl;

	cout << endl;
	Roman_Numbers_ forSubtraction;
	cout << "SUBTRACTION" << endl;
	if (obj1 < obj2)
	{
		cout << "Cannot subtract a higher numeral from a lower one" << endl;
	}
	else
	{
		forSubtraction = obj1 - obj2;
		if (forSubtraction.isNum0())
		{
			cout << obj1 << "-" << obj2 << "=" << "ZERO" << endl;

		}
		else
		{
			cout << obj1 << "-" << obj2 << "=" << forSubtraction << endl;
		}
	}

	cout << endl;
	Roman_Numbers_ forMultiplication;
	cout << "MULTIPLICATION" << endl;
	forMultiplication = obj1 * obj2;
	cout << obj1 << "*" << obj2 << "=" << forMultiplication<<endl;

	cout << endl;
	Roman_Numbers_ forDivision;
	cout << "DIVISION" << endl;
	if (obj1.isNum0() || obj2.isNum0())
	{
		cout << "Division not possible one number is 0" << endl;
	}
	else if(obj1 < obj2)
	{
		cout << "Cannot divide a higher numeral from a lower one" << endl;
	}
	else
	{
		forDivision = obj1 / obj2;
		cout << obj1 << "/" << obj2 << "=";
		cout<< forDivision<<endl;
		if (forDivision.rem != 0)
		{
			cout << "and remainder is " << forDivision.rem_roman << endl;
		}
		else
			cout << "and remainder is ZERO." << endl;
	}

	cout << endl;
	if (obj1 == obj2)
	{
		cout << "Equal(== overloading)" << endl;
	}
	else
	{
		cout << "Not Equal(== overloading)" << endl;
	}

	cout << endl;
	if (obj1 != obj2)
	{
		cout << "Not Equal(!= overloading)" << endl;
	}
	else
	{
		cout << "Equal(!= overloading)" << endl;
	}

	cout << endl;
	if (obj1 > obj2)
	{
		cout << obj1 << " is larger(> overloading)" << endl;
	}
	else
	{
        cout << obj2 << " is larger(> overloading)" << endl;
	}

	cout << endl;
	if (obj1 < obj2)
	{
		cout << obj2 << " is larger(< overloading)" << endl;
	}
	else
	{
		cout << obj1 << " is larger(< overloading)" << endl;
	}
	cout << endl << endl;
	cout << "Increments Overloading" << endl;
	cout << "Pre Increment of " << obj1 <<":::" << endl;
	++obj1;cout << obj1<<endl;
	Roman_Numbers_ Post;
	Post = obj1++;
	cout << "Post Increment " << endl;
	cout << "Incremented values of Post object after post increment" << endl;
	cout << Post<<endl;
	cout << "Incremented values of original object" << endl;
	cout << obj1<<endl;

	cout << endl << endl;

	cout << "Decrements Overloading" << endl;
	cout << "Pre Decrement of "<<obj1 << endl;
	--obj1; cout << obj1<<endl;
	Roman_Numbers_ PostDec;
	PostDec = obj1--;
	cout << "Post Decrement" << endl;
	cout << "Decremented values of PostDec object after post Decrement" << endl;
	cout << PostDec << endl;
	cout << "Decremented values of original object" << endl;
	cout << obj1<<endl;

	system("pause");
	return 0;
}