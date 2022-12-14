// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "OpenGLDialog.h"
#include "ServerSocket.h"
#include "OpenGLDialogDlg.h"

// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// CServerSocket member functions

void CServerSocket::OnReceive(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	((COpenGLDialogDlg*)m_pDlg)-> OnReceive();
	CAsyncSocket::OnReceive(nErrorCode);
}
void CServerSocket :: SetParentDlg (CDialog* pDlg)
{
    m_pDlg = pDlg;
}

