/* automatically created by mc from /home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/Assertion.def.  */


#if !defined (_Assertion_H)
#   define _Assertion_H

#   ifdef __cplusplus
extern "C" {
#   endif
#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif


#   if defined (_Assertion_C)
#      define EXTERN
#   else
#      define EXTERN extern
#   endif


/*
   Assert - tests the boolean Condition, if it fails then HALT is called.
*/

EXTERN void Assertion_Assert (unsigned int Condition);
#   ifdef __cplusplus
}
#   endif

#   undef EXTERN
#endif
