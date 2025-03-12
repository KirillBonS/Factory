#include "class.h"

Factory::Factory() {
	this->Factory_name = "SomeFactory";
	this->product_name = "SomeProduct";
	for (int i = 0; i < 4; i++) quartal[i] = plan();
}

Factory::Factory(string F, string p, plan* q) {
	this->Factory_name = F;
	this->product_name = p;
	//if (this->quartal) {
	//	delete[] this->quartal;
	//}
	for (int i = 0; i < 4; i++) {
		this->quartal[i] = q[i];
	}

}
Factory::Factory(const Factory& F) {
	if (this != &F) {
		delete[] this->quartal;
		this->Factory_name = F.Factory_name;
		this->product_name = F.product_name;
		for (int i = 0; i < 4; i++) {
			this->quartal[i] = F.quartal[i];
		}
	}
}

// МЕТОДЫ

void Factory::set_F(string newF) {
	this->Factory_name = newF;
}
string Factory::get_F() const {
	return this->Factory_name;
}
void Factory::set_P(string newP) {
	this->product_name = newP;
}
string Factory::get_P() const {
	return this->product_name;
}

plan* Factory::get_Q() {
	return this->quartal;
}

bool Factory::exp_act() {
	for (int i = 0; i < 4; i++) {
		if (this->quartal[i].get_A() != this->quartal[i].get_E()) {
			return true;
			break;
		}
	}
	return false;
}

int Factory::cnt_actual() {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		// берём actual из quartal[i]
		sum += this->quartal[i].get_A();
	}
	return sum;
}

// ПЕРЕГРУЗКА ОПЕРАЦИЙ

// присваивания
Factory& Factory:: operator = (const Factory& F) {
	if (this != &F) {
		delete[] this->quartal;
		this->Factory_name = F.Factory_name;
		this->product_name = F.product_name;
		for (int i = 0; i < 4; i++) {
			this->quartal[i] = F.quartal[i];
		}
	}
	return *this;
}

// ввода значений в поля данных
istream& operator >>(istream& in, plan& p) {
	int temp_exp, temp_act;
	in >> temp_exp >> temp_act;
	p.set_E(temp_exp);
	p.set_A(temp_act);
	return in;
}

istream& operator >>(istream& in, Factory& F) {
	cout << "Type the Factory name" << endl;
	string temp_F, temp_P;
	in >> temp_F;
	cout << "Type the product name" << endl;
	in >> temp_P;
	F.set_F(temp_F); F.set_P(temp_P);
	for (int i = 0; i < 4; i++) {
		cout << "Type expected and actual data for " << i << " quartal" << endl;
		in >> F.quartal[i];
	}
	return in;
}

// вывода данных на экран
ostream& operator << (ostream& out, const Factory& F) {
	out << F.Factory_name << ",";
	out << F.product_name << ",{";
	for (int i = 0; i < 4; i++) {
		plan temp = F.quartal[i];
		out << "(" << temp.get_E() << ", ";
		out << temp.get_A() << ") ";
	}
	out << "}" << endl;
	return out;
}


// сравнения двух объектов (частич. равенство по кол-ву вып. продукции)
bool Factory::operator == (Factory& other) {
	return cnt_actual() == other.cnt_actual();
}

bool Factory::operator < (Factory& other) {
	return cnt_actual() < other.cnt_actual();
}

bool Factory::operator > (Factory& other) {
	return cnt_actual() > other.cnt_actual();
}

//// сравнения двух объектов (полное равенство)
//bool Factory::operator == (Factory& other) {
//	if (get_F() != other.Factory_name) return false;
//	if (get_P() != other.product_name) return false;
//	if (cnt_actual() != other.cnt_actual()) return false;
//	return true;
//}