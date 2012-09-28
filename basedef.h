#ifndef __SPELL_EDITOR_BASEDEF_H__
#define __SPELL_EDITOR_BASEDEF_H__
#include <assert.h>
namespace BSLib
{
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