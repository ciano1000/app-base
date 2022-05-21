#include <stdint.h>

//NOTE	Compiler Context
#ifdef	__clang__
#define COMPILER_CLANG	1
#define COMPILER_VS		0
#define COMPILER_GCC	0
#elif	_MSC_VER
#define COMPILER_VS		1
#define COMPILER_CLANG	0
#define COMPILER_GCC	0
#elif	__GNUC__
#define COMPILER_GCC	1
#define COMPILER_CLANG	0
#define COMPILER_VS		0
#else
#error "Can't determine compiler."
#endif 

#ifdef	_WIN64
#define OS_WIN64	1
#define OS_LINUX	0
#endif

#ifdef __gnu_linux__
#define OS_LINUX	1
#define OS_WIN64	0
#endif

typedef uint8_t 	u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;
#define b8 			u8;
#define b16			u16;
#define b32 		u32;
#define b64 		u64;
typedef int8_t  	s8;
typedef int16_t 	s16;
typedef int32_t 	s32;
typedef int64_t 	s64;
typedef float 		f32;
typedef double  	f64;

//Generic Macro Utilities - macros prepended with "_" are only intended for use within other macros
#define _TokenPaste_(x, y) x##y				//Concatenate as a token, not a string
#define _TokenCat_(x,y) TOKEN_PASTE(x,y)	//Concatenate preproc strings
#define _DeferLoop_(begin, end, var) for (u32 var = (begin, 0); !var; ++var, end)	//Replicate basic odin/jai/golang like "defer" functionality
#define ArrayCount(array) (sizeof(array) / sizeof(array[0])) //get num items in a static array
//Constants
#define UNIQUE_INT CAT(prefix, __COUNTER__)	//Technically not a constant but whatever

