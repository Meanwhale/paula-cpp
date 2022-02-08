// MiniMean.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include "paula.hpp"

#ifdef EXTRA_LOAD
#include <string>
#endif


void allocTest()
{
	int top = heap.getTop();
	int all = heap.getNumAllocs();
	int del = heap.getNumDeletes();

	int* i = new int(123);
	int* array = new int[5];
	char* c = new char('a');
	
	ASSERT(*i == 123, allocErrorMsg);
	ASSERT(heap.getTop() == top + 10, allocErrorMsg);
	ASSERT(heap.getNumAllocs() == all + 3, allocErrorMsg);
	ASSERT(heap.getNumDeletes() == del + 0, allocErrorMsg);

	delete i;
	delete c;
	delete[] array;
	
	ASSERT(heap.getNumAllocs() == all + 3, allocErrorMsg);
	ASSERT(heap.getNumDeletes() == del + 3, allocErrorMsg);
}

void stringTest()
{
	ASSERT(compare("abc", "abc") == 0, "");
	ASSERT(compare("abc", "bc") == -1, "");
	ASSERT(compare("bc", "abc") == 1, "");
	
	PString s("abc");

	ASSERT(compare(s.get(), "abc") == 0, "");
}

#ifdef PAULA_DEBUG
void stdRead()
{
	// read until EOF (Ctrl-Z)
	constexpr int BUFFERSIZE = 100;
    char buffer[BUFFERSIZE];
    sayl("Enter a message:");
    while(fgets(buffer, BUFFERSIZE , stdin) != NULL)
    {
        sayl(buffer);
    }
}
void sayNumberTest()
{
	say(1234567);
	sayl("");
	say(1234567890);
	sayl("");
	say(-345);
	sayl("");
	say(0);
	sayl("");
	say(1);
}
#endif

int paulaMain()
{
	stringTest();

	allocTest();
#ifdef EXTRA_LOAD
	std::string s("a");
	say(s.c_str());
#endif
	sayl("");
	heap.info();
	return 0;
}