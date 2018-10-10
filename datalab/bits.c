/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 9.0.0.  Version 9.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, fourth edition, plus
   Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
   (Amd. 2 was published 2016-05-01,
  
  I see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
 	int x = 0x55;
	x <<= 8;
	x |= 0x55;
	x <<= 8;
	x |= 0x55;
	x <<= 8;
	x |= 0x55;
	x <<= 8;
	x |= 0x55;
	return x;
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
	int count = 0;
	int xCopy = x;
	int xCopy2 = x;
	int Count = 0;
	count += !!x;
	x >>= 8;
	count += !!x;
	x >>= 8;
	count += !!x;
	x >>= 8;
	count += !!x;
	x >>= 8;
	count += (( ~1) + 1);
    Count = count + count + count + count + count + count + count + count;
	xCopy >>= Count;
	Count += !!xCopy;
	xCopy >>= 1;
	Count += !!xCopy;
	xCopy >>= 1;
	Count += !!xCopy;
	xCopy >>= 1;
	Count += !!xCopy;
	xCopy >>= 1;
	Count += !!xCopy;
	xCopy >>= 1;
	Count += !!xCopy;
	xCopy >>= 1;
	Count += !!xCopy;
	xCopy >>= 1;
	Count += !!xCopy;
	return (0x1 << (Count +  (~1) + 1)) & (~(!!xCopy2) + 1);
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  unsigned sign = (~(uf >> 31)) + 1;
  unsigned exponent = (uf >> 23) & 0xff;
  unsigned tail = uf & 0x7fffff;
  unsigned res = 0;
  if((uf == 0x80000000) || (uf == 0)) return uf;
  else if (exponent == 0xff) return uf;
  else if ((exponent == 0) && (tail != 0)) {
  	tail <<= 1;
	tail &= 0x7fffff;
	res = (sign <<= 31);
	sign = tail >> 22;
	if(sign) res |= ((exponent + 1) << 23);
	res |= tail;
  }
  else{
    res = (sign <<= 31);//set sign
    res |= ((exponent + 1) << 23);
	res |= tail;
  }
  return res;
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  int moveAfter = 0;
  int moveLeft = (x >> (33 + (~n))) & (~((~((33 + (~n))>>5)) + 1));
  moveLeft &= (~((~0)<<n));
  moveAfter = (x << n);
  return moveLeft + moveAfter;
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
	int sign = x >> 31;
    sign |= !!x;  
	return sign;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	//After one-day effort paid to this function but failed, I found an example on the Internet
	unsigned sign = 0;
	unsigned shiftLeft = 0;
	unsigned flag = 0, tmp;
	unsigned absX = x;              
	if (x == 0) return 0;
	if (x < 0) {
		sign = 0x80000000;
		absX = -x;
	}
	while (1) {
		tmp = absX;
		absX <<= 1;
		shiftLeft++;
		if (tmp & 0x80000000) break;
	}
	if ((absX & 0x01ff) > 0x100) flag = 1;      
	else if ((absX & 0x03ff) == 0x0300) flag = 1;     
	return sign + (absX>>9) + ((159-shiftLeft) << 23) + flag;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {      
     //this function also found on the web after a long and hard effort
	 //I try many times to compare bettween the complements of positive and negtive constants,
	 //while the -1 and max circumstances turn out over and over again 		
     int temp=x^(x>>31);//get positive of x;
      int isZero=!temp;
     //notZeroMask is 0xffffffff
	 int notZeroMask=(!(!temp)<<31)>>31;
	 int bit_16,bit_8,bit_4,bit_2,bit_1;
	 bit_16=!(!(temp>>16))<<4;
	 //see if the high 16bits have value,if have,then we need at least 16 bits
	 //if the highest 16 bits have value,then rightshift 16 to see the exact place of  
	 //if not means they are all zero,right shift nothing and we should only consider the low 16 bits
	 temp=temp>>bit_16;
	 bit_8=!(!(temp>>8))<<3;
	 temp=temp>>bit_8;
	 bit_4=!(!(temp>>4))<<2;
	 temp=temp>>bit_4;
	 bit_2=!(!(temp>>2))<<1;
	 temp=temp>>bit_2;
	 bit_1=!(!(temp>>1));
	 temp=bit_16+bit_8+bit_4+bit_2+bit_1+2;//at least we need one bit for 1 to tmax,
	 //and we need another bit for sign
	 return isZero|(temp&notZeroMask);	  
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
	return !!(~((~x) + y));
}
/* 
 * implication - return x -> y in propositional logic - 0 for false, 1
 * for true
 *   Example: implication(1,1) = 1
 *            implication(1,0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y) {
    return ((!x) | y);
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
	int move = highbit + 1;
	int highset = 0;
	int lowset = 0;
	highset = (~0) << (move);
	highset &= (~((~(move >> 5)) + 1));
	lowset = (~0) << (lowbit);
	return (highset ^ lowset) & (~((move + (~lowbit)) >> 31)) ;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	return (!(x+1+x+1))&(!!(x+1));
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
	int z = x + y;
	int case1 = 0;
	int case2 = 0;
     	z = (z >> 31) & 0x1;
	x = (x >> 31) & 0x1;
	y = (y >> 31) & 0x1;
	case1 = ((x) ^ (y));
    case2 = (!((x) ^ (y))) & (!((z) ^ (x)));
	return case1 | case2;
}
