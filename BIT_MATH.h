#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,bit)    (REG)|=(1<<bit)
#define CLR_BIT(REG,bit)    (REG)&=~(1<<bit)
#define TOG_BIT(REG,bit)    (REG)^=(1<<bit)
#define GET_BIT(REG,bit)    (((REG)>>(bit))&1)

/* To write 1/0 in one operation for
      1-one BIT
	  2-Clear the required bits
	  3-insert new values|    */
#define WRITE_BIT(REG, bit, VAL)      ( (REG) = (( (REG) & (~(1<<(bit))) ) | ( (VAL) << (bit))) )

/* To write 1/0 in one operation for THE WHOLE PORT REGISTER*/
#define WRITE_REG(REG, VAL)              ((REG) = (VAL))


#endif







