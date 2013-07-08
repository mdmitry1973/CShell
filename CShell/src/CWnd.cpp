/*
 *  CWnd.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QObject>
#include <QCoreApplication>
#include <QtWidgets/QMessageBox>
#include <QDir>
#include <QtXml>
#include <QDomDocument>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QGroupBox>
#include <QSlider>
#include <QTabBar>
#include <QProgressBar>
#include <QRadioButton>
#include <QCheckBox>
#include <QSpinBox>
#include <QListWidget>
#include <QListView>
#include <QPixmap>
#include <QMainWindow>
#include "CQSlider.h"

#include "CDef.h"
#include "CShellEventReceiver.h"
#include "CWinApp.h"
#include "CMenu.h"
#include "CWnd.h"

CWnd CWnd::wndBottom;
CWnd CWnd::wndTop;
CWnd CWnd::wndTopMost;
CWnd CWnd::wndNoTopMost;

IMPLEMENT_DYNAMIC(CWnd, CCmdTarget)

CWnd::CWnd()
{
    mWindowController = NULL;
    m_hWnd = NULL;
    mWindowDelegate = NULL;
    mWindowHandle = NULL;
	
    mParentWin = NULL;
	mMainWindow = false;
	
	mFinished = false;
}

CWnd::~CWnd()
{
    QWidget *widget = (QWidget *)m_hWnd;

   // for(unsigned int i = 0; i < m_mapEventHandle.size(); i++)
    //{
    //    QWidget *control = (QWidget *)(m_mapEventHandle[i].control);
    //
    //    widget->disconnect(control, 0, 0, 0);
    //}

    if (m_hWnd && mMainWindow)
	{
        delete (QWidget *)m_hWnd;
	}
	
	if (mWindowController)
	{
        //[(NSWindowController *)mWindowController dealloc];
	}
	
	if (mWindowDelegate)
	{
        //[(CNSWindowDelegate *)mWindowDelegate dealloc];
	}
	
	if (mWindowHandle)
	{
        //[(CNSWindowHandle *)mWindowHandle dealloc];
	}
	
	if (mMainWindow)
	{
		//std::map<int,CWnd*>::iterator it;
		
		//for(it = m_arrTempControls.begin(); it != m_arrTempControls.end(); it++)
		//{
		//	delete it->second;
		//}
		
		//m_arrTempControls.clear();
	}

	std::map<int, CWnd *>::iterator it;
	
	for(it = mMapControls.begin(); it != mMapControls.end(); it++)
	{
		delete it->second;
	}
}

BOOL CWnd::Create(LPCTSTR lpszClassName, 
					LPCTSTR lpszWindowName,
					DWORD dwStyle,
					const RECT& rect,
					CWnd* pParentWnd,
					UINT nID,
					CCreateContext* pContext
					)
{
    qDebug() << "TO DO CWnd::Create";
	return TRUE;
}

void CWnd::DoDataExchange(CDataExchange* pDX)
{
	
}

BOOL CWnd::CreatFromResFile(UINT nIDTemplate, BOOL bView, CWnd *window)
{
	BOOL res = false;
	
    CString str;

    str = str.Format(_T("%d"), nIDTemplate);
	
    res = CreatFromResFile(str, bView, window);
	
	return res;
}

BOOL CWnd::CreatFromResFile(LPCTSTR lpszTemplateName, BOOL bView, CWnd *window)
{
	BOOL res = false;
    QString resPath = QDir::currentPath();
    QDomDocument doc;
    QFile file(resPath + "\\Resources.xml");
    int errorLine, errorColumn;
    QString errorMsg;
    QString strTemplateName = QString::fromWCharArray(lpszTemplateName);

    if (!file.open(QIODevice::ReadOnly))
    {
       qDebug() << "Cannot open file.";
       return FALSE;
    }

    if (!doc.setContent(&file, &errorMsg, &errorLine, &errorColumn))
    {
        qDebug() << "Cannot open xml document.";
        file.close();
        return FALSE;
    }

    file.close();

    QDomElement docElem = doc.documentElement();
    QString arrDialoTags[] = {"DIALOG", "DIALOGEX", ""};

    for(int n = 0; !arrDialoTags[n].isEmpty(); n++)
    {
        QDomNodeList children = docElem.elementsByTagName(arrDialoTags[n]);

        for(int i = 0; i < children.count(); i++)
        {
            QDomNode node = children.at(i);
            QDomElement idNode = node.firstChildElement("ID");
            QDomElement idStrNode = node.firstChildElement("IDSTR");
            QString strIdVal =  idNode.text();
            QString strStrId = idStrNode.text();

            if (strIdVal == strTemplateName ||
                strStrId == strTemplateName)
            {
                QDomElement captionNode = node.firstChildElement("CAPTION");
                QDomElement boxNode = node.firstChildElement("BOX");

                QDialog *dlg = new QDialog();

                if (!boxNode.isNull())
                {
                    QString strBox = boxNode.text();
                    QStringList listBox =  strBox.split(",");
                    QRect contentRect(0, 0, 100, 100);

                    if (listBox.count() >=  1)
                        contentRect.setX(listBox.at(0).toInt());
                    if (listBox.count() >=  2)
                        contentRect.setY(listBox.at(1).toInt());
                    if (listBox.count() >=  3)
                        contentRect.setWidth(listBox.at(2).toInt());
                    if (listBox.count() ==  4)
                        contentRect.setHeight(listBox.at(3).toInt());

                    dlg->move (contentRect.x(), contentRect.y());
                    dlg->resize(contentRect.width(), contentRect.height());
                }

                if (!captionNode.isNull())
                {
                    dlg->window()->setWindowTitle(captionNode.text());
                }

                 dlg->setAccessibleName(idNode.text());

                 m_hWnd = dlg;

                 QDomElement child = node.firstChildElement();

                 while(!child.isNull())
                 {
                    QString nameChild = child.nodeName();

                    if (nameChild.startsWith("BUTTON") ||
                        nameChild.startsWith("PUSHBUTTON") ||
                        nameChild.startsWith("DEFPUSHBUTTON"))
                    {
                        CreateButton(&child, dlg);
                    }
                    else
                    if (nameChild.startsWith("CTEXT") ||
                        nameChild.startsWith("LTEXT"))
                    {
                        CreateStaticText(&child, dlg);
                    }
                    else
                    if (nameChild.startsWith("CONTROL"))
                    {
                        CreateControl(&child, dlg);
                    }
                    else
                    if (nameChild.startsWith("GROUPBOX"))
                    {
                        CreateGroupBox(&child, dlg);
                    }
                    else
                    if (nameChild.startsWith("COMBOBOX"))
                    {
                        CreateComboBox(&child, dlg);
                    }
                    else
                    if (nameChild.startsWith("EDITTEXT"))
                    {
                        CreateEditText(&child, dlg);
                    }
                    else
                    if (nameChild.startsWith("LISTBOX"))
                    {
                        CreateListBox(&child, dlg);
                    }

                    child = child.nextSiblingElement();
                 }

                 res = true;

                 break;
            }
        }

        if (res)
        {
             break;
        }
    }

	return res;	
}

bool CWnd::CreateButton(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <ID></ID>
		 <IDSTR>IDOK</IDSTR>
		 <TEXT>OK</TEXT>
		 <BOX>113,41,50,14</BOX>
		 <STYLE>WS_GROUP</STYLE>
		 <DEFPUSHBUTTON/>									 
		 */

        QWidget *parent = (QWidget *)nsView;
        QDomElement *controlNode = (QDomElement *)controlNodeIn;
        QDomElement idStrNode = controlNode->firstChildElement("IDSTR");
        QDomElement idNode = controlNode->firstChildElement("ID");
        QDomElement textNode = controlNode->firstChildElement("TEXT");
        QDomElement boxNode = controlNode->firstChildElement("BOX");

        QPushButton  *button = new QPushButton(parent);

        if (!boxNode.isNull())
        {
            QString strBox = boxNode.text();
            QStringList listBox =  strBox.split(",");
            QRect contentRect(0, 0, 100, 100);

            if (listBox.count() >=  1)
                contentRect.setX(listBox.at(0).toInt());
            if (listBox.count() >=  2)
                contentRect.setY(listBox.at(1).toInt());
            if (listBox.count() >=  3)
                contentRect.setWidth(listBox.at(2).toInt());
            if (listBox.count() ==  4)
                contentRect.setHeight(listBox.at(3).toInt());

            QWidget *childPoint = parent->childAt(contentRect.x(), contentRect.y());

            if (dynamic_cast<QGroupBox *>(childPoint))
            {
                button->setParent(childPoint);
            }

            button->move (contentRect.x(), contentRect.y());
            button->resize(contentRect.width(), contentRect.height());
        }

        if (!textNode.isNull())
        {
            button->setText(textNode.text());
        }

        QString strId;

        if (!idNode.isNull())
        {
            strId = idNode.text();
        }
        else
        if (!idStrNode.isNull())
        {
            strId = idStrNode.text();
        }

        button->setAccessibleName(strId);

        if (controlNode->nodeName() == "DEFPUSHBUTTON")
        {
            button->setDefault(true);
        }
	}
	
	return res;
}

bool CWnd::CreateStaticText(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <CTEXT>           
		 <IDSTR>IDC_STATIC</IDSTR>
		 <TEXT>Place dialog controls here.</TEXT>
		 <BOX>10,96,300,8</BOX>
		 </CTEXT> 									 
		 */

        QWidget *parent = (QWidget *)nsView;
        QDomElement *controlNode = (QDomElement *)controlNodeIn;
        QDomElement idStrNode = controlNode->firstChildElement("IDSTR");
        QDomElement idNode = controlNode->firstChildElement("ID");
        QDomElement textNode = controlNode->firstChildElement("TEXT");
        QDomElement boxNode = controlNode->firstChildElement("BOX");

        QLabel  *label = new QLabel(parent);

        if (!boxNode.isNull())
        {
            QString strBox = boxNode.text();
            QStringList listBox =  strBox.split(",");
            QRect contentRect(0, 0, 100, 100);

            if (listBox.count() >=  1)
                contentRect.setX(listBox.at(0).toInt());
            if (listBox.count() >=  2)
                contentRect.setY(listBox.at(1).toInt());
            if (listBox.count() >=  3)
                contentRect.setWidth(listBox.at(2).toInt());
            if (listBox.count() ==  4)
                contentRect.setHeight(listBox.at(3).toInt());

            label->move (contentRect.x(), contentRect.y());
            label->resize(contentRect.width(), contentRect.height());
        }

        if (!textNode.isNull())
        {
            label->setText(textNode.text());
        }

        QString strId;

        if (!idNode.isNull())
        {
            strId = idNode.text();
        }
        else
        if (!idStrNode.isNull())
        {
            strId = idStrNode.text();
        }

        label->setAccessibleName(strId);
	}

	return res;
}

bool CWnd::CreateComboBox(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;

	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <COMBOBOX>
		 <ID>1002</ID>
		 <IDSTR>IDC_COMBO1</IDSTR>
		 <BOX>113,23,118,72</BOX>
		 <STYLE>CBS_DROPDOWNLIST | CBS_SORT | WS_VSCROLL | WS_TABSTOP</STYLE>
		 </COMBOBOX>								 
		 */

        QWidget *parent = (QWidget *)nsView;
        QDomElement *controlNode = (QDomElement *)controlNodeIn;
        QDomElement idStrNode = controlNode->firstChildElement("IDSTR");
        QDomElement idNode = controlNode->firstChildElement("ID");
        QDomElement boxNode = controlNode->firstChildElement("BOX");

        QComboBox  *comboBox = new QComboBox(parent);

        if (!boxNode.isNull())
        {
            QString strBox = boxNode.text();
            QStringList listBox =  strBox.split(",");
            QRect contentRect(0, 0, 100, 100);

            if (listBox.count() >=  1)
                contentRect.setX(listBox.at(0).toInt());
            if (listBox.count() >=  2)
                contentRect.setY(listBox.at(1).toInt());
            if (listBox.count() >=  3)
                contentRect.setWidth(listBox.at(2).toInt());
            //if (listBox.count() ==  4)
                contentRect.setHeight(20);//listBox.at(3).toInt());

            QWidget *childPoint = parent->childAt(contentRect.x(), contentRect.y());

            if (dynamic_cast<QGroupBox *>(childPoint))
            {
                comboBox->setParent(childPoint);
            }

            comboBox->move (contentRect.x(), contentRect.y());
            comboBox->resize(contentRect.width(), contentRect.height());

            comboBox->view()->setMinimumHeight(contentRect.height());
        }

        QString strId;

        if (!idNode.isNull())
        {
            strId = idNode.text();
        }
        else
        if (!idStrNode.isNull())
        {
            strId = idStrNode.text();
        }

        comboBox->setAccessibleName(strId);
	}

	return res;
}

bool CWnd::CreateControl(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;

	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <CONTROL>
		 <ID>1001</ID>
		 <IDSTR>IDC_CHECK1</IDSTR>
		 <TEXT>Test</TEXT>
		 <BOX>33,23,30,10</BOX>
		 <CLASS>Button</CLASS>
		 <STYLE>BS_AUTOCHECKBOX | WS_TABSTOP</STYLE>
		 </CONTROL>									 
		 */

        QWidget *parent = (QWidget *)nsView;
        QDomElement *controlNode = (QDomElement *)controlNodeIn;
        QDomElement idStrNode = controlNode->firstChildElement("IDSTR");
        QDomElement idNode = controlNode->firstChildElement("ID");
        QDomElement boxNode = controlNode->firstChildElement("BOX");
        QDomElement classNode = controlNode->firstChildElement("CLASS");
        QDomElement styleNode = controlNode->firstChildElement("STYLE");
        QDomElement textNode = controlNode->firstChildElement("TEXT");
        QString strClass;
        QString strStyles;
        QString strText;
        QWidget  *control = NULL;
        QRect contentRect(0, 0, 100, 100);

        if (!boxNode.isNull())
        {
            QString strBox = boxNode.text();
            QStringList listBox =  strBox.split(",");

            if (listBox.count() >=  1)
                contentRect.setX(listBox.at(0).toInt());
            if (listBox.count() >=  2)
                contentRect.setY(listBox.at(1).toInt());
            if (listBox.count() >=  3)
                contentRect.setWidth(listBox.at(2).toInt());
            if (listBox.count() ==  4)
                contentRect.setHeight(listBox.at(3).toInt());
        }

        QWidget *childPoint = parent->childAt(contentRect.x(), contentRect.y());

        if (dynamic_cast<QGroupBox *>(childPoint))
        {
            parent = childPoint;

            QPoint parentPos = parent->pos();

            contentRect.setX(contentRect.x() - parentPos.x());
            contentRect.setY(contentRect.y() - parentPos.y());

            contentRect.setWidth(contentRect.width() - parentPos.x());
            contentRect.setHeight(contentRect.height() - parentPos.y());
        }

        if (!classNode.isNull())
        {
            strClass = classNode.text();
        }

        if (!styleNode.isNull())
        {
            strStyles = styleNode.text();
        }

        if (!textNode.isNull())
        {
            strText = textNode.text();
        }

        if (strClass.startsWith("msctls_trackbar"))
        {
             CQSlider *slider = new CQSlider(parent);

             slider->setOrientation(Qt::Horizontal);

             slider->m_pParent = this;
             slider->setEventConnection();

             control = slider;
        }
        else
        if (strClass.startsWith("SysTabControl"))
        {
             control = new QTabBar(parent);
        }
        else
        if (strClass.startsWith("msctls_updown"))
        {
             control = new QSpinBox(parent);
        }
        else
        if (strClass.startsWith("msctls_progress"))
        {
             control = new QProgressBar(parent);
        }
        else
        if (strClass.startsWith("Static") &&
            strStyles.startsWith("SS_BITMAP"))
        {
             QLabel *imageLabel = new QLabel(parent);
             control = imageLabel;

             std::map<int,CShellBitmapInfo>::iterator it;
             int id_bitmap = strText.toInt();

             CWinApp::LoadBitmapInfo();

             std::map<int,CShellBitmapInfo> &bmp_map =  CWinApp::GetBitmapInfoMap();

             if (id_bitmap &&
                 (it = bmp_map.find(id_bitmap)) != bmp_map.end())
             {
                 QString resPath = QDir::currentPath();
                 QString imagePath = resPath + "\\" + QString::fromWCharArray(it->second.name.c_str());
                 QPixmap image(imagePath);

                 if (image.isNull())
                 {
                     qDebug() << "image.isNull";
                 }
                 else
                 {
                    imageLabel->setPixmap(image);
                 }
             }
        }
        else
        {
            if (strStyles.startsWith("BS_AUTORADIOBUTTON"))
            {
                control = new QRadioButton(parent);

                /*
                //WS_GROUP
                if ([strStyle rangeOfString: @"WS_GROUP" options: NSCaseInsensitiveSearch].location != NSNotFound)
                {
                    [(CNSButton *)control setGroup:true];
                }
                */

                ((QCheckBox *)control)->setText(strText);
            }
            else
            {
                control = new QCheckBox(parent);
                ((QCheckBox *)control)->setText(strText);
            }
        }

        if (!control)
        {
            return false;
        }

        if (!boxNode.isNull())
        {
            control->move (contentRect.x(), contentRect.y());
            control->resize(contentRect.width(), contentRect.height());
        }

        QString strId;

        if (!idNode.isNull())
        {
            strId = idNode.text();
        }
        else
        if (!idStrNode.isNull())
        {
            strId = idStrNode.text();
        }

        control->setAccessibleName(strId);
	}

	return res;
}

bool CWnd::CreateGroupBox(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;

	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <GROUPBOX>
		 <IDSTR>IDC_STATIC</IDSTR>
		 <TEXT>Group test</TEXT>
		 <BOX>58,46,212,42</BOX>
		 </GROUPBOX>								 
		 */

        QWidget *parent = (QWidget *)nsView;
        QDomElement *controlNode = (QDomElement *)controlNodeIn;
        QDomElement idStrNode = controlNode->firstChildElement("IDSTR");
        QDomElement idNode = controlNode->firstChildElement("ID");
        QDomElement textNode = controlNode->firstChildElement("TEXT");
        QDomElement boxNode = controlNode->firstChildElement("BOX");

        QGroupBox  *groupBox = new QGroupBox(parent);

        if (!boxNode.isNull())
        {
            QString strBox = boxNode.text();
            QStringList listBox =  strBox.split(",");
            QRect contentRect(0, 0, 100, 100);

            if (listBox.count() >=  1)
                contentRect.setX(listBox.at(0).toInt());
            if (listBox.count() >=  2)
                contentRect.setY(listBox.at(1).toInt());
            if (listBox.count() >=  3)
                contentRect.setWidth(listBox.at(2).toInt());
            if (listBox.count() ==  4)
                contentRect.setHeight(listBox.at(3).toInt());

            groupBox->move (contentRect.x(), contentRect.y());
            groupBox->resize(contentRect.width(), contentRect.height());
        }

        if (!textNode.isNull())
        {
            groupBox->setTitle(textNode.text());
        }

        QString strId;

        if (!idNode.isNull())
        {
            strId = idNode.text();
        }
        else
        if (!idStrNode.isNull())
        {
            strId = idStrNode.text();
        }

        groupBox->setAccessibleName(strId);
	}

	return res;
}

bool CWnd::CreateEditText(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;

	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <CTEXT>           
		 <IDSTR>IDC_STATIC</IDSTR>
		 <TEXT>Place dialog controls here.</TEXT>
		 <BOX>10,96,300,8</BOX>
		 </CTEXT> 									 
		 */

        QWidget *parent = (QWidget *)nsView;
        QDomElement *controlNode = (QDomElement *)controlNodeIn;
        QDomElement idStrNode = controlNode->firstChildElement("IDSTR");
        QDomElement idNode = controlNode->firstChildElement("ID");
        QDomElement textNode = controlNode->firstChildElement("TEXT");
        QDomElement boxNode = controlNode->firstChildElement("BOX");
       // int windowHeight = 0;

       // QLineEdit  *lineEdit = new QLineEdit(parent);
        QTextEdit  *textEditor = new QTextEdit(parent);

        if (!boxNode.isNull())
        {
            QString strBox = boxNode.text();
            QStringList listBox =  strBox.split(",");
            QRect contentRect(0, 0, 100, 100);

            if (listBox.count() >=  1)
                contentRect.setX(listBox.at(0).toInt());
            if (listBox.count() >=  2)
                contentRect.setY(listBox.at(1).toInt());
            if (listBox.count() >=  3)
                contentRect.setWidth(listBox.at(2).toInt());
            if (listBox.count() ==  4)
                contentRect.setHeight(listBox.at(3).toInt());

            textEditor->move (contentRect.x(), contentRect.y());
            textEditor->resize(contentRect.width(), contentRect.height());
        }

        if (!textNode.isNull())
        {
            textEditor->setText(textNode.text());
        }

        QString strId;

        if (!idNode.isNull())
        {
            strId = idNode.text();
        }
        else
        if (!idStrNode.isNull())
        {
            strId = idStrNode.text();
        }

        textEditor->setAccessibleName(strId);
	}

	return res;
}

bool CWnd::CreateListBox(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;

	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <LISTBOX>
			 <IDSTR>IDC_LIST1</IDSTR>
			 <ID>1004</ID>
			 <BOX>191,113,122,53</BOX>
			 <STYLE>LBS_SORT | LBS_NOINTEGRALHEIGHT | WS_VSCROLL | WS_TABSTOP</STYLE>
		 </LISTBOX>									 
		 */

        QWidget *parent = (QWidget *)nsView;
        QDomElement *controlNode = (QDomElement *)controlNodeIn;
        QDomElement idStrNode = controlNode->firstChildElement("IDSTR");
        QDomElement idNode = controlNode->firstChildElement("ID");
        QDomElement boxNode = controlNode->firstChildElement("BOX");

        QListWidget *listBox = new QListWidget(parent);

        if (!boxNode.isNull())
        {
            QString strBox = boxNode.text();
            QStringList arrBox =  strBox.split(",");
            QRect contentRect(0, 0, 100, 100);

            if (arrBox.count() >=  1)
                contentRect.setX(arrBox.at(0).toInt());
            if (arrBox.count() >=  2)
                contentRect.setY(arrBox.at(1).toInt());
            if (arrBox.count() >=  3)
                contentRect.setWidth(arrBox.at(2).toInt());
            if (arrBox.count() ==  4)
                contentRect.setHeight(arrBox.at(3).toInt());

            listBox->move (contentRect.x(), contentRect.y());
            listBox->resize(contentRect.width(), contentRect.height());
        }

        QString strId;

        if (!idNode.isNull())
        {
            strId = idNode.text();
        }
        else
        if (!idStrNode.isNull())
        {
            strId = idStrNode.text();
        }

        listBox->setAccessibleName(strId);
	}

	return res;	
}

void CWnd::FinaleSetup()
{
	if (!mFinished)
	{
		SetMessageMap();
		
		DoDataExchange(&mDX);
		
		if (IsDialog())
		{
			OnInitDialog();
		}
		
		mFinished = true;
	}
}

PtrNSWindowDelegate CWnd::GetWindowDelegate()
{
	return mWindowDelegate;
}

PtrNSWindow CWnd::GetNSWindow()
{
	return m_hWnd;
}

void CWnd::SetNSWindow(PtrNSWindow hWnd)
{
    m_hWnd = hWnd;
}

void CWnd::AddEventHandle(int objID, EventFun fun, int eventType)
{
	if (m_hWnd)
	{
        QWidget *widget = (QWidget *)m_hWnd;
        QString strID;
        QObject *object =NULL;

        CCmdTargetEventHandle handle;

        handle.tag			= objID;
        handle.fun			= fun;
        handle.eventType	= eventType;
        handle.control		= this;

        m_mapEventHandle.push_back(handle);

        if (objID == 0)
        {
            qDebug() << "CWnd::AddEventHandle objID=0 event come from subclasses";

        }
        else
        {
            strID.setNum(objID);

            QList<QObject*> listObjs = ((QObject *)m_hWnd)->findChildren<QObject *>();

            for(int i = 0; i < listObjs.count(); i++)
            {
                object = listObjs.at(i);

                if (object->isWidgetType())
                {
                   QWidget *widget =  (QWidget *)object;

                   if (widget->accessibleName() == strID)
                   {
                       break;
                   }
                }
            }
        }

        if (object)
        {
            CShellEventReceiver *funHandle =  new CShellEventReceiver();

            if (eventType == EVENT_TYPE_BN_CLICKED)
            {
                QMetaObject::Connection handle = widget->connect(qobject_cast<QAbstractButton *>(object), &QAbstractButton::clicked, funHandle, &CShellEventReceiver::eventFunction);

                if (handle == false)
                {
                    qDebug() << "QMetaObject::Connection handle == false";
                }
            }
            else
            if (eventType == EVENT_TYPE_LBN_SELCHANGE)
            {
                QMetaObject::Connection handle = widget->connect(qobject_cast<QListWidget *>(object), &QListWidget::itemSelectionChanged, funHandle, &CShellEventReceiver::eventFunction);

                if (handle == false)
                {
                    qDebug() << "QMetaObject::Connection handle == false";
                }
            }
            else
            if (eventType == EVENT_TYPE_CBN_SELCHANGE)
            {
                void (QComboBox::*indexChangedSignal)(int) = &QComboBox::currentIndexChanged;

                QMetaObject::Connection handle = widget->connect(qobject_cast<QComboBox *>(object), indexChangedSignal, funHandle, &CShellEventReceiver::eventIndexFunction);

                if (handle == false)
                {
                    qDebug() << "QMetaObject::Connection handle == false";
                }
            }
            else
            if (eventType == EVENT_TYPE_EN_CHANGE)
            {
                QMetaObject::Connection handle = widget->connect(qobject_cast<QTextEdit *>(object), &QTextEdit::textChanged, funHandle, &CShellEventReceiver::eventFunction);

                if (handle == false)
                {
                    qDebug() << "QMetaObject::Connection handle == false";
                }
            }
            else
            {
                qDebug() << "TO DO event type";
            }

            funHandle->mReceiverData.tag        = objID;
            funHandle->mReceiverData.fun        = fun;
            funHandle->mReceiverData.eventType	= eventType;
            funHandle->mReceiverData.control	= object;
            funHandle->setReceiver(this);
        }
	}
}

void CWnd::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)
{
    qDebug() << "TO DO CWnd::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)";
}

void CWnd::AddEventHandle(void *obj, EventFun fun, int eventType)
{
    //AddEventHandle([(NSView *)obj tag], fun, eventType);
}

void CWnd::DDX_Control(CDataExchange *pDX, int nIDC, CWnd &control)
{
	control.InitControl(nIDC, this);
	control.FinaleSetup();
}

void CWnd::DDX_CBIndex(CDataExchange *pDX, int nIDC, int& index)
{
	pDX->m_mapValues[nIDC] = &index;
}

void CWnd::DDX_Check(CDataExchange *pDX, int nIDC, BOOL& value)
{
	pDX->m_mapValues[nIDC] = &value;
}

void CWnd::DDX_Radio(CDataExchange* pDX, int nIDC, int& value)
{
	pDX->m_mapValues[nIDC] = &value;
}

void CWnd::DDX_Text(CDataExchange* pDX, int nIDC, CString& value)
{
	pDX->m_mapValues[nIDC] = &value;
}

void CWnd::DDV_MaxChars(CDataExchange* pDX, CString const& value, int nChars)
{
    qDebug() << "TO DO CWnd::DDV_MaxChars";
}

PtrNSWindow CWnd::GetControlByIDC(int IDC)
{
    assert(m_hWnd);

    QString strID;
    QObject *object =NULL;

    strID.setNum(IDC);

    QList<QObject*> listObjs = ((QObject *)m_hWnd)->findChildren<QObject *>();

    for(int i = 0; i < listObjs.count(); i++)
    {
        object = listObjs.at(i);

        if (object->isWidgetType())
        {
           QWidget *widget =  (QWidget *)object;

           if (widget->accessibleName() == strID)
           {
               break;
           }
        }
    }

    return object;
}

BOOL CWnd::UpdateData(BOOL bSaveAndValidate)
{
	std::map<int, void *>::iterator it;
	
	for(it = mDX.m_mapValues.begin(); it != mDX.m_mapValues.end(); it++)		
	{
        int id = it->first;

        QString strID;
        QObject *object =NULL;

        strID.setNum(id);

        QList<QObject*> listObjs = ((QObject *)m_hWnd)->findChildren<QObject *>();

        for(int i = 0; i < listObjs.count(); i++)
        {
            object = listObjs.at(i);

            if (object->isWidgetType())
            {
               QWidget *widget =  (QWidget *)object;

               if (widget->accessibleName() == strID)
               {
                   break;
               }
            }
        }

        if (object)
        {
            QAbstractButton *button = dynamic_cast<QAbstractButton *>(object);
            QAbstractSlider *slider = dynamic_cast<QAbstractSlider *>(object);

            if (button)
            {
                if (bSaveAndValidate) // get from controls
                {
                    *((int *)(it->second)) = button->isChecked();
                }
                else
                {
                    button->setChecked( *((int *)(it->second)));
                }
            }
            else
            if (slider)
            {
                if (bSaveAndValidate) // get from controls
                {
                    *((int *)(it->second)) = slider->sliderPosition();
                }
                else
                {
                    slider->setSliderPosition(*((int *)(it->second)));
                }
            }
            else
            {
                qDebug() << "TO DO CWnd::UpdateData";
            }
        }
	}

	return TRUE;
}

CWnd* CWnd::GetDlgItem(int nID)// const
{
    CWnd *control = NULL;
	std::map<int, CWnd*>::iterator it;
	
	it = mMapControls.find(nID);
	
	if (it != mMapControls.end())
	{
        return it->second;
	}
	
	control = new CWnd;
	
	if (!control->InitControl(nID, (CWnd* )this))
	{
        return NULL;
	}
	
	mMapControls[nID] = control;
	
	return control;
}

HICON CWnd::SetIcon(HICON hIcon, BOOL bBigIcon)
{
    qDebug() << "TO DO CWnd::SetIcon";
	return hIcon;
}

CMenu* CWnd::GetSystemMenu(BOOL bRevert)// const
{
    //NSMenu *rootMenu = [NSApp mainMenu];
    //NSMenu *appMenu = [[rootMenu itemAtIndex:0] submenu];
	
    //mMenu.SetNSMenu((void *)appMenu, this);
	
    //return &mMenu;//CWnd::GetMenu(this);

    return NULL;
}

void CWnd::SetWindowText(LPCTSTR lpszString )
{
    //if (m_hWnd && [(NSObject *)m_hWnd isKindOfClass: [NSControl class]])
    //{
    //	[(NSControl *)m_hWnd setStringValue: [NSString stringWithUTF8String: lpszString]];
    //}
    //else
    //{
    //	mCaptionStr = lpszString;
    //}
}

int CWnd::GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const
{
    /*
	if (m_hWnd && [(NSObject *)m_hWnd isKindOfClass: [NSControl class]])
	{
		NSString *str = [(NSControl *)m_hWnd stringValue];
		
		if (str)
		{
			[str getCString:lpszStringBuf maxLength:nMaxCount encoding:NSUTF8StringEncoding];
			
			return [str length];
		}
	}
	
	strncpy(lpszStringBuf, mCaptionStr.c_str(), mCaptionStr.size() > nMaxCount ? nMaxCount : mCaptionStr.size());
	return mCaptionStr.size() > nMaxCount ? nMaxCount : mCaptionStr.size();
    */
    return 0;
}

void CWnd::GetWindowText(CString& rString) const
{
    /*
	if (m_hWnd && [(NSObject *)m_hWnd isKindOfClass: [NSControl class]])
	{
		NSString *str = [(NSControl *)m_hWnd stringValue];
		
		if (str)
		{
			rString = [str UTF8String];
		}
	}
	else 
	{
		rString = mCaptionStr;
	}
    */
}

BOOL CWnd::ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags)
{
    qDebug() << "TO DO CWnd::ModifyStyle";
	
	return TRUE;	
}

void CWnd::DragAcceptFiles(BOOL bAccept)
{
    qDebug() << "TO DO CWnd::DragAcceptFiles";
}

BOOL CWnd::SetWindowPlacement(const WINDOWPLACEMENT*lpwndpl)
{
    qDebug() << "TO DO CWnd::SetWindowPlacement";
	
	return FALSE;
}

CFont* CWnd::GetFont() const
{
    qDebug() << "TO DO CWnd::GetFont";
	
	return NULL;
}

UINT_PTR CWnd::SetTimer(UINT_PTR nIDEvent, UINT nElapse, void (* lpfnTimer)(HWND, UINT, UINT_PTR, DWORD))
{
    qDebug() << "TO DO CWnd::SetTimer";
	
	return 0;
}

BOOL CWnd::KillTimer(UINT_PTR nIDEvent)
{
    qDebug() << "TO DO CWnd::KillTimer";
	
	return FALSE;
}

void CWnd::OnTimer(UINT nIDEvent)
{
	qDebug() << "TO DO CWnd::OnTimer";
}

BOOL CWnd::EnableToolTips(BOOL bEnable)
{
    qDebug() << "TO DO CWnd::EnableToolTips";
	
	return TRUE;
}

void CWnd::Invalidate(BOOL bErase)
{
    qDebug() << "TO DO CWnd::Invalidate";
}

void CWnd::InvalidateRect(LPCRECT lpRect, BOOL bErase )
{
    qDebug() << "TO DO CWnd::InvalidateRect";
}

void CWnd::SetFont(CFont* pFont, BOOL bRedraw)
{
    qDebug() << "TO DO CWnd::GetFont";
}

DWORD CWnd::GetStyle( ) const
{
    qDebug() << "TO DO CWnd::GetStyle";
	return 0;	
}

int CWnd::GetDlgCtrlID() const
{
    //if ([(NSObject *)m_hWnd  isKindOfClass:[NSView class]])
    //{
    //	return [(NSView *)m_hWnd tag];
    //}
	
	return 0;
}

CWnd* CWnd::GetParent() const
{
	return mParentWin;
}

void CWnd::GetClientRect(LPRECT lpRect) const
{
    /*
	lpRect->left = 0;
	lpRect->top = 0;
	lpRect->right = 0;
	lpRect->bottom = 0;
	
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSView class]])
	{
		NSRect rect = [(NSView *)m_hWnd bounds];
		
		lpRect->left = 0;
		lpRect->top = 0;
		lpRect->right = rect.size.width;
		lpRect->bottom = rect.size.height;
	}
	else
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSWindow class]])
	{
		NSRect rect = [(NSWindow *)m_hWnd frame];
		
		lpRect->left = 0;
		lpRect->top = 0;
		lpRect->right = rect.size.width;
		lpRect->bottom = rect.size.height;
	}
    */
}

void CWnd::GetWindowRect(LPRECT lpRect) const
{
    /*
	lpRect->left = 0;
	lpRect->top = 0;
	lpRect->right = 0;
	lpRect->bottom = 0;
	
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSView class]])
	{
		NSRect rect = [(NSView *)m_hWnd frame];
		
		lpRect->left = rect.origin.x;
		lpRect->top = rect.origin.y;
		lpRect->right = rect.origin.x + rect.size.width;
		lpRect->bottom = rect.origin.y + rect.size.height;
	}
	else
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSWindow class]])
	{
		NSRect rect = [(NSWindow *)m_hWnd frame];
		
		lpRect->left = rect.origin.x;
		lpRect->top = rect.origin.y;
		lpRect->right = rect.size.width;
		lpRect->bottom = rect.size.height;
	}
    */
}

CWnd* CWnd::GetFocus()
{
    qDebug() << "TO DO CWnd::GetFocus";
	return 0;
}

CWnd* CWnd::SetFocus()
{
    qDebug() << "TO DO CWnd::SetFocus";
	return 0;
}

BOOL CWnd::ShowWindow(int nCmdShow)
{
    //if (nCmdShow == SW_SHOW)
    //{
    //	[(NSView *)m_hWnd setHidden:false];
    //}
    //else
    //{
    //	[(NSView *)m_hWnd setHidden:true];
    //}

	return TRUE;
}

BOOL CWnd::EnableWindow(BOOL bEnable)
{
	BOOL res = FALSE;
    //NSObject *obj = (NSObject *)m_hWnd;
	
    //if ([obj isKindOfClass:[NSControl class]])
    //{
    //	res = [(NSControl *)obj isEnabled];
		
    //	[(NSControl *)obj setEnabled:bEnable];
    //}
	
	return res;
}

BOOL CWnd::IsIconic() const
{
    qDebug() << "TO DO CWnd::IsIconic";
	return FALSE;
}

BOOL CWnd::SetWindowPos(const CWnd* pWndInsertAfter, int x, int y, int cx, int cy, UINT nFlags)
{
    qDebug() << "TO DO CWnd::SetWindowPos";
	return TRUE;
}

void CWnd::ScreenToClient(LPPOINT lpPoint) const
{
    qDebug() << "TO DO CWnd::ScreenToClient";
}

void CWnd::ScreenToClient(LPRECT lpRect) const
{
    qDebug() << "TO DO CWnd::ScreenToClient";
}

void CWnd::MoveWindow(int x, int y, int nWidth, int nHeight, BOOL bRepaint)
{
    qDebug() << "TO DO CWnd::MoveWindow";
}

void CWnd::MoveWindow(LPCRECT lpRect, BOOL bRepaint)
{
    qDebug() << "TO DO CWnd::MoveWindow";
}

LRESULT CWnd::SendMessage(UINT message, WPARAM wParam,LPARAM lParam)
{
    qDebug() << "TO DO CWnd::SendMessage";
	return TRUE;
}

BOOL CWnd::PostMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
    qDebug() << "TO DO CWnd::SetFocus";
	return TRUE;
}

BOOL CWnd::PreTranslateMessage(MSG* pMsg)
{
    qDebug() << "TO DO CWnd::PreTranslateMessage";
	return TRUE;
}

void CWnd::PreSubclassWindow()
{
    qDebug() << "TO DO CWnd::PreSubclassWindow";
}

BOOL CWnd::PreCreateWindow(CREATESTRUCT& cs)
{
    qDebug() << "TO DO CWnd::PreCreateWindow";
	return TRUE;
}

void CWnd::UpdateWindow()
{
    qDebug() << "TO DO CWnd::UpdateWindow";
}

int CWnd::MessageBox(LPCTSTR lpszText, LPCTSTR lpszCaption, UINT nType)
{

	int res = IDCANCEL;

    /*
	NSAlert *alert = nil;
	
	if (nType & (MB_DEFBUTTON1 | MB_DEFBUTTON2 | MB_DEFBUTTON3 | MB_DEFBUTTON4))
	{
        qDebug() << "TO DO AfxMessageBox not support MB_DEFBUTTON1 | MB_DEFBUTTON2 | MB_DEFBUTTON3 | MB_DEFBUTTON4");
	}
	
	if (nType & (MB_APPLMODAL | MB_SYSTEMMODAL | MB_TASKMODAL | MB_DEFAULT_DESKTOP_ONLY))
	{
        qDebug() << "TO DO AfxMessageBox not support MB_APPLMODAL | MB_SYSTEMMODAL | MB_TASKMODAL | MB_DEFAULT_DESKTOP_ONLY");
	}
	
	if (nType & (MB_RIGHT | MB_SETFOREGROUND))
	{
        qDebug() << "TO DO AfxMessageBox not support MB_RIGHT | MB_SETFOREGROUND");
	}			
	
	if (nType & MB_OK)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"OK"
							 alternateButton:nil 
								 otherButton:nil
				   informativeTextWithFormat:@""];
	}
	else 
		if (nType & MB_OKCANCEL)
		{
			alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
								   defaultButton:@"OK"
								 alternateButton:@"Cancel" 
									 otherButton:nil
					   informativeTextWithFormat:@""];
		}
		else 
			if (nType & MB_RETRYCANCEL)
			{
				alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
									   defaultButton:@"Retry"
									 alternateButton:@"Cancel" 
										 otherButton:nil
						   informativeTextWithFormat:@""];
			}
			else 
				if (nType & MB_YESNO)
				{
					alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
										   defaultButton:@"Yes"
										 alternateButton:@"No" 
											 otherButton:nil
							   informativeTextWithFormat:@""];
				}
				else 
					if (nType & MB_YESNOCANCEL)
					{
						alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
											   defaultButton:@"Yes"
											 alternateButton:@"No" 
												 otherButton:@"Cancel"
								   informativeTextWithFormat:@""];
					}
					else 
						if (nType & MB_ABORTRETRYIGNORE)
						{
							alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
												   defaultButton:@"Abort"
												 alternateButton:@"Retry" 
													 otherButton:@"Ignore"
									   informativeTextWithFormat:@""];
						}
						else 
							if (nType & MB_CANCELTRYCONTINUE)
							{
								alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
													   defaultButton:@"Cancel"
													 alternateButton:@"Try Again" 
														 otherButton:@"Continue"
										   informativeTextWithFormat:@""];
							}
							else 
							{
								alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
													   defaultButton:@"OK"
													 alternateButton:nil 
														 otherButton:nil
										   informativeTextWithFormat:@""];	
							}
	
	if (alert)
	{
		NSInteger result;
		
		if (nType & MB_ICONEXCLAMATION)
		{
			[alert setAlertStyle: NSWarningAlertStyle];
		}
		else
			if (nType & MB_ICONWARNING)
			{
				[alert setAlertStyle: NSWarningAlertStyle];
			}
			else
				if (nType & MB_ICONINFORMATION)
				{
					[alert setAlertStyle: NSInformationalAlertStyle];
				}
				else
					if (nType & MB_ICONASTERISK)
					{
						[alert setAlertStyle: NSInformationalAlertStyle];
					}
					else
						if (nType & MB_ICONQUESTION)
						{
							[alert setAlertStyle: NSInformationalAlertStyle];
						}
						else
							if (nType & MB_ICONSTOP)
							{
								[alert setAlertStyle: NSCriticalAlertStyle];
							}
							else
								if (nType & MB_ICONERROR)
								{
									[alert setAlertStyle: NSCriticalAlertStyle];
								}
								else
									if (nType & MB_ICONHAND)
									{
										[alert setAlertStyle: NSCriticalAlertStyle];
									}
		
		result = [alert runModal];
		
		if (nType & MB_OK)
		{
			res =  IDOK;
		}
		else 
			if (nType & MB_OKCANCEL)
			{
				res =  IDCANCEL;
				
				if (result == NSAlertDefaultReturn)
				{
					res =  IDOK;
				}
			}
			else 
				if (nType & MB_RETRYCANCEL)
				{
					res =  IDRETRY;
					
					if (result == NSAlertDefaultReturn)
					{
						res =  IDCANCEL;
					}
				}
				else 
					if (nType & MB_YESNO)
					{
						res =  IDNO;
						
						if (result == NSAlertDefaultReturn)
						{
							res =  IDYES;
						}
					}
					else 
						if (nType & MB_YESNOCANCEL)
						{
							res =  IDCANCEL;
							
							if (result == NSAlertDefaultReturn)
							{
								res =  IDYES;
							}
							else 
								if (result == NSAlertAlternateReturn)
								{
									res =  IDNO;
								}
						}
						else 
							if (nType & MB_ABORTRETRYIGNORE)
							{
								res =  IDIGNORE;
								
								if (result == NSAlertDefaultReturn)
								{
									res =  IDABORT;
								}
								else 
									if (result == NSAlertAlternateReturn)
									{
										res =  IDRETRY;
									}
							}
							else 
								if (nType & MB_CANCELTRYCONTINUE)
								{
									res =  IDCONTINUE;
									
									if (result == NSAlertDefaultReturn)
									{
										res =  IDCANCEL;
									}
									else 
										if (result == NSAlertAlternateReturn)
										{
											res =  IDTRYAGAIN;
										}
								}
	}
    */

	return res;
}

BOOL CWnd::SetMenu(CMenu* pMenu)
{
    qDebug() << "TO DO CWnd::SetMenu";

	return FALSE;
}

void CWnd::DrawMenuBar()
{
    qDebug() << "TO DO CWnd::DrawMenuBar";
}

CDC* CWnd::GetDC()
{
    qDebug() << "TO DO CWnd::GetDC";
	return NULL;
}

BOOL CWnd::OnInitDialog()
{
	return true;
}

void CWnd::OnOK()
{
    //[NSApp stopModalWithCode:IDOK];
}

void CWnd::OnCancel()
{
    //[NSApp stopModalWithCode:IDCANCEL];
}

void CWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    qDebug() << "TO DO CWnd::OnChar";
}

void CWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
    qDebug() << "TO DO CWnd::OnLButtonDown";
}

void CWnd::OnRButtonDown(UINT nFlags, CPoint point)
{
    qDebug() << "TO DO CWnd::OnRButtonDown";
}

void CWnd::OnLButtonUp(UINT nFlags, CPoint point)
{
    qDebug() << "TO DO CWnd::OnLButtonUp";
}

void CWnd::OnRButtonUp(UINT nFlags, CPoint point)
{
    qDebug() << "TO DO CWnd::OnRButtonUp";
}

void CWnd::OnKillFocus(CWnd* pNewWnd)
{
    qDebug() << "TO DO CWnd::OnKillFocus";
}

void CWnd::OnSetFocus(CWnd* pOldWnd)
{
    qDebug() << "TO DO CWnd::OnSetFocus";
}

void CWnd::OnPaint()
{
    qDebug() << "TO DO CWnd::OnPaint";
}

void CWnd::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    qDebug() << "TO DO CWnd::OnHScroll";
}

void CWnd::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    qDebug() << "TO DO CWnd::OnHScroll";
}


int	CWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    qDebug() << "TO DO CWnd::OnCreate";
	return 0;
}

void CWnd::OnSysCommand(UINT nID, LPARAM lParam)
{
    qDebug() << "TO DO CWnd::OnSysCommand";
}

BOOL CWnd::InitControl(int nIDC, CWnd *win)
{
    m_hWnd = NULL;
	mParentWin = win;

	if (mParentWin)
	{
        //if (mWindowHandle)
        //{
        //	[(CNSWindowHandle *)mWindowHandle dealloc];
        //}
		
        //mWindowHandle = [[CNSWindowHandle alloc] init];
        //[(CNSWindowHandle *)mWindowHandle setCWnd: this];
		
		m_hWnd = mParentWin->GetControlByIDC(nIDC);
		
        //if (m_hWnd &&
        //	[(NSControl *)m_hWnd isKindOfClass: [CNSButton class]])
        //{
        //	CNSButton *button = (CNSButton *)m_hWnd;
			
        //	[button setWnd: this];
        //	[button setParentWnd: mParentWin];
        //}
		
        //if (m_hWnd &&
        //	[(NSControl *)m_hWnd isKindOfClass: [CNSTextField class]])
        //{
        //	mWindowDelegate = [[CNSTextFieldDelegate alloc] init];
        //	[(CNSTextFieldDelegate *)mWindowDelegate setCWnd: this];
        //	[(CNSTextField *)m_hWnd setDelegate: (CNSTextFieldDelegate *)mWindowDelegate];
			
        //	[(CNSTextField *)m_hWnd setWnd: this];
        //	[(CNSTextField *)m_hWnd setParentWnd: mParentWin];
        //}
		
        //if (m_hWnd &&
        //	[(NSControl *)m_hWnd isKindOfClass: [CNSTabView class]])
        //{
        //	mWindowDelegate = [[CNSTabViewDelegate alloc] init];
        //	[(CNSTabViewDelegate *)mWindowDelegate setCWnd: this];
        //	[(CNSTabView *)m_hWnd setDelegate: (CNSTabViewDelegate *)mWindowDelegate];
        //
        //	[(CNSTabView *)m_hWnd setWnd: this];
        //	[(CNSTabView *)m_hWnd setParentWnd: mParentWin];
        //}
		
		PreSubclassWindow();
	}

	return TRUE;
}

BOOL CWnd::IsDialog()
{
	return false;
}
