// target_page.cpp : implementation file
//

#include "stdafx.h"
#include "configure.h"
#include "target_page.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTargetPage property page

IMPLEMENT_DYNCREATE(CTargetPage, CPropertyPage)

CTargetPage::CTargetPage() : CPropertyPage(CTargetPage::IDD)
{
  //{{AFX_DATA_INIT(CTargetPage)
  m_projectType=-1;
  m_quantumDepth=Q16;
  m_X11Mode=X11_DISABLED;
  m_decorateFiles=FALSE;
  m_optionalFiles=FALSE;
  m_standalone=FALSE;
  m_visualStudio7=FALSE;
  m_build64Bit=FALSE;
  m_hdri=FALSE;
  m_openMP=TRUE;
  m_openCL=FALSE;
  m_excludeDeprecated=FALSE;
  m_bigCoderDLL=FALSE;
  m_disableOpenCL=TRUE;
  //}}AFX_DATA_INIT
}

CTargetPage::~CTargetPage()
{
}

void CTargetPage::DoDataExchange(CDataExchange* pDX)
{
  CPropertyPage::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CTargetPage)
  DDX_Radio(pDX,IDC_PROJECT_TYPE,m_projectType);
  DDX_CBIndex(pDX,IDC_QUANTUM_DEPTH,m_quantumDepth);
  DDX_Check(pDX,IDC_DECORATE_FILES,m_decorateFiles);
  DDX_Check(pDX,IDC_INCLUDE_OPTIONAL,m_optionalFiles);
  DDX_Check(pDX,IDC_STANDALONE,m_standalone);
  DDX_Check(pDX,IDC_GENERATE_VS7,m_visualStudio7);
  DDX_Check(pDX,IDC_BUILD_64_BIT,m_build64Bit);
  DDX_Check(pDX,IDC_HDRI,m_hdri);
  DDX_Check(pDX,IDC_OPEN_CL,m_openCL);
  DDX_Check(pDX,IDC_OPEN_MP,m_openMP);
  DDX_Check(pDX,IDC_EXCLUDE_DEPRECATED,m_excludeDeprecated);
  DDX_Check(pDX,IDC_BIGCODERDLL,m_bigCoderDLL);
  DDX_CBIndex(pDX,IDC_X11,m_X11Mode);
  if (m_disableOpenCL)
    DisableOpenCL();
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTargetPage, CPropertyPage)
  //{{AFX_MSG_MAP(CTargetPage)
  ON_BN_CLICKED(IDC_EditConfig, OnEditConfig)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTargetPage message handlers

BOOL CTargetPage::OnInitDialog()
{
  CPropertyPage::OnInitDialog();

  UpdateData(FALSE);

  return TRUE;  // return TRUE unless you set the focus to a control
                // EXCEPTION: OCX Property Pages should return FALSE
}

void CTargetPage::OnEditConfig()
{
  CString strConfigFile = "..\\magick\\magick-baseconfig.h.in";

  CString strCommandLine;
  strCommandLine.Format("notepad.exe \"%s\"",strConfigFile);

  if (WinExec(strCommandLine, SW_SHOW) <= 31)
    MessageBox(_T("Unable to run notepad"));
}

void CTargetPage::DisableOpenCL(void)
{
  CButton
    *openCL;

  openCL=(CButton*) GetDlgItem(IDC_OPEN_CL);
  openCL->EnableWindow(FALSE);
  m_disableOpenCL=FALSE;
}
