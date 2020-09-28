#include "pch.h"
#include <iostream>
using namespace std;

class Count {
private:
	float value = 0;
public:
	Count() {
		
		while (true) {
			cout << "Enter value: ";
			cin >> value;

			try {
				if (value <= 0)
					throw - 1;
				break;
			}
			catch (int a) {
				cout << "False, bitch" << endl;
			}
		}
	}
	Count(float val) :value(val) {}
	Count(const Count& other) {
		value = other.value;
	}
		Count operator+(const Count& other) {
			return Count(this->value + other.value);
		}
		Count operator-(const Count& other) {
			return Count(this->value - other.value);
		}
		Count operator*(const Count& other) {
			return Count(this->value * other.value);
		}
		Count operator/(const Count& other) {
			return Count(this->value / other.value);
		}
	
	friend std::ostream& operator<<(std::ostream& out, const Count &d1);
};

std::ostream& operator<<(std::ostream& out, const Count &count)
{
	out << count.value;
	return out;
}


int main()
{
	Count x;
	Count y;
	Count sum = x + y;
	Count dec = x - y;
	Count mult = x * y;
	Count div = x / y;
	cout << sum << endl;
	cout << dec << endl;
	cout << mult << endl;
	cout << div << endl;
}
