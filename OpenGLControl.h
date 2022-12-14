#if !defined(AFX_OPENGLCONTROL_H__52A6B63B_01A2_449D_8691_1FF59EECAB71__INCLUDED_)
#define AFX_OPENGLCONTROL_H__52A6B63B_01A2_449D_8691_1FF59EECAB71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpenGLControl.h : Header-Datei
//

//#include "OpenGLDevice.h"
#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>  // GLUT, include glu.h and gl.h
//#include "freeglut_std.h"
#include <GL/glut.h>
/////////////////////////////////////////////////////////////////////////////
// Fenster COpenGLControl 

class COpenGLControl : public CWnd
{
// Konstruktion
public:
	COpenGLControl();

// Attribute
public:

// Operationen
public:

// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(COpenGLControl)
	public:
	//}}AFX_VIRTUAL

// Implementierung
public:
	void Create(CRect rect,CWnd* parent);
	virtual ~COpenGLControl();

//float theta;

float x;
float y;
void DrawGLScene();
	// Generierte Nachrichtenzuordnungsfunktionen
protected:
//	void InitGL();
	
//	OpenGLDevice openGLDevice;
	CClientDC* dc;
	float rotation;

	//{{AFX_MSG(COpenGLControl)
	afx_msg void OnPaint();
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	bool setDCPixelFormat(HDC& deviceContext,int stencil);
HGLRC renderContext;

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_OPENGLCONTROL_H__52A6B63B_01A2_449D_8691_1FF59EECAB71__INCLUDED_
