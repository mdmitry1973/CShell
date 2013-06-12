/*
 *  CTime.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CTIME_DEFINE
#define CTIME_DEFINE 1

#include "CDef.h"

#include "winbase.h"

class CTime
{
	
public:
	
	CTime();
	CTime(const FILETIME& ft, int nDST = -1);
	virtual ~CTime();
	
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	int GetHour() const;
	int GetMinute() const;
	int GetSecond() const;
	int GetDayOfWeek() const;
	
	__time64_t GetTime() const;
	
	static CTime GetCurrentTime();

private:
	
	time_t m_curtime;
	
};

#endif//CTIME_DEFINE