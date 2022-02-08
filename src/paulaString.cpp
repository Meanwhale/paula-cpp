#include "paulaString.hpp"

PString::PString () : size(-1), data(0)
{
}
PString::~PString ()
{
	delete data;
}
PString::PString (const char * s)
{
	int len = getLength(s);
	data = new char[len];
	copy(s, data, 0, 0, len);
}
PString::PString (const char * s, int start, int end)
{
}
const char * PString::get()
{
	return data;
}