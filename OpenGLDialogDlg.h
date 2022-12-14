// OpenGLDialogDlg.h : Header-Datei
//

#if !defined(AFX_OPENGLDIALOGDLG_H__920A32A4_A76B_48E8_AE75_0942A4B378C2__INCLUDED_)
#define AFX_OPENGLDIALOGDLG_H__920A32A4_A76B_48E8_AE75_0942A4B378C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "OpenGLControl.h"
#include "ServerSocket.h"
#include <assert.h>

typedef struct Point
{
    float		x;
    float		y;
}Point;
/////////////////////////////////////////////////////////////////////////////
// COpenGLDialogDlg Dialogfeld

class COpenGLDialogDlg : public CDialog
{
// Konstruktion
public:
	COpenGLDialogDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(COpenGLDialogDlg)
	enum { IDD = IDD_OPENGLDIALOG_DIALOG };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(COpenGLDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
		// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;
	COpenGLControl openGLControl;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(COpenGLDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//afx_msg void OnAboutClick();
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOk();
	afx_msg void OnBnClickedAbout();
	void InitAzimuthMap();
	CServerSocket rcvlistening;
	TCHAR *HCommPort;
	HANDLE CommPort;
	DCB	dcb;      
	COMMTIMEOUTS timeouts;
	void InitSerial(CString PortSpecifier);
Point azmap[5000];

	static UINT RcvThread(LPVOID pArguments);
	CString display;
	void InitSocket();
	void OnReceive();
	char rcvrtn;
	unsigned char az;
	char rcvbuff;
	UINT azimuth;
	bool Az_Rx_Flag;

	//float display;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_OPENGLDIALOGDLG_H__920A32A4_A76B_48E8_AE75_0942A4B378C2__INCLUDED_)
