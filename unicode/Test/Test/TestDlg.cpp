// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"
#include <iostream>
using namespace std;
#include "YCodec.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestDlg 对话框




CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_INPUT, m_Input);
	DDX_Control(pDX, IDC_EDIT_DISP, m_Disp);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_EXIT, &CTestDlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(IDC_BEN_EXC, &CTestDlg::OnBnClickedBenExc)
	ON_BN_CLICKED(IDC_BEN_EXC2, &CTestDlg::OnBnClickedBenExc2)
	ON_BN_CLICKED(IDC_BEN_EXC3, &CTestDlg::OnBnClickedBenExc3)
	ON_BN_CLICKED(IDC_BEN_EXC4, &CTestDlg::OnBnClickedBenExc4)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 退出
void CTestDlg::OnBnClickedBtnExit()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
// 执行
void CTestDlg::OnBnClickedBenExc()
{
	// TODO: Add your control notification handler code here
}

// 执行2
void CTestDlg::OnBnClickedBenExc2()
{
	// TODO: Add your control notification handler code here
}

// 执行3
// unicode十六进制字符串转中英文实例
void CTestDlg::OnBnClickedBenExc3()
{
	// TODO: Add your control notification handler code here
	CString input;
	m_Input.GetWindowTextW(input);
	//input.MakeUpper();

	CString tmp;

	YCodec yCodec;

	// CString to char*
	int strlen = input.GetLength();
	char* str = new char[strlen+1];
	memset(str, 0, strlen+1);
	for(int i=0; i<strlen; i++)	str[i] = input.GetAt(i);
	// hex string to wchar_t*
	int wchslen = 0;
	if(yCodec.HexStr2WChars(str, strlen, 4, NULL, &wchslen) != -1){
		wchar_t* wchs = new wchar_t[wchslen+1];
		memset(wchs, 0, sizeof(wchar_t)*(wchslen+1));
		int n = yCodec.HexStr2WChars(str, strlen, 4, wchs, &wchslen);
		if(n != -1){
			// wchar_t to CString
			wchar_t* pwch = wchs;
			for(int i=0; i<wchslen; i++)	tmp.AppendChar(*pwch++);
		}
		if(wchs)	delete []wchs;
	}


	m_Disp.SetWindowTextW(tmp);
}

// 执行4
// 中英文转unicode十六进制字符串
void CTestDlg::OnBnClickedBenExc4()
{
	// TODO: Add your control notification handler code here
	CString input;
	m_Input.GetWindowTextW(input);

	CString tmp;
	YCodec yCodec;

	// CString to wchar_t*
	int len = input.GetLength();
	wchar_t* wchs = new wchar_t[len+1];
	memset(wchs, 0, sizeof(wchar_t)*(len+1));
	wcscpy(wchs, input.GetBuffer(len) );
	// wchar_t* to hex string
	int hexlen = 0;
	if(yCodec.Wchart2HexStr(wchs, len, 4, NULL, &hexlen) != -1){
		char* hexstr = new char[hexlen+1];
		memset(hexstr, 0, hexlen+1);
		int n = yCodec.Wchart2HexStr(wchs, len, 4, hexstr, &hexlen);
		if(n != -1){
			// char* to CString
			char* p = hexstr;
			for(int i=0; i<hexlen; i++)	tmp.AppendChar(*p++);
		}
		if(hexstr)	delete []hexstr;
	}

	if(wchs)	delete []wchs;

	m_Disp.SetWindowTextW(tmp);
}