/*
 *  afxole.h
 *  Untitled
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 CShell. All rights reserved.
 *
 */


#ifndef AFXOLE_H
#define AFXOLE_H

/////////////////////////////////////////////////////////////////////////////
// Useful OLE specific types (some from OLE 1.0 headers)

// Codes for CallBack events
enum OLE_NOTIFICATION
{
	OLE_CHANGED,        // representation of a draw aspect has changed
	OLE_SAVED,          // the item has committed its storage
	OLE_CLOSED,         // the item has closed
	OLE_RENAMED,        // the item has changed its moniker
	OLE_CHANGED_STATE,  // the item state (open, active, etc.) has changed
	OLE_CHANGED_ASPECT, // the item draw aspect has changed
};

// Object types
enum OLE_OBJTYPE
{
	OT_UNKNOWN = 0,
	
	// These are OLE 1.0 types and OLE 2.0 types as returned from GetType().
	OT_LINK = 1,
	OT_EMBEDDED = 2,
	OT_STATIC = 3,
	
	// All OLE2 objects are written with this tag when serialized.  This
	//  differentiates them from OLE 1.0 objects written with MFC 2.0.
	//  This value will never be returned from GetType().
	OT_OLE2 = 256,
};

#endif//AFXOLE_H