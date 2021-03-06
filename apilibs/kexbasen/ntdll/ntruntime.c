/*
 *  KernelEx
 *  Copyright (C) 2013, Ley0k
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

#include "_ntdll_apilist.h"

static inline int digitval(int ch)
{
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	} else if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 10;
	} else if (ch >= 'a' && ch <= 'z') {
		return ch - 'a' + 10;
	} else {
		return -1;
	}
}

uintmax_t strntoumax(const char *nptr, char **endptr, int base, size_t n)
{
	int minus = 0;
	uintmax_t v = 0;
	int d;

	while (n && isspace((unsigned char)*nptr)) {
		nptr++;
		n--;
	}

	/* Single optional + or - */
	if (n) {
		char c = *nptr;
		if (c == '-' || c == '+') {
			minus = (c == '-');
			nptr++;
			n--;
		}
	}

	if (base == 0) {
		if (n >= 2 && nptr[0] == '0' &&
		    (nptr[1] == 'x' || nptr[1] == 'X')) {
			n -= 2;
			nptr += 2;
			base = 16;
		} else if (n >= 1 && nptr[0] == '0') {
			n--;
			nptr++;
			base = 8;
		} else {
			base = 10;
		}
	} else if (base == 16) {
		if (n >= 2 && nptr[0] == '0' &&
		    (nptr[1] == 'x' || nptr[1] == 'X')) {
			n -= 2;
			nptr += 2;
		}
	}

	while (n && (d = digitval(*nptr)) >= 0 && d < base) {
		v = v * base + d;
		n--;
		nptr++;
	}

	if (endptr)
		*endptr = (char *)nptr;

	return minus ? -(long)v : v;
}

/* MAKE_EXPORT _atoi64=_atoi64 */
/* MAKE_EXPORT _chkstk=_chkstk */
__declspec(naked) void _chkstk(void)
{
__asm {
		push    ecx
		cmp     eax, 1000h
		lea     ecx, [esp+4+4]
		jb      short _below

_loop:
		sub     ecx, 1000h
		sub     eax, 1000h
		test    [ecx], eax
		cmp     eax, 1000h
		jnb     short _loop

_below:
		sub     ecx, eax
		mov     eax, esp
		test    [ecx], eax
		mov     esp, ecx
		mov     ecx, [eax]
		mov     eax, [eax+4]
		push    eax
		retn
	}
}
/* MAKE_EXPORT _itoa=_itoa */
/* MAKE_EXPORT _itow=_itow */
/* MAKE_EXPORT _ltoa=_ltoa */
/* MAKE_EXPORT _ltow=_ltow */
/* MAKE_EXPORT _memccpy=_memccpy */
/* MAKE_EXPORT _memicmp=_memicmp */
/* MAKE_EXPORT _snprintf=_snprintf */
/* MAKE_EXPORT _snwprintf=_snwprintf */
/* MAKE_EXPORT _splitpath=_splitpath */
/* MAKE_EXPORT _strcmpi=_strcmpi */
/* MAKE_EXPORT _strlwr=_strlwr */
/* MAKE_EXPORT _strnicmp=_stricmp */
/* MAKE_EXPORT _strupr=_strupr */
/* MAKE_EXPORT __ctype_tolower=_tolower */
/* MAKE_EXPORT __ctype_toupper=_toupper */
/* MAKE_EXPORT _ultoa=_ultoa */
/* MAKE_EXPORT _ultow=_ultow */
/* MAKE_EXPORT _vsnprintf=_vsnprintf */
/* MAKE_EXPORT _wcsicmp=_wcsicmp */
/* MAKE_EXPORT _wcslwr=_wcslwr */
/* MAKE_EXPORT _wcsnicmp=_wcsnicmp */
/* MAKE_EXPORT _wcsupr=_wcsupr */
/* MAKE_EXPORT _wtoi=_wtoi */
/* MAKE_EXPORT _wtoi64=_wtoi64 */
/* MAKE_EXPORT _wtol=_wtol */
/* MAKE_EXPORT abs=abs */
/* MAKE_EXPORT atan=atan */
/* MAKE_EXPORT atoi_NT=atoi */
int atoi_NT(const char *nptr)
{
	return (int)strntoumax(nptr, (char **)NULL, 10, ~(size_t) 0);
}

/* MAKE_EXPORT atol_NT=atol */
int atol_NT(const char *nptr)
{
	return (long)strntoumax(nptr, (char **)NULL, 10, ~(size_t) 0);
}

/* MAKE_EXPORT ceil=ceil */
/* MAKE_EXPORT cos=cos */
/* MAKE_EXPORT fabs=fabs */
/* MAKE_EXPORT floor=floor */
/* MAKE_EXPORT __ctype_isalnum=isalnum */
/* MAKE_EXPORT __ctype_isalpha=isalpha */
/* MAKE_EXPORT __ctype_isascii=isascii */
/* MAKE_EXPORT __ctype_iscntrl=iscntrl */
/* MAKE_EXPORT __ctype_isdigit=isdigit */
/* MAKE_EXPORT __ctype_isgraph=isgraph */
/* MAKE_EXPORT __ctype_islower=islower */
/* MAKE_EXPORT __ctype_ispunct=ispunct */
/* MAKE_EXPORT __ctype_isspace=isspace */
/* MAKE_EXPORT __ctype_isupper=isupper */
/* MAKE_EXPORT __ctype_isxdigit=isxdigit */
/* MAKE_EXPORT labs=labs */
/* MAKE_EXPORT log=log */
/* MAKE_EXPORT mbstowcs=mbstowcs */
/* MAKE_EXPORT memccpy=memccpy */
/* MAKE_EXPORT memchr=memchr */
/* MAKE_EXPORT memcmp=memcmp */
/* MAKE_EXPORT memcpy=memcpy */
/* MAKE_EXPORT memmove=memmove */
/* MAKE_EXPORT memset=memset */
/* MAKE_EXPORT pow=pow */
/* MAKE_EXPORT qsort=qsort */
/* MAKE_EXPORT sin=sin */
/* MAKE_EXPORT sprintf=sprintf */
/* MAKE_EXPORT sqrt=sqrt */
/* MAKE_EXPORT sscanf=sscanf */
/* MAKE_EXPORT strcat=strcat */
/* MAKE_EXPORT strchr=strchr */
/* MAKE_EXPORT strcmp=strcmp */
/* MAKE_EXPORT strcmpi=strcmpi */
/* MAKE_EXPORT strcpy=strcpy */
/* MAKE_EXPORT strcspn=strcspn */
/* MAKE_EXPORT strdup=strdup */
/* MAKE_EXPORT strlen=strlen */
/* MAKE_EXPORT strncat=strncat */
/* MAKE_EXPORT strncmp=strncmp */
/* MAKE_EXPORT strncpy=strncpy */
/* MAKE_EXPORT strnicmp=strnicmp */
/* MAKE_EXPORT strpbrk=strpbrk */
/* MAKE_EXPORT strrchr=strrchr */
/* MAKE_EXPORT strstr=strstr */
/* MAKE_EXPORT strtok=strok */
/* MAKE_EXPORT strtol=strtol */
/* MAKE_EXPORT strtoul=strtoul */
/* MAKE_EXPORT swprintf=swprintf */
/* MAKE_EXPORT strupr=strupr */
/* MAKE_EXPORT tan=tan */
/* MAKE_EXPORT __ctype_tolower=tolower */
/* MAKE_EXPORT __ctype_toupper=toupper */
/* MAKE_EXPORT towlower=towlower */
/* MAKE_EXPORT towupper=towupper */
/* MAKE_EXPORT vsprintf=vsprintf */
/* MAKE_EXPORT wcscat=wcscat */
/* MAKE_EXPORT wcschr=wcschr */
/* MAKE_EXPORT wcscmp=wcscmp */
/* MAKE_EXPORT wcscpy=wcscpy */
/* MAKE_EXPORT wcscspn=wcscspn */
/* MAKE_EXPORT wcslen=wcslen */
/* MAKE_EXPORT wcsncat=wcsncat */
/* MAKE_EXPORT wcsncmp=wcsncmp */
/* MAKE_EXPORT wcsncpy=wcsncpy */
/* MAKE_EXPORT wcspbrk=wcspbrk */
/* MAKE_EXPORT wcsrchr=wcsrchr */
/* MAKE_EXPORT wcsspn=wcsspn */
/* MAKE_EXPORT wcsstr=wcsstr */
/* MAKE_EXPORT wcstol=wcstol */
/* MAKE_EXPORT wcstombs=wcstombs */
/* MAKE_EXPORT wcstoul=wcstoul */