/*
 *  CDataExchange.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDATAEXCHANGE_DEFINE
#define CDATAEXCHANGE_DEFINE 1

#include <map>

#include "CDef.h"

class CSHELL_LIB_EXPORT CDataExchange
{

public:
	
	CDataExchange();
	virtual ~CDataExchange();
	
	std::map<int, void *> m_mapValues;
};

#endif//CDATAEXCHANGE_DEFINE
