/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: salbmp.h,v $
 * $Revision: 1.6 $
 *
 * This file is part of OpenOffice.org.
 *
 * OpenOffice.org is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * OpenOffice.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with OpenOffice.org.  If not, see
 * <http://www.openoffice.org/license.html>
 * for a copy of the LGPLv3 License.
 *
 ************************************************************************/

#ifndef _SV_SALBMP_H
#define _SV_SALBMP_H
#ifdef AVS
#include <wincomp.hxx>
#include <tools/gen.hxx>
#include <vcl/sv.h>
#include <vcl/salbmp.hxx>
#endif

#include "../tools/gen.hxx"
#include "../vcl/salbmp.hxx"

#include "../ASC/WinDefines.h"

// --------------
// - SalBitmap	-
// --------------

class WinSalBitmap : public SalBitmap
{
private:

	SvmSize				maSize;
	HGLOBAL 			mhDIB;
	HBITMAP 			mhDDB;
	USHORT				mnBitCount;

public:

	HGLOBAL 			ImplGethDIB() const { return mhDIB; }
	HBITMAP 			ImplGethDDB() const { return mhDDB; }

	static HGLOBAL		ImplCreateDIB( const SvmSize& rSize, USHORT nBitCount, const BitmapPalette& rPal );
	static HANDLE		ImplCopyDIBOrDDB( HANDLE hHdl, bool bDIB );
	static USHORT		ImplGetDIBColorCount( HGLOBAL hDIB );

	static void 		ImplDecodeRLEBuffer( const BYTE* pSrcBuf, BYTE* pDstBuf,
											 const SvmSize& rSizePixel, bool bRLE4 );

public:

						WinSalBitmap();
	virtual				~WinSalBitmap();

public:

	bool                        Create( HANDLE hBitmap, bool bDIB, bool bCopyHandle );
	virtual bool                Create( const SvmSize& rSize, USHORT nBitCount, const BitmapPalette& rPal );
	virtual bool                Create( const SalBitmap& rSalBmpImpl );
	virtual bool                Create( const SalBitmap& rSalBmpImpl, SalGraphics* pGraphics );
	virtual bool                Create( const SalBitmap& rSalBmpImpl, USHORT nNewBitCount );

	virtual void                Destroy();

	virtual SvmSize                GetSize() const { return maSize; }
	virtual USHORT              GetBitCount() const { return mnBitCount; }

	virtual BitmapBuffer*		AcquireBuffer( bool bReadOnly );
	virtual void                ReleaseBuffer( BitmapBuffer* pBuffer, bool bReadOnly );
#ifdef AVS
    virtual bool                GetSystemData( BitmapSystemData& rData );
#endif

};

#endif // _SV_SALBMP_HXX