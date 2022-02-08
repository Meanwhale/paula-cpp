#include "paula.hpp"
#include "dummyHeap.hpp"
#include <stdlib.h>

DummyHeap heap;

// HEAP

DummyHeap::DummyHeap() :
	size(HEAP_SIZE),
	top(0),
	numAllocs(0),
	numDeletes(0)
{
}
DummyHeap::~DummyHeap()
{
#if PAULA_DEBUG
	if (numAllocs == numDeletes) sayl("Dummy heap exit cleanly!");
	else sayl("Dummy heap is not empty...");
#endif
}

INT32 DummyHeap::getNumAllocs()		{ return numAllocs;		}
INT32 DummyHeap::getNumDeletes()	{ return numDeletes;	}
INT32 DummyHeap::getSize()			{ return size;			}
INT32 DummyHeap::getTop()			{ return top;			}

void* DummyHeap::alloc(INT32 _s)
{
	int s = (_s / 4);
	if ((_s % 4) != 0) s++;
	ASSERT(size > top + s + 1, allocErrorMsg);
#if PAULA_DEBUG
	sayl("alloc");
	numAllocs++;
#endif
	data[top] = s;
	void * ptr = data + top + 1;
	top += 1 + s;
	return ptr;
}

void DummyHeap::free(void * ptr)
{
	if (ptr == 0) return;
#if PAULA_DEBUG
	sayl("delete");
	sayl((*((int*)ptr-1)));
	numDeletes++;
#endif
}
void DummyHeap::reset()
{
	ASSERT(numAllocs == 0 && numDeletes == 0, allocErrorMsg);
	top = 0;
}
void DummyHeap::info()
{
#ifdef PAULA_DEBUG

	say("DummyHeap info\n");
	say("allocs:   ");   say(numAllocs);
	say("\ndeletes:  "); say(numDeletes);
	for (int i=0; i<top; i++)
	{
		say("\n"); say(i); say(": "); say(data[i]);
	}
	say("\n");
#endif
}

