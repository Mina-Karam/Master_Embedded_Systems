/*
 * Platform_Types.h
 *
 * Created on : Dec 22, 2021
 *     Author : Mina Karam
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


/*----------------------------------------------------------------------------*/
/*-------------------------------- Types -------------------------------------*/
/*----------------------------------------------------------------------------*/


typedef _Bool                       boolean;
typedef char                        char_t;
typedef signed char                 sint8_t;
typedef unsigned char               uint8_t;
typedef signed short                sint16_t;
typedef unsigned short              uint16_t;
typedef signed int                  sint32_t;
typedef unsigned int                uint32_t;
typedef signed long long int        sint64_t;
typedef unsigned long long int      uint64_t;

typedef volatile char                       vchar_t;
typedef volatile signed char                vsint8_t;
typedef volatile unsigned char              vuint8_t;
typedef volatile signed short               vsint16_t;
typedef volatile unsigned short             vuint16_t;
typedef volatile signed int                 vsint32_t;
typedef volatile unsigned int               vuint32_t;
typedef volatile signed long long int       vsint64_t;
typedef volatile unsigned long long int     vuint64_t;

typedef float       float32;
typedef double      float64;

/*----------------------------------------------------------------------------*/
/*-------------------------------- Defines -----------------------------------*/
/*----------------------------------------------------------------------------*/

#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif

#endif /* PLATFORM_TYPES_H_ */
