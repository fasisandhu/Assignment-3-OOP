#include <iostream>
#include <cmath>
using namespace std;

class VectorType
{
private:
		//necessary variables of pointers type
		double* x; double* y; double* z;
public:
	VectorType();//default
	VectorType(double* x, double* y, double* z);//parametized
	VectorType(const VectorType&);//copyconstructor
	~VectorType();//destructor
	VectorType& operator=(const VectorType&);//Overloaded assignment operator
	VectorType operator*(const VectorType&);//multiplication overloading
	VectorType operator+(const VectorType&);//addition overloading
	VectorType operator-(const VectorType&);//subtraction overloading
	VectorType operator++();//preinc overloading
	VectorType operator++(int);//postinc overloading
	VectorType operator--();//predec overloading
	VectorType operator--(int);//postdec overloading
	friend bool operator==(const VectorType&, const VectorType);//== overloading
	friend bool operator!=(const VectorType&, const VectorType);//!= overloading
	friend ostream& operator<<(ostream&,const VectorType&);//<< overloading
	friend istream& operator>>(istream&, VectorType&);//>> overloading
	double dotProduct(VectorType&);//dotproduct
	double length();//length of vector
	double angle(VectorType&);//angle

};

VectorType::VectorType()//default
{
	x = new double;y = new double;z=new double;
	*x = 1; *y = 1; *z = 1;
}

VectorType::VectorType(double* x, double* y, double* z)//parametized
{
	this->x = new double; this->y = new double; this->z = new double;
	this->x = x; this->y = y; this->z = z;
}

VectorType::VectorType(const VectorType& _object_)//copyconstructor
{
	x = new double; y = new double; z = new double;
	*x = *_object_.x;*y = *_object_.y;*z = *_object_.z;
}

VectorType::~VectorType()//destructor
{
	delete x; x = NULL;
	delete y; y = NULL;
	delete z; z = NULL;
}

VectorType& VectorType::operator=(const VectorType& _object_)//assignment operator
{
	if (&_object_ != this)
	{
		delete x; delete y; delete z;
		x = nullptr; y = nullptr; z = nullptr;
		x = new double; y = new double; z = new double;
		*x = *_object_.x; *y = *_object_.y; *z = *_object_.z;
		return *this;
	}
}

VectorType VectorType::operator*(const VectorType& _object_)//multiplication operator
{
	VectorType _temp;
	*_temp.x = (*x) * (*_object_.x);
	*_temp.y = (*y) * (*_object_.y);
	*_temp.z = (*z) * (*_object_.z);
	return _temp;
}

VectorType VectorType::operator+(const VectorType&_object_)//addition operator
{
	VectorType _temp;
	*_temp.x = *x + *_object_.x;
	*_temp.y = *y + *_object_.y;
	*_temp.z = *z + *_object_.z;
	return _temp;
}

VectorType VectorType::operator-(const VectorType& _object_)//subtracion operator
{
	VectorType _temp;
	*_temp.x = *x - *_object_.x;
	*_temp.y = *y - *_object_.y;
	*_temp.z = *z - *_object_.z;
	return _temp;
}

VectorType VectorType::operator++()//preinc overloading
{
	++(*x); ++(*y); ++(*z);
	return *this;
}

VectorType VectorType::operator++(int)//postinc overloading
{
	VectorType _temp = *this;
	(*x)++; (*y)++; (*z)++;
	return _temp;
}

VectorType VectorType::operator--()//predec overloading
{
	--(*x); --(*y); --(*z);
	return *this;
}

VectorType VectorType::operator--(int)//postidec overloading
{
	VectorType _temp = *this;
	(*x)--; (*y)--; (*z)--;
	return _temp;
}

bool operator==(const VectorType& _object_1, const VectorType _object_2)//== overloading
{
	return(*_object_1.x == *_object_2.x && *_object_1.y == *_object_2.y && * _object_1.z == *_object_2.z);
}

bool operator!=(const VectorType& _object_1, const VectorType _object_2)//!= overloading
{
	return(*_object_1.x != *_object_2.x || *_object_1.y != *_object_2.y || *_object_1.z != *_object_2.z);
}

ostream& operator<<(ostream& c, const VectorType& _object_)//<< overloading
{
	c << "X:" << *_object_.x<<endl;
	c << "Y:" << *_object_.y<<endl;
	c << "Z:" << *_object_.z<<endl;
	return c;
}

istream& operator>>(istream& c, VectorType& _object_)//>> overloading
{
	c >> *_object_.x>>*_object_.y >> *_object_.z;
	return c;
}

double VectorType::dotProduct(VectorType& _object_)//dotproduct
{
	VectorType _temp;
	_temp = (*this) * _object_;
	double result;
	result = (*_temp.x) + (*_temp.y) + (*_temp.z);
	return result;
}

double VectorType::length()//length of vector
{
	double _temp;
	_temp = sqrt(pow(*x, 2) + pow(*y, 2) + pow(*z, 2));
	return _temp;
}

double VectorType::angle(VectorType &_object_)//angle
{
	double _temp;
	_temp = dotProduct(_object_);
	double l1 = length();
	double l2 = _object_.length();
	double result;
	result = acos(_temp/(l1*l2));
	return result;
}


int main()
{
	//************************TASK-1****************************
	double *x,* y,* z;
	x = new double; y = new double; z = new double;
	cout << "Enter x for V vector:" << endl;
	cin >> *x;
	cout << "Enter y for V vector:" << endl;
	cin >> *y;
	cout << "Enter z for V vector:" << endl;
	cin >> *z;
	VectorType U;//default
	VectorType V(x, y,z);//parametized
	VectorType CopyConstructor = V;//copyconstructor
	cout << "Values of U vector" << endl << U;//<< overloading
	cout << "Values of V vector"<< endl << V;//<< overloading
	U = V;//assignment overloading
	cout << "Enter new values of X,Y,Z for U vector:" << endl;
	cin >> U;//>>overloading
	cout << "New Values of U vector" << endl << U;//<< overloading
	double dot;
	dot = U.dotProduct(V);
	cout << "Dot Product is " <<dot <<endl;
	double len1;
	len1 = U.length();
	cout << "Length of U vector is " << len1 << endl;
	double len;
	len = V.length();
	cout << "Length of V vector is " << len << endl;
	double angle;
	angle = U.angle(V);
	cout << "Angle between vectorS is " << angle <<" radians" << endl;
	VectorType add;
	add = U + V;
	cout << "Additon Overloading(U+V)" << endl;
	cout << add;
	VectorType sub;
	sub = U - V;
	cout << "Subtraction Overloading(U-V)" << endl;
	cout << sub;
	VectorType mult;
	mult = U * V;
	cout << "Multiplication Overloading(U*V)" << endl;
	cout << mult;
	cout << "Increments Overloading" << endl;
	++U;
	cout << "Pre Increment of U vector(++U)" << endl;
	cout << U;
	VectorType Post;
	Post = U++;
	cout << "Post Increment with U vector(Post=U++)" << endl;
	cout << "Incremented values of Post vector after post increment(Post=U++)" << endl;
	cout << Post;
	cout << "Incremented values of U vector after post increment(Post=U++)" << endl;
	cout << U;
	cout << "Decrements Overloading" << endl;
	--U;
	cout << "Pre Decrement of U vector(--U)" << endl;
	cout << U;
	VectorType PostDec;
	PostDec = U--;
	cout << "Post Decrement with U vector(PostDec=U--)" << endl;
	cout << "Decremented values of PostDec vector after post Decrement(PostDec=U--)" << endl;
	cout << PostDec;
	cout << "Decremented values of U vector after post Decrement(PostDec=U--)" << endl;
	cout << U;

	if (U != V)
	{
		cout << "U and V are not equal.Result through != overloading"<<endl;
	}
	else
	{
		cout << "U and V are equal.Result through != overloading" << endl;
	}
	U = V;//assignment overloading
	cout << "Making U and V equal through assignment overloading." << endl;
	if (U == V)
	{
		cout << "U and V are equal.Result through == overloading" << endl;
	}
	else
	{
		cout << "U and V are not equal.Result through == overloading" << endl;
	}
	//**************************************************************************


	system("pause");
	return 0;
}