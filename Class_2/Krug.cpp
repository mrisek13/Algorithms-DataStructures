#include "Krug.h"

Krug::Krug(void)
{
	radius = 0;
}

Krug::Krug(double _radius)
{
	radius = _radius;
}


Krug::~Krug(void)
{
}

double Krug::getPovrsina() const
{
	return radius * radius * PI;
}

void Krug::setPovrsina(double _povrsina)
{
	radius = sqrt(_povrsina / PI);
}

double Krug::getOpseg() const
{
	return 2 * radius * PI;
}

void Krug::setOpseg(double _opseg)
{
	radius = _opseg / (2 * PI);
}

double Krug::getRadius() const
{
	return radius;
}

void Krug::setRadius(double _radius)
{
	radius = _radius;
}

string Krug::Opis() const
{
	stringstream ss;
	ss << "Krug - Radius=" << getRadius() <<
		", Opseg=" << getOpseg() <<
		", Povrsina=" << getPovrsina();
	return ss.str();
}