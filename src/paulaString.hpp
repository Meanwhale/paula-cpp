#pragma once

#ifndef _PSTRING_H_
#define _PSTRING_H_

#include "paula.hpp"

class PString
{
public:
	PString ();
	~PString ();
	PString (const char *);
	PString (const char *, int start, int end);

	// access

	const char * get();

private:
	int size;
	char * data;
};


#endif