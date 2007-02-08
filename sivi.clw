; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSignalView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sivi.h"
LastPage=0

ClassCount=7
Class1=CSiviApp
Class2=CSignalDoc
Class3=CSignalView
Class4=CMainFrame

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_SIVITYPE
Class5=CChildFrame
Class6=CAboutDlg
Resource4=IDR_SIGNALMENU (English (U.S.))
Resource5=IDR_MAINFRAME (English (U.S.))
Resource6=IDD_ABOUTBOX (English (U.S.))
Class7=CSigPrmsDlg
Resource7=IDD_SIGPARAMS

[CLS:CSiviApp]
Type=0
HeaderFile=sivi.h
ImplementationFile=sivi.cpp
Filter=N

[CLS:CSignalDoc]
Type=0
HeaderFile=SignalDoc.h
ImplementationFile=SignalDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_VIEW_ZOOM_ORIGINALSIZE

[CLS:CSignalView]
Type=0
HeaderFile=SignalView.h
ImplementationFile=SignalView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_FILE_ADDSIGNAL


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=sivi.cpp
ImplementationFile=sivi.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
CommandCount=8
Command8=ID_APP_ABOUT

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
CommandCount=8
Command8=ID_APP_ABOUT

[MNU:IDR_SIVITYPE]
Type=1
Class=CSignalView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
CommandCount=21
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE


[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_ADDSIGNAL
Command5=ID_VIEW_ZOOM_ZOOMIN
Command6=ID_VIEW_ZOOM_ZOOMOUT
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_VIEW_ZOM_ZOOMIN
Command2=ID_VIEW_ZOM_ZOOMOUT
Command3=ID_VIEW_ZOM_ORIGINALSIZE
Command4=ID_FILE_ADDSIGNAL
Command5=ID_EDIT_COPY
Command6=ID_FILE_NEW
Command7=ID_FILE_OPEN
Command8=ID_FILE_PRINT
Command9=ID_FILE_SAVE
Command10=ID_EDIT_PASTE
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_EDIT_CUT
Command18=ID_EDIT_UNDO
CommandCount=18

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SIGPARAMS]
Type=1
Class=CSigPrmsDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STSIGTYPE,static,1342308864
Control4=IDC_SIGTYPE,combobox,1344340227
Control5=IDC_SIGAMP,edit,1350631552
Control6=IDC_SIGFREQ,edit,1350631552
Control7=IDC_STSIGAMP,static,1342308864
Control8=IDC_STSIGFREQ,static,1342308864

[CLS:CSigPrmsDlg]
Type=0
HeaderFile=SigPrmsDlg.h
ImplementationFile=SigPrmsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_FILE_SAVE

[MNU:IDR_SIGNALMENU (English (U.S.))]
Type=1
Class=CSignalDoc
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_ADDSIGNAL
Command7=ID_FILE_PRINT
Command8=ID_FILE_PRINT_PREVIEW
Command9=ID_FILE_PRINT_SETUP
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_VIEW_ZOOM_ZOOMIN
Command17=ID_VIEW_ZOOM_ZOOMOUT
Command18=ID_VIEW_ZOOM_ORIGINALSIZE
Command19=ID_VIEW_TOOLBAR
Command20=ID_VIEW_STATUS_BAR
Command21=ID_WINDOW_NEW
Command22=ID_WINDOW_CASCADE
Command23=ID_WINDOW_TILE_HORZ
Command24=ID_WINDOW_ARRANGE
Command25=ID_APP_ABOUT
CommandCount=25

