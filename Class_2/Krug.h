#pragma once
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

const double PI = 3.141592;

class Krug
{
	double radius;//private
public:
	Krug(void);
	Krug(double _radius);

	~Krug(void); //destruktor

	double getPovrsina() const;
	void setPovrsina(double _povrsina);
	double getOpseg() const;
	void setOpseg(double _opseg);
	double getRadius() const;
	void setRadius(double _radius);
	string Opis()const;
};

