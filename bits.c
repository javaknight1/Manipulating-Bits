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

typedef struct
{
   char *teamname;
   char *name1;
   char *id1;
   char *name2;
   char *id2;
} team_struct;

/* 
 * Instructions to Students:
 *
* STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member */
   "pw97976alem2",
 
   /* Student name 1: Replace with the full name of first team member */
   "Robert Avery",

   /* Login ID 1: Replace with the login ID of first team member */
   "pw97976",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "Alem Sahle",
   /* Login ID 2: Login ID of the second team member */
   "alem2"
};

#if 0
/*
 *
 * STEP 2: Read the following instructions carefully.
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
     cannot use unsigned, arrays, structs, or unions.
 
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
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif

/* CMSC 313 Spring 2012 
** 15 puzzles, 75 points
** teams of 2 permitted
*/




/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */

int bitOr(int x, int y) {
   
   //This uses De Morgan's law   
   return ~( (~x) & (~y) );
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
/*
 * Separate the in into 4 bytes a,b,c,d & them wi the mask and
 * add them back together. Using the ! operator twice will
 * return a 0 if there was no odd bit set, 1 otherwise
 */
int anyOddBit(int x) {

   int mask, a, b, c, d, ret;

   mask = 0xAA;
   a = x & mask;
   b = (x >> 8) & mask;
   c = (x >> 16) & mask;
   d = (x >> 24) & mask;
   ret = a + b + c + d;
   
   return !(!ret);
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  
  //Shifts it left one less than it's bit size, then
  //shifts it right one less than it's bit size
  //Everything is zero except the LSB
  return ( (x << 31) >> 31 );
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
 
  //Make a mask for the end 
  int x = (2 << highbit) + ~0;

  //Make a mask for the beginning
  int y = (1 << lowbit) + ~0;

  //Combine them together
  int z = x & (~y);

  return z;
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {

  int a, b , c, d;

  //Take the bits at the end
  a = (x & (0xff << 24)) >> 24;
  a = a & 0xff;
  b = (x & (0xff << 16)) >>  8;
  
  //Take the bits at the beginning
  c = (x & (0xff << 8)) <<  8;
  d = (x & 0xff) << 24;

  //printf("a = 0x%x\n", a);
  //printf("b = 0x%x\n", b);
  //printf("c = 0x%x\n", c);
  //printf("d = 0x%x\n", d);
  //Combine them in reverse order
  return a | b | c | d;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
/*
 * The point of mask2 is that if x is zero, mask2 will
 * be all zero bits, if x is not zero, mask2 will be all
 * ones bits. The result will be that val1 and val2 will be filtered
 * out, depending on whether x = 0 or x != 0...
 * since returning the y or z, depending on which one was filtered out
 */
int conditional(int x, int y, int z) {

   int mask1, mask2, val1, val2;

   mask1 = !!x;
   mask2 = ~mask1 + 1;
   val1 = mask2 & y;
   val2 = ~mask2 & z;  

   return val1 + val2;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
   
   int y, z;

   //Make y NOT x
   y = ~x;
   
   //Add 1 to that
   z = y + 1;
   
   //NOT z and & with y, then shift
   //it right 31( 32 -1 ). This will
   //give you the opposite of what you want,
   //so you & with 1
   x = ( (~z & y) >> 31) & 1;

   return x;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
/*
 * If x is Tmax than it will be 10.....01 x+= a will
 * elimate the sign bit, the combination of !(~x|mask) will
 * yield a 0 for any other case other than x = 1000.....000
 */
int isTmax(int x) {
  
   int a, mask;

   a = x + 1;
   mask = !a;
   /*00....10*/
   x+=a;
   return !(~x|mask);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {

  int y;
  
  //Make n = 32 - n
  n = 33 + ~n;

  //Shift x left of the new n, then
  //shift back right with the same n
  y = x << n;
  y = y >> n;

  //Exclusive OR x and y, then bang it
  y = !(y^x);

  return y;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
/*
 * If two numbers are hte same, exclusive or will result in
 * sero, if tehy are not the same it will yield some bit
 * pattern..the !! will mkae sure that a 1 is returned in
 * the case that the two numbers are not identical, and still
 * a 0 in the case that they are
 */
int isNotEqual(int x, int y) {
  return !!(x ^ y);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
 
  int y;

  //Shift x right
  x = x >> n;

  //Find 32 - n
  n = 32 + ~n;
  
  //Take a 4 bytes and make them all 1's,
  //then shift them left by n+1
  y = ( (~0x0) << n) << 1;

  //OR x and y, then XOR that with y
  //This make the right shift on x arithmetic
  //whether or not it was, then chagnes it to
  //logical shift
  x = (x|y)^y;

  return x;
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
  
   int y, z, s;
   
   //Find 32 - n number
   s = 32 + ~n;

   //Creates a mask for the end
   z = ~((~0x0) << n);

   //Make y the bits being shifted
   y = (x >> s) >> 1;
   y = z & y;

   //Make x the rotated bytes without the shifted bits
   x = x << n;
   
   //Combine x and y
   return x|y;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
 
  int y, z;

  //If y = -1, then 0x30 <= x is FALSE
  //If y =  0, then 0x30 <= x is TRUE
  y = x + (~0x2f);
  y = y >> 31;

  //If z = -1, then x <= 0x39 is FALSE
  //If z =  0, then x <= 0x39 is TRUE
  z = 58 + ~x;
  z = z >> 31;

  return !(y|z);
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
/*
 * Creates a mask of all 1 bitsadding this mask
 * to x creates a mirror image of the bits whose
 * order represents the magnitude of the number
 * passedin...so exclusive or with all 1's flips
 * that image and yields the magnitude of the number
 * passed in
 */
int absVal(int x) {

  int mask, ret;

  mask = x >> 31;
  ret = x + mask;
  ret = ret ^ mask;
  return ret;
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {

  int y;
 
  //Add x with the biggest postive number
  y = x + (~(0x80 << 24));
  
  //OR x and y
  y = x|y;
  
  //Shift that left 31(32-1)
  //This will give you the opposite bit of what you want
  x = y >> 31;
  
  //AND with 1 and will return the correct number 
  return x & 1;
}
