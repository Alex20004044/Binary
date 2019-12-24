#pragma warning (disable: 4996)
#include <iostream>
#include <string>
using namespace std;

namespace binary {

	class Binary
	{
	private:
		char* digits;
		int length;
		void NormolizeDigits();
		void SetDefaultDigits();
	public:
		static bool IsCorrectDigits(const char* _digits);
		Binary();
		Binary(const long& num);
		Binary(const char* _digits);
		~Binary();
		Binary(const Binary&);
		Binary(Binary&&);
		Binary& operator=(const Binary&);
		Binary& operator=(Binary&&);
		string GetBin() const;
		bool IsPositive() const;
		long GetDec() const;
		string GetInversalCode() const;
		string GetAdditionalCode() const;
		Binary Add(const Binary& arg) const;
		void SetBinaryWithAdditionalCode(const char* _digits);
		Binary& GetPreInc();
		Binary& GetPreDec();
		Binary GetPostInc();// <--GetPostInc(Binary&)
		Binary GetPostDec();
		Binary GetMinusBin() const;
		friend Binary operator+(const Binary& lv, const Binary& rv);
		friend Binary operator-(const Binary& lv, const Binary& rv);//long x = 5; Binary y (10); Binary(x) + y; y + Binary(x); y+x; x + y; 
		friend bool operator==(const Binary& lv, const Binary& rv);
		friend bool operator!=(const Binary& lv, const Binary& rv);
		Binary operator-();
		Binary& operator--(); // ++x -> Binary& operator++(); x++ -> Binary operator++(int)
		Binary& operator++();
		Binary operator-- (int); //??
		Binary operator++(int);
		friend ostream& operator << (ostream& out, const Binary& bin);
		friend istream& operator >> (istream& in, Binary& bin);
	};
}
