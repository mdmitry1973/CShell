/*
 *  CTime.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CTime.h"

CTime::CTime()
{
	m_curtime = time(0);
	
	/*
	struct tm *timeTm = gmtime(&curtime);
	satime.m_year    = (SAUInt)(timeTm->tm_year+1900);
	satime.m_month   = (SAUInt)(timeTm->tm_mon+1);
	satime.m_day     = (SAUInt)timeTm->tm_mday;
	satime.m_hour    = (SAUInt)timeTm->tm_hour;
	satime.m_minute  = (SAUInt)timeTm->tm_min;
	satime.m_second  = (SAUInt)timeTm->tm_sec;
	satime.m_wday	  = (SAUInt)timeTm->tm_wday;
	 */
}

CTime::CTime(const FILETIME& ft, int nDST)
{
	
}

CTime::~CTime()
{
	
}

CTime CTime::GetCurrentTime()
{
	return CTime();
}

int CTime::GetYear() const
{
	struct tm *timeTm = gmtime(&m_curtime);
	return (timeTm->tm_year+1900);
}

int CTime::GetMonth() const
{
	struct tm *timeTm = gmtime(&m_curtime);
	return (timeTm->tm_mon+1);
}

int CTime::GetDay() const
{
	struct tm *timeTm = gmtime(&m_curtime);
	return timeTm->tm_mday;
}

int CTime::GetHour() const
{
	struct tm *timeTm = gmtime(&m_curtime);
	return timeTm->tm_hour;
}

int CTime::GetMinute() const
{
	struct tm *timeTm = gmtime(&m_curtime);
	return timeTm->tm_min;
}

int CTime::GetSecond() const
{
	struct tm *timeTm = gmtime(&m_curtime);
	return timeTm->tm_sec;
}

int CTime::GetDayOfWeek() const
{
	struct tm *timeTm = gmtime(&m_curtime);
	return timeTm->tm_wday;
}

__time64_t CTime::GetTime() const
{
	return m_curtime;
}

