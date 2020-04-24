// MiniMean.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include "paula.hpp"

#ifdef EXTRA_LOAD
#include <string>
#endif

int paulaMain()
{
	int* i = new int(123);
	int* array = new int[5];
	char* c = new char('a');
	say(*i);
	say(*c);
	delete i;
	delete c;
	delete[] array;
#ifdef EXTRA_LOAD
	std::string s("a");
	say(s.c_str());
#endif
	sayl("");
	heap.info();
	return 0;
}
#ifdef PAULA_DEBUG
void stdRead()
{
	// read until EOF (Ctrl-Z)
	constexpr int BUFFERSIZE = 10;
    char buffer[BUFFERSIZE];
    printf("Enter a message: \n");
    while(fgets(buffer, BUFFERSIZE , stdin) != NULL)
    {
        printf("%s\n", buffer);
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