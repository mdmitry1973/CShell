/*
 *  CBitmap.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QtXml>
#include <QDomDocument>
#include <QFile>
#include <QPixmap>

#include "CBitmap.h"

std::map<QString, QPixmap*> g_mapResBitMaps;

CBitmap::CBitmap()
{
    mBitMap = NULL;
}

CBitmap::~CBitmap()
{
    if (mBitMap)
    {
       QPixmap *bitmap = (QPixmap *)mBitMap;

       delete bitmap;
    }
}

BOOL CBitmap::LoadBitmap(LPCTSTR lpszResourceName)
{
    if (g_mapResBitMaps.size() == 0)
    {
        QString resPath = QDir::currentPath();
        QDomDocument doc;
        QFile file(resPath + "\\Resources.xml");
        int errorLine, errorColumn;
        QString errorMsg;

        if (!file.open(QIODevice::ReadOnly))
        {
           return FALSE;
        }

        if (!doc.setContent(&file, &errorMsg, &errorLine, &errorColumn))
        {
            file.close();
            return FALSE;
        }

        file.close();

        /*
         *
         *<BITMAPTABLE>
        <BITMAP IDSTR="IDR_MAINFRAME" ID="128" NAME="Toolbar.bmp"/>
      </BITMAPTABLE>
      */

        QDomElement docElem = doc.documentElement();

        QDomElement bitmapTable = docElem.firstChildElement("BITMAPTABLE");

        while(!bitmapTable.isNull())
        {
            QDomElement bitmapTableItem = bitmapTable.firstChildElement("BITMAP");

            while(!bitmapTableItem.isNull())
            {
                QDomNamedNodeMap attrs = bitmapTableItem.attributes();

                QDomNode idAttr = attrs.namedItem("ID");
                QDomNode idStrAttr = attrs.namedItem("IDSTR");
                QDomNode nameAttr = attrs.namedItem("NAME");

                QString resPath = QDir::currentPath();
                QString imagePath = resPath + "\\" + nameAttr.nodeValue();
                QPixmap *image = new QPixmap;

                if (image->load(imagePath))
                {
                    if (!idAttr.isNull())
                    {
                        g_mapResBitMaps[idAttr.nodeValue()] = image;
                    }
                    else
                    if (!idStrAttr.isNull())
                    {
                        g_mapResBitMaps[idStrAttr.nodeValue()] = image;
                    }
                }
                else
                {
                    delete image;
                }

                bitmapTableItem = bitmapTableItem.nextSiblingElement("BITMAP");
            }

            bitmapTable = bitmapTable.nextSiblingElement("BITMAPTABLE");
        }
    }

    if (mBitMap)
    {
        QPixmap *bitmap = (QPixmap *)mBitMap;
        delete bitmap;
    }

    if (g_mapResBitMaps.find(QString::fromWCharArray(lpszResourceName)) != g_mapResBitMaps.end())
    {
        mBitMap = new QPixmap(*(g_mapResBitMaps[QString::fromWCharArray(lpszResourceName)]));
    }

    return mBitMap != NULL;
}

BOOL CBitmap::LoadBitmap(UINT nIDResource)
{
    return LoadBitmap(QString().number(nIDResource).toStdWString().c_str());
}

BOOL CBitmap::LoadOEMBitmap(UINT nIDBitmap)
{
    qDebug() << "to do CBitmap::LoadBitmap";
}

BOOL CBitmap::CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitcount, const void* lpBits)
{
    qDebug() << "to do CBitmap::LoadBitmap";
}

BOOL CBitmap::Attach(HGDIOBJ hObject)
{
    qDebug() << "to do CBitmap::LoadBitmap";
}

HGDIOBJ CBitmap::Detach()
{
    qDebug() << "to do CBitmap::LoadBitmap";
}

CBitmap::operator HBITMAP() const
{
    return (HBITMAP)mBitMap;
}

int CBitmap::GetBitmap(BITMAP* pBitMap)
{
    qDebug() << "to do CBitmap::LoadBitmap";
}

// Operations
DWORD CBitmap::SetBitmapBits(DWORD dwCount, const void* lpBits)
{
    qDebug() << "to do CBitmap::LoadBitmap";
}

DWORD CBitmap::GetBitmapBits(DWORD dwCount, LPVOID lpBits) const
{
    qDebug() << "to do CBitmap::LoadBitmap";
}

CSize CBitmap::SetBitmapDimension(int nWidth, int nHeight)
{
    qDebug() << "to do CBitmap::LoadBitmap";
}

CSize CBitmap::GetBitmapDimension() const
{
    qDebug() << "to do CBitmap::LoadBitmap";
}
