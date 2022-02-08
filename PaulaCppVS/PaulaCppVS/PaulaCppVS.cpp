#include "paula.hpp"

int floatToIntBits(float f)
{
	char * c = (char*)&f;
	int i = 0;
	i |= (int)((c[3] << 24)		& 0xff000000);
	i |= (int)((c[2] << 16)		& 0x00ff0000);
	i |= (int)((c[1] << 8)		& 0x0000ff00);
	i |= (int)((c[0])			& 0x000000ff);
	return i;
}

int main ()
{
	float flo = -123.456f;
	
	int i = floatToIntBits(flo);

	float uusiluku = (*reinterpret_cast<float*>(&(i)));

	return paulaMain();
}