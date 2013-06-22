/*
 *  COleMessageFilter.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "COleMessageFilter.h"

COleMessageFilter::COleMessageFilter()
{
	
}

COleMessageFilter::~COleMessageFilter()
{

}

BOOL COleMessageFilter::Register()
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}

void COleMessageFilter::Revoke()
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}

void COleMessageFilter::BeginBusyState()
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}

void COleMessageFilter::EndBusyState()
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}

void COleMessageFilter::SetRetryReply(DWORD nRetryReply)
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}

void COleMessageFilter::SetMessagePendingDelay(DWORD nTimeout)
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}

void COleMessageFilter::EnableBusyDialog(BOOL bEnableBusy)
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}

void COleMessageFilter::EnableNotRespondingDialog(BOOL bEnableNotResponding)
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}

BOOL COleMessageFilter::OnMessagePending(const MSG* pMsg)
{
	NSLog(@"to do COleMessageFilter::OnMessagePending");
}