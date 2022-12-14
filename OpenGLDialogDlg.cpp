// OpenGLDialogDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "OpenGLDialog.h"
#include "OpenGLDialogDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenGLDialogDlg Dialogfeld

COpenGLDialogDlg::COpenGLDialogDlg(CWnd* pParent /*=NULL*/)
: CDialog(COpenGLDialogDlg::IDD, pParent)
, display(_T(""))
//, display(0)
{
	//{{AFX_DATA_INIT(COpenGLDialogDlg)
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenGLDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpenGLDialogDlg)
	//}}AFX_DATA_MAP
		DDX_Text(pDX, IDC_EDIT1, display);
	//DDX_Text(pDX, IDC_EDIT1, display);
}

BEGIN_MESSAGE_MAP(COpenGLDialogDlg, CDialog)
	//{{AFX_MSG_MAP(COpenGLDialogDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, OnAboutClick)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLDialogDlg Nachrichten-Handler

BOOL COpenGLDialogDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

//	HCommPort = TEXT("COM1");/
//	InitSerial(HCommPort);

	ShowWindow(SW_MAXIMIZE);

	rcvlistening.SetParentDlg(this);
	
	AfxSocketInit(NULL);
	InitSocket();			//Both Sockets Initialized
	
	CRect rect;

	GetDlgItem(IDC_OPENGL_WINDOW)->GetWindowRect(rect);
	GetWindowRect(rect);
	ScreenToClient(rect);
	
	//dc = NULL;
	//	rotation = 0.0f;
	
	//GetWindowRect(this Rect);


	openGLControl.Create(rect,this);
	//Create(rect,this);
//	AfxBeginThread(&RcvThread, this, THREAD_PRIORITY_HIGHEST);
	InitAzimuthMap();
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch für Sie erledigt.

void COpenGLDialogDlg::OnPaint() 
{
	CDialog::OnPaint();
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, während der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR COpenGLDialogDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void COpenGLDialogDlg::InitSocket()
{
	rcvlistening.Create (20108,SOCK_DGRAM,FD_READ,"192.168.0.201");	//AZIMUTH
}

void COpenGLDialogDlg::InitAzimuthMap()
{
	int i = 0x0FFF;
	double pi = 3.14;
	double angle_rad;

	while(i>=0x0000)
	{
		angle_rad = ((i*2*pi)/4096);	//angle in radians
		Point azpoints;
		azpoints.x = ( (10 * cos(angle_rad - pi/2)));		//xc + r*cos(theta)
		azpoints.y = ( (10 * sin(angle_rad - pi/2)));		//yc + r*sin(theta)
		azmap[i] = azpoints;
		display.Format(_T("%f"),azpoints.x);
		UpdateData(FALSE);
		i--;
	}
}

void COpenGLDialogDlg::OnReceive()
{		
	
	rcvrtn = rcvlistening.Receive(&rcvbuff,1);		//192.168.0.201
	az = rcvbuff;

	if((rcvrtn != 0))
	{	
		if (az==0xFF)
		{	
			azimuth = 0xFFF;
			Az_Rx_Flag = true;
		}
		else if (az & 0x80 )
		{
			azimuth += (0x7f & az);
			Az_Rx_Flag = true;
		}
		else if(azimuth >= az)
		{
			if(azimuth==0xFFF)
			{
				azimuth=0;
			}
			azimuth += az;
			Az_Rx_Flag = true;
		}
		if(Az_Rx_Flag == true)
		{
			openGLControl.x = azmap[azimuth].x;
			openGLControl.y = azmap[azimuth].y;
			openGLControl.DrawGLScene();
			Az_Rx_Flag = false;
		}
	}
}



		