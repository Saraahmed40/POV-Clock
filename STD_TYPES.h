#ifndef STD_TYPES_H     // for guarding 
#define STD_TYPES_H


/*signed data type*/
typedef unsigned char  u8;
typedef unsigned short int  u16;
typedef unsigned long int  u32;
typedef unsigned long long int  u64;

/*unsigned data type*/
typedef signed char  s8;
typedef signed short int  s16;
typedef signed long int  s32;
typedef signed long long int  s64;

/*float data type*/
typedef float f32;
typedef double f64;
typedef long double f128;

/* Address NULL */
#define NULL  (void *)0x00

#define OK               0
#define NOT_OK           1
#define NULL_POINTER     2
#define ERROR_BUSYSTATE  3

#define TRUE  1
#define FALSE  0

#endif
