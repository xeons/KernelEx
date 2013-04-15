/*
 *  KernelEx
 *  Copyright (C) 2008, Xeno86
 *
 *  This file is part of KernelEx source code.
 *
 *  KernelEx is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation; version 2 of the License.
 *
 *  KernelEx is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GNU Make; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef _USER32_APILIST_H
#define _USER32_APILIST_H

#include "common.h"
#include <commctrl.h>
#include <ddeml.h>
#include "unifwd.h"
#include <wchar.h>

BOOL init_user32();
extern const apilib_api_table apitable_user32;

/*** AUTOGENERATED APILIST DECLARATIONS BEGIN ***/
FWDPROC EnumDisplayDevicesW_fwd;
FWDPROC EnumDisplaySettingsExW_fwd;
FWDPROC EnumDisplaySettingsW_fwd;
FWDPROC EnumPropsExW_fwd;
FWDPROC EnumPropsW_fwd;
long WINAPI BroadcastSystemMessageW_new(DWORD dwFlags, LPDWORD lpdwRecipients, UINT uiMessage, WPARAM wParam, LPARAM lParam);
LONG WINAPI ChangeDisplaySettingsExW_new(LPCWSTR lpszDeviceName, LPDEVMODEW lpDevMode, HWND hwnd, DWORD dwflags, LPVOID lParam);
HSZ WINAPI DdeCreateStringHandleW_new(DWORD idInst, LPWSTR pszW, int iCodePage);
UINT WINAPI DdeInitializeW_new(LPDWORD pidInst, PFNCALLBACK pfnCallback, DWORD afCmd, DWORD ulRes);
DWORD WINAPI DdeQueryStringW_new(DWORD idInst, HSZ hsz, LPWSTR pszW, DWORD cchMax, int iCodePage);
int WINAPI DlgDirListComboBoxW_new(HWND hDlg, LPWSTR lpPathSpecW, int nIDComboBox, int nIDStaticPath, UINT uFiletype);
int WINAPI DlgDirListW_new(HWND hDlg, LPWSTR lpPathSpecW, int nIDListBox, int nIDStaticPath, UINT uFileType);
BOOL WINAPI DlgDirSelectComboBoxExW_new(HWND hDlg, LPWSTR lpString, int nCount, int nIDComboBox);
BOOL WINAPI DlgDirSelectExW_new(HWND hDlg, LPWSTR lpString, int nCount, int nIDListBox);
BOOL WINAPI DrawStateW_new(HDC hdc, HBRUSH hbr, DRAWSTATEPROC lpOutputFunc, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT fuFlags);
int WINAPI DrawTextExW_new(HDC hdc, LPWSTR lpchTextW, int cchText, LPRECT lprc, UINT dwDTFormat, LPDRAWTEXTPARAMS lpDTParams);
int WINAPI DrawTextW_new(HDC hdc, LPWSTR lpchText, int cchText, LPRECT lprc, UINT dwDTFormat);
HWND WINAPI FindWindowExW_new(HWND hwndParent, HWND hwndChildAfter, LPCWSTR lpszClassW, LPCWSTR lpszWindowW);
HWND WINAPI FindWindowW_new(LPCWSTR lpszClass, LPCWSTR lpszWindow);
BOOL WINAPI GetClassNameW_new(HWND hWnd, LPWSTR lpClassName, int nMaxCount);
BOOL WINAPI GetClipboardFormatNameW_new(UINT format, LPWSTR lpszFormatName, int cchMaxCount);
BOOL WINAPI GetKeyboardLayoutNameW_new(LPWSTR pwszKLID);
int WINAPI GetKeyNameTextW_new(LONG lParam, LPWSTR lpString, int nSize);
BOOL WINAPI GetMenuItemInfoW_new(HMENU hMenu, UINT uItem, BOOL fByPosition, LPMENUITEMINFOW lpmii);
int WINAPI GetMenuStringW_new(HMENU hMenu, UINT uIDItem, LPWSTR lpString, int nMaxCount, UINT uFlag);
BOOL WINAPI GetMonitorInfoW_new(HMONITOR hMonitor, LPMONITORINFO lpmi);
HANDLE WINAPI GetPropW_new(HWND hWnd, LPCWSTR lpStringW);
DWORD WINAPI GetTabbedTextExtentW_new(HDC hDC, LPCWSTR lpStringW, int nCount, int nTabPositions, CONST LPINT lpnTabStopPositions);
BOOL WINAPI GrayStringW_new(HDC hDC, HBRUSH hBrush, GRAYSTRINGPROC lpOutputFunc, LPARAM lpData, int nCount, int X, int Y, int nWidth, int nHeight);
BOOL WINAPI InsertMenuItemW_new(HMENU hMenu, UINT uItem, BOOL fByPosition, LPCMENUITEMINFO lpmii);
HACCEL WINAPI LoadAcceleratorsW_new(HINSTANCE hInstance, LPCWSTR lpTableNameW);
HBITMAP WINAPI LoadBitmapW_new(HINSTANCE hInstance, LPCWSTR lpBitmapNameW);
HCURSOR WINAPI LoadCursorFromFileW_new(LPCWSTR lpFileNameW);
HCURSOR WINAPI LoadCursorW_new(HINSTANCE hInstance, LPCWSTR lpCursorNameW);
HICON WINAPI LoadIconW_new(HINSTANCE hInstance, LPCWSTR lpIconNameW);
HANDLE WINAPI LoadImageW_new(HINSTANCE hinst, LPCWSTR lpszNameW, UINT uType, int cxDesired, int cyDesired, UINT fuLoad);
HKL WINAPI LoadKeyboardLayoutW_new(LPCWSTR pwszKLIDW, UINT Flags);
UINT WINAPI MapVirtualKeyExW_new(UINT uCode, UINT uMapType, HKL dwhkl);
UINT WINAPI MapVirtualKeyW_new(UINT uCode, UINT uMapType);
int WINAPI MessageBoxIndirectW_new(const LPMSGBOXPARAMSW lpMsgBoxParams);
UINT WINAPI RegisterClipboardFormatW_new(LPCWSTR lpszFormatW);
HDEVNOTIFY WINAPI RegisterDeviceNotificationW_new(HANDLE hRecipient, LPVOID NotificationFilter, DWORD Flags);
UINT WINAPI RegisterWindowMessageW_new(LPCWSTR lpStringW);
HANDLE WINAPI RemovePropW_new(HWND hWnd, LPCWSTR lpStringW);
BOOL WINAPI SetMenuItemInfoW_new(HMENU hMenu, UINT uItem, BOOL fByPosition, LPCMENUITEMINFO lpmii);
BOOL WINAPI SetPropW_new(HWND hWnd, LPCWSTR lpStringW, HANDLE hData);
BOOL WINAPI SystemParametersInfoW_new(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni);
LONG WINAPI TabbedTextOutW_new(HDC hDC, int X, int Y, LPCWSTR lpStringW, int nCount, int nTabPositions, CONST LPINT lpnTabStopPositions, int nTabOrigin);
SHORT WINAPI VkKeyScanExW_new(WCHAR ch, HKL dwhkl);
SHORT WINAPI VkKeyScanW_new(WCHAR ch);
BOOL WINAPI WinHelpW_new(HWND hWndMain, LPCWSTR lpszHelpW, UINT uCommand, ULONG_PTR dwData);
int wsprintfW_new(LPWSTR lpOut, LPCWSTR lpFmt, ...);
int wvsprintfW_new(LPWSTR lpOutput, LPCWSTR lpFmt, va_list arglist);
/*** AUTOGENERATED APILIST DECLARATIONS END ***/

#endif
