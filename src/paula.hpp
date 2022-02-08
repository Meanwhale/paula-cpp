#pragma once
#ifndef _PAULA_H_
#define _PAULA_H_

#ifndef HEAP_SIZE
#define HEAP_SIZE 1024
#endif

typedef int INT32;

#include "dummyHeap.hpp"
#include "paulaString.hpp"

#include <stddef.h>

int paulaMain();

#ifdef PAULA_DEBUG
#ifdef WIN32
#define HALT __debugbreak() 
#define ASSERT(b,msg) { if (!(b)) {sayl(msg); HALT; }; }
#else
#define ASSERT(b,msg) { if (!(b)) {sayl(msg); exit(-1); }; }
#endif
#else // !PAULA_DEBUG
#define ASSERT(b,msg)
#endif
constexpr const char * allocErrorMsg = "alloc error";

void say(char);
void say(const char*);
void say(INT32);
void sayHex(INT32);
void sayl(char);
void sayl(const char*);
void sayl(int);
void saylHex(int);

int getLength(const char*, int max = 100000);
void copy(const char* src, char* trg, int srcStart, int dstStart, int length);
int compare(const char* a,const char* b, int max = 1000);

extern DummyHeap heap;

#ifdef OVERLOAD_NEW
#ifdef WIN32
void* operator new  (size_t count );
void* operator new[](size_t count );
void operator delete  (void* ptr);
void operator delete[](void* ptr);
//#ifdef PAULA_DEBUG
//#include <string>
//void* operator new  (size_t count, const std::nothrow_t& tag);
//void* operator new[](size_t count, const std::nothrow_t& tag);
//void operator delete  (void* ptr,   std::size_t);
//void operator delete[](void* ptr,   std::size_t);
//#endif
#else
#include <cstddef>
#include <new>
void* operator new  (std::size_t count );
void* operator new[](std::size_t count );
void operator delete  (void* ptr);
void operator delete[](void* ptr);

//void operator delete  ( void* ptr, std::align_val_t al ) noexcept;
//void operator delete[]( void* ptr, std::align_val_t al ) noexcept;
void operator delete  ( void* ptr, std::size_t sz ) noexcept;
void operator delete[]( void* ptr, std::size_t sz ) noexcept;
#endif
#endif

#endif // !_MMINI_H_
