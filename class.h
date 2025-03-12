#pragma once
#include <iostream>
#include <string>
#include  <fstream>
using namespace std;

//Вариант 9
class plan {
private:
	int expect;
	int actual;
public:
	//конструкторы
	plan() {
		this->expect = 0;
		this->actual = 0;
	}
	plan(int e, int a) {
		this->expect = e;
		this->actual = a;
	}
	//деструктор
	~plan() {};
	//функции доступа
	int get_E() const { return this->expect; }
	int get_A() const { return this->actual; }
	void set_E(int e) { this->expect = e; }
	void set_A(int a) { this->actual = a; }

	friend istream& operator >>(istream& in, plan& p);

	plan& operator = (const plan& p) {
		if (this != &p) {
			this->expect = p.expect;
			this->actual = p.actual;
		}
		return *this;
	}
};

class Factory {
private:
	string Factory_name;
	string product_name;
	plan quartal[4];

public:
	Factory();
	Factory(string F, string p, plan* q);
	Factory(const Factory& F);
	~Factory() {};

	void set_F(string newF);
	string get_F() const;
	void set_P(string newP);
	string get_P() const;

	int get_QS() const noexcept {
		return quartal[0].get_A() + quartal[1].get_A() + quartal[2].get_A() + quartal[3].get_A();
	}

	plan* get_Q();

	bool exp_act(); // exp != actual хоть в 1 квартале
	int cnt_actual(); // сумма факт. выпущенной продукции

	Factory& operator = (const Factory& F);
	friend istream& operator >> (istream& in, Factory& F);
	friend ostream& operator << (ostream& out, const Factory& F);
	bool operator == (Factory& other);
	bool operator < (Factory& other);
	bool operator > (Factory& other);
};