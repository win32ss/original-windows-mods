BOOL IsDebuggerPresentSpoof()
/*
win32 - April 16 2022
Drop-in replacement for IsDebuggerPresent().
It can be used to hide a debugger or fake the presence of a debugger, on a specific application or system-wide.
If no override key has been made available, the original source for IsDebuggerPresent(), the boolean member of the PEB
named BeingDebugged is returned.
*/
{
    WCHAR ImagePathName[MAX_PATH];
   	GetModuleFileNameW(NULL, ImagePathName, MAX_PATH);
	if(!GetPrivateProfileIntW(ImagePathName, L"Enabled", 0, L"osver.ini"))
		return GetPrivateProfileIntW(L"global", L"ShowDebugger", NtCurrentTeb()->ProcessEnvironmentBlock->BeingDebugged, L"osver.ini");
	else
    return GetPrivateProfileIntW(ImagePathName, L"ShowDebugger", NtCurrentTeb()->ProcessEnvironmentBlock->BeingDebugged, L"osver.ini");

}
