/*
 *  CToolBar.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QToolBar>
#include <QString>
#include <QDir>
#include <QtXml>
#include <QDomDocument>
#include <QFile>
#include <QMainWindow>
#include <QPixmap>
#include <QToolButton>
#include <QVariant>
#include <QAction>

#include "CToolBar.h"
#include "CMenu.h"
#include "CBitmap.h"

#include "..\CShellQT\CShellEventReceiver.h"

extern std::map<QString, QPixmap*> g_mapResBitMaps;

extern CShellEventReceiver *pGCommandEvent;

CToolBar::CToolBar() : CWnd()
{
	
}

CToolBar::~CToolBar()
{

}

BOOL CToolBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
    QWidget *parent = NULL;

    if (pParentWnd)
    {
        parent = (QWidget *)pParentWnd->GetNSWindow();
    }

    QToolBar *toolBar = new QToolBar("", parent);

    toolBar->setAccessibleName(QString().setNum(nID));

    QMainWindow *mainWnd = dynamic_cast<QMainWindow *>(parent);

    if (mainWnd)
    {
        mainWnd->addToolBar(toolBar);
    }

    m_hWnd = toolBar;
    mParentWin = pParentWnd;

	return TRUE;
}

BOOL CToolBar::CreateEx(CWnd* pParentWnd, DWORD dwCtrlStyle, DWORD dwStyle, CRect rcBorders, UINT nID)
{	
    BOOL res = Create(pParentWnd, dwStyle, nID);
    QToolBar *toolBar = (QToolBar *)m_hWnd;

    return res;
}

BOOL CToolBar::LoadToolBar(LPCTSTR lpszResourceName)
{
    /*
     *
     *<BITMAPTABLE>
    <BITMAP IDSTR="IDR_MAINFRAME" ID="128" NAME="Toolbar.bmp"/>
  </BITMAPTABLE>
     * <TOOLBAR IDSTR="IDR_MAINFRAME" ID="128">
    <IDSTR>IDR_MAINFRAME</IDSTR>
    <ID>128</ID>
    <X>16</X>
    <Y>15</Y>
    <BUTTON strID="ID_FILE_NEW"/>
    <BUTTON strID="ID_FILE_OPEN"/>
    <BUTTON strID="ID_FILE_SAVE"/>
    <SEPARATOR/>
    <BUTTON strID="ID_EDIT_CUT"/>
    <BUTTON strID="ID_EDIT_COPY"/>
    <BUTTON strID="ID_EDIT_PASTE"/>
    <SEPARATOR/>
    <BUTTON strID="ID_FILE_PRINT"/>
    <BUTTON strID="ID_APP_ABOUT"/>
  </TOOLBAR>
     */

    CBitmap bitmap;

    bitmap.LoadBitmap(lpszResourceName);

    std::vector<QPixmap> listBitmaps;
    std::map<QString, QPixmap*>::iterator it = g_mapResBitMaps.find(QString::fromWCharArray(lpszResourceName));

    if (it != g_mapResBitMaps.end())
    {
        QPixmap *pixmap = it->second;

        for(int i = 0; i < pixmap->width(); i = i + 16)
        {
            QPixmap	item = pixmap->copy(i, 0, 16, pixmap->height());

            listBitmaps.push_back(item);
        }
    }

    QToolBar *toolBar = (QToolBar *)m_hWnd;
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

    void (QToolBar::*actionTriggered)(QAction*) = &QToolBar::actionTriggered;

    pGCommandEvent->connect(toolBar, actionTriggered, pGCommandEvent, &CShellEventReceiver::menuSelection);

    QDomElement docElem = doc.documentElement();
    QString resId = QString::fromWCharArray(lpszResourceName);
    QDomElement toolBarNode = docElem.firstChildElement("TOOLBAR");
    int buttonIndex = 0;

    while(!toolBarNode.isNull())
    {
        QString idStr = toolBarNode.attribute("ID");

        if (idStr.compare(resId) == 0)
        {
            QDomElement itemNode = toolBarNode.firstChildElement();

           // docElem.firstChildElement("TOOLBAR");

            while(!itemNode.isNull())
            {
                QString name = itemNode.nodeName();

                if (name == "BUTTON")
                {
                    QString strID = itemNode.attribute("strID");
                    std::map<std::string, long> &menuCommands = CMenu::GetStandardCommand();

                    QPixmap	item;

                    if (listBitmaps.size() > buttonIndex)
                    {
                        item = listBitmaps[buttonIndex];
                        buttonIndex++;
                    }

                    if (!item.isNull())
                    {
                        QIcon icon(item);
                        QAction *action = toolBar->addAction(icon, "");

                        if (action)
                        {
                            std::map<std::string, long>::iterator command_it = menuCommands.find(strID.toStdString());

                            if (command_it != menuCommands.end())
                            {
                                action->setData(QVariant((int)(command_it->second)));
                            }
                        }
                    }
                }
                else
                if (name == "SEPARATOR")
                {
                    toolBar->addSeparator();
                }

                itemNode = itemNode.nextSiblingElement();
            }

            break;
        }

        toolBarNode = toolBarNode.nextSiblingElement("TOOLBAR");
    }


	return TRUE;
}

BOOL CToolBar::LoadToolBar(UINT nIDResource)
{
    QString strID = QString::number(nIDResource);

    return LoadToolBar(strID.toStdWString().c_str());
}

void CToolBar::EnableDocking(DWORD dwDockStyle)
{
    qDebug() << "TO DO CToolBar::EnableDocking";
}


void CToolBar::OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{
    qDebug() << "TO DO CToolBar::OnUpdateCmdUI";
}

DWORD CToolBar::GetBarStyle()
{
    qDebug() << "TO DO CToolBar::EnableDocking";
    return 0;
}

void CToolBar::SetBarStyle(DWORD dwStyle)
{
    qDebug() << "TO DO CToolBar::SetBarStyle";
}

UINT CToolBar::GetItemID(int nIndex) const
{
    qDebug() << "TO DO CToolBar::GetItemID";
    return 0;
}

void CToolBar::GetItemRect(int nIndex, LPRECT lpRect) const
{
    qDebug() << "TO DO CToolBar::GetItemRect";
}

UINT CToolBar::GetButtonStyle(int nIndex) const
{
    qDebug() << "TO DO CToolBar::GetButtonStyle";
    return 0;
}

void CToolBar::SetButtonStyle(int nIndex, UINT nStyle)
{
    qDebug() << "TO DO CToolBar::SetButtonStyle";
}

CToolBarCtrl& CToolBar::GetToolBarCtrl() const
{
    qDebug() << "TO DO CToolBar::GetToolBarCtrl";
    static CToolBarCtrl ff;
    return ff;
}
