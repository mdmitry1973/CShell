/*
 *  wtypes.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef WTYPES_H
#define WTYPES_H 1

typedef
enum tagMSHLFLAGS
{	MSHLFLAGS_NORMAL	= 0,
	MSHLFLAGS_TABLESTRONG	= 1,
	MSHLFLAGS_TABLEWEAK	= 2,
	MSHLFLAGS_NOPING	= 4,
	MSHLFLAGS_RESERVED1	= 8,
	MSHLFLAGS_RESERVED2	= 16,
	MSHLFLAGS_RESERVED3	= 32,
	MSHLFLAGS_RESERVED4	= 64
} 	MSHLFLAGS;

typedef 
enum tagMSHCTX
{	MSHCTX_LOCAL	= 0,
	MSHCTX_NOSHAREDMEM	= 1,
	MSHCTX_DIFFERENTMACHINE	= 2,
	MSHCTX_INPROC	= 3,
	MSHCTX_CROSSCTX	= 4
} 	MSHCTX;

typedef 
enum tagDVASPECT
{	DVASPECT_CONTENT	= 1,
	DVASPECT_THUMBNAIL	= 2,
	DVASPECT_ICON	= 4,
	DVASPECT_DOCPRINT	= 8
} 	DVASPECT;

typedef 
enum tagSTGC
{	STGC_DEFAULT	= 0,
	STGC_OVERWRITE	= 1,
	STGC_ONLYIFCURRENT	= 2,
	STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE	= 4,
	STGC_CONSOLIDATE	= 8
} 	STGC;

typedef 
enum tagSTGMOVE
{	STGMOVE_MOVE	= 0,
	STGMOVE_COPY	= 1,
	STGMOVE_SHALLOWCOPY	= 2
} 	STGMOVE;

typedef 
enum tagSTATFLAG
{	STATFLAG_DEFAULT	= 0,
	STATFLAG_NONAME	= 1,
	STATFLAG_NOOPEN	= 2
} 	STATFLAG;


#endif//WTYPES_H