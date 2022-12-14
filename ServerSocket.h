#pragma once

// CServerSocket command target

class CServerSocket : public CAsyncSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
	virtual void OnReceive(int nErrorCode);
	bool Az_Rx_Flag;
	void SetParentDlg (CDialog * pDlg);
	CDialog* m_pDlg;
};


