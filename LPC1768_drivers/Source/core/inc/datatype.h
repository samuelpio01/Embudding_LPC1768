/*
 *	File Name: datatype.h
 *
 *  Description: This header includes the typedef'd basic data types
 *
 *  Author: Samuel D'costa
 */

#ifndef __DATATYPE_H_
#define __DATATYPE_H_


#ifndef NULL_D
	/* Macro definition for NULL */
	#define NULL_D	((void *)0)
#endif

typedef enum
{
	/* Boolean value for FALSE */
	FALSE_E = 0x00,
	/* Boolean value for TRUE */
	TRUE_E = 0xFF
}BOOL_T;

/* Macro definition to represent boolean true */
#define TRUE_D	(TRUE_E)
/* Macro definition to represent boolean false */
#define FALSE_D	(FALSE_E)

/*****************************************************
* Typedef for unsigned data types
******************************************************/

/* 8 bit or unsigned type */
typedef unsigned char					UNSIGNED8;
/* 16 bit unsigned type */
typedef unsigned short					UNSIGNED16;
/* 32 bit unsigned type */
typedef unsigned long					UNSIGNED32;
/* 64 bit unsigned type */
typedef unsigned long long				UNSIGNED64;

/*****************************************************
* Typedef for signed data types
******************************************************/

/* 8 bit signed type */
typedef signed char						SIGNED8;
/* 16 bit signed type */
typedef signed short					SIGNED16;
/* 32 bit signed type */
typedef signed long						SIGNED32;
/* 64 bit signed type */
typedef signed long long				SIGNED64;

/*****************************************************
* Typedef for float data types
******************************************************/

/* 32 bit float type */
typedef float							FLOAT32;
/* 64 bit double type */
typedef double							DOUBLE64;

#endif /* DATATYPE_H_ */
