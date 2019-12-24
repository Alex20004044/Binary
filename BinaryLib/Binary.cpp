// GLaba_3.cpp : Определяет функции для статической библиотеки.
//

#pragma once
#pragma warning (disable: 4996)
//#include "pch.h"
//#include "framework.h"
#include <iostream>
#include <string>
#include "Binary.h"
//#include "../BinaryLib/Binary.h"

using namespace std;

namespace binary {
	bool Binary::IsCorrectDigits(const char* _digits)
	{
		int i = 0;
		if (_digits[0] == '-' || _digits[0] == '+')
		{
			i = 1;
		}
		while (_digits[i] != '\0')
		{
			if (!(_digits[i] == '0' || _digits[i] == '1'))
			{
				return false;
			}
			i++;
		}
		return true;
	}

	void Binary::NormolizeDigits()
	{
		int l = strlen(digits);
		if (l != 1)
		{
			int j = 1;
			while (digits[j] == '0')
			{
				j++;
			}
			if (digits[j] == '\0')
			{
				j--;
				digits[0] = '0';
			}
			int i = 1;
			j--;
			for (; digits[i + j] != '\0'; i++)
			{
				digits[i] = digits[i + j];
			}
			digits[i] = '\0';
			length = strlen(digits);
		}
		else
		{
			SetDefaultDigits();
		}
	}
	void Binary::SetDefaultDigits()
	{
		length = 2;
		digits = new char[3];
		digits[0] = '0';
		digits[1] = '0';
		digits[2] = '\0';
	}
	string Binary::GetBin() const
	{
		return string(digits);
	}
	bool Binary::IsPositive() const
	{
		return digits[0] == '0';
	}
	long Binary::GetDec() const
	{
		int l = strlen(digits);
		long dec = 0;

		for (int i = 1; i < l; i++)
		{
			dec *= 2;
			dec += (digits[i] - 48);

		}
		if (digits[0] == '1')
		{
			dec = -dec;
		}
		return dec;
	}
	string Binary::GetInversalCode() const
	{
		
		char* str = new char[length + 1];

		if (digits[0] == '0')
		{
			strcpy(str, digits);
			return str;
		}
		else
		{
			str[0] = digits[0];
			int i = 1;
			while (digits[i] != '\0')
			{
				if (digits[i] == '0')
				{
					str[i] = '1';
				}
				else
				{
					str[i] = '0';
				}
				i++;
			}
			str[i] = '\0';
			string s = string(str);
			delete[] str;
			return s;

		}
	}
	string Binary::GetAdditionalCode() const
	{
		char* str = new char[length + 1];
		if (digits[0] == '0')
		{
			strcpy(str, digits);
			return str;
		}
		else
		{
			string temp = GetInversalCode();
			strcpy(str, temp.c_str());
			int l = strlen(str);
			int i = l - 1;
			while (true)
			{
				if (str[i] == '0')
				{
					str[i] = '1';
					break;
				}
				else
				{
					str[i] = '0';
					i--;
					if (i < 0)
					{
						break;
					}
				}
			}
			string s = string(str);
			delete[] str;
			return s;
		}
	}
	Binary Binary::Add(const Binary& arg)const
	{
		string fstr = GetAdditionalCode();
		char* fdigits = new char[length + 2];
		string sstr = arg.GetAdditionalCode();
		char* sdigits = new char[arg.length + 2];

		if (fstr.size() < sstr.size())
		{
			strcpy(fdigits, sstr.c_str());
			strcpy(sdigits, fstr.c_str());
		}
		else
		{
			strcpy(fdigits, fstr.c_str());
			strcpy(sdigits, sstr.c_str());
		}

		int fl = strlen(fdigits);
		int sl = strlen(sdigits);


		for (int i = fl + 1; i > 0; i--)
		{
			fdigits[i] = fdigits[i - 1];
		}
		for (int i = sl + 1; i > 0; i--)
		{
			sdigits[i] = sdigits[i - 1];
		}

		for (int i = fl + 2; i > 1; i--)
		{
			fdigits[i] = fdigits[i - 1];
		}
		for (int i = sl + 2; i > 1; i--)
		{
			sdigits[i] = sdigits[i - 1];
		}
		char* str = new char[fl + 2];

		str[fl + 2] = '\0';
		bool isAddOne = false;
		fl++;
		sl++;
		while (true)
		{
			if (fdigits[fl] == '0' && sdigits[sl] == '0')//0 && 0
			{
				if (isAddOne)
				{
					str[fl] = '1';
					isAddOne = false;
				}
				else
				{
					str[fl] = '0';
				}

			}
			else if (fdigits[fl] == '1' && sdigits[sl] == '1') // 1 && 1
			{
				if (isAddOne)
				{
					str[fl] = '1';
					isAddOne = true;
				}
				else
				{
					str[fl] = '0';
					isAddOne = true;
				}
			}
			else//0 && 1 || 1 && 0
			{
				if (isAddOne)
				{
					str[fl] = '0';
					isAddOne = true;
				}
				else
				{
					str[fl] = '1';
				}
			}

			fl--;


			if (fl < 0)
			{
				break;
			}
			sl--;
			if (sl == 0)
			{
				sl = 1;
			}
			if (fl == 0)
			{
				sl = 0;
			}
		}
		int strl = strlen(str) + 1;
		/*
		for (int i = strl; i > 0; i--)
		{
		str[i] = str[i - 1];
		}
		if (isAddOne)
		{
		str[0] = '1';
		}
		else
		{
		str[0] = '0';
		}*/

		if (str[0] != str[1])
		{
			throw OVERFLOW;
			//return Binary();
		}
		else
		{
			for (int i = 0; i < strl; i++)
			{
				str[i] = str[i + 1];
			}


			if (str[0] == '0')
			{
				return Binary(str);
			}
			else
			{
				Binary b;
				b.SetBinaryWithAdditionalCode(str);
				return b;
			}
		}

	}
	void Binary::SetBinaryWithAdditionalCode(const char* _digits)
	{
		if (IsCorrectDigits(_digits))
		{
			delete[] digits;
			digits = new char[strlen(_digits) + 1];
			strcpy(digits, _digits);
			string temp = GetAdditionalCode();
			strcpy(digits, temp.c_str());
			NormolizeDigits();
			length = strlen(digits);
		}
	}
	Binary& Binary::GetPreInc()
	{
		Binary inc;
		inc = Binary("01");
		*this = Add(inc);
		return *this;
	}
	Binary& Binary::GetPreDec()
	{
		Binary inc("11");
		//inc = Binary("11");
		*this = Add(inc); // not recommended
		return *this;
	}
	Binary Binary::GetPostInc()
	{
		Binary b = Binary(*this);
		Binary dec;
		dec = Binary("01");
		*this = Add(dec);
		return b;
	}
	Binary Binary::GetPostDec()
	{
		Binary b = Binary(*this);
		Binary dec;
		dec = Binary("11");
		*this = Add(dec);
		return b;
	}
	Binary Binary::GetMinusBin() const
	{
		string str = GetBin();
		if (str.c_str() == "00")
		{
			return Binary(*this);
		}
		if (str[0] == '0')
		{
			str[0] = '1';
		}
		else
		{
			str[0] = '0';
		}
		Binary b = Binary(str.c_str());
		return b;
	}
	Binary operator+(const Binary& lv, const Binary& rv) {
		return rv.Add(lv);
	}
	Binary operator-(const Binary& lv, const Binary& rv) {
		return lv.Add(rv.GetMinusBin());
	}
	Binary& Binary::operator++()
	{
		return this->GetPreInc();
	}
	Binary& Binary::operator--()
	{
		return this->GetPreDec();
	}
	Binary  Binary::operator++(int)
	{
		return this->GetPostInc();
	}
	Binary Binary::operator--(int)
	{
		return this->GetPostDec();
	}
	Binary Binary::operator-() {
		return this->GetMinusBin();
	}
	bool operator==(const Binary& lv, const Binary& rv) {
		return lv.GetBin() == rv.GetBin();
	}
	bool operator!=(const Binary& lv, const Binary& rv) {
		return lv.GetBin() != rv.GetBin();
	}
	ostream& operator << (ostream& out, const Binary& bin)
	{
		out << bin.GetBin();
		return out;
	}
	istream& operator >> (istream& in, Binary& bin)
	{
		in >> bin;
		return in;
	}
	Binary::Binary()
	{
		SetDefaultDigits();
	}
	Binary::Binary(const long &num)
	{
		int i = 0;
		long num_cpy = num;
		while (true)
		{
			num_cpy /= 2;
			i++;
			if (num_cpy == 0)
			{
				break;
			}
		}
		try{
			digits = new char[i + 2];
		}
		catch (bad_alloc)
		{
			SetDefaultDigits();
		}
		length = i + 1;
		ltoa(abs(num), digits + 1, 2);
		if (num >= 0)
		{
			digits[0] = '0';
		}
		else
		{
			digits[0] = '1';
		}
	}
	Binary::Binary(const char* _digits)
	{

		if (IsCorrectDigits(_digits))
		{
			length = strlen(_digits);
			digits = new char[length + 1];
			int j = 0;
			if (_digits[0] == '-')
			{
				digits[0] = '1';
				j++;
			}
			else if (_digits[0] == '+')
			{
				digits[0] = '0';
				j++;
			}
			int l = strlen(_digits);

			for (int i = j;; i++)
			{
				if (_digits[i] != '\0')
				{
					digits[i] = _digits[i];
				}
				else
				{
					digits[i] = '\0';
					break;
				}
			}
			NormolizeDigits();
		}
		else
		{
			SetDefaultDigits();
		}
	}

	Binary::~Binary()
	{
		//length = -1;
		delete[]digits;
	}

	Binary::Binary(const Binary& rv)
	{
		digits = new char[rv.length + 1];
		for (int i = 0; i < rv.length + 1; i++)
		{
			digits[i] = rv.digits[i];
		}
		length = rv.length;
	}
	Binary& Binary::operator=(const Binary& rv)//A=A;
	{
		if (&rv == this)
		{
			return *this;
		}
		char* temp;
		temp = new char[rv.length + 1];
		delete[] digits;
		digits = temp;
		for (int i = 0; i < rv.length + 1; i++)
		{
			digits[i] = rv.digits[i];
		}
		length = rv.length;
		return *this;
	}
	Binary::Binary(Binary&& rv)
	{
		char * temp;
		temp = digits;
		digits = rv.digits;
		length = rv.length;
		rv.digits = temp;
	}
	Binary& Binary::operator=(Binary&& rv)
	{
		char * temp;
		temp = digits;
		digits = rv.digits;
		length = rv.length;
		rv.digits = temp;
		return *this;
	}
}
