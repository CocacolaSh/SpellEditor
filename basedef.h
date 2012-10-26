#ifndef __SPELL_EDITOR_BASEDEF_H__
#define __SPELL_EDITOR_BASEDEF_H__
#include <assert.h>
#include <cstdlib>
namespace BSLib
{

#if defined(_DEBUG)
#if defined(_IRR_WINDOWS_API_) && defined(_MSC_VER) && !defined (_WIN32_WCE)
#if defined(WIN64) || defined(_WIN64) // using portable common solution for x64 configuration
#include <crtdbg.h>
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ ) if (_CONDITION_) {_CrtDbgBreak();}
#else
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ ) if (_CONDITION_) {_asm int 3}
#endif
#else
#include "assert.h"
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ ) assert( !(_CONDITION_) );
#endif
#else
#define _IRR_DEBUG_BREAK_IF( _CONDITION_ )
#endif


#ifdef _MSC_VER
typedef unsigned __int8		u8;
typedef __int8				s8;
typedef unsigned __int16	u16;
typedef __int16				s16;
typedef unsigned __int32	u32;
typedef __int32				s32;
typedef unsigned __int64	u64;
typedef __int64				s64;
#else
typedef unsigned char		u8;
typedef signed char			s8;
typedef unsigned short		u16;
typedef signed short		s16;
typedef unsigned int		u32;
typedef signed int			s32;
typedef unsigned long long  u64;
typedef long long			s64;
#endif

typedef char				c8;

typedef float				f32;

typedef double				f64;


}
#endif