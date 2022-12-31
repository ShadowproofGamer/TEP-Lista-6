#pragma once
#include "CRefCounter.h"

template <typename T> class CMySmartPointer
{
public:
	CMySmartPointer(T* pcPointer)
	{
		pc_pointer = pcPointer;
		pc_counter = new CRefCounter();
		pc_counter->iAdd();
	}//CMySmartPointer(CSellData *pcPointer)
	CMySmartPointer(const CMySmartPointer& pcOther)
	{
		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
	}//CMySmartPointer(const CMySmartPointer &pcOther)
	~CMySmartPointer()
	{
		decrement();
	}//~CMySmartPointer()
	T& operator*() { return(*pc_pointer); }
	T* operator->() { return(pc_pointer); }

	void operator=(CMySmartPointer& pcOther) {
		decrement();
		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
	};
private:
	CRefCounter* pc_counter;
	T* pc_pointer;
	void decrement() {
		if (pc_counter->iDec() == 0)
		{
			delete pc_pointer;
			delete pc_counter;
		}//if (pc_counter->iDec())
	}//decrement()
};//class CMySmartPointer
