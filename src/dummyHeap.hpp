#pragma once

#ifndef _DUMMY_HEAP_H_
#define _DUMMY_HEAP_H_

#include "paula.hpp"

class DummyHeap
{
public:
	DummyHeap();
	~DummyHeap();
	void* alloc(INT32);
	void free(void*);
	void reset();
	void info();
	
	INT32 getNumAllocs();
	INT32 getNumDeletes();
	INT32 getSize();
	INT32 getTop();

private:
	INT32 size, top;
	INT32 data[HEAP_SIZE];
	INT32 numAllocs, numDeletes;
};


#endif
