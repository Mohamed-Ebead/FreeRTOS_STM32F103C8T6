






#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define LOW_NIBB 					        0x0F
#define HIGH_NIBB 				            0xF0

/****************PIN calculation****************/
#define SET_BIT(REG,BIT_NUM)	  			((REG) |= (1<<(BIT_NUM)))
#define CLR_BIT(REG,BIT_NUM) 		  		((REG) &= ~(1<<(BIT_NUM)))
#define TOGGLE_BIT(REG,BIT_NUM) 			((REG) ^= (1<<(BIT_NUM)))
#define GET_BIT(REG,BIT_NUM) 			    (!!((REG) &(1<<(BIT_NUM))))

/*#define ASS_BIT(REG,N,V)				  	do                  \
  											{ 	if (V==1)         \
                                        		REG |= (1<<N);    \
                                        		else              \
                                        		REG &= ~(1<<N);   \
                                      	    }while(0)*/
                                    
#define BITCALC_ASS_BIT(REG,BIT_NUM,VALUE)  		REG=((REG)&(~(1<<(BIT_NUM))))|(VALUE<<BIT_NUM)

/****************port calculation****************/
#define BITCALC_ASS_PORT(REG,VALUE)					(REG)=(VALUE)
#define BITCALC_GET_PORT(REG,VALUE)					(VALUE)=(REG)

/****************Nipple calculation****************/
#define BITCALC_SET_HIGH_NIBBLE(REG) 			    (REG |= HIGH_NIBB)
#define BITCALC_CLR_HIGH_NIBBLE(REG) 			    (REG &= ~(HIGH_NIBB))
#define BITCALC_TOGGLE_HIGH_NIBBLE(REG) 		    (REG ^= (HIGH_NIBB))

#define BITCALC_SET_LOW_NIBBLE(REG) 		  		(REG |= LOW_NIBB)
#define BITCALC_CLR_LOW_NIBBLE(REG) 			  	(REG &= ~(LOW_NIBB))
#define BITCALC_TOGGLE_LOW_NIBBLE(REG) 				(REG ^= (LOW_NIBB))

/****************concatination****************/
#define BITCALC_CONC_8BIT(b0,b1,b2,b3,b4,b5,b6,b7)			 BITCALC_CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)
#define BITCALC_CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)		 0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif /*BIT_MATH_H_*/
