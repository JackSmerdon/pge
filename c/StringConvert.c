/* automatically created by mc from /home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/StringConvert.mod.  */

#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#   if !defined (TRUE)
#      define TRUE (1==1)
#   endif

#   if !defined (FALSE)
#      define FALSE (1==0)
#   endif

#include <stddef.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define _StringConvert_H
#define _StringConvert_C

#   include "GSYSTEM.h"
#   include "Glibc.h"
#   include "Glibm.h"
#   include "GM2RTS.h"
#   include "GDynamicStrings.h"
#   include "Gldtoa.h"
#   include "Gdtoa.h"


/*
   IntegerToString - converts INTEGER, i, into a String. The field with can be specified
                     if non zero. Leading characters are defined by padding and this
                     function will prepend a + if sign is set to TRUE.
                     The base allows the caller to generate binary, octal, decimal, hexidecimal
                     numbers. The value of lower is only used when hexidecimal numbers are
                     generated and if TRUE then digits abcdef are used, and if FALSE then ABCDEF
                     are used.
*/

DynamicStrings_String StringConvert_IntegerToString (int i, unsigned int width, char padding, unsigned int sign, unsigned int base, unsigned int lower);

/*
   CardinalToString - converts CARDINAL, c, into a String. The field with can be specified
                      if non zero. Leading characters are defined by padding.
                      The base allows the caller to generate binary, octal, decimal, hexidecimal
                      numbers. The value of lower is only used when hexidecimal numbers are
                      generated and if TRUE then digits abcdef are used, and if FALSE then ABCDEF
                      are used.
*/

DynamicStrings_String StringConvert_CardinalToString (unsigned int c, unsigned int width, char padding, unsigned int base, unsigned int lower);

/*
   StringToInteger - converts a string, s, of, base, into an INTEGER.
                     Leading white space is ignored. It stops converting
                     when either the string is exhausted or if an illegal
                     numeral is found.
                     The parameter found is set TRUE if a number was found.
*/

int StringConvert_StringToInteger (DynamicStrings_String s, unsigned int base, unsigned int *found);

/*
   StringToCardinal - converts a string, s, of, base, into a CARDINAL.
                      Leading white space is ignored. It stops converting
                      when either the string is exhausted or if an illegal
                      numeral is found.
                      The parameter found is set TRUE if a number was found.
*/

unsigned int StringConvert_StringToCardinal (DynamicStrings_String s, unsigned int base, unsigned int *found);

/*
   LongIntegerToString - converts LONGINT, i, into a String. The field with
                         can be specified if non zero. Leading characters
                         are defined by padding and this function will
                         prepend a + if sign is set to TRUE.
                         The base allows the caller to generate binary,
                         octal, decimal, hexidecimal numbers.
                         The value of lower is only used when hexidecimal
                         numbers are generated and if TRUE then digits
                         abcdef are used, and if FALSE then ABCDEF are used.
*/

DynamicStrings_String StringConvert_LongIntegerToString (long int i, unsigned int width, char padding, unsigned int sign, unsigned int base, unsigned int lower);

/*
   StringToLongInteger - converts a string, s, of, base, into an LONGINT.
                         Leading white space is ignored. It stops converting
                         when either the string is exhausted or if an illegal
                         numeral is found.
                         The parameter found is set TRUE if a number was found.
*/

long int StringConvert_StringToLongInteger (DynamicStrings_String s, unsigned int base, unsigned int *found);

/*
   LongCardinalToString - converts LONGCARD, c, into a String. The field
                          width can be specified if non zero. Leading
                          characters are defined by padding.
                          The base allows the caller to generate binary,
                          octal, decimal, hexidecimal numbers.
                          The value of lower is only used when hexidecimal
                          numbers are generated and if TRUE then digits
                          abcdef are used, and if FALSE then ABCDEF are used.
*/

DynamicStrings_String StringConvert_LongCardinalToString (long unsigned int c, unsigned int width, char padding, unsigned int base, unsigned int lower);

/*
   StringToLongCardinal - converts a string, s, of, base, into a LONGCARD.
                          Leading white space is ignored. It stops converting
                          when either the string is exhausted or if an illegal
                          numeral is found.
                          The parameter found is set TRUE if a number was found.
*/

long unsigned int StringConvert_StringToLongCardinal (DynamicStrings_String s, unsigned int base, unsigned int *found);

/*
   ShortCardinalToString - converts SHORTCARD, c, into a String. The field
                          width can be specified if non zero. Leading
                          characters are defined by padding.
                          The base allows the caller to generate binary,
                          octal, decimal, hexidecimal numbers.
                          The value of lower is only used when hexidecimal
                          numbers are generated and if TRUE then digits
                          abcdef are used, and if FALSE then ABCDEF are used.
*/

DynamicStrings_String StringConvert_ShortCardinalToString (short unsigned int c, unsigned int width, char padding, unsigned int base, unsigned int lower);

/*
   StringToShortCardinal - converts a string, s, of, base, into a SHORTCARD.
                           Leading white space is ignored. It stops converting
                           when either the string is exhausted or if an illegal
                           numeral is found.
                           The parameter found is set TRUE if a number was found.
*/

short unsigned int StringConvert_StringToShortCardinal (DynamicStrings_String s, unsigned int base, unsigned int *found);

/*
   stoi - decimal string to INTEGER
*/

int StringConvert_stoi (DynamicStrings_String s);

/*
   itos - integer to decimal string.
*/

DynamicStrings_String StringConvert_itos (int i, unsigned int width, char padding, unsigned int sign);

/*
   ctos - cardinal to decimal string.
*/

DynamicStrings_String StringConvert_ctos (unsigned int c, unsigned int width, char padding);

/*
   stoc - decimal string to CARDINAL
*/

unsigned int StringConvert_stoc (DynamicStrings_String s);

/*
   hstoi - hexidecimal string to INTEGER
*/

int StringConvert_hstoi (DynamicStrings_String s);

/*
   ostoi - octal string to INTEGER
*/

int StringConvert_ostoi (DynamicStrings_String s);

/*
   bstoi - binary string to INTEGER
*/

int StringConvert_bstoi (DynamicStrings_String s);

/*
   hstoc - hexidecimal string to CARDINAL
*/

unsigned int StringConvert_hstoc (DynamicStrings_String s);

/*
   ostoc - octal string to CARDINAL
*/

unsigned int StringConvert_ostoc (DynamicStrings_String s);

/*
   bstoc - binary string to CARDINAL
*/

unsigned int StringConvert_bstoc (DynamicStrings_String s);

/*
   StringToLongreal - returns a LONGREAL and sets found to TRUE if a legal number is seen.
*/

long double StringConvert_StringToLongreal (DynamicStrings_String s, unsigned int *found);

/*
   LongrealToString - converts a LONGREAL number, Real, which has,
                      TotalWidth, and FractionWidth into a string.
                      It uses decimal notation.

                      So for example:

                      LongrealToString(1.0, 4, 2)  -> '1.00'
                      LongrealToString(12.3, 5, 2) -> '12.30'
                      LongrealToString(12.3, 6, 2) -> ' 12.30'
                      LongrealToString(12.3, 6, 3) -> '12.300'

                      if total width is too small then the fraction
                      becomes truncated.

                      LongrealToString(12.3, 5, 3) -> '12.30'

                      Positive numbers do not have a '+' prepended.
                      Negative numbers will have a '-' prepended and
                      the TotalWidth will need to be large enough
                      to contain the sign, whole number, '.' and
                      fractional components.
*/

DynamicStrings_String StringConvert_LongrealToString (long double x, unsigned int TotalWidth, unsigned int FractionWidth);

/*
   stor - returns a REAL given a string.
*/

double StringConvert_stor (DynamicStrings_String s);

/*
   stolr - returns a LONGREAL given a string.
*/

long double StringConvert_stolr (DynamicStrings_String s);

/*
   ToSigFig - returns a floating point or base 10 integer
              string which is accurate to, n, significant
              figures.  It will return a new String
              and, s, will be destroyed.


              So:  12.345

              rounded to the following significant figures yields

              5      12.345
              4      12.34
              3      12.3
              2      12
              1      10
*/

DynamicStrings_String StringConvert_ToSigFig (DynamicStrings_String s, unsigned int n);

/*
   ToDecimalPlaces - returns a floating point or base 10 integer
                     string which is accurate to, n, decimal
                     places.  It will return a new String
                     and, s, will be destroyed.
                     Decimal places yields, n, digits after
                     the .

                     So:  12.345

                     rounded to the following decimal places yields

                     5      12.34500
                     4      12.3450
                     3      12.345
                     2      12.34
                     1      12.3
*/

DynamicStrings_String StringConvert_ToDecimalPlaces (DynamicStrings_String s, unsigned int n);

/*
   Assert - implement a simple assert.
*/

static void Assert (unsigned int b, char *file_, unsigned int _file_high, unsigned int line, char *func_, unsigned int _func_high);

/*
   Max -
*/

static unsigned int Max (unsigned int a, unsigned int b);

/*
   Min -
*/

static unsigned int Min (unsigned int a, unsigned int b);

/*
   LongMin - returns the smallest LONGCARD
*/

static long unsigned int LongMin (long unsigned int a, long unsigned int b);

/*
   IsDigit - returns TRUE if, ch, lies between '0'..'9'.
*/

static unsigned int IsDigit (char ch);

/*
   IsDecimalDigitValid - returns the TRUE if, ch, is a base legal decimal digit.
                         If legal then the value is appended numerically onto, c.
*/

static unsigned int IsDecimalDigitValid (char ch, unsigned int base, unsigned int *c);

/*
   IsHexidecimalDigitValid - returns the TRUE if, ch, is a base legal hexidecimal digit.
                             If legal then the value is appended numerically onto, c.
*/

static unsigned int IsHexidecimalDigitValid (char ch, unsigned int base, unsigned int *c);

/*
   IsDecimalDigitValidLong - returns the TRUE if, ch, is a base legal decimal digit.
                             If legal then the value is appended numerically onto, c.
*/

static unsigned int IsDecimalDigitValidLong (char ch, unsigned int base, long unsigned int *c);

/*
   IsHexidecimalDigitValidLong - returns the TRUE if, ch, is a base legal hexidecimal digit.
                                 If legal then the value is appended numerically onto, c.
*/

static unsigned int IsHexidecimalDigitValidLong (char ch, unsigned int base, long unsigned int *c);

/*
   IsDecimalDigitValidShort - returns the TRUE if, ch, is a base legal decimal digit.
                              If legal then the value is appended numerically onto, c.
*/

static unsigned int IsDecimalDigitValidShort (char ch, unsigned int base, short unsigned int *c);

/*
   IsHexidecimalDigitValidShort - returns the TRUE if, ch, is a base legal hexidecimal digit.
                                  If legal then the value is appended numerically onto, c.
*/

static unsigned int IsHexidecimalDigitValidShort (char ch, unsigned int base, short unsigned int *c);

/*
   ToThePower10 - returns a LONGREAL containing the value of v * 10^power.
*/

static long double ToThePower10 (long double v, int power);

/*
   DetermineSafeTruncation - we wish to use TRUNC when converting REAL/LONGREAL
                             into a string for the non fractional component.
                             However we need a simple method to
                             determine the maximum safe truncation value.
*/

static unsigned int DetermineSafeTruncation (void);

/*
   rtos -
*/

static DynamicStrings_String rtos (double r, unsigned int TotalWidth, unsigned int FractionWidth);

/*
   lrtos -
*/

static DynamicStrings_String lrtos (long double r, unsigned int TotalWidth, unsigned int FractionWidth);

/*
   doDecimalPlaces - returns a string which is accurate to
                     n decimal places.  It returns a new String
                     and, s, will be destroyed.
*/

static DynamicStrings_String doDecimalPlaces (DynamicStrings_String s, unsigned int n);

/*
   doSigFig - returns a string which is accurate to
              n decimal places.  It returns a new String
              and, s, will be destroyed.
*/

static DynamicStrings_String doSigFig (DynamicStrings_String s, unsigned int n);

/*
   carryOne - add a carry at position, i.
*/

static DynamicStrings_String carryOne (DynamicStrings_String s, unsigned int i);


/*
   Assert - implement a simple assert.
*/

static void Assert (unsigned int b, char *file_, unsigned int _file_high, unsigned int line, char *func_, unsigned int _func_high)
{
  char file[_file_high+1];
  char func[_func_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (file, file_, _file_high+1);
  memcpy (func, func_, _func_high+1);

  if (! b)
    M2RTS_ErrorMessage ((char *) "assert failed", 13, (char *) file, _file_high, line, (char *) func, _func_high);
}


/*
   Max -
*/

static unsigned int Max (unsigned int a, unsigned int b)
{
  if (a > b)
    return a;
  else
    return b;
}


/*
   Min -
*/

static unsigned int Min (unsigned int a, unsigned int b)
{
  if (a < b)
    return a;
  else
    return b;
}


/*
   LongMin - returns the smallest LONGCARD
*/

static long unsigned int LongMin (long unsigned int a, long unsigned int b)
{
  if (a < b)
    return a;
  else
    return b;
}


/*
   IsDigit - returns TRUE if, ch, lies between '0'..'9'.
*/

static unsigned int IsDigit (char ch)
{
  return (ch >= '0') && (ch <= '9');
}


/*
   IsDecimalDigitValid - returns the TRUE if, ch, is a base legal decimal digit.
                         If legal then the value is appended numerically onto, c.
*/

static unsigned int IsDecimalDigitValid (char ch, unsigned int base, unsigned int *c)
{
  if ((IsDigit (ch)) && ((((unsigned int) (ch))-((unsigned int) ('0'))) < base))
    {
      (*c) = ((*c)*base)+(((unsigned int) (ch))-((unsigned int) ('0')));
      return TRUE;
    }
  else
    return FALSE;
}


/*
   IsHexidecimalDigitValid - returns the TRUE if, ch, is a base legal hexidecimal digit.
                             If legal then the value is appended numerically onto, c.
*/

static unsigned int IsHexidecimalDigitValid (char ch, unsigned int base, unsigned int *c)
{
  if (((ch >= 'a') && (ch <= 'f')) && (((((unsigned int) (ch))-((unsigned int) ('a')))+10) < base))
    {
      (*c) = ((*c)*base)+((((unsigned int) (ch))-((unsigned int) ('a')))+10);
      return TRUE;
    }
  else if (((ch >= 'A') && (ch <= 'F')) && (((((unsigned int) (ch))-((unsigned int) ('F')))+10) < base))
    {
      (*c) = ((*c)*base)+((((unsigned int) (ch))-((unsigned int) ('A')))+10);
      return TRUE;
    }
  else
    return FALSE;
}


/*
   IsDecimalDigitValidLong - returns the TRUE if, ch, is a base legal decimal digit.
                             If legal then the value is appended numerically onto, c.
*/

static unsigned int IsDecimalDigitValidLong (char ch, unsigned int base, long unsigned int *c)
{
  if ((IsDigit (ch)) && ((((unsigned int) (ch))-((unsigned int) ('0'))) < base))
    {
      (*c) = (*c)*((long unsigned int ) (base+(((unsigned int) (ch))-((unsigned int) ('0')))));
      return TRUE;
    }
  else
    return FALSE;
}


/*
   IsHexidecimalDigitValidLong - returns the TRUE if, ch, is a base legal hexidecimal digit.
                                 If legal then the value is appended numerically onto, c.
*/

static unsigned int IsHexidecimalDigitValidLong (char ch, unsigned int base, long unsigned int *c)
{
  if (((ch >= 'a') && (ch <= 'f')) && (((((unsigned int) (ch))-((unsigned int) ('a')))+10) < base))
    {
      (*c) = (*c)*((long unsigned int ) (base+((((unsigned int) (ch))-((unsigned int) ('a')))+10)));
      return TRUE;
    }
  else if (((ch >= 'A') && (ch <= 'F')) && (((((unsigned int) (ch))-((unsigned int) ('F')))+10) < base))
    {
      (*c) = (*c)*((long unsigned int ) (base+((((unsigned int) (ch))-((unsigned int) ('A')))+10)));
      return TRUE;
    }
  else
    return FALSE;
}


/*
   IsDecimalDigitValidShort - returns the TRUE if, ch, is a base legal decimal digit.
                              If legal then the value is appended numerically onto, c.
*/

static unsigned int IsDecimalDigitValidShort (char ch, unsigned int base, short unsigned int *c)
{
  if ((IsDigit (ch)) && ((((unsigned int) (ch))-((unsigned int) ('0'))) < base))
    {
      (*c) = (*c)*((short unsigned int ) (base+(((unsigned int) (ch))-((unsigned int) ('0')))));
      return TRUE;
    }
  else
    return FALSE;
}


/*
   IsHexidecimalDigitValidShort - returns the TRUE if, ch, is a base legal hexidecimal digit.
                                  If legal then the value is appended numerically onto, c.
*/

static unsigned int IsHexidecimalDigitValidShort (char ch, unsigned int base, short unsigned int *c)
{
  if (((ch >= 'a') && (ch <= 'f')) && (((((unsigned int) (ch))-((unsigned int) ('a')))+10) < base))
    {
      (*c) = (*c)*((short unsigned int ) (base+((((unsigned int) (ch))-((unsigned int) ('a')))+10)));
      return TRUE;
    }
  else if (((ch >= 'A') && (ch <= 'F')) && (((((unsigned int) (ch))-((unsigned int) ('F')))+10) < base))
    {
      (*c) = (*c)*((short unsigned int ) (base+((((unsigned int) (ch))-((unsigned int) ('A')))+10)));
      return TRUE;
    }
  else
    return FALSE;
}


/*
   ToThePower10 - returns a LONGREAL containing the value of v * 10^power.
*/

static long double ToThePower10 (long double v, int power)
{
  int i;

  i = 0;
  if (power > 0)
    while (i < power)
      {
        v = v*10.0;
        i += 1;
      }
  else
    while (i > power)
      {
        v = v/10.0;
        i -= 1;
      }
  return v;
}


/*
   DetermineSafeTruncation - we wish to use TRUNC when converting REAL/LONGREAL
                             into a string for the non fractional component.
                             However we need a simple method to
                             determine the maximum safe truncation value.
*/

static unsigned int DetermineSafeTruncation (void)
{
  double MaxPowerOfTen;
  unsigned int LogPower;

  MaxPowerOfTen = 1.0;
  LogPower = 0;
  while ((MaxPowerOfTen*10.0) < ((double) ((INT_MAX) / 10)))
    {
      MaxPowerOfTen = MaxPowerOfTen*10.0;
      LogPower += 1;
    }
  return LogPower;
}


/*
   rtos -
*/

static DynamicStrings_String rtos (double r, unsigned int TotalWidth, unsigned int FractionWidth)
{
  M2RTS_HALT (-1);
  return NULL;
}


/*
   lrtos -
*/

static DynamicStrings_String lrtos (long double r, unsigned int TotalWidth, unsigned int FractionWidth)
{
  M2RTS_HALT (-1);
  return NULL;
}


/*
   doDecimalPlaces - returns a string which is accurate to
                     n decimal places.  It returns a new String
                     and, s, will be destroyed.
*/

static DynamicStrings_String doDecimalPlaces (DynamicStrings_String s, unsigned int n)
{
  int i;
  int l;
  int point;
  DynamicStrings_String t;
  DynamicStrings_String whole;
  DynamicStrings_String fraction;
  DynamicStrings_String tenths;
  DynamicStrings_String hundreths;

  l = DynamicStrings_Length (s);
  i = 0;
  /* remove '.'  */
  point = DynamicStrings_Index (s, '.', 0);
  if (point == 0)
    s = DynamicStrings_Slice (DynamicStrings_Mark (s), 1, 0);
  else if (point < l)
    s = DynamicStrings_ConCat (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, point), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), point+1, 0)));
  else
    s = DynamicStrings_Slice (DynamicStrings_Mark (s), 0, point);
  l = DynamicStrings_Length (s);
  i = 0;
  if (l > 0)
    {
      /* skip over leading zeros  */
      while ((i < l) && ((DynamicStrings_char (s, i)) == '0'))
        i += 1;
      /* was the string full of zeros?  */
      if ((i == l) && ((DynamicStrings_char (s, i-1)) == '0'))
        {
          s = DynamicStrings_KillString (s);
          s = DynamicStrings_ConCat (DynamicStrings_InitString ((char *) "0.", 2), DynamicStrings_Mark (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar ('0')), n)));
          return s;
        }
    }
  /* insert leading zero  */
  s = DynamicStrings_ConCat (DynamicStrings_InitStringChar ('0'), DynamicStrings_Mark (s));
  point += 1;  /* and move point position to correct place  */
  l = DynamicStrings_Length (s);  /* update new length  */
  i = point;  /* update new length  */
  while ((n > 1) && (i < l))
    {
      n -= 1;
      i += 1;
    }
  if ((i+3) <= l)
    {
      t = DynamicStrings_Dup (s);
      hundreths = DynamicStrings_Slice (DynamicStrings_Mark (s), i+1, i+3);
      s = t;
      if ((StringConvert_stoc (hundreths)) >= 50)
        s = carryOne (DynamicStrings_Mark (s), (unsigned int) i);
      hundreths = DynamicStrings_KillString (hundreths);
    }
  else if ((i+2) <= l)
    {
      t = DynamicStrings_Dup (s);
      tenths = DynamicStrings_Slice (DynamicStrings_Mark (s), i+1, i+2);
      s = t;
      if ((StringConvert_stoc (tenths)) >= 5)
        s = carryOne (DynamicStrings_Mark (s), (unsigned int) i);
      tenths = DynamicStrings_KillString (tenths);
    }
  /* check whether we need to remove the leading zero  */
  if ((DynamicStrings_char (s, 0)) == '0')
    {
      s = DynamicStrings_Slice (DynamicStrings_Mark (s), 1, 0);
      l -= 1;
      point -= 1;
    }
  if (i < l)
    {
      s = DynamicStrings_Slice (DynamicStrings_Mark (s), 0, i);
      l = DynamicStrings_Length (s);
      if (l < point)
        s = DynamicStrings_ConCat (s, DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar ('0')), (unsigned int) point-l));
    }
  /* re-insert the point  */
  if (point >= 0)
    {
      /* avoid gcc warning by using compound statement even if not strictly necessary.  */
      if (point == 0)
        s = DynamicStrings_ConCat (DynamicStrings_InitStringChar ('.'), DynamicStrings_Mark (s));
      else
        s = DynamicStrings_ConCat (DynamicStrings_ConCatChar (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, point), '.'), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), point, 0)));
    }
  return s;
}


/*
   doSigFig - returns a string which is accurate to
              n decimal places.  It returns a new String
              and, s, will be destroyed.
*/

static DynamicStrings_String doSigFig (DynamicStrings_String s, unsigned int n)
{
  int i;
  int l;
  int z;
  int point;
  DynamicStrings_String t;
  DynamicStrings_String tenths;
  DynamicStrings_String hundreths;

  l = DynamicStrings_Length (s);
  i = 0;
  /* remove '.'  */
  point = DynamicStrings_Index (s, '.', 0);
  if (point >= 0)
    if (point == 0)
      s = DynamicStrings_Slice (DynamicStrings_Mark (s), 1, 0);
    else if (point < l)
      s = DynamicStrings_ConCat (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, point), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), point+1, 0)));
    else
      s = DynamicStrings_Slice (DynamicStrings_Mark (s), 0, point);
  else
    s = DynamicStrings_Dup (DynamicStrings_Mark (s));
  l = DynamicStrings_Length (s);
  i = 0;
  if (l > 0)
    {
      /* skip over leading zeros  */
      while ((i < l) && ((DynamicStrings_char (s, i)) == '0'))
        i += 1;
      /* was the string full of zeros?  */
      if ((i == l) && ((DynamicStrings_char (s, i-1)) == '0'))
        {
          /* truncate string  */
          s = DynamicStrings_Slice (DynamicStrings_Mark (s), 0, (int) n);
          i = n;
        }
    }
  /* add a leading zero in case we need to overflow the carry  */
  z = i;  /* remember where we inserted zero  */
  if (z == 0)  /* remember where we inserted zero  */
    s = DynamicStrings_ConCat (DynamicStrings_InitStringChar ('0'), DynamicStrings_Mark (s));
  else
    s = DynamicStrings_ConCat (DynamicStrings_ConCatChar (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, i), '0'), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), i, 0)));
  n += 1;  /* and increase the number of sig figs needed  */
  l = DynamicStrings_Length (s);  /* and increase the number of sig figs needed  */
  while ((n > 1) && (i < l))
    {
      n -= 1;
      i += 1;
    }
  if ((i+3) <= l)
    {
      t = DynamicStrings_Dup (s);
      hundreths = DynamicStrings_Slice (DynamicStrings_Mark (s), i+1, i+3);
      s = t;
      if ((StringConvert_stoc (hundreths)) >= 50)
        s = carryOne (DynamicStrings_Mark (s), (unsigned int) i);
      hundreths = DynamicStrings_KillString (hundreths);
    }
  else if ((i+2) <= l)
    {
      t = DynamicStrings_Dup (s);
      tenths = DynamicStrings_Slice (DynamicStrings_Mark (s), i+1, i+2);
      s = t;
      if ((StringConvert_stoc (tenths)) >= 5)
        s = carryOne (DynamicStrings_Mark (s), (unsigned int) i);
      tenths = DynamicStrings_KillString (tenths);
    }
  /* check whether we need to remove the leading zero  */
  if ((DynamicStrings_char (s, z)) == '0')
    {
      if (z == 0)
        s = DynamicStrings_Slice (DynamicStrings_Mark (s), z+1, 0);
      else
        s = DynamicStrings_ConCat (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, z), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), z+1, 0)));
      l = DynamicStrings_Length (s);
    }
  else
    point += 1;
  if (i < l)
    {
      s = DynamicStrings_Slice (DynamicStrings_Mark (s), 0, i);
      l = DynamicStrings_Length (s);
      if (l < point)
        s = DynamicStrings_ConCat (s, DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar ('0')), (unsigned int) point-l));
    }
  /* re-insert the point  */
  if (point >= 0)
    {
      /* avoid gcc warning by using compound statement even if not strictly necessary.  */
      if (point == 0)
        s = DynamicStrings_ConCat (DynamicStrings_InitStringChar ('.'), DynamicStrings_Mark (s));
      else
        s = DynamicStrings_ConCat (DynamicStrings_ConCatChar (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, point), '.'), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), point, 0)));
    }
  return s;
}


/*
   carryOne - add a carry at position, i.
*/

static DynamicStrings_String carryOne (DynamicStrings_String s, unsigned int i)
{
  if (i >= 0)
    if (IsDigit (DynamicStrings_char (s, (int) i)))
      {
        /* avoid gcc warning by using compound statement even if not strictly necessary.  */
        if ((DynamicStrings_char (s, (int) i)) == '9')
          if (i == 0)
            {
              s = DynamicStrings_ConCat (DynamicStrings_InitStringChar ('1'), DynamicStrings_Mark (s));
              return s;
            }
          else
            {
              s = DynamicStrings_ConCat (DynamicStrings_ConCatChar (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, (int) i), '0'), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), (int) i+1, 0)));
              return carryOne (s, i-1);
            }
        else
          if (i == 0)
            s = DynamicStrings_ConCat (DynamicStrings_InitStringChar ((char) (((unsigned int) (DynamicStrings_char (s, (int) i)))+1)), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), (int) i+1, 0)));
          else
            s = DynamicStrings_ConCat (DynamicStrings_ConCatChar (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, (int) i), (char) (((unsigned int) (DynamicStrings_char (s, (int) i)))+1)), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), (int) i+1, 0)));
      }
  return s;
}


/*
   IntegerToString - converts INTEGER, i, into a String. The field with can be specified
                     if non zero. Leading characters are defined by padding and this
                     function will prepend a + if sign is set to TRUE.
                     The base allows the caller to generate binary, octal, decimal, hexidecimal
                     numbers. The value of lower is only used when hexidecimal numbers are
                     generated and if TRUE then digits abcdef are used, and if FALSE then ABCDEF
                     are used.
*/

DynamicStrings_String StringConvert_IntegerToString (int i, unsigned int width, char padding, unsigned int sign, unsigned int base, unsigned int lower)
{
  DynamicStrings_String s;
  unsigned int c;

  if (i < 0)
    {
      if (i == (INT_MIN))
        {
          /* remember that -15 MOD 4 = 1 in Modula-2  */
          c = ((unsigned int ) (abs (i+1)))+1;
          if (width > 0)
            return DynamicStrings_ConCat (StringConvert_IntegerToString (-((int ) (c / base)), width-1, padding, sign, base, lower), DynamicStrings_Mark (StringConvert_IntegerToString ((int) c % base, 0, ' ', FALSE, base, lower)));
          else
            return DynamicStrings_ConCat (StringConvert_IntegerToString (-((int ) (c / base)), 0, padding, sign, base, lower), DynamicStrings_Mark (StringConvert_IntegerToString ((int) c % base, 0, ' ', FALSE, base, lower)));
        }
      else
        s = DynamicStrings_InitString ((char *) "-", 1);
      i = -i;
    }
  else
    if (sign)
      s = DynamicStrings_InitString ((char *) "+", 1);
    else
      s = DynamicStrings_InitString ((char *) "", 0);
  if (i > (((int ) (base))-1))
    s = DynamicStrings_ConCat (DynamicStrings_ConCat (s, DynamicStrings_Mark (StringConvert_IntegerToString ((int) ((unsigned int ) (i)) / base, 0, ' ', FALSE, base, lower))), DynamicStrings_Mark (StringConvert_IntegerToString ((int) ((unsigned int ) (i)) % base, 0, ' ', FALSE, base, lower)));
  else
    if (i <= 9)
      s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) (((unsigned int ) (i))+((unsigned int) ('0'))))));
    else
      if (lower)
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) ((((unsigned int ) (i))+((unsigned int) ('a')))-10))));
      else
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) ((((unsigned int ) (i))+((unsigned int) ('A')))-10))));
  if (width > (DynamicStrings_Length (s)))
    return DynamicStrings_ConCat (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar (padding)), width-(DynamicStrings_Length (s))), DynamicStrings_Mark (s));
  return s;
}


/*
   CardinalToString - converts CARDINAL, c, into a String. The field with can be specified
                      if non zero. Leading characters are defined by padding.
                      The base allows the caller to generate binary, octal, decimal, hexidecimal
                      numbers. The value of lower is only used when hexidecimal numbers are
                      generated and if TRUE then digits abcdef are used, and if FALSE then ABCDEF
                      are used.
*/

DynamicStrings_String StringConvert_CardinalToString (unsigned int c, unsigned int width, char padding, unsigned int base, unsigned int lower)
{
  DynamicStrings_String s;

  s = DynamicStrings_InitString ((char *) "", 0);
  if (c > (base-1))
    s = DynamicStrings_ConCat (DynamicStrings_ConCat (s, DynamicStrings_Mark (StringConvert_CardinalToString (c / base, 0, ' ', base, lower))), DynamicStrings_Mark (StringConvert_CardinalToString (c % base, 0, ' ', base, lower)));
  else
    if (c <= 9)
      s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) (c+((unsigned int) ('0'))))));
    else
      if (lower)
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) ((c+((unsigned int) ('a')))-10))));
      else
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) ((c+((unsigned int) ('A')))-10))));
  if (width > (DynamicStrings_Length (s)))
    return DynamicStrings_ConCat (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar (padding)), width-(DynamicStrings_Length (s))), s);
  return s;
}


/*
   StringToInteger - converts a string, s, of, base, into an INTEGER.
                     Leading white space is ignored. It stops converting
                     when either the string is exhausted or if an illegal
                     numeral is found.
                     The parameter found is set TRUE if a number was found.
*/

int StringConvert_StringToInteger (DynamicStrings_String s, unsigned int base, unsigned int *found)
{
  unsigned int n;
  unsigned int l;
  unsigned int c;
  unsigned int negative;

  s = DynamicStrings_RemoveWhitePrefix (s);  /* returns a new string, s  */
  l = DynamicStrings_Length (s);  /* returns a new string, s  */
  c = 0;
  n = 0;
  negative = FALSE;
  if (n < l)
    {
      /* parse leading + and -  */
      while (((DynamicStrings_char (s, (int) n)) == '-') || ((DynamicStrings_char (s, (int) n)) == '+'))
        {
          if ((DynamicStrings_char (s, (int) n)) == '-')
            negative = ! negative;
          n += 1;
        }
      while ((n < l) && ((IsDecimalDigitValid (DynamicStrings_char (s, (int) n), base, &c)) || (IsHexidecimalDigitValid (DynamicStrings_char (s, (int) n), base, &c))))
        {
          (*found) = TRUE;
          n += 1;
        }
    }
  s = DynamicStrings_KillString (s);
  if (negative)
    return -((int ) (Min (((unsigned int ) (INT_MAX))+1, c)));
  else
    return (int ) (Min ((unsigned int) INT_MAX, c));
}


/*
   StringToCardinal - converts a string, s, of, base, into a CARDINAL.
                      Leading white space is ignored. It stops converting
                      when either the string is exhausted or if an illegal
                      numeral is found.
                      The parameter found is set TRUE if a number was found.
*/

unsigned int StringConvert_StringToCardinal (DynamicStrings_String s, unsigned int base, unsigned int *found)
{
  unsigned int n;
  unsigned int l;
  unsigned int c;

  s = DynamicStrings_RemoveWhitePrefix (s);  /* returns a new string, s  */
  l = DynamicStrings_Length (s);  /* returns a new string, s  */
  c = 0;
  n = 0;
  if (n < l)
    {
      /* parse leading +  */
      while ((DynamicStrings_char (s, (int) n)) == '+')
        n += 1;
      while ((n < l) && ((IsDecimalDigitValid (DynamicStrings_char (s, (int) n), base, &c)) || (IsHexidecimalDigitValid (DynamicStrings_char (s, (int) n), base, &c))))
        {
          (*found) = TRUE;
          n += 1;
        }
    }
  s = DynamicStrings_KillString (s);
  return c;
}


/*
   LongIntegerToString - converts LONGINT, i, into a String. The field with
                         can be specified if non zero. Leading characters
                         are defined by padding and this function will
                         prepend a + if sign is set to TRUE.
                         The base allows the caller to generate binary,
                         octal, decimal, hexidecimal numbers.
                         The value of lower is only used when hexidecimal
                         numbers are generated and if TRUE then digits
                         abcdef are used, and if FALSE then ABCDEF are used.
*/

DynamicStrings_String StringConvert_LongIntegerToString (long int i, unsigned int width, char padding, unsigned int sign, unsigned int base, unsigned int lower)
{
  DynamicStrings_String s;
  long unsigned int c;

  if (i < 0)
    {
      if (i == (LONG_MIN))
        {
          /* remember that -15 MOD 4 is 1 in Modula-2, and although ABS(MIN(LONGINT)+1)
            is very likely MAX(LONGINT), it is safer not to assume this is the case  */
          c = ((long unsigned int ) (labs (i+1)))+1;
          if (width > 0)
            return DynamicStrings_ConCat (StringConvert_LongIntegerToString (-((long int ) (c / ((long unsigned int ) (base)))), width-1, padding, sign, base, lower), DynamicStrings_Mark (StringConvert_LongIntegerToString ((long int) c % ((long unsigned int ) (base)), 0, ' ', FALSE, base, lower)));
          else
            return DynamicStrings_ConCat (StringConvert_LongIntegerToString (-((long int ) (c / ((long unsigned int ) (base)))), 0, padding, sign, base, lower), DynamicStrings_Mark (StringConvert_LongIntegerToString ((long int) c % ((long unsigned int ) (base)), 0, ' ', FALSE, base, lower)));
        }
      else
        s = DynamicStrings_InitString ((char *) "-", 1);
      i = -i;
    }
  else
    if (sign)
      s = DynamicStrings_InitString ((char *) "+", 1);
    else
      s = DynamicStrings_InitString ((char *) "", 0);
  if (i > ((long int ) (base-1)))
    s = DynamicStrings_ConCat (DynamicStrings_ConCat (s, DynamicStrings_Mark (StringConvert_LongIntegerToString (i / ((long int ) (base)), 0, ' ', FALSE, base, lower))), DynamicStrings_Mark (StringConvert_LongIntegerToString (i % ((long int ) (base)), 0, ' ', FALSE, base, lower)));
  else
    if (i <= 9)
      s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) (((unsigned int ) (i))+((unsigned int) ('0'))))));
    else
      if (lower)
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) ((((unsigned int ) (i))+((unsigned int) ('a')))-10))));
      else
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ((char) ((((unsigned int ) (i))+((unsigned int) ('A')))-10))));
  if (width > (DynamicStrings_Length (s)))
    return DynamicStrings_ConCat (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar (padding)), width-(DynamicStrings_Length (s))), s);
  return s;
}


/*
   StringToLongInteger - converts a string, s, of, base, into an LONGINT.
                         Leading white space is ignored. It stops converting
                         when either the string is exhausted or if an illegal
                         numeral is found.
                         The parameter found is set TRUE if a number was found.
*/

long int StringConvert_StringToLongInteger (DynamicStrings_String s, unsigned int base, unsigned int *found)
{
  unsigned int n;
  unsigned int l;
  long unsigned int c;
  unsigned int negative;

  s = DynamicStrings_RemoveWhitePrefix (s);  /* returns a new string, s  */
  l = DynamicStrings_Length (s);  /* returns a new string, s  */
  c = 0;
  n = 0;
  negative = FALSE;
  if (n < l)
    {
      /* parse leading + and -  */
      while (((DynamicStrings_char (s, (int) n)) == '-') || ((DynamicStrings_char (s, (int) n)) == '+'))
        {
          if ((DynamicStrings_char (s, (int) n)) == '-')
            negative = ! negative;
          n += 1;
        }
      while ((n < l) && ((IsDecimalDigitValidLong (DynamicStrings_char (s, (int) n), base, &c)) || (IsHexidecimalDigitValidLong (DynamicStrings_char (s, (int) n), base, &c))))
        {
          (*found) = TRUE;
          n += 1;
        }
    }
  s = DynamicStrings_KillString (s);
  if (negative)
    return -((long int ) (LongMin (((long unsigned int ) (LONG_MAX))+1, c)));
  else
    return (long int ) (LongMin ((long unsigned int) LONG_MAX, c));
}


/*
   LongCardinalToString - converts LONGCARD, c, into a String. The field
                          width can be specified if non zero. Leading
                          characters are defined by padding.
                          The base allows the caller to generate binary,
                          octal, decimal, hexidecimal numbers.
                          The value of lower is only used when hexidecimal
                          numbers are generated and if TRUE then digits
                          abcdef are used, and if FALSE then ABCDEF are used.
*/

DynamicStrings_String StringConvert_LongCardinalToString (long unsigned int c, unsigned int width, char padding, unsigned int base, unsigned int lower)
{
  DynamicStrings_String s;

  s = DynamicStrings_InitString ((char *) "", 0);
  if (c > ((long unsigned int ) (base-1)))
    s = DynamicStrings_ConCat (DynamicStrings_ConCat (s, StringConvert_LongCardinalToString (c / ((long unsigned int ) (base)), 0, ' ', base, lower)), StringConvert_LongCardinalToString (c % ((long unsigned int ) (base)), 0, ' ', base, lower));
  else
    if (c <= 9)
      s = DynamicStrings_ConCat (s, DynamicStrings_InitStringChar ((char) (((unsigned int ) (c))+((unsigned int) ('0')))));
    else
      if (lower)
        s = DynamicStrings_ConCat (s, DynamicStrings_InitStringChar ((char) ((((unsigned int ) (c))+((unsigned int) ('a')))-10)));
      else
        s = DynamicStrings_ConCat (s, DynamicStrings_InitStringChar ((char) ((((unsigned int ) (c))+((unsigned int) ('A')))-10)));
  if (width > (DynamicStrings_Length (s)))
    return DynamicStrings_ConCat (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar (padding)), width-(DynamicStrings_Length (s))), s);
  return s;
}


/*
   StringToLongCardinal - converts a string, s, of, base, into a LONGCARD.
                          Leading white space is ignored. It stops converting
                          when either the string is exhausted or if an illegal
                          numeral is found.
                          The parameter found is set TRUE if a number was found.
*/

long unsigned int StringConvert_StringToLongCardinal (DynamicStrings_String s, unsigned int base, unsigned int *found)
{
  unsigned int n;
  unsigned int l;
  long unsigned int c;

  s = DynamicStrings_RemoveWhitePrefix (s);  /* returns a new string, s  */
  l = DynamicStrings_Length (s);  /* returns a new string, s  */
  c = 0;
  n = 0;
  if (n < l)
    {
      /* parse leading +  */
      while ((DynamicStrings_char (s, (int) n)) == '+')
        n += 1;
      while ((n < l) && ((IsDecimalDigitValidLong (DynamicStrings_char (s, (int) n), base, &c)) || (IsHexidecimalDigitValidLong (DynamicStrings_char (s, (int) n), base, &c))))
        {
          (*found) = TRUE;
          n += 1;
        }
    }
  s = DynamicStrings_KillString (s);
  return c;
}


/*
   ShortCardinalToString - converts SHORTCARD, c, into a String. The field
                          width can be specified if non zero. Leading
                          characters are defined by padding.
                          The base allows the caller to generate binary,
                          octal, decimal, hexidecimal numbers.
                          The value of lower is only used when hexidecimal
                          numbers are generated and if TRUE then digits
                          abcdef are used, and if FALSE then ABCDEF are used.
*/

DynamicStrings_String StringConvert_ShortCardinalToString (short unsigned int c, unsigned int width, char padding, unsigned int base, unsigned int lower)
{
  DynamicStrings_String s;

  s = DynamicStrings_InitString ((char *) "", 0);
  if (((unsigned int ) (c)) > (base-1))
    s = DynamicStrings_ConCat (DynamicStrings_ConCat (s, StringConvert_ShortCardinalToString (c / ((short unsigned int ) (base)), 0, ' ', base, lower)), StringConvert_ShortCardinalToString (c % ((short unsigned int ) (base)), 0, ' ', base, lower));
  else
    if (c <= 9)
      s = DynamicStrings_ConCat (s, DynamicStrings_InitStringChar ((char) (((unsigned int ) (c))+((unsigned int) ('0')))));
    else
      if (lower)
        s = DynamicStrings_ConCat (s, DynamicStrings_InitStringChar ((char) ((((unsigned int ) (c))+((unsigned int) ('a')))-10)));
      else
        s = DynamicStrings_ConCat (s, DynamicStrings_InitStringChar ((char) ((((unsigned int ) (c))+((unsigned int) ('A')))-10)));
  if (width > (DynamicStrings_Length (s)))
    return DynamicStrings_ConCat (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar (padding)), width-(DynamicStrings_Length (s))), s);
  return s;
}


/*
   StringToShortCardinal - converts a string, s, of, base, into a SHORTCARD.
                           Leading white space is ignored. It stops converting
                           when either the string is exhausted or if an illegal
                           numeral is found.
                           The parameter found is set TRUE if a number was found.
*/

short unsigned int StringConvert_StringToShortCardinal (DynamicStrings_String s, unsigned int base, unsigned int *found)
{
  unsigned int n;
  unsigned int l;
  short unsigned int c;

  s = DynamicStrings_RemoveWhitePrefix (s);  /* returns a new string, s  */
  l = DynamicStrings_Length (s);  /* returns a new string, s  */
  c = 0;
  n = 0;
  if (n < l)
    {
      /* parse leading +  */
      while ((DynamicStrings_char (s, (int) n)) == '+')
        n += 1;
      while ((n < l) && ((IsDecimalDigitValidShort (DynamicStrings_char (s, (int) n), base, &c)) || (IsHexidecimalDigitValidShort (DynamicStrings_char (s, (int) n), base, &c))))
        {
          (*found) = TRUE;
          n += 1;
        }
    }
  s = DynamicStrings_KillString (s);
  return c;
}


/*
   stoi - decimal string to INTEGER
*/

int StringConvert_stoi (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToInteger (s, 10, &found);
}


/*
   itos - integer to decimal string.
*/

DynamicStrings_String StringConvert_itos (int i, unsigned int width, char padding, unsigned int sign)
{
  return StringConvert_IntegerToString (i, width, padding, sign, 10, FALSE);
}


/*
   ctos - cardinal to decimal string.
*/

DynamicStrings_String StringConvert_ctos (unsigned int c, unsigned int width, char padding)
{
  return StringConvert_CardinalToString (c, width, padding, 10, FALSE);
}


/*
   stoc - decimal string to CARDINAL
*/

unsigned int StringConvert_stoc (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToCardinal (s, 10, &found);
}


/*
   hstoi - hexidecimal string to INTEGER
*/

int StringConvert_hstoi (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToInteger (s, 16, &found);
}


/*
   ostoi - octal string to INTEGER
*/

int StringConvert_ostoi (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToInteger (s, 8, &found);
}


/*
   bstoi - binary string to INTEGER
*/

int StringConvert_bstoi (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToInteger (s, 2, &found);
}


/*
   hstoc - hexidecimal string to CARDINAL
*/

unsigned int StringConvert_hstoc (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToCardinal (s, 16, &found);
}


/*
   ostoc - octal string to CARDINAL
*/

unsigned int StringConvert_ostoc (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToCardinal (s, 8, &found);
}


/*
   bstoc - binary string to CARDINAL
*/

unsigned int StringConvert_bstoc (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToCardinal (s, 2, &found);
}


/*
   StringToLongreal - returns a LONGREAL and sets found to TRUE if a legal number is seen.
*/

long double StringConvert_StringToLongreal (DynamicStrings_String s, unsigned int *found)
{
  unsigned int error;
  long double value;

  s = DynamicStrings_RemoveWhitePrefix (s);  /* new string is created  */
  value = ldtoa_strtold (DynamicStrings_string (s), &error);  /* new string is created  */
  s = DynamicStrings_KillString (s);
  (*found) = ! error;
  return value;
}


/*
   LongrealToString - converts a LONGREAL number, Real, which has,
                      TotalWidth, and FractionWidth into a string.
                      It uses decimal notation.

                      So for example:

                      LongrealToString(1.0, 4, 2)  -> '1.00'
                      LongrealToString(12.3, 5, 2) -> '12.30'
                      LongrealToString(12.3, 6, 2) -> ' 12.30'
                      LongrealToString(12.3, 6, 3) -> '12.300'

                      if total width is too small then the fraction
                      becomes truncated.

                      LongrealToString(12.3, 5, 3) -> '12.30'

                      Positive numbers do not have a '+' prepended.
                      Negative numbers will have a '-' prepended and
                      the TotalWidth will need to be large enough
                      to contain the sign, whole number, '.' and
                      fractional components.
*/

DynamicStrings_String StringConvert_LongrealToString (long double x, unsigned int TotalWidth, unsigned int FractionWidth)
{
  unsigned int maxprecision;
  DynamicStrings_String s;
  void * r;
  int point;
  unsigned int sign;
  int l;

  if (TotalWidth == 0)
    {
      maxprecision = TRUE;
      r = ldtoa_ldtoa (x, (ldtoa_Mode) ldtoa_decimaldigits, 100, &point, &sign);
    }
  else
    r = ldtoa_ldtoa (x, (ldtoa_Mode) ldtoa_decimaldigits, 100, &point, &sign);
  s = DynamicStrings_InitStringCharStar (r);
  libc_free (r);
  l = DynamicStrings_Length (s);
  if (point > l)
    {
      s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar ('0')), (unsigned int) point-l)));
      s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitString ((char *) ".0", 2)));
      if (! maxprecision && (FractionWidth > 0))
        {
          FractionWidth -= 1;
          if (((int ) (FractionWidth)) > (point-l))
            s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitString ((char *) "0", 1)), FractionWidth)));
        }
    }
  else if (point < 0)
    {
      s = DynamicStrings_ConCat (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar ('0')), (unsigned int) -point), DynamicStrings_Mark (s));
      l = DynamicStrings_Length (s);
      s = DynamicStrings_ConCat (DynamicStrings_InitString ((char *) "0.", 2), DynamicStrings_Mark (s));
      if (! maxprecision && (l < ((int ) (FractionWidth))))
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitString ((char *) "0", 1)), (unsigned int) ((int ) (FractionWidth))-l)));
    }
  else
    {
      if (point == 0)
        s = DynamicStrings_ConCat (DynamicStrings_InitString ((char *) "0.", 2), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), point, 0)));
      else
        s = DynamicStrings_ConCat (DynamicStrings_ConCatChar (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, point), '.'), DynamicStrings_Mark (DynamicStrings_Slice (DynamicStrings_Mark (s), point, 0)));
      if (! maxprecision && ((l-point) < ((int ) (FractionWidth))))
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitString ((char *) "0", 1)), (unsigned int) ((int ) (FractionWidth))-(l-point))));
    }
  if ((DynamicStrings_Length (s)) > TotalWidth)
    {
      /* avoid gcc warning by using compound statement even if not strictly necessary.  */
      if (TotalWidth > 0)
        if (sign)
          {
            s = DynamicStrings_Slice (DynamicStrings_Mark (StringConvert_ToDecimalPlaces (s, FractionWidth)), 0, (int) TotalWidth-1);
            s = DynamicStrings_ConCat (DynamicStrings_InitStringChar ('-'), DynamicStrings_Mark (s));
            sign = FALSE;
          }
        else
          /* minus 1 because all results will include a '.'  */
          s = DynamicStrings_Slice (DynamicStrings_Mark (StringConvert_ToDecimalPlaces (s, FractionWidth)), 0, (int) TotalWidth);
      else
        if (sign)
          {
            s = StringConvert_ToDecimalPlaces (s, FractionWidth);
            s = DynamicStrings_ConCat (DynamicStrings_InitStringChar ('-'), DynamicStrings_Mark (s));
            sign = FALSE;
          }
        else
          /* minus 1 because all results will include a '.'  */
          s = StringConvert_ToDecimalPlaces (s, FractionWidth);
    }
  if ((DynamicStrings_Length (s)) < TotalWidth)
    s = DynamicStrings_ConCat (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar (' ')), TotalWidth-(DynamicStrings_Length (s))), DynamicStrings_Mark (s));
  return s;
}


/*
   stor - returns a REAL given a string.
*/

double StringConvert_stor (DynamicStrings_String s)
{
  unsigned int found;

  return (double ) (StringConvert_StringToLongreal (s, &found));
}


/*
   stolr - returns a LONGREAL given a string.
*/

long double StringConvert_stolr (DynamicStrings_String s)
{
  unsigned int found;

  return StringConvert_StringToLongreal (s, &found);
}


/*
   ToSigFig - returns a floating point or base 10 integer
              string which is accurate to, n, significant
              figures.  It will return a new String
              and, s, will be destroyed.


              So:  12.345

              rounded to the following significant figures yields

              5      12.345
              4      12.34
              3      12.3
              2      12
              1      10
*/

DynamicStrings_String StringConvert_ToSigFig (DynamicStrings_String s, unsigned int n)
{
  int point;
  unsigned int poTen;

  Assert ((IsDigit (DynamicStrings_char (s, 0))) || ((DynamicStrings_char (s, 0)) == '.'), (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/StringConvert.mod", 72, 1215, (char *) "ToSigFig", 8);
  point = DynamicStrings_Index (s, '.', 0);
  if (point < 0)
    poTen = DynamicStrings_Length (s);
  else
    poTen = point;
  s = doSigFig (s, n);
  /* if the last character is '.' remove it  */
  if (((DynamicStrings_Length (s)) > 0) && ((DynamicStrings_char (s, -1)) == '.'))
    return DynamicStrings_Slice (DynamicStrings_Mark (s), 0, -1);
  else
    {
      if (poTen > (DynamicStrings_Length (s)))
        s = DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar ('0')), poTen-(DynamicStrings_Length (s)))));
      return s;
    }
}


/*
   ToDecimalPlaces - returns a floating point or base 10 integer
                     string which is accurate to, n, decimal
                     places.  It will return a new String
                     and, s, will be destroyed.
                     Decimal places yields, n, digits after
                     the .

                     So:  12.345

                     rounded to the following decimal places yields

                     5      12.34500
                     4      12.3450
                     3      12.345
                     2      12.34
                     1      12.3
*/

DynamicStrings_String StringConvert_ToDecimalPlaces (DynamicStrings_String s, unsigned int n)
{
  int point;

  Assert ((IsDigit (DynamicStrings_char (s, 0))) || ((DynamicStrings_char (s, 0)) == '.'), (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/StringConvert.mod", 72, 1062, (char *) "ToDecimalPlaces", 15);
  point = DynamicStrings_Index (s, '.', 0);
  if (point < 0)
    {
      /* avoid gcc warning by using compound statement even if not strictly necessary.  */
      if (n > 0)
        return DynamicStrings_ConCat (DynamicStrings_ConCat (s, DynamicStrings_Mark (DynamicStrings_InitStringChar ('.'))), DynamicStrings_Mult (DynamicStrings_Mark (DynamicStrings_InitStringChar ('0')), n));
      else
        return s;
    }
  s = doDecimalPlaces (s, n);
  /* if the last character is '.' remove it  */
  if (((DynamicStrings_Length (s)) > 0) && ((DynamicStrings_char (s, -1)) == '.'))
    return DynamicStrings_Slice (DynamicStrings_Mark (s), 0, -1);
  else
    return s;
}

void _M2_StringConvert_init (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}

void _M2_StringConvert_finish (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}
