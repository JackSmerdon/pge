/* automatically created by mc from ../pge/m2/roots.mod.  */

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

#   include <complex.h>
#define _roots_H
#define _roots_C

#   include "Glibc.h"
#   include "Glibm.h"
#   include "Ggdbif.h"

typedef struct {
                   double x;
                   double y;
               } coord_Coord;

#   define Epsilon 0.000001
#   define Debugging FALSE
static unsigned int tracing;

/*
   findOctic - returns TRUE if a root >= 0 exists for the equation:

                 8     7    6    5    4    3    2
               ax  + bx + cx + dx + ex + fx + gx + hx + i = 0
*/

unsigned int roots_findOctic (double a, double b, double c, double d, double e, double f, double g, double h, double i, double *x0);

/*
   findQuadratic - returns TRUE if scalar values of x can be found
                   for.

                     2
                   ax  +  bx + c == 0
*/

unsigned int roots_findQuadratic (double a, double b, double c, double *x0, double *x1);

/*
   findQuartic - returns TRUE if a scalar root can be found for:

                   4      3      2
                 ax  +  bx  +  cx  +  dx +  e  == 0

                 TRUE is only returned if a positive value for
                 x is found and it returns the smallest value for x.
*/

unsigned int roots_findQuartic (double a, double b, double c, double d, double e, double *x);

/*
   findAllRootsQuartic - returns all the real roots for:

                           4      3      2
                         ax  +  bx  +  cx  +  dx +  e  == 0
*/

unsigned int roots_findAllRootsQuartic (double a, double b, double c, double d, double e, double *x, unsigned int _x_high);

/*
   nearZero - returns TRUE if, r, is close to 0.0
*/

unsigned int roots_nearZero (double r);

/*
   nearSame - returns TRUE if, |a-b| < epsilon
*/

unsigned int roots_nearSame (double a, double b);

/*
   nearCoord - returns TRUE if position, a, is very close to, b.
*/

unsigned int roots_nearCoord (coord_Coord a, coord_Coord b);

/*
   setTrace - turns tracing on/off.
*/

void roots_setTrace (unsigned int on);

/*
   roundZero -
*/

static double roundZero (double r);

/*
   roundRoot -
*/

static double roundRoot (double r);

/*
   roundRoots -
*/

static void roundRoots (double *r, unsigned int _r_high, unsigned int n);

/*
   cnearZero - returns TRUE if the magnitude of, c, is close to 0.
*/

static unsigned int cnearZero (double complex c);

/*
   isReal - returns TRUE if the imaginary component of, c, is near zero.
*/

static unsigned int isReal (double complex c);

/*
   rsqrt - useful for debugging
*/

static double rsqrt (double r);

/*
   sqr - returns r^2
*/

static double sqr (double r);

/*
   cub - returns r^3
*/

static double cub (double r);

/*
   cubr - returns r^(1/3)
*/

static double cubr (double r);

/*
   cpower -
*/

static double complex cpower (double complex c, double r);

/*
   csqrt - useful for debugging
*/

static double complex csqrt_ (double complex c);

/*
   csqr - returns c^2
*/

static double complex csqr (double complex c);

/*
   ccub - returns c^3
*/

static double complex ccub (double complex c);

/*
   ccubr - returns c^(1/3)
*/

static double complex ccubr (double complex c);

/*
   ccubr - returns c^(1/3)
*/

static void mystop (void);

/*
   findCubic - returns TRUE if a root can be found for

                 3      2
               ax  +  bx  +  cx  +  d  ==  0

               if returns TRUE if it finds a root >= 0
               and will return the smallest root >= 0
*/

static unsigned int findCubic (double a, double b, double c, double d, double *x);

/*
   Assert -
*/

static void Assert (unsigned int b);

/*
   setTrace - turns tracing on/off.
*/

static void test (void);


/*
   roundZero -
*/

static double roundZero (double r)
{
  if (roots_nearZero (r))
    return 0.0;
  else
    return r;
}


/*
   roundRoot -
*/

static double roundRoot (double r)
{
  return roundZero (r);
}


/*
   roundRoots -
*/

static void roundRoots (double *r, unsigned int _r_high, unsigned int n)
{
  unsigned int i;

  i = 0;
  while (i < n)
    {
      r[i] = roundRoot (r[i]);
      i += 1;
    }
}


/*
   cnearZero - returns TRUE if the magnitude of, c, is close to 0.
*/

static unsigned int cnearZero (double complex c)
{
  double r;

  r = rsqrt ((sqr (creal (c)))+(sqr (cimag (c))));
  return roots_nearZero (r);
}


/*
   isReal - returns TRUE if the imaginary component of, c, is near zero.
*/

static unsigned int isReal (double complex c)
{
  return roots_nearZero (cimag (c));
}


/*
   rsqrt - useful for debugging
*/

static double rsqrt (double r)
{
  return libm_sqrt (r);
}


/*
   sqr - returns r^2
*/

static double sqr (double r)
{
  return r*r;
}


/*
   cub - returns r^3
*/

static double cub (double r)
{
  return (r*r)*r;
}


/*
   cubr - returns r^(1/3)
*/

static double cubr (double r)
{
  if (r < 0.0)
    return -(libm_pow (-r, 1.0/3.0));
  else
    return libm_pow (r, 1.0/3.0);
}


/*
   cpower -
*/

static double complex cpower (double complex c, double r)
{
  double radiusr;
  double radius;
  double angle;

  radius = rsqrt (((creal (c))*(creal (c)))+((cimag (c))*(cimag (c))));
  angle = libm_atan2 (cimag (c), creal (c));
  radiusr = libm_pow (radius, r);
  return (radiusr*(libm_cos (angle*r))) + (radiusr*(libm_sin (angle*r)) * I);
}


/*
   csqrt - useful for debugging
*/

static double complex csqrt_ (double complex c)
{
  return cpower (c, 1.0/2.0);
}


/*
   csqr - returns c^2
*/

static double complex csqr (double complex c)
{
  return c*c;
}


/*
   ccub - returns c^3
*/

static double complex ccub (double complex c)
{
  return (c*c)*c;
}


/*
   ccubr - returns c^(1/3)
*/

static double complex ccubr (double complex c)
{
  return cpower (c, 1.0/3.0);
}


/*
   ccubr - returns c^(1/3)
*/

static void mystop (void)
{
}


/*
   findCubic - returns TRUE if a root can be found for

                 3      2
               ax  +  bx  +  cx  +  d  ==  0

               if returns TRUE if it finds a root >= 0
               and will return the smallest root >= 0
*/

static unsigned int findCubic (double a, double b, double c, double d, double *x)
{
  typedef struct _T1_a _T1;

  struct _T1_a { double array[2-1+1]; };
  unsigned int i;
  unsigned int j;
  _T1 X;

  i = 0;
  if (roots_nearZero (a))
    {
      /* avoid dangling else.  */
      if (roots_findQuadratic (b, c, d, &X.array[1-1], &X.array[2-1]))
        i = 2;
    }
  else
    {
      i = 1;
      X.array[1-1] = ((-(b/(3.0*a)))-((1.0/(3.0*a))*(cubr ((((2.0*(cub (b)))-(((9.0*a)*b)*c))+((27.0*(sqr (a)))*d))+(rsqrt ((sqr (((2.0*(cub (b)))-(((9.0*a)*b)*c))+((27.0*(sqr (a)))*d)))-(4.0*(cub ((sqr (b))-((3.0*a)*c))))))))))-((1.0/(3.0*a))*(cubr ((((2.0*(cub (b)))-(((9.0*a)*b)*c))+((27.0*(sqr (a)))*d))-(rsqrt ((sqr (((2.0*(cub (b)))-(((9.0*a)*b)*c))+((27.0*(sqr (a)))*d)))-(4.0*(cub ((sqr (b))-((3.0*a)*c)))))))));
    }
  roundRoots ((double *) &X.array[0], (2-1), i);
  if (tracing)
    {
      libc_printf ((char *) "findCubic found %d roots\\n", 26, i);
      j = 1;
      while (j <= i)
        {
          libc_printf ((char *) "  root %d  = %g\\n", 17, j, X.array[j-1]);
          j += 1;
        }
    }
  j = 1;
  (*x) = -1.0;
  while (j <= i)
    {
      if ((X.array[j-1] >= 0.0) && ((X.array[j-1] < (*x)) || ((*x) < 0.0)))
        (*x) = X.array[j-1];
      j += 1;
    }
  return (*x) >= 0.0;
}


/*
   Assert -
*/

static void Assert (unsigned int b)
{
  if (! b)
    libc_printf ((char *) "assert failed\\n", 15);
}


/*
   setTrace - turns tracing on/off.
*/

static void test (void)
{
  double A;
  double B;
  double C;
  double D;
  double E;
  double t;
  double T;

  A = 3.0;
  B = 6.0;
  C = -123.0;
  D = -126.0;
  E = 1080.0;
  if (roots_findQuartic (A, B, C, D, E, &t))
    {
      T = ((((A*((sqr (t))*(sqr (t))))+(B*((sqr (t))*t)))+(C*(sqr (t))))+(D*t))+E;
      if (Debugging)
        libc_printf ((char *) "%gt^4 + %gt^3 +%gt^2 + %gt + %g = %g    (t=%g)\\n", 48, A, B, C, D, E, T, t);
      Assert (t == 3.0);
    }
  else
    libc_printf ((char *) "failed to find root\\n", 21);
  A = 1.0;
  B = 0.0;
  C = -15.0;
  D = 10.0;
  E = 24.0;
  if (roots_findQuartic (A, B, C, D, E, &t))
    {
      T = ((((A*((sqr (t))*(sqr (t))))+(B*((sqr (t))*t)))+(C*(sqr (t))))+(D*t))+E;
      if (Debugging)
        libc_printf ((char *) "%gt^4 + %gt^3 +%gt^2 + %gt + %g = %g    (t=%g)\\n", 48, A, B, C, D, E, T, t);
      Assert (t == 2.0);
    }
  else
    libc_printf ((char *) "failed to find root\\n", 21);
  A = 1.0;
  B = 0.0;
  C = -5.0;
  D = 0.0;
  E = 4.0;
  if (roots_findQuartic (A, B, C, D, E, &t))
    {
      T = ((((A*((sqr (t))*(sqr (t))))+(B*((sqr (t))*t)))+(C*(sqr (t))))+(D*t))+E;
      if (Debugging)
        libc_printf ((char *) "%gt^4 + %gt^3 +%gt^2 + %gt + %g = %g    (t=%g)\\n", 48, A, B, C, D, E, T, t);
      Assert (t == 1.0);
    }
  else
    libc_printf ((char *) "failed to find root\\n", 21);
}


/*
   findOctic - returns TRUE if a root >= 0 exists for the equation:

                 8     7    6    5    4    3    2
               ax  + bx + cx + dx + ex + fx + gx + hx + i = 0
*/

unsigned int roots_findOctic (double a, double b, double c, double d, double e, double f, double g, double h, double i, double *x0)
{
  return FALSE;
}


/*
   findQuadratic - returns TRUE if scalar values of x can be found
                   for.

                     2
                   ax  +  bx + c == 0
*/

unsigned int roots_findQuadratic (double a, double b, double c, double *x0, double *x1)
{
  double q;
  double discriminant;

  if (tracing)
    libc_printf ((char *) "entered findQuadratic\\n", 23);
  if (roots_nearZero (a))
    {
      if (tracing)
        libc_printf ((char *) "findQuadratic a == 0\\n", 22);
      if (roots_nearZero (b))
        {
          if (tracing)
            libc_printf ((char *) "findQuadratic a == 0, b == 0   -> false\\n", 41);
          return FALSE;
        }
      else
        {
          (*x0) = -(c/b);
          (*x0) = roundRoot ((*x0));
          (*x1) = (*x0);
          if (tracing)
            libc_printf ((char *) "findQuadratic a == 0, x0 = %g, x1 = %g  -> true\\n", 49, (*x0), (*x1));
          return TRUE;
        }
    }
  else
    {
      discriminant = (sqr (b))-((4.0*a)*c);
      if (discriminant > 0.0)
        {
          q = rsqrt (discriminant);
          (*x0) = (-b+q)/(2.0*a);
          (*x1) = (-b-q)/(2.0*a);
          (*x0) = roundRoot ((*x0));
          (*x1) = roundRoot ((*x1));
          if (tracing)
            {
              libc_printf ((char *) "findQuadratic discriminant > 0.0, x0 = %g, x1 = %g  -> true\\n", 61, (*x0), (*x1));
              if (roots_nearSame ((*x1), 0.388415))
                {}  /* empty.  */
            }
          return TRUE;
        }
      else if (discriminant == 0.0)
        {
          (*x0) = -(b/(2.0*a));
          (*x0) = roundRoot ((*x0));
          (*x1) = (*x0);
          if (tracing)
            libc_printf ((char *) "findQuadratic discriminant = 0.0, x0 = %g, x1 = %g  -> true\\n", 61, (*x0), (*x1));
          return TRUE;
        }
      else
        {
          if (tracing)
            libc_printf ((char *) "findQuadratic discriminant < 0.0  -> false\\n", 44);
          return FALSE;
        }
    }
}


/*
   findQuartic - returns TRUE if a scalar root can be found for:

                   4      3      2
                 ax  +  bx  +  cx  +  dx +  e  == 0

                 TRUE is only returned if a positive value for
                 x is found and it returns the smallest value for x.
*/

unsigned int roots_findQuartic (double a, double b, double c, double d, double e, double *x)
{
  typedef struct _T2_a _T2;

  struct _T2_a { double array[3+1]; };
  _T2 t;
  unsigned int i;
  unsigned int n;
  unsigned int unset;

  if (a == 0.0)
    return findCubic (b, c, d, e, x);
  else
    {
      if (tracing)
        libc_printf ((char *) "findQuartic finding all roots\\n", 31, n);
      n = roots_findAllRootsQuartic (a, b, c, d, e, (double *) &t.array[0], 3);
      roundRoots ((double *) &t.array[0], 3, n);
      if (tracing)
        {
          libc_printf ((char *) " findQuartic found %d roots\\n", 29, n);
          i = 0;
          while (i < n)
            {
              libc_printf ((char *) "  root %d  = %g\\n", 17, i, t.array[i]);
              i += 1;
            }
        }
      unset = TRUE;
      (*x) = -1.0;
      i = 0;
      while (i < n)
        {
          if (unset || ((t.array[i] >= 0.0) && (t.array[i] < (*x))))
            {
              unset = FALSE;
              (*x) = t.array[i];
            }
          i += 1;
        }
      if (tracing)
        {
          libc_printf ((char *) "findQuartic x = %g", 18, (*x));
          if ((*x) >= 0.0)
            libc_printf ((char *) " returning TRUE\\n", 17);
          else
            libc_printf ((char *) " returning FALSE\\n", 18);
        }
      return (*x) >= 0.0;
    }
}


/*
   findAllRootsQuartic - returns all the real roots for:

                           4      3      2
                         ax  +  bx  +  cx  +  dx +  e  == 0
*/

unsigned int roots_findAllRootsQuartic (double a, double b, double c, double d, double e, double *x, unsigned int _x_high)
{
  typedef struct _T3_a _T3;

  struct _T3_a { double complex array[4-1+1]; };
  unsigned int i;
  unsigned int k;
  double f;
  double p;
  double q;
  double alpha;
  double beta;
  double gamma;
  double complex r;
  double complex u;
  double complex w;
  double complex y;
  double complex z;
  _T3 X;

  alpha = (-((3.0*(sqr (b)))/(8.0*(sqr (a)))))+(c/a);
  beta = (((cub (b))/(8.0*(cub (a))))-((b*c)/(2.0*(sqr (a)))))+(d/a);
  gamma = (((-(((3.0*(sqr (b)))*(sqr (b)))/((256.0*(sqr (a)))*(sqr (a)))))+((c*(sqr (b)))/(16.0*(cub (a)))))-((b*d)/(4.0*(sqr (a)))))+(e/a);
  if (beta == 0.0)
    {
      X.array[1-1] = ( (-(b/(4.0*a))) + (0.0 * I))+(csqrt_ ((( (-alpha) + (0.0 * I))+(csqrt_ ( ((sqr (alpha))-(4.0*gamma)) + (0.0 * I))))/( (2.0) + (0.0 * I))));
      X.array[2-1] = ( (-(b/(4.0*a))) + (0.0 * I))+(csqrt_ ((( (-alpha) + (0.0 * I))-(csqrt_ ( ((sqr (alpha))-(4.0*gamma)) + (0.0 * I))))/( (2.0) + (0.0 * I))));
      X.array[3-1] = ( (-(b/(4.0*a))) + (0.0 * I))-(csqrt_ ((( (-alpha) + (0.0 * I))+(csqrt_ ( ((sqr (alpha))-(4.0*gamma)) + (0.0 * I))))/( (2.0) + (0.0 * I))));
      X.array[4-1] = ( (-(b/(4.0*a))) + (0.0 * I))-(csqrt_ ((( (-alpha) + (0.0 * I))-(csqrt_ ( ((sqr (alpha))-(4.0*gamma)) + (0.0 * I))))/( (2.0) + (0.0 * I))));
    }
  else
    {
      p = (-((sqr (alpha))/12.0))-gamma;
      q = ((-((cub (alpha))/108.0))+((alpha*gamma)/3.0))-((sqr (beta))/8.0);
      f = ((sqr (q))/4.0)+((cub (p))/27.0);
      r = (-( (q/2.0) + (0.0 * I)))+(csqrt_ ( (f) + (0.0 * I)));
      u = ccubr (r);
      if (cnearZero (u))
        y = ((-( ((5.0/6.0)*alpha) + (0.0 * I)))+u)-(ccubr ( (q) + (0.0 * I)));
      else
        y = ((-( ((5.0/6.0)*alpha) + (0.0 * I)))+u)-(( (p) + (0.0 * I))/(( (3.0) + (0.0 * I))*u));
      w = csqrt_ (( (alpha) + (0.0 * I))+(( (2.0) + (0.0 * I))*y));
      z = -((( (3.0*alpha) + (0.0 * I))+(( (2.0) + (0.0 * I))*y))+(( (2.0*beta) + (0.0 * I))/w));
      X.array[1-1] = (-( (b/(4.0*a)) + (0.0 * I)))+((w-(csqrt_ (z)))/( (2.0) + (0.0 * I)));
      X.array[2-1] = (-( (b/(4.0*a)) + (0.0 * I)))+((w+(csqrt_ (z)))/( (2.0) + (0.0 * I)));
      z = -((( (3.0*alpha) + (0.0 * I))+(( (2.0) + (0.0 * I))*y))-(( (2.0*beta) + (0.0 * I))/w));
      X.array[3-1] = (-( (b/(4.0*a)) + (0.0 * I)))+((-w-(csqrt_ (z)))/( (2.0) + (0.0 * I)));
      X.array[4-1] = (-( (b/(4.0*a)) + (0.0 * I)))+((-w+(csqrt_ (z)))/( (2.0) + (0.0 * I)));
    }
  k = 0;
  for (i=1; i<=4; i++)
    if (isReal (X.array[i-1]))
      {
        x[k] = creal (X.array[i-1]);
        k += 1;
      }
  return k;
}


/*
   nearZero - returns TRUE if, r, is close to 0.0
*/

unsigned int roots_nearZero (double r)
{
  if (r >= 0.0)
    return r < Epsilon;
  else
    return -r < Epsilon;
}


/*
   nearSame - returns TRUE if, |a-b| < epsilon
*/

unsigned int roots_nearSame (double a, double b)
{
  return roots_nearZero (a-b);
}


/*
   nearCoord - returns TRUE if position, a, is very close to, b.
*/

unsigned int roots_nearCoord (coord_Coord a, coord_Coord b)
{
  return (roots_nearSame (a.x, b.x)) && (roots_nearSame (a.y, b.y));
}


/*
   setTrace - turns tracing on/off.
*/

void roots_setTrace (unsigned int on)
{
  tracing = on;
}

void _M2_roots_init (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
  tracing = Debugging;
}

void _M2_roots_finish (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}
