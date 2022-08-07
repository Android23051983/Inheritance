#pragma once
#ifdef _UNICODE
#define _tcslen	wcslen
#else 
#define _tcslen	strlen
#endif 