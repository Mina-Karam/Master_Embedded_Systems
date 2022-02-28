#ifndef UTIL_H
#define UTIL_H

#define	GET_BIT(reg,n)				(((reg)>>(n))&1)
#define SET_BIT(reg,n)				(reg|=(1<<n))
#define CLR_BIT(reg,n)				(reg&=~(1<<n))
#define TOGGLE_BIT(reg,n)			(reg^=(1<<n))

#define	GET_REG(reg)				(reg)
#define SET_REG(reg)				((reg)=0XFF)
#define CLR_REG(reg)				((reg)=0X00)
#define TOGGLE_REG(reg)				((reg)^=0xFF) //((reg)~=(reg))
#define ASSIGN_REG(reg,value)		((reg)=(value))

#define	GET_LOW_NIB(reg)			((reg)&0X0F)
#define SET_LOW_NIB(reg)			((reg)|=0X0F)
#define CLR_LOW_BIT(reg)			((reg)&=0XF0)
#define TOGGLE_LOW_NIB(reg)			((reg)^=0X0F)
#define ASSIGN_LOW_NIB(reg,value)	((reg)=(((reg)&0XF0)|((value)&0x0F))) //??

#define	GET_HIGH_NIB(reg)			(((reg)&0XF0)>>4)
#define SET_HIGH_NIB(reg)			((reg)|=0XF0)
#define CLR_HIGH_BIT(reg)			((reg)&=0X0F)
#define TOGGLE_HIGH_NIB(reg)		((reg)^=0XF0)
#define ASSIGN_HIGH_NIB(reg)		((reg)=((value<<4)|(reg&0X0F)))

#endif //TYPES_H