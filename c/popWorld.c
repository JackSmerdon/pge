/* automatically created by mc from ../git-pge/m2/popWorld.mod.  */

#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#include <string.h>
#include <limits.h>
#define _popWorld_H
#define _popWorld_C

#   include "GdeviceIf.h"
#   include "GmacroObjects.h"
#   include "GFractions.h"
#   include "GPoints.h"
#   include "Glibc.h"
#   include "GtwoDsim.h"
#   include "GM2RTS.h"

#   define FPSgroff 80
#   define FPSpy 80
static unsigned int pFixed;
static Points_Point defaultVelocity;
static Fractions_Fract defaultMass;
static double defaultRotation;

/*
   populate - populate the 2D world with the contents of macro, m.
*/

void popWorld_populate (macroObjects_Macro m, unsigned int fixed, unsigned int solid);

/*
   mass - sets the default mass for a movable object.
*/

void popWorld_mass (Fractions_Fract m);

/*
   velocity - sets the default velocity for a movable object.
*/

void popWorld_velocity (Points_Point v);

/*
   rotate - sets the default angular velocity for a movable object.
*/

void popWorld_rotate (Fractions_Fract r);

/*
   init - initialise the 2D world and configure the device to be groff or pygame.
*/

void popWorld_init (unsigned int groff);

/*
   ppolygon -
*/

static void ppolygon (unsigned int n, Points_Point *p_, unsigned int _p_high, unsigned int fill, Fractions_Fract thick, deviceIf_Colour c);

/*
   pcircle -
*/

static void pcircle (Points_Point pos, unsigned int fill, Fractions_Fract thick, Fractions_Fract rad, deviceIf_Colour c);


/*
   ppolygon -
*/

static void ppolygon (unsigned int n, Points_Point *p_, unsigned int _p_high, unsigned int fill, Fractions_Fract thick, deviceIf_Colour c)
{
  unsigned int o;
  Points_Point p[_p_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (p, p_, (_p_high+1) * sizeof (Points_Point));

  switch (n)
    {
      case 3:
        o = twoDsim_poly3 (Fractions_getReal (p[0].x), Fractions_getReal (p[0].y), Fractions_getReal (p[1].x), Fractions_getReal (p[1].y), Fractions_getReal (p[2].x), Fractions_getReal (p[2].y), c);
        break;

      case 4:
        o = twoDsim_poly4 (Fractions_getReal (p[0].x), Fractions_getReal (p[0].y), Fractions_getReal (p[1].x), Fractions_getReal (p[1].y), Fractions_getReal (p[2].x), Fractions_getReal (p[2].y), Fractions_getReal (p[3].x), Fractions_getReal (p[3].y), c);
        break;

      case 5:
        o = twoDsim_poly5 (Fractions_getReal (p[0].x), Fractions_getReal (p[0].y), Fractions_getReal (p[1].x), Fractions_getReal (p[1].y), Fractions_getReal (p[2].x), Fractions_getReal (p[2].y), Fractions_getReal (p[3].x), Fractions_getReal (p[3].y), Fractions_getReal (p[4].x), Fractions_getReal (p[4].y), c);
        break;

      case 6:
        o = twoDsim_poly6 (Fractions_getReal (p[0].x), Fractions_getReal (p[0].y), Fractions_getReal (p[1].x), Fractions_getReal (p[1].y), Fractions_getReal (p[2].x), Fractions_getReal (p[2].y), Fractions_getReal (p[3].x), Fractions_getReal (p[3].y), Fractions_getReal (p[4].x), Fractions_getReal (p[4].y), Fractions_getReal (p[5].x), Fractions_getReal (p[5].y), c);
        break;

      case 10:
        o = twoDsim_poly10 (Fractions_getReal (p[0].x), Fractions_getReal (p[0].y), Fractions_getReal (p[1].x), Fractions_getReal (p[1].y), Fractions_getReal (p[2].x), Fractions_getReal (p[2].y), Fractions_getReal (p[3].x), Fractions_getReal (p[3].y), Fractions_getReal (p[4].x), Fractions_getReal (p[4].y), Fractions_getReal (p[5].x), Fractions_getReal (p[5].y), Fractions_getReal (p[6].x), Fractions_getReal (p[6].y), Fractions_getReal (p[7].x), Fractions_getReal (p[7].y), Fractions_getReal (p[8].x), Fractions_getReal (p[8].y), Fractions_getReal (p[9].x), Fractions_getReal (p[9].y), c);
        break;

      default:
        libc_printf ((char *) "too many sides to the polygon, max 10 allowed\\n", 47);
        M2RTS_HALT (-1);
        break;
    }
  if (pFixed)
    o = twoDsim_fix (o);
  else
    {
      o = twoDsim_mass (o, Fractions_getReal (defaultMass));
      o = twoDsim_velocity (o, Fractions_getReal (defaultVelocity.x), Fractions_getReal (defaultVelocity.y));
      o = twoDsim_rotate (o, defaultRotation);
    }
}


/*
   pcircle -
*/

static void pcircle (Points_Point pos, unsigned int fill, Fractions_Fract thick, Fractions_Fract rad, deviceIf_Colour c)
{
  unsigned int o;

  o = twoDsim_circle (Fractions_getReal (pos.x), Fractions_getReal (pos.y), Fractions_getReal (rad), c);
  if (pFixed)
    o = twoDsim_fix (o);
  else
    {
      o = twoDsim_mass (o, Fractions_getReal (defaultMass));
      o = twoDsim_velocity (o, Fractions_getReal (defaultVelocity.x), Fractions_getReal (defaultVelocity.y));
      o = twoDsim_rotate (o, defaultRotation);
    }
}


/*
   populate - populate the 2D world with the contents of macro, m.
*/

void popWorld_populate (macroObjects_Macro m, unsigned int fixed, unsigned int solid)
{
  pFixed = fixed;
  macroObjects_runCallBacks (m, (macroObjects_pProc) {(macroObjects_pProc_t) ppolygon}, (macroObjects_cProc) {(macroObjects_cProc_t) pcircle});
}


/*
   mass - sets the default mass for a movable object.
*/

void popWorld_mass (Fractions_Fract m)
{
  defaultMass = Fractions_unroot (defaultMass);
  defaultMass = Fractions_root (m);
}


/*
   velocity - sets the default velocity for a movable object.
*/

void popWorld_velocity (Points_Point v)
{
  defaultVelocity = Points_unRootPoint (defaultVelocity);
  defaultVelocity = Points_rootPoint (v);
}


/*
   rotate - sets the default angular velocity for a movable object.
*/

void popWorld_rotate (Fractions_Fract r)
{
  defaultRotation = Fractions_getReal (r);
}


/*
   init - initialise the 2D world and configure the device to be groff or pygame.
*/

void popWorld_init (unsigned int groff)
{
  defaultMass = Fractions_root (Fractions_one ());
  defaultVelocity = Points_rootPoint (Points_initPoint (Fractions_zero (), Fractions_zero ()));
  if (groff)
    {
      deviceIf_useGroff ();
      deviceIf_configDevice (Points_initPoint (Fractions_one (), Fractions_one ()), Points_initPoint (Fractions_cardinal (5), Fractions_cardinal (5)), FPSgroff);
      twoDsim_fps ((double) (FPSgroff));
    }
  else
    {
      deviceIf_useRPC ();
      deviceIf_configDevice (Points_initPoint (Fractions_one (), Fractions_one ()), Points_initPoint (Fractions_cardinal (1000), Fractions_cardinal (1000)), FPSpy);
      twoDsim_fps ((double) (FPSpy));
    }
}

void _M2_popWorld_init (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}

void _M2_popWorld_finish (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}
