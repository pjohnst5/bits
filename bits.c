/* 
 * CS:APP Data Lab 
 * 
 * Paul Johnston: pjohnst5 
 * Robert Bogh: rbogh 
 * Caleb Pomar: cpomar
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
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* Rating 1 -- 2 points each */

/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
 /* Our implementation works by first getting a bit mask of 85 
  * which is 01010101 in binary and the answer initialized to 01010101 as well.
  * Next, we bit shifted the answer to the left by 8 and or'd it with 85 
  * to make the newly added zeros on the right side to also be 01010101,
  * We continued this proccess until all the even positions of the int (4 bytes size) were 1's.
  */
  const int numShifts = 8;
  int mask = 85;
  int answer = 85;

  answer = (answer << numShifts) | mask;
  answer= (answer << numShifts) | mask;
  answer = (answer << numShifts) | mask;
  return answer;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  /* Our implementation sets the answer to 0 then flips the bits to be all 1's!*/
  
  int answer = 0;
  return (~answer);
}
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
/*
  First we create an int and set it all to zeroes and then negate it to get all ones. 
  Next we created a new int that consists of the flipped bits of the number of ones to be 
  represented on the far left of the answer plus the offset of one, this is simply to 
  get the additive inverse of n. To get the number of times that we will eventually shift
  (why we will do this will be elaborated on later) we add this additive inverse to the 
  total number of bits. Then we create a mask to query whether we have been given a number
  n equal to 0. This mask is created by taking the number n, and converting it to the boolean
  value by means of !! If n were zero, then the mask would consist of all zeroes, else
  it would be all ones. All this done, we can then create a statment that left shifts 
  on the original answer int the number of times we previously decided, as long as the mask 
  is not all zeroes.
*/

  const int getMostSig = 31;
  const int numBits = 32;
  int answer = 0;
  int offset = 1;
  int negationOfN = 0;
  int numShifts = 0;
  int mask = n;

  answer = (~answer);
  negationOfN = ((~n) + offset);
  numShifts = (numBits + negationOfN);
  mask = (!!mask);
  mask = mask << getMostSig;
  mask = mask >> getMostSig; //would be all zeros if n were zero, otherwise, would be all 1's

  return ((answer << numShifts )& mask);
}
/* Rating 2 -- 3 points each */
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
/* First we make a mask such that the first byte consists of all ones
 * Then we mimic mulitplication by shifting the number n three times to the left to 
 * generate the number of times we would need to shift x to the right  
 * Then we create a new int which consists of x shifted numShift number of times to the right
 * Lastly, we & the newly formated answer int and the mask together to return the byte we want
*/
  const int multiplyShift = 3;
  int mask = 255;
  int numShift = n<<multiplyShift;
  int answer = x>>numShift;

  return (answer&mask);
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
/*
 * first we xored x vs y. Because xor returns 0 if both bits are the same,
 * if the number is the same, the xor result will be all zero. Then we
 * !! the result to reformat a nonzero xorResult to 1 (zero results will 
 * remain zero)
 * */
  int xorResult = x ^ y;
  return !!xorResult;
}
/* Rating 3 -- 2 points each */
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* First, we xored "x" with 000000, then we took that result and !! it so that if it 
   * was 0 to begin with, it stayed as 0, if it were something other than 0 to begin with, 
   * it was 0001. After that we shifted it to the left 31 and then right 31 to make all the bits
   * whatever the right most bit was. We made a second mask to be the opposite of that result. 
   * Now if "x" was zero, xorResult was also 0. If "x" was not zero, xorResult was all 1's. 
   * We anded xorResult with y and mask2 with z. 
   * If x was zero, we sould show z, if x was 
   * not zero, we would show y.
   * */
  const int getSigBit = 31;
  int xorMask = 0;
  int mask2 = 0;
  int xorResult = 0;

  xorResult = x ^ xorMask;
  xorResult = !!xorResult;
  xorResult = (xorResult << getSigBit);
  xorResult = (xorResult >> getSigBit);
  mask2 = ~xorResult;
 
  return ((xorResult&y)|(mask2&z));
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /* There were two cases to consider: when x and y had the same sign, and different signs.
   * copy2OfX accounts for when the signs are different.
   * firstWay accounts for when the signs are the same.
   * We find out if the signs are the same by isolating the sign bits and xor'ing them together.
   * We then take that result, and & it with the copy2OfX.
   * We negate the xor result and & it with the first way.
   * When the signs are the same, copy2OfX becomes 0.
   * When the signs are different, firstWay becomes 0.
   */
  const int sigShift = 31;
  int signMask = 1;
  int copy2OfX = 0;
  int copy1OfX = 0;
  int copy1OfY = 0;
  int tempx = 0;
  int tempy = 0;
  int firstWay = 0;
  int xorResult = 0;
  int oppoXorResult = 0;

  copy2OfX = x;
  copy1OfX = x;
  copy1OfY = y;
  tempx = x;
  tempy = y;
  signMask = (signMask << sigShift);

  copy2OfX = (copy2OfX & signMask);
  copy2OfX = (!copy2OfX);

  firstWay = (tempx + (~tempy));
  firstWay = (firstWay & signMask);
  firstWay = (!firstWay);

  copy1OfX = (copy1OfX & signMask);
  copy1OfY = (copy1OfY & signMask);
  xorResult = (copy1OfX ^ copy1OfY);
  xorResult = (xorResult >> sigShift); 
  oppoXorResult = xorResult;
  oppoXorResult = (~oppoXorResult);

  return ((firstWay & oppoXorResult)|(copy2OfX & xorResult));
}

/* Rating 4 -- 1 point each */
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
/*First we create three ints: two masks and an int to be the negation of x. 
 * Then we negate x by flipping the bits and adding one. We then set the first mask equal to 
 * the negation of x, and shift right the first mask 31 times in order to get the sign, 
 * indicated by the bit that would now be on the far right. Then we set another mask 
 * to hold the sign info, and negate that: so if the original number was zero, 
 * mask2 negated will now be 1, and vice versa. 
 * Then we return mask1 & x or mask2 & the negation of x.
 */
   const int sigShift = 31;
   int mask1 = 0; 
   int mask2 = 0;
   int negX = 0;

   negX = x;
   negX = (~negX);
   negX = negX+1;
   mask1 = negX;
   mask1 = (mask1>>sigShift);
   mask2 = mask1;
   mask2 = (~mask2);
   return (mask1&x)|(mask2&negX);
}
/* Float Rating 2 -- 3 points each */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  /* First, we make a mask of 24 0's and 8 1's (255).
   * Then we shifted a copy of the input to the right 23 steps to get the exponent in
   * the far right 8 bits. Then we and that with the mask we just made to reveal if 
   * the exponent was all 1's.
   * Next we take a second copy of the input and shift it to the left 9 bits to 
   * isolate the significand. We !it once to reveal
   * if it had anything non zero in it. If it did, we know that the input is NaN. 
   * Otherwise, we change the most significant bit of the input.
   */
  const int blueShift = 23;
  const int greyShift = 9;
  const int sigShift = 31;
  int blueMask = 255;
  unsigned int resultOfBlueMasking = 0;
  unsigned int blueCopy = 0;
  unsigned int greyCopy = 0;
  int signChange = 1;
  int answer = 0;

  blueCopy = uf;
  greyCopy = uf;
  
  blueCopy = (blueCopy >> blueShift);
  resultOfBlueMasking = (blueCopy & blueMask);
 
  greyCopy = (greyCopy << greyShift);
  greyCopy = !greyCopy;

 
  if (resultOfBlueMasking == 255 && greyCopy == 0){
     return uf;
  }

  signChange = (signChange << sigShift);
  answer = uf;
  answer = (answer ^ signChange); 
  return answer;
  
}
/* Float Rating 4 -- 1 point each */
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  return 2;
}
