/* automatically created by mc from ../git-pge-frozen/m2/ramps.mod.  */

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

#   include "GpopWorld.h"
#   include "GtwoDsim.h"
#   include "GdeviceIf.h"
#   include "GFractions.h"
#   include "GPoints.h"
#   include "GmacroObjects.h"

#   define testCorner FALSE
#   define testRight FALSE
static Fractions_Fract size;
static deviceIf_Colour light;
static deviceIf_Colour dark;

/*
   placeBoundary - 
*/

static void placeBoundary (macroObjects_Macro m);

/*
   placeRamps - 
*/

static void placeRamps (void);

/*
   dropBall - 
*/

static void dropBall (deviceIf_Colour c);

/*
   placeBoundary - 
*/

static void placeBoundary (macroObjects_Macro m);

/*
   placeRamps - 
*/

static void placeRamps (void);

/*
   dropBall - 
*/

static void dropBall (deviceIf_Colour c);


/*
   placeBoundary - 
*/

static void placeBoundary (macroObjects_Macro m)
{
  /* left edge  */
  m = macroObjects_moveTo (m, Points_initPoint (Fractions_zero (), Fractions_zero ()));
  m = macroObjects_rectangle (m, TRUE, Fractions_zero (), (deviceIf_Colour) deviceIf_red (), Fractions_initFract (0, 1, 100), Fractions_one ());
  /* right edge  */
  m = macroObjects_moveTo (m, Points_initPoint (Fractions_initFract (0, 99, 100), Fractions_zero ()));
  m = macroObjects_rectangle (m, TRUE, Fractions_zero (), (deviceIf_Colour) deviceIf_red (), Fractions_initFract (0, 1, 100), Fractions_one ());
  /* bot edge  */
  m = macroObjects_moveTo (m, Points_initPoint (Fractions_zero (), Fractions_zero ()));
  m = macroObjects_rectangle (m, TRUE, Fractions_zero (), (deviceIf_Colour) deviceIf_red (), Fractions_one (), Fractions_initFract (0, 1, 100));
  /* top edge  */
  m = macroObjects_moveTo (m, Points_initPoint (Fractions_zero (), Fractions_initFract (0, 99, 100)));
  m = macroObjects_rectangle (m, TRUE, Fractions_zero (), (deviceIf_Colour) deviceIf_red (), Fractions_one (), Fractions_initFract (0, 1, 100));
}


/*
   placeRamps - 
*/

static void placeRamps (void)
{
  macroObjects_Macro m;
  macroObjects_Macro n;
  macroObjects_Macro p;

  m = macroObjects_initMacro ();
  n = macroObjects_initMacro ();
  m = macroObjects_moveTo (m, Points_initPoint (Fractions_initFract (0, 3, 10), Fractions_initFract (0, 6, 10)));
  m = macroObjects_triangle (m, TRUE, Fractions_zero (), light, Points_initPoint (Fractions_initFract (0, 7, 10), Fractions_zero ()), Points_initPoint (Fractions_zero (), Fractions_initFract (0, 1, 10)));
  m = macroObjects_moveTo (m, Points_initPoint (Fractions_initFract (0, 7, 10), Fractions_initFract (0, 3, 10)));
  m = macroObjects_triangle (m, TRUE, Fractions_zero (), light, Points_initPoint (Fractions_negate (Fractions_initFract (0, 7, 10)), Fractions_zero ()), Points_initPoint (Fractions_zero (), Fractions_initFract (0, 1, 10)));
  /* 
   n := rectangle(n, TRUE, zero(), light, initFract(0, 8, 10), initFract(0, 1, 10)) ;
   p := dup(n) ;
   n := rotate(n, initPoint(zero(), zero()), div(pi(), cardinal(20))) ;
   m := append(m, n) ;
   
   m := moveTo(m, initPoint(initFract(0, 1, 10), initFract(0, 2, 10))) ;
   p := rotate(p, initPoint(zero(), zero()), negate(div(pi(), cardinal(20)))) ;
   m := append(m, p) ;
  */
  placeBoundary (m);
  m = macroObjects_rootMacro (m);
  popWorld_populate (m, TRUE, TRUE);
}


/*
   dropBall - 
*/

static void dropBall (deviceIf_Colour c)
{
  macroObjects_Macro m;

  m = macroObjects_initMacro ();
  /* drop the ball at the top of stairs with a leftwards velocity  */
  m = macroObjects_moveTo (m, Points_initPoint (Fractions_initFract (0, 17, 20), Fractions_initFract (0, 15, 20)));
  m = macroObjects_circle (m, TRUE, Fractions_zero (), c, size);
  m = macroObjects_rootMacro (m);
  popWorld_mass (Fractions_cardinal (1));
  popWorld_velocity (Points_initPoint (Fractions_zero (), Fractions_zero ()));
  popWorld_populate (m, FALSE, TRUE);
}

void _M2_ramps_init (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
  popWorld_init (FALSE);
  light = deviceIf_defineColour (Fractions_initFract (0, 166, 256), Fractions_initFract (0, 124, 256), Fractions_initFract (0, 54, 256));
  dark = deviceIf_defineColour (Fractions_initFract (0, 76, 256), Fractions_initFract (0, 47, 256), Fractions_zero ());
  size = Fractions_initFract (0, 1, 21);
  placeRamps ();
  dropBall ((deviceIf_Colour) deviceIf_green ());
  twoDsim_gravity (-9.81);
  twoDsim_simulateFor (1.0);
  dropBall ((deviceIf_Colour) deviceIf_yellow ());
  twoDsim_simulateFor (1.0);
  dropBall ((deviceIf_Colour) deviceIf_red ());
  twoDsim_simulateFor (1.0);
  dropBall ((deviceIf_Colour) deviceIf_purple ());
  twoDsim_simulateFor (10.0);
}

void _M2_ramps_finish (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}
