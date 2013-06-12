/*
 *  CPreviewDC.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CPREVIEWDC_DEFINE
#define CPREVIEWDC_DEFINE 1

#include "CDef.h"
#include "CDC.h"

class CPreviewDC  : public CDC
{
	
public:
	
	CPreviewDC();
	virtual ~CPreviewDC();
	

};

#endif//CPREVIEWDC_DEFINE