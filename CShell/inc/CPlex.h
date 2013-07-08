/*
 *  CPlex.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CPLEX_DEFINE
#define CPLEX_DEFINE 1

struct CSHELL_LIB_EXPORT CPlex     // warning variable length structure
{
	CPlex* pNext;
//#if (_AFX_PACKING >= 8)
//	DWORD dwReserved[1];    // align on 8 byte boundary
//#endif
	// BYTE data[maxNum*elementSize];
	
	void* data() { return this+1; }
	
	static CPlex* Create(CPlex*& head, UINT nMax, UINT cbElement);
	// like 'calloc' but no zero fill
	// may throw memory exceptions
	
	void FreeDataChain();       // free this one and links
};

#endif//CPLEX_DEFINE
