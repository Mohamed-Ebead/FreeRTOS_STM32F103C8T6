

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char	      	u8;
typedef unsigned short int  	u16;
typedef unsigned long int   	u32;
typedef signed char 	      	s8;
typedef signed short int 	    s16;
typedef signed long int	    	s32;
typedef float 			       	f32;
typedef double 			        f64;

typedef union{
	struct
	{
		u8 Bit0 : 1;
		u8 Bit1 : 1;
		u8 Bit2 : 1;
		u8 Bit3 : 1;
		u8 Bit4 : 1;
		u8 Bit5 : 1;
		u8 Bit6 : 1;
		u8 Bit7 : 1;
	}BitAcces;

	u8 ByteAccess;
}Register;

/*ERROR Status*/
#define STD_u8_ERROR_NOK  (u8)1
#define STD_u8_ERROR_OK   (u8)0

#define Null ((void *)0)

#endif /* STD_TYPES_H_ */
