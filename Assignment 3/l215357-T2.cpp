#include <iostream>
#include <string>
using namespace std;

class _string 
{
private:
	char* _ptr_;
public:
	_string();
	_string(char*,int x=100);
	int	_stringLen();
	void _stringUpper();
	void _stringLower();
	char _stringAt(int);
	char* _stringSubString(int,int);
	int _stringStartIndex(char*);
	int _stringCompare(_string);
	void _stringConcat(_string);
	void _stringConcat(string);
	void _stringConcat(char*);
	void _stringConcat(char);
	void _stringConcat(int);
	void _stringConcat(float);
	void _stringPrepend(_string);
	void _stringPrepend(string);
	void _stringPrepend(char*);
	void _stringPrepend(char);
	void _stringPrepend(int);
	void _stringPrepend(float);
	//operators
	friend _string& operator+(_string,_string);
	friend _string& operator+(_string,string);
	friend _string& operator+(_string,char*);
	friend _string& operator+(_string,char);
	friend _string& operator+(_string, int);
	friend _string& operator+(_string, float);
	friend _string& operator+(string,_string);
	friend _string& operator+(char*, _string);
	friend _string& operator+(char, _string);
	friend _string& operator+(int, _string);
	friend _string& operator+(float, _string);
	_string& operator= (_string);
	bool operator== (_string);
	bool operator!= (_string);
	bool operator< (_string);
	bool operator> (_string);
	char operator[] (int);
	friend ostream& operator<< (ostream&, const _string&);
	friend istream& operator>> (istream&, _string&);

};
//******
_string& operator+(_string obj1, _string obj2)
{
	_string temp; temp = obj1;
	temp._stringConcat(obj2);
	return temp;
}

_string& operator+(_string obj1, string obj2)
{
	_string temp; temp = obj1;
	temp._stringConcat(obj2);
	return temp;
}

_string& operator+(_string obj1, char* obj2)
{
	_string temp; temp = obj1;
	temp._stringConcat(obj2);
	return temp;
}

_string& operator+(_string obj1, char obj2)
{
	_string temp; temp = obj1;
	temp._stringConcat(obj2);
	return temp;
}

_string& operator+(_string obj1, int obj2)
{
	_string temp; temp = obj1;
	temp._stringConcat(obj2);
	return temp;
}

_string& operator+(_string obj1, float obj2)
{
	_string temp; temp = obj1;
	temp._stringConcat(obj2);
	return temp;
}

//prepend

_string& operator+(string obj2,_string obj1)
{
	_string temp; temp = obj1;
	temp._stringPrepend(obj2);
	return temp;
}

_string& operator+(char* obj2, _string obj1)
{
	_string temp; temp = obj1;
	temp._stringPrepend(obj2);
	return temp;
}

_string& operator+(char obj2, _string obj1)
{
	_string temp; temp = obj1;
	temp._stringPrepend(obj2);
	return temp;
}

_string& operator+(int obj2, _string obj1)
{
	_string temp; temp = obj1;
	temp._stringPrepend(obj2);
	return temp;
}
_string& operator+(float obj2, _string obj1)
{
	_string temp; temp = obj1;
	temp._stringPrepend(obj2);
	return temp;
}

//*******
_string::_string()
{
	_ptr_ = new char[100];
}

_string::_string(char*p, int x)
{
	_ptr_ = new char[100];
	for (int i = 0; i < x; i++)
	{
		_ptr_[i] = p[i];
	}
}
//length: determine the length of string
int _string::_stringLen()
{
	int _count = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		_count++;
	}
	return _count;
}
//upper: convert the string to upper case
void _string::_stringUpper()
{
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		if (_ptr_[i] >= 97 && _ptr_[i] <= 122)
		{
			_ptr_[i] = _ptr_[i] - 32;
		}
	}
}
//lower: convert the string to lower case
void _string::_stringLower()
{
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		if (_ptr_[i] >= 65 && _ptr_[i] <= 90)
		{
			_ptr_[i] = _ptr_[i] + 32;
		}
	}
}
//at: return character at a given index
char _string::_stringAt(int ind)
{
	return _ptr_[ind];
}
//substring: extract a substring given start and end
char* _string::_stringSubString(int st, int en)
{
	if (st > en)
	{
		swap(st, en);
	}
	int len = (en - st)+2;
	char* sub = new char[len];
	int j = 0;
	for (int i = st; i <= en; i++)
	{
		sub[j] = _ptr_[i]; j++;
	}
	sub[j] = '\0';
	return sub;
}
//index: find starting index of a substring
int _string::_stringStartIndex(char *p)
{
	int check = 0; int indexreq=-1;
	//for finding len of substring
	int len = 0;
	for (int i = 0; p[i] != '\0'; i++)
	{
		len++;
	}
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		if (_ptr_[i] == p[0])
		{
			int k = 0;
			for (int j = i; j < i + len; j++)
			{
				if (_ptr_[j] != p[k])
				{
					check = 0;
					indexreq = -1;
					break;
				}
				else
				{
					check++;
				}
				k++;
			}
			if(check==len)
			{
				indexreq = i;
				break;
			}
		}
	}

	return indexreq;
}
//compare: compare two strings
int _string::_stringCompare(_string obj)
{
	int len = 0,check=0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		len++;
	}
	int len2 = obj._stringLen(); 
	if (len > len2)
	{
		return 1;
	}
	else if (len < len2)
	{
		return -1;
	}
	else if (len == len2)
	{
		for (int i = 0; i < len ; i++)
		{
			if (_ptr_[i] != obj._ptr_[i])
			{
				return 404;
			}
			else
			{
				check++;
			}
		}
	}
	if (check == len)
	{
		return 0;
	}
	
}
//concat: concatenate/append the argument after current string. Cater cases for different data
void _string::_stringConcat(_string obj)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i]; 
	}
	_ptr_[forNull] = '\0';
	//******************************************
	_ptr_[forNull] = ' '; int k = 0;
	for (int i = forNull+1; obj._ptr_[k] != '\0'; i++)
	{
		_ptr_[i] = obj._ptr_[k]; k++;
	}
	int newNull = forNull + k + 1;
	_ptr_[newNull] = '\0';
}

void _string::_stringConcat(string obj)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	_ptr_[forNull] = ' ';
	int len = obj.length(); int k = 0;
	for (int i = forNull + 1;k<len ; i++)
	{
		_ptr_[i] = obj[k]; k++;
	}
	int newNull = forNull + len + 1;
	_ptr_[newNull] = '\0';
}

void _string::_stringConcat(char* cstrng)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	_ptr_[forNull] = ' '; int k = 0;
	for (int i = forNull + 1; cstrng[k] != '\0'; i++)
	{
		_ptr_[i] = cstrng[k]; k++;
	}
	int newNull = forNull + k + 1;
	_ptr_[newNull] = '\0';
}

void _string::_stringConcat(char c)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	_ptr_[forNull] = ' '; _ptr_[forNull + 1] = c;
	int newNull = forNull + 1 + 1;
	_ptr_[newNull] = '\0';
}

void _string::_stringConcat(int num)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	//converting int to char
	if (num < 0)
	{
		_ptr_[forNull] = ' '; _ptr_[forNull + 1] = '-';
		forNull = forNull + 1 + 1;
		_ptr_[forNull] = '\0';
		num = num * -1;//so it is +ve
	}
	else if (num > 0)
	{
		_ptr_[forNull] = ' ';
		forNull = forNull + 1;
		_ptr_[forNull] = '\0';
	}
	else if (num == 0)
	{
		_ptr_[forNull] = ' '; _ptr_[forNull + 1] = '0';
		forNull = forNull + 1 + 1;
		_ptr_[forNull] = '\0';
	}
	//to check if the num has zeroes at end
	int rev = 0,reversed = 0,dummy = num,numof0s=0;
	while (dummy != 0)
	{
		rev = dummy % 10;
		dummy = dummy / 10;
		if (rev == 0)
		{
			numof0s++;
		}
		else if(rev!=0)
		{
			break;
		}
	}

	//first we will reverse the num
	rev = 0; reversed = 0; dummy = num;
	while (dummy != 0)
	{
		rev = dummy % 10;
		reversed = (reversed * 10) + rev;
		dummy = dummy / 10;
	}
	//now converting char to int
	char inttochar;
	while (reversed != 0)
	{
		rev = reversed % 10;
		reversed = reversed / 10;
		inttochar = rev + '0';
		_ptr_[forNull] = inttochar;
		forNull++;
		_ptr_[forNull] = '\0';
	}
	for (int i = 0; i < numof0s; i++)
	{
		_ptr_[forNull] = '0';
		forNull++;
		_ptr_[forNull] = '\0';
	}
}

void _string::_stringConcat(float num)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	//converting float to char
	//this will be in two steps first int part will be added then decimal part
	if (num < 0)
	{
		_ptr_[forNull] = ' '; _ptr_[forNull + 1] = '-';
		forNull = forNull + 1 + 1;
		_ptr_[forNull] = '\0';
		num = num * -1;//so it is +ve
	}
	else if (num > 0)
	{
		_ptr_[forNull] = ' ';
		forNull = forNull + 1;
		_ptr_[forNull] = '\0';
	}
	else if (num == 0)
	{
		_ptr_[forNull] = ' '; _ptr_[forNull + 1] = '0';
		forNull = forNull + 1 + 1;
		_ptr_[forNull] = '\0';
	}
	//to check if the num has zeroes at end
	int rev = 0,reversed = 0,dummy = num,numof0s=0;
	while (dummy != 0)
	{
		rev = dummy % 10;
		dummy = dummy / 10;
		if (rev == 0)
		{
			numof0s++;
		}
		else if(rev!=0)
		{
			break;
		}
	}

	//first we will reverse the num
	rev = 0; reversed = 0; dummy = num;
	while (dummy != 0)
	{
		rev = dummy % 10;
		reversed = (reversed * 10) + rev;
		dummy = dummy / 10;
	}
	//now converting char to int
	char inttochar;
	while (reversed != 0)
	{
		rev = reversed % 10;
		reversed = reversed / 10;
		inttochar = rev + '0';
		_ptr_[forNull] = inttochar;
		forNull++;
		_ptr_[forNull] = '\0';
	}
	//adding 0s
	for (int i = 0; i < numof0s; i++)
	{
		_ptr_[forNull] = '0';
		forNull++;
		_ptr_[forNull] = '\0';
	}
	//adding decimal
	_ptr_[forNull] = '.';
	forNull = forNull + 1;
	_ptr_[forNull] = '\0';
	//for decimal
	int floattint = (int)num;
	float decimal1 = num - floattint;
	numof0s = 0;
	decimal1 = decimal1 * (int)pow(10,8);
	for (int i = 7; i >= 1; i--)//to cater cases such as .00323
	{
		if (decimal1 < (int)pow(10, i))
		{
			numof0s++;
		}
	}
	for (int i = 0; i < numof0s; i++)
	{
		_ptr_[forNull] = '0';
		forNull++;
		_ptr_[forNull] = '\0';
	}
	int decimal = (int)decimal1;
	rev = 0; reversed = 0; dummy = decimal;

	while (dummy != 0)
	{
	   rev = dummy % 10;
	   reversed = (reversed * 10) + rev;
	   dummy = dummy / 10;
	}
	//**************
	while (reversed != 0)
	{
		rev = reversed % 10;
		reversed = reversed / 10;
		inttochar = rev + '0';
		_ptr_[forNull] = inttochar;
		forNull++;
		_ptr_[forNull] = '\0';
	}
}

//prepend: concatenate/append the argument before current string. 
void _string::_stringPrepend(_string obj)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	int len = obj._stringLen(); int len1 = _stringLen();
	for (int i = len1;i>=0; i--)
	{
		_ptr_[i+len+1] = _ptr_[i];
	}

	for (int i = 0; i<len; i++)
	{
		_ptr_[i] = obj._ptr_[i];
	}
	_ptr_[len] = ' ';
}

void _string::_stringPrepend(string input)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	int len = input.length();  int len1 = _stringLen(); forNull = len1 + len + 2;
	for (int i = len1; i >= 0; i--)
	{
		_ptr_[i + len + 1] = _ptr_[i];
	}

	for (int i = 0; i < len; i++)
	{
		_ptr_[i] = input[i];
	}
	_ptr_[len] = ' ';
	_ptr_[forNull] = '\0';
}

void _string::_stringPrepend(char*p)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	int len = strlen(p);  int len1 = _stringLen(); forNull = len1 + len + 2;
	for (int i = len1; i >= 0; i--)
	{
		_ptr_[i + len + 1] = _ptr_[i];
	}
	for (int i = 0; i < len; i++)
	{
		_ptr_[i] = p[i];
	}
	_ptr_[len] = ' ';
	_ptr_[forNull] = '\0';
}

void _string::_stringPrepend(char input)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	int len1 = _stringLen(); forNull = len1 + 1 + 2;
	for (int i = len1; i >= 0; i--)
	{
		_ptr_[i + 1 + 1] = _ptr_[i];
	}
	_ptr_[0] = input;
	_ptr_[1] = ' ';
	_ptr_[forNull] = '\0';
}

void _string::_stringPrepend(int num)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	int size = 0;//a space
	char* tempchar = new char[500];
	//converting int to char
	if (num < 0)
	{
        tempchar[size] = '-'; size++;
		num = num * -1;//so it is +ve
	}
	else if (num == 0)
	{
		tempchar[size] = '0'; size++;
	}
	//to check if the num has zeroes at end
	int rev = 0, reversed = 0, dummy = num, numof0s = 0;
	while (dummy != 0)
	{
		rev = dummy % 10;
		dummy = dummy / 10;
		if (rev == 0)
		{
			numof0s++;
		}
		else if (rev != 0)
		{
			break;
		}
	}

	//first we will reverse the num
	rev = 0; reversed = 0; dummy = num;
	while (dummy != 0)
	{
		rev = dummy % 10;
		reversed = (reversed * 10) + rev;
		dummy = dummy / 10;
	}
	//now converting char to int
	char inttochar;
	while (reversed != 0)
	{
		rev = reversed % 10;
		reversed = reversed / 10;
		inttochar = rev + '0';
		tempchar[size] = inttochar;
		size++;
	}
	for (int i = size; i < size+numof0s; i++)
	{
		tempchar[i] = '0';
	}
	size = size + numof0s;
	tempchar[size] = '\0';
	//***
	int len = size; int len1 = _stringLen(); forNull = len1 + len + 2;
	for (int i = len1; i >= 0; i--)
	{
		_ptr_[i + len + 1] = _ptr_[i];
	}
	for (int i = 0; i < len; i++)
	{
		_ptr_[i] = tempchar[i];
	}
	_ptr_[len] = ' ';
	_ptr_[forNull] = '\0';
}

void _string::_stringPrepend(float num)
{
	//increasing size though deep copy*************************************
	_string temp; int forNull = 0;
	for (int i = 0; _ptr_[i] != '\0'; i++)
	{
		temp._ptr_[i] = _ptr_[i]; forNull++;
	}
	temp._ptr_[forNull] = '\0';

	delete[] _ptr_; _ptr_ = NULL; _ptr_ = new char[1000];
	for (int i = 0; temp._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = temp._ptr_[i];
	}
	_ptr_[forNull] = '\0';
	//******************************************
	int size = 0;//a space
	char* tempchar = new char[500];
	//converting int to char
	if (num < 0)
	{
		tempchar[size] = '-'; size++;
		num = num * -1;//so it is +ve
	}
	else if (num == 0)
	{
		tempchar[size] = '0'; size++;
	}
	//to check if the num has zeroes at end
	int rev = 0, reversed = 0, dummy = num, numof0s = 0;
	while (dummy != 0)
	{
		rev = dummy % 10;
		dummy = dummy / 10;
		if (rev == 0)
		{
			numof0s++;
		}
		else if (rev != 0)
		{
			break;
		}
	}
	//first we will reverse the num
	rev = 0; reversed = 0; dummy = num;
	while (dummy != 0)
	{
		rev = dummy % 10;
		reversed = (reversed * 10) + rev;
		dummy = dummy / 10;
	}
	//now converting char to int
	char inttochar;
	while (reversed != 0)
	{
		rev = reversed % 10;
		reversed = reversed / 10;
		inttochar = rev + '0';
		tempchar[size] = inttochar;
		size++;
	}
	for (int i = size; i < size + numof0s; i++)
	{
		tempchar[i] = '0';
	}
	size = size + numof0s;
	//adding decimal
	tempchar[size] = '.'; size++;
	//for decimal
	int floattint = (int)num;
	float decimal1 = num - floattint;
	numof0s = 0;
	decimal1 = decimal1 * (int)pow(10, 8);
	for (int i = 7; i >= 1; i--)//to cater cases such as .00323
	{
		if (decimal1 < (int)pow(10, i))
		{
			numof0s++;
		}
	}
	for (int i = size; i < size + numof0s; i++)
	{
		tempchar[i] = '0';
	}
	size = size + numof0s;
	int decimal = (int)decimal1;
	rev = 0; reversed = 0; dummy = decimal;
	while (dummy != 0)
	{
		rev = dummy % 10;
		reversed = (reversed * 10) + rev;
		dummy = dummy / 10;
	}
	//**************
	while (reversed != 0)
	{
		rev = reversed % 10;
		reversed = reversed / 10;
		inttochar = rev + '0';
		tempchar[size] = inttochar;
		size++;
	}
	tempchar[size] = '\0';
	int len = size; int len1 = _stringLen(); forNull = len1 + len + 2;
	for (int i = len1; i >= 0; i--)
	{
		_ptr_[i + len + 1] = _ptr_[i];
	}
	for (int i = 0; i < len; i++)
	{
		_ptr_[i] = tempchar[i];
	}
	_ptr_[len] = ' ';
	_ptr_[forNull] = '\0';
}

//operators
_string& _string::operator= (_string obj)
{
	delete[] _ptr_; _ptr_ = new char[100];
	int forNull = 0;
	for (int i = 0; obj._ptr_[i] != '\0'; i++)
	{
		_ptr_[i] = obj._ptr_[i];
		forNull++;
	}
	_ptr_[forNull] = '\0';
	return *this;
}

char _string::operator[] (int ind)
{
	char atIndex = _stringAt(ind);
	return atIndex;
}

bool _string::operator== (_string obj)
{
	if (_stringCompare(obj) == 0)
	{
		return true;
	}
	else
		return false;
}

bool _string::operator!= (_string obj)
{
	if (_stringCompare(obj) != 0)
	{
		return true;
	}
	else
		return false;
}

bool _string::operator< (_string obj)
{
	if (_stringCompare(obj) == -1)
	{
		return true;
	}
	else
		return false;
}

bool _string::operator> (_string obj)
{
	if (_stringCompare(obj) == 1)
	{
		return true;
	}
	else
		return false;
}


ostream& operator<< (ostream& c, const _string& obj)
{
	c << obj._ptr_;
	return c;
}

istream& operator>> (istream& c, _string& obj)
{
	c.getline(obj._ptr_,100);
	return c;
}

int main()
{
	char* ptr;
	ptr = new char[100];
	cout << "Enter string for parametized constructor: " << endl;
	cin.getline(ptr, 100);
	_string defaultcon;//for default constructor
	_string paracon(ptr);//for overloader
	cout << paracon<< endl;
	//length: determine the length of string
	int len;
	len = paracon._stringLen();
	cout <<"Length of string is " << len<<endl;
	//upper: convert the string to upper case
	_string obj1; cout << "Enter the string: (input thorugh >> overloading): " << endl;
	cin >> obj1;
	obj1._stringUpper();
	cout << "String converted to upper case...Output through << overloading: " << endl << obj1 << endl;
	//lower: convert the string to lower case
	obj1._stringLower();
	cout << "String converted to lower case: " << endl;
	cout << obj1 << endl;

	//at: return character at a given index
	int ind; cout << "Enter index: " << endl;
	cin >> ind;
	char letter = obj1._stringAt(ind);
	cout <<"Letter at index "<<ind<<" is " << letter << endl;

	//substring: extract a substring given start and end
	int strt, end; cout << "Enter starting and ending index for substring respectively " << endl;
	cin >> strt >> end;
	char* sub;
	sub = obj1._stringSubString(strt, end);
	cout<<"Sub String is \n" << sub << endl;

	//index: find starting index of a substring
	char* indexsub; indexsub = new char[100];
	cin.ignore(); cout << "Enter the subtring: " << endl;
	cin.getline(indexsub, 100);
	int indexofsubstring; indexofsubstring = obj1._stringStartIndex(indexsub);
	if (indexofsubstring != -1)
	{
		cout << "Starting Index of substring is " << indexofsubstring << endl;
	}
	else
	{
		cout << "Sub String not found" << endl;
	}

	//compare: compare two strings
	_string toCompare; cout << "Enter the string to comapre:\n"; cin >> toCompare;
	if (!obj1._stringCompare(toCompare))
	{
		cout << "Strings are equal" << endl;
	}
	else if (obj1._stringCompare(toCompare) == 404)
	{
		cout << "Strings have same size but not the same content." << endl;
	}
	else if (obj1._stringCompare(toCompare) == 1)
	{
		cout << "Strings are not equal. String 1 is greater in size" << endl;
	}
	else if (obj1._stringCompare(toCompare) == -1)
	{
		cout << "Strings are not equal. String 2 is greater in size" << endl;
	}
	_string toconcate; string conc; char* cstring; char charconc; int intconc; float floatconc; int size;
	
	//operators
	_string obj3;// cin.ignore();
	_string operatorchk; cout << "Enter string to check = operator overloading:"<<endl; cin >> operatorchk;
	obj3 = operatorchk;
	cout <<"Obj3 made equal to inputted string thorugh = overloading"<<endl << obj3 << endl;
	cout << "Now checking are the 2 objects equal" << endl;
	if (obj3 == operatorchk)
	{
		cout << "equal"<<endl;
	}
	else
		cout << "not equal" << endl;

	cout << "All following inputs will be compared with obj3" << endl;
	cout << "Enter string to check != operator overloading:\n";
	cin >> operatorchk;
	if (obj3 != operatorchk)
	{
		cout << "not equal" << endl;
	}
	else
		cout << "equal" << endl;

	cout << "Enter string to check < operator overloading:\n";
	cin >> operatorchk;
	if (obj3 < operatorchk)
	{
		cout << "string 2 greater" << endl;
	}
	else
		cout << "string 1 greater" << endl;

	cout << "Enter string to check > operator overloading:\n";
	cin >> operatorchk;
	if (obj3 > operatorchk)
	{
		cout << "string 1 greater" << endl;
	}
	else
		cout << "string 2 greater" << endl;

	int index; cout << "Enter index to check [] operator overloading:\n"; cin >> index;
    char specficIndex = obj3[index];
	cout << "Result: " << specficIndex << endl;

	//concat: concatenate/append the argument after current string. Cater cases for
	//different data
	//custom string data type
	cout << "CONCAT THrougGH OPERAOTRS" << endl;
	_string obj4; cin.ignore(); _string rsult;
	cout << "Enter string to check CONCAT through operator overloading:" << endl; cin >> obj4;
	cout << "Enter the string to concat(custom string data type)\n"; cin >> toconcate;
	rsult = obj4 + toconcate; cout << "in main "<<endl << rsult << endl;
	//built in string data type
	cout << "Enter the string to concat(built in string data type)\n"; getline(cin, conc);
	rsult = obj4 + conc;cout << "in main " << endl << rsult << endl;
	//c string
	cout << "Enter size of c string want to concate" << endl; cin >> size; size++; cstring = new char[size];
	cout << "Enter the string to concat(c string)\n"; cin.ignore(); cin.getline(cstring, size);
	rsult = obj4 + cstring; delete[]cstring;
	cout << "in main " << endl << rsult << endl;
	//char
	cout << "Enter the character to concat(char data type)\n"; cin >> charconc;
	rsult = obj4 + charconc;
	cout << "in main " << endl << rsult << endl;
	//int
	cout << "Enter the integr to concat(int data type)\n"; cin >> intconc;
	rsult = obj4 + intconc;
	cout << "in main " << endl << rsult << endl;
	//float
	cout << "Enter the float to concat(float data type)\n"; cin >> floatconc;
	rsult = obj4 + floatconc;
	cout << "in main " << endl << rsult << endl;
	 
	cout << endl;
	cout << "Prepend THrougGH OPERAOTRS" << endl;
	_string obj5; cin.ignore();
	cout << "Enter string to check Prepend through operator overloading:" << endl;
	cin >> obj5;
	//custom
	cout << "Enter the string to prepend(custom string data type)\n"; cin >> toconcate;
	rsult = toconcate+obj5;
	cout << "in main " << endl << rsult << endl;
	//built in string data type
	cout << "Enter the string to Prepend(built in string data type)\n"; getline(cin, conc);
	rsult = conc+obj5; cout << "in main " << endl << rsult << endl;
	//c string
	cout << "Enter size of c string want to concate" << endl; cin >> size; size++; cstring = new char[size];
	cout << "Enter the string to Prepend(c string)\n"; cin.ignore(); cin.getline(cstring, size);
	rsult = cstring+obj5; delete[]cstring;
	cout << "in main " << endl << rsult << endl;
	//char
	cin.clear();
	cout << "Enter the character to Prepend(char data type)\n"; cin >> charconc;
	rsult = charconc + obj5;
	cout << "in main " << endl << rsult << endl;
	//int
	cout << "Enter the integr to Prepend(int data type)\n"; cin >> intconc;
	rsult = intconc + obj5;
	cout << "in main " << endl << rsult << endl;
	//float
	cout << "Enter the float to Prepend(float data type)\n"; cin >> floatconc;
	rsult = floatconc + obj5;
	cout << "in main " << endl << rsult << endl;

	system("pause");
	return 0;
}


