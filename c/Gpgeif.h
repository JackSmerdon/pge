/* automatically created by mc from ../pge/m2/pgeif.def.  */


#if !defined (_H)
#   define _H

#   ifdef __cplusplus
extern "C" {
#   endif
#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#   include "GSYSTEM.h"

#   if defined (_C)
#      define EXTERN
#   else
#      define EXTERN extern
#   endif

typedef enum {IncorrectType, IdOutOfBounds, ValueOutOfRange} ExceptionKind;


/*
   rgb - make a colour object using red, blue and green components.
         The colour object is returned.
*/

EXTERN unsigned int rgb (double r, double g, double b);

/*
   white - returns the colour, white.
*/

EXTERN unsigned int white (void);

/*
   black - returns the colour, black.
*/

EXTERN unsigned int black (void);

/*
   red - returns the colour, red.
*/

EXTERN unsigned int red (void);

/*
   green - returns the colour, green.
*/

EXTERN unsigned int green (void);

/*
   blue - returns the colour, blue.
*/

EXTERN unsigned int blue (void);

/*
   yellow - returns the colour, yellow.
*/

EXTERN unsigned int yellow (void);

/*
   purple - returns the colour, purple.
*/

EXTERN unsigned int purple (void);

/*
   gravity - turn on gravity at: g m^2
*/

EXTERN void gravity (double g);

/*
   box - place a box in the world at (x0,y0),(x0+i,y0+j)
*/

EXTERN unsigned int box (double x0, double y0, double i, double j, unsigned int c);

/*
   poly3 - place a triangle in the world at:
           (x0,y0), (x1,y1), (x2,y2)
*/

EXTERN unsigned int poly3 (double x0, double y0, double x1, double y1, double x2, double y2, unsigned int c);

/*
   poly4 - place a rectangle in the world at:
           (x0,y0), (x1,y1), (x2,y2), (x3,y3)
*/

EXTERN unsigned int poly4 (double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, unsigned int c);

/*
   poly5 - place a pentagon in the world at:
           (x0,y0), (x1,y1), (x2,y2), (x3,y3), (x4,y4)
*/

EXTERN unsigned int poly5 (double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, unsigned int c);

/*
   poly6 - place a hexagon in the world at:
           (x0,y0), (x1,y1), (x2,y2), (x3,y3), (x4,y4), (x5,y5)
*/

EXTERN unsigned int poly6 (double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5, unsigned int c);

/*
   mass - specify the mass of an object and return the, id.
*/

EXTERN unsigned int mass (unsigned int id, double m);

/*
   fix - fix the object to the world.
*/

EXTERN unsigned int fix (unsigned int id);

/*
   circle - adds a circle to the world.  Center
            defined by: x0, y0 radius, radius.
*/

EXTERN unsigned int circle (double x0, double y0, double radius, unsigned int c);

/*
   velocity - give an object, id, a velocity, vx, vy.
*/

EXTERN unsigned int velocity (unsigned int id, double vx, double vy);

/*
   accel - give an object, id, an acceleration, ax, ay.
*/

EXTERN unsigned int accel (unsigned int id, double ax, double ay);

/*
   rotate - rotates object with a angular velocity, angle.
*/

EXTERN unsigned int rotate (unsigned int id, double angle);

/*
   is_collision - returns TRUE if next event is a collision event.
*/

EXTERN unsigned int is_collision (void);

/*
   is_frame - returns TRUE if the next event is a redraw frame event.
*/

EXTERN unsigned int is_frame (void);

/*
   is_function - returns TRUE if the next event is a function event.
*/

EXTERN unsigned int is_function (void);

/*
   create_function_event - creates a function event at time, t,
                           in the future.
*/

EXTERN void create_function_event (double t, unsigned int id);

/*
   time_until - returns the relative time from now until the next event.
*/

EXTERN double time_until (void);

/*
   skip_until - advances time for, t, units or until the next event is reached.
*/

EXTERN double skip_until (double t);

/*
   process_event - advance time to the next event and then
                   process the event.
*/

EXTERN void process_event (void);

/*
   get_time - return the current simulation time.
*/

EXTERN double get_time (void);

/*
   rm - delete this object from the simulated world.
        The same id is returned.
*/

EXTERN unsigned int rm (unsigned int id);

/*
   get_xpos - returns the first point, x, coordinate of object.
*/

EXTERN double get_xpos (unsigned int id);

/*
   get_ypos - returns the first point, y, coordinate of object.
*/

EXTERN double get_ypos (unsigned int id);

/*
   get_xvel - returns the X velocity of object.
*/

EXTERN double get_xvel (unsigned int id);

/*
   get_yvel - returns the Y velocity of object.
*/

EXTERN double get_yvel (unsigned int id);

/*
   get_xaccel - returns the X acceleration of object.
*/

EXTERN double get_xaccel (unsigned int id);

/*
   get_yaccel - returns the Y acceleration of object.
*/

EXTERN double get_yaccel (unsigned int id);

/*
   put_xvel - assigns the X velocity of object.
*/

EXTERN void put_xvel (unsigned int id, double r);

/*
   put_yvel - assigns the Y velocity of object.
*/

EXTERN void put_yvel (unsigned int id, double r);

/*
   put_xaccel - assigns the X acceleration of object.
*/

EXTERN void put_xaccel (unsigned int id, double r);

/*
   put_yaccel - assigns the Y acceleration of object.
*/

EXTERN void put_yaccel (unsigned int id, double r);

/*
   set_colour - sets colour of object, id, to, c.
*/

EXTERN void set_colour (unsigned int id, unsigned int c);

/*
   apply_impulse - applies an impulse of magnitude along vector
                   [x, y] for object, id.
*/

EXTERN void apply_impulse (unsigned int id, double x, double y, double m);

/*
   moving_towards - returns TRUE if object, id, is moving towards
                    a point x, y.
*/

EXTERN unsigned int moving_towards (unsigned int id, double x, double y);

/*
   batch - use the batch device to record the output frames.
*/

EXTERN void batch (void);

/*
   use_buffer - use the buffer device to record the output frames.
*/

EXTERN void use_buffer (void);

/*
   empty_cbuffer - empty the colour buffer.
*/

EXTERN void empty_cbuffer (void);

/*
   empty_fbuffer - empty the frame buffer.
*/

EXTERN void empty_fbuffer (void);
EXTERN void use_time_delay (unsigned int on);

/*
   draw_collision - turn on drawing of the actual collision frame
                    and the prediction frame.
*/

EXTERN void draw_collision (unsigned int actual, unsigned int predict);

/*
   set_collision_colour - when two objects collide they will both be draw using
                          colour, c.
*/

EXTERN void set_collision_colour (unsigned int c);

/*
   dump_world - dump a list of all objects and their characteristics.
*/

EXTERN void dump_world (void);

/*
   check_objects - perform a check to make sure that all non fixed
                   objects have a mass.
*/

EXTERN void check_objects (void);

/*
   l2h - translate a twoDsim, id, to the pgeid.
*/

EXTERN unsigned int l2h (unsigned int id);

/*
   h2l - translate a pgeif, id, to the twoDsim.
*/

EXTERN unsigned int h2l (unsigned int id);

/*
   fps - set frames per second.
*/

EXTERN void fps (double f);
#   ifdef __cplusplus
}
#   endif

#   undef EXTERN
#endif