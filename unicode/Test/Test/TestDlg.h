// TestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CTestDlg �Ի���
class CTestDlg : public CDialog
{
// ����
public:
	CTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnBnClickedBenExc();
	CEdit m_Input;
	CEdit m_Disp;
	BOOL GetMsg(CString source, CString& phone, CString& msg, CString& other);
	afx_msg void OnBnClickedBenExc2();
	afx_msg void OnBnClickedBenExc3();
	afx_msg void OnBnClickedBenExc4();
};
