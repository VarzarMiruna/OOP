#include "Number.h"

Number::Number(const char* value, int base)
{
	this->baza = base;
	if (value == "0") {
		this->valoare = 0;
	}
	int power = 1;
	int num = 0;
	int i;
	int len = strlen(value);
	for (i = len - 1; i >= 0; i--)
	{
		num += charToInt(value[i]) * power;
		power = power * base;
	}
	valoare = num;
}


Number::Number(const Number& d) //copy
{
	this->valoare = d.valoare;
	this->baza = d.baza;
}


Number::Number(const int charToInt)
{
	this->valoare = charToInt;
}
Number::Number(const char* str)
{
	int power = 1;
	int num = 0;
	int i;
	int len = strlen(str);
	for (i = len - 1; i >= 0; i--)
	{
		num += charToInt(str[i]) * power;
		power = power * baza;
	}
	valoare = num;
}
int Number::charToInt(char c)
{
	printf("Convert char to int\n");
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10; //pt baze cu litere
}


char Number::intToChar(int num)
{
	printf("Convert int to char\n");
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}
void Number::strev(char* str)
{
	printf("reverse\n");
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int Number::operator[](int index)
{
	printf("index\n");
	int x = valoare;
	char res[500];
	int ind = 0;
	while (x > 0)
	{
		res[ind++] = intToChar(x % baza);
		x /= baza;
	}
	res[ind] = '\0';

	strev(res);
	return res[index];
}
void Number::Print()
{
	int v = valoare;
	char res[500];
	int index = 0;  // Initialize index of result 

	// Convert input number is given base by repeatedly 
	// dividing it by base and taking remainder 
	while (v > 0)
	{
		res[index++] = intToChar(v % baza);
		v /= baza;
	}
	res[index] = '\0';

	// Reverse the result 
	strev(res);

	cout << res << endl;

}


Number operator+(Number lhs, Number rhs)
{
	printf("Operatorul friend +\n");
	int maxx = 0;
	if (lhs.baza > rhs.baza)
		maxx = lhs.baza;
	else
		maxx = rhs.baza;
	Number temp("0", maxx);
	temp.valoare = lhs.valoare + rhs.valoare;
	return temp;
}
Number operator- (Number lhs, Number rhs)
{
	printf("Operatorul friend -\n");
	int maxx = 0;
	if (lhs.baza > rhs.baza)
		maxx = lhs.baza;
	else
		maxx = rhs.baza;
	Number temp("0", maxx);
	if (lhs.valoare > rhs.valoare)
		temp.valoare = lhs.valoare - rhs.valoare;
	else
		temp.valoare = rhs.valoare - lhs.valoare;

	return temp;
}
bool Number:: operator== (const Number& n)
{
	printf("Operatorul ==\n");
	if (n.valoare == valoare)
		return true;
	else
		return false;

}
bool Number:: operator> (const Number& n)
{
	printf("Operatorul >\n");
	if (n.valoare > valoare)
		return true;
	else
		return false;

}
bool Number:: operator< (const Number& n)
{
	printf("Operatorul <\n");
	if (n.valoare < valoare)
		return true;
	else
		return false;

}
bool Number:: operator<= (const Number& n)
{
	printf("Operatorul <=\n");
	if (n.valoare <= valoare)
		return true;
	else
		return false;

}
bool Number:: operator>= (const Number& n)
{
	printf("Operatorul >=\n");
	if (n.valoare >= valoare)
		return true;
	else
		return false;

}
bool Number:: operator!= (const Number& n)
{
	printf("Operatorul !=\n");
	if (n.valoare != valoare)
		return true;
	else
		return false;

}
bool Number:: operator! () const
{
	printf("Operatorul !\n");
	return (valoare == 0);
}
Number Number :: operator--(int)
{
	printf("Postfixare: operatorul --\n");
	int x = valoare;
	char res[500];
	int index = 0;

	while (x > 0)
	{
		res[index++] = intToChar(x % baza);
		x /= baza;
	}
	res[index] = '\0';

	strev(res);
	res[strlen(res) - 1] = '\0';

	int power = 1;
	int num = 0;
	int i;
	int len = strlen(res);
	for (i = len - 1; i >= 0; i--)
	{
		num += charToInt(res[i]) * power;
		power = power * baza;
	}
	valoare = num;
	return(*this);


}
Number& Number ::operator-- ()
{
	printf("Prefixare: operatorul --\n");
	int x = valoare;
	char res[500];
	int index = 0;

	while (x > 0)
	{
		res[index++] = intToChar(x % baza);
		x /= baza;
	}
	res[index] = '\0';

	strev(res);

	int i, len = strlen(res);
	for (i = 1; i < len; i++)
	{
		res[i - 1] = res[i];
	}
	res[i - 1] = '\0';

	int power = 1;
	int num = 0;
	int j;
	int lun = strlen(res);
	for (j = lun - 1; j >= 0; j--)
	{
		num += charToInt(res[j]) * power;
		power = power * baza;
	}
	valoare = num;
	return(*this);

}
void Number::operator+=(Number i)
{
	printf("Operatorul +=\n");
	if (baza > i.baza)
		baza = baza;
	else
		baza = i.baza;
	valoare = valoare + i.valoare;
}


void Number::SwitchBase(int newbase)
{
	baza = newbase;
}
int Number::GetBase()
{
	return baza;
}
int Number::GetDigitsCount()
{
	int x = valoare;
	char res[500];
	int index = 0;
	while (x > 0)
	{
		res[index++] = intToChar(x % baza);
		x /= baza;
	}
	res[index] = '\0';

	strev(res);
	int c = strlen(res);
	return c;

}