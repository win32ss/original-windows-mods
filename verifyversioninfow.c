BOOL VerifyVersionInfoWFake(LPOSVERSIONINFOEXW lpVersionInformation, DWORD dwTypeMask, DWORDLONG dwlConditionMask)
/*
   This function replicates all the behaviour of the original and is a little lighter too.

   One oddity is that for the version members of the struct, explicit "greater" or "less" operators specified
   in the condition mask will also be evaluated as true if the operands are equal, despite the existence of available <= or >= operators.
   This does not apply to the product type or suite members of the struct.
*/
{
	  BOOL Status;
      OSVERSIONINFOEXW osex;

	  if(lpVersionInformation->dwOSVersionInfoSize != sizeof(OSVERSIONINFOEXW) || !dwTypeMask || !dwlConditionMask)
	  {
		  SetLastError(ERROR_BAD_ARGUMENTS);
		  return FALSE;
	  }

	  RtlZeroMemory(&osex, sizeof(OSVERSIONINFOEXW));
	  osex.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);
	  if(!GetVersionExW(&osex))
	  {
		  return FALSE;
	  }
	  
	  Status = FALSE;

	  if(dwTypeMask & VER_MINORVERSION)
	  {
		   if(osex.dwMajorVersion > lpVersionInformation->dwMajorVersion)
			  Status = TRUE;

           if(dwlConditionMask & 1 || dwlConditionMask & 1 << 1 || dwlConditionMask & 1 << 2)
		   {
			   if(osex.dwMinorVersion == lpVersionInformation->dwMinorVersion)
			   {
				   Status = TRUE;
			   }

		   }
		   if(dwlConditionMask & 1 << 1)
		   {
			   if(osex.dwMinorVersion > lpVersionInformation->dwMinorVersion)
			   {
                   Status = TRUE;
			   }
		   }
		   if(dwlConditionMask & 1 << 2)
		   {
			   if(osex.dwMinorVersion < lpVersionInformation->dwMinorVersion)
			   {
                   Status = TRUE;
			   }
		   }
           if(!Status)
		   {
			   SetLastError(ERROR_OLD_WIN_VERSION);
			   return FALSE;
		   }
	  }

	  

	  if(dwTypeMask & VER_MAJORVERSION)
	  {
		  Status = FALSE;
           if(dwlConditionMask & 1 << 3 || dwlConditionMask & 1 << 4 || dwlConditionMask & 1 << 5)
		   {
			   if(osex.dwMajorVersion == lpVersionInformation->dwMajorVersion)
			   {
				   Status = TRUE;
			   }

		   }

		   if(dwlConditionMask & 1 << 4)
		   {
			   if(osex.dwMajorVersion > lpVersionInformation->dwMajorVersion)
			   {
                   Status = TRUE;
			   }
		   }
		   if(dwlConditionMask & 1 << 5)
		   {
			   if(osex.dwMajorVersion < lpVersionInformation->dwMajorVersion)
			   {
                   Status = TRUE;
			   }
		   }
           if(!Status)
		   {
			   SetLastError(ERROR_OLD_WIN_VERSION);
			   return FALSE;
		   }
	  }

	  

	  if(dwTypeMask & VER_BUILDNUMBER)
	  {
		  Status = FALSE;
           if(dwlConditionMask & 1 << 6 || dwlConditionMask & 1 << 7 || dwlConditionMask & 1 << 8)
		   {
			   if(osex.dwBuildNumber == lpVersionInformation->dwBuildNumber)
			   {
				   Status = TRUE;
			   }

		   }
		   if(dwlConditionMask & 1 << 7)
		   {
			   if(osex.dwBuildNumber > lpVersionInformation->dwBuildNumber)
			   {
                   Status = TRUE;
			   }
		   }
		   if(dwlConditionMask & 1 << 8)
		   {
			   if(osex.dwBuildNumber < lpVersionInformation->dwBuildNumber)
			   {
                   Status = TRUE;
			   }
		   }
           if(!Status)
		   {
			   SetLastError(ERROR_OLD_WIN_VERSION);
			   return FALSE;
		   }
	  }

	  if(dwTypeMask & VER_PLATFORMID)
	  {
		  Status = FALSE;
           if(dwlConditionMask & 1 << 9 || dwlConditionMask & 1 << 10 || dwlConditionMask & 1 << 11)
		   {
			   if(osex.dwPlatformId == lpVersionInformation->dwPlatformId)
			   {
				   Status = TRUE;
			   }

		   }
		   if(dwlConditionMask & 1 << 10)
		   {
			   if(osex.dwPlatformId > lpVersionInformation->dwPlatformId)
			   {
                   Status = TRUE;
			   }
		   }
		   if(dwlConditionMask & 1 << 11)
		   {
			   if(osex.dwPlatformId < lpVersionInformation->dwPlatformId)
			   {
                   Status = TRUE;
			   }
		   }
           if(!Status)
		   {
			   SetLastError(ERROR_OLD_WIN_VERSION);
			   return FALSE;
		   }
	  }

	  if(dwTypeMask & VER_SERVICEPACKMINOR)
	  {
		  Status = FALSE;

		   if(osex.dwMajorVersion > lpVersionInformation->dwMajorVersion || osex.dwMinorVersion > lpVersionInformation->dwMinorVersion)
			  Status = TRUE;

           if(dwlConditionMask & 1 << 12 || dwlConditionMask & 1 << 13 || dwlConditionMask & 1 << 14)
		   {
			   if(osex.wServicePackMinor == lpVersionInformation->wServicePackMinor)
			   {
				   Status = TRUE;
			   }

		   }
		   if(dwlConditionMask & 1 << 13)
		   {
			   if(osex.wServicePackMinor > lpVersionInformation->wServicePackMinor)
			   {
                   Status = TRUE;
			   }
		   }
		   if(dwlConditionMask & 1 << 14)
		   {
			   if(osex.wServicePackMinor < lpVersionInformation->wServicePackMinor)
			   {
                   Status = TRUE;
			   }
		   }
           if(!Status)
		   {
			   SetLastError(ERROR_OLD_WIN_VERSION);
			   return FALSE;
		   }
	  }

	  
	  if(dwTypeMask & VER_SERVICEPACKMAJOR)
	  {
		  Status = FALSE;
 
		  if(osex.dwMajorVersion > lpVersionInformation->dwMajorVersion || osex.dwMinorVersion > lpVersionInformation->dwMinorVersion)
			  Status = TRUE;

           if(dwlConditionMask & 1 << 15 || dwlConditionMask & 1 << 16 || dwlConditionMask & 1 << 17)
		   {
			   if(osex.wServicePackMajor == lpVersionInformation->wServicePackMajor)
			   {
				   Status = TRUE;
			   }

		   }
		   if(dwlConditionMask & 1 << 16)
		   {
			   if(osex.wServicePackMajor > lpVersionInformation->wServicePackMajor)
			   {
                   Status = TRUE;
			   }
		   }
		   if(dwlConditionMask & 1 << 17)
		   {
			   if(osex.wServicePackMajor < lpVersionInformation->wServicePackMajor)
			   {
                   Status = TRUE;
			   }
		   }
           if(!Status)
		   {
			   SetLastError(ERROR_OLD_WIN_VERSION);
			   return FALSE;
		   }
	  }

	  if(dwTypeMask & VER_SUITENAME)
	  {
		  Status = FALSE;
           if(dwlConditionMask & 1 << 18)
		   {
			   int j = 0;
			   while(j < 16)
			   {
			   if((osex.wSuiteMask & 1 << j) && (lpVersionInformation->wSuiteMask & 1 << j))
			   {
				   Status = TRUE;
				   break;
			   }
			   else
				   ++j;
			   }

		   }
		   if(dwlConditionMask & 1 << 19)
		   {
			   if((osex.wSuiteMask ^ lpVersionInformation->wSuiteMask) == 0)
			   {
                   Status = TRUE;
			   }
		   }
		   if(dwlConditionMask & 1 << 20)
		   {
			   if((osex.wSuiteMask ^ lpVersionInformation->wSuiteMask) == 0)
			   {
                   Status = TRUE;
			   }
		   }
           if(!Status)
		   {
			   SetLastError(ERROR_OLD_WIN_VERSION);
			   return FALSE;
		   }
	  }

	  if(dwTypeMask & VER_PRODUCT_TYPE)
	  {
		  Status = FALSE;
           if(dwlConditionMask & 1 << 21)
		   {
			   if(osex.wProductType == lpVersionInformation->wProductType)
			   {
				   Status = TRUE;
			   }

		   }
		   if(dwlConditionMask & 1 << 22)
		   {
			   if(osex.wProductType > lpVersionInformation->wProductType)
			   {
                   Status = TRUE;
			   }
		   }
		   if(dwlConditionMask & 1 << 23)
		   {
			   if(osex.wProductType < lpVersionInformation->wProductType)
			   {
                   Status = TRUE;
			   }
		   }
           if(!Status)
		   {
			   SetLastError(ERROR_OLD_WIN_VERSION);
			   return FALSE;
		   }
	  }

	  return TRUE;

}