#include "paula.hpp"
#include <stdio.h>
#include <stdlib.h>

void say(char c)
{
	putchar(c);
}
void say(const char * s)
{
	for (int i = 0; s[i] != '\0'; i++) putchar(s[i]);
}
void sayHex(INT32 i)
{
	say("TODO"); say(i);
}
void say(INT32 i)
{
	if (i==0) { say('0'); return; }
	if (i<0) { say('-'); i=-i; }
	INT32 div = 1000000000;
	while ((i / div) == 0) div /= 10;
	for (; div > 0; div /= 10) {		
		say((char)('0' + ((i / div) % 10)));
	}
}
void sayl(char s)         { say(s); say('\n'); }
void saylHex(int s)       { say(s); say('\n'); }
void sayl(int s)          { say(s); say('\n'); }
void sayl(const char * s) { say(s); say('\n'); }


#ifdef OVERLOAD_NEW
#ifdef WIN32
void * operator new(size_t count) {	return heap.alloc(count); }
void * operator new[](size_t count) { return heap.alloc(count); }
void operator delete(void * ptr) { heap.free(ptr); }
void operator delete[](void * ptr) { heap.free(ptr); }
#else
void * operator new(std::size_t count) {	return heap.alloc(count); }
void * operator new[](std::size_t count) { return heap.alloc(count); }
void operator delete(void * ptr) { heap.free(ptr); }
void operator delete[](void * ptr) { heap.free(ptr); }

void operator delete  ( void* ptr, std::size_t sz ) noexcept { heap.free(ptr); };
void operator delete[]( void* ptr, std::size_t sz ) noexcept { heap.free(ptr); };

//void* operator new (std::size_t count){	return heap.alloc(count); };
//void* operator new (std::size_t count, const std::nothrow_t&) noexcept{	return heap.alloc(count); };
//void* operator new (std::size_t count, void*) noexcept{	return heap.alloc(count); };
#endif
#ifdef PAULA_DEBUG
//#ifdef WIN32
//void* operator new  (size_t count, const std::nothrow_t& tag) {return heap.alloc(count);};
//void* operator new[](size_t count, const std::nothrow_t& tag) {return heap.alloc(count);};
//void operator delete  (void* ptr,   std::size_t)			  {heap.free(ptr);};
//void operator delete[](void* ptr,   std::size_t)			  {heap.free(ptr);};
//#else
//void* operator new (std::size_t count){return heap.alloc(count);};
//// nothrow:    
//void* operator new (std::size_t count, const std::nothrow_t& nothrow_value) {return heap.alloc(count);};
//// placement:  
//void* operator new (std::size_t count, void* ptr) noexcept{return heap.alloc(count);};
#endif // PAULA_DEBUG

#endif
