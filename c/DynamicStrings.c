/* automatically created by mc from /home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod.  */

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
#   include "GStorage.h"
#define _DynamicStrings_H
#define _DynamicStrings_C

#   include "Glibc.h"
#   include "GStrLib.h"
#   include "GStorage.h"
#   include "GAssertion.h"
#   include "GSYSTEM.h"
#   include "GASCII.h"
#   include "GM2RTS.h"

#   define MaxBuf 127
#   define PoisonOn FALSE
#   define DebugOn FALSE
#   define CheckOn FALSE
#   define TraceOn FALSE
typedef struct Contents_r Contents;

typedef struct DebugInfo_r DebugInfo;

typedef struct stringRecord_r stringRecord;

typedef struct descriptor_r descriptor;

typedef descriptor *Descriptor;

typedef struct frameRec_r frameRec;

typedef frameRec *frame;

typedef struct _T1_a _T1;

typedef enum {inuse, marked, onlist, poisoned} desState;

typedef stringRecord *DynamicStrings_String;

struct DebugInfo_r {
                     DynamicStrings_String next;
                     void *file;
                     unsigned int line;
                     void *proc;
                   };

struct descriptor_r {
                      unsigned int charStarUsed;
                      void *charStar;
                      unsigned int charStarSize;
                      unsigned int charStarValid;
                      desState state;
                      DynamicStrings_String garbage;
                    };

struct frameRec_r {
                    DynamicStrings_String alloc;
                    DynamicStrings_String dealloc;
                    frame next;
                  };

struct _T1_a { char array[(MaxBuf-1)+1]; };
struct Contents_r {
                    _T1 buf;
                    unsigned int len;
                    DynamicStrings_String next;
                  };

struct stringRecord_r {
                        Contents contents;
                        Descriptor head;
                        DebugInfo debug;
                      };

static unsigned int Initialized;
static frame frameHead;
static DynamicStrings_String captured;

/*
   InitString - creates and returns a String type object.
                Initial contents are, a.
*/

DynamicStrings_String DynamicStrings_InitString (char *a_, unsigned int _a_high);

/*
   KillString - frees String, s, and its contents.
                NIL is returned.
*/

DynamicStrings_String DynamicStrings_KillString (DynamicStrings_String s);

/*
   Fin - finishes with a string, it calls KillString with, s.
         The purpose of the procedure is to provide a short cut
         to calling KillString and then testing the return result.
*/

void DynamicStrings_Fin (DynamicStrings_String s);

/*
   InitStringCharStar - initializes and returns a String to contain the C string.
*/

DynamicStrings_String DynamicStrings_InitStringCharStar (void * a);

/*
   InitStringChar - initializes and returns a String to contain the single character, ch.
*/

DynamicStrings_String DynamicStrings_InitStringChar (char ch);

/*
   Mark - marks String, s, ready for garbage collection.
*/

DynamicStrings_String DynamicStrings_Mark (DynamicStrings_String s);

/*
   Length - returns the length of the String, s.
*/

unsigned int DynamicStrings_Length (DynamicStrings_String s);

/*
   ConCat - returns String, a, after the contents of, b, have been appended.
*/

DynamicStrings_String DynamicStrings_ConCat (DynamicStrings_String a, DynamicStrings_String b);

/*
   ConCatChar - returns String, a, after character, ch, has been appended.
*/

DynamicStrings_String DynamicStrings_ConCatChar (DynamicStrings_String a, char ch);

/*
   Assign - assigns the contents of, b, into, a.
            String, a, is returned.
*/

DynamicStrings_String DynamicStrings_Assign (DynamicStrings_String a, DynamicStrings_String b);

/*
   Dup - duplicate a String, s, returning the copy of s.
*/

DynamicStrings_String DynamicStrings_Dup (DynamicStrings_String s);

/*
   Add - returns a new String which contains the contents of a and b.
*/

DynamicStrings_String DynamicStrings_Add (DynamicStrings_String a, DynamicStrings_String b);

/*
   Equal - returns TRUE if String, a, and, b, are equal.
*/

unsigned int DynamicStrings_Equal (DynamicStrings_String a, DynamicStrings_String b);

/*
   EqualCharStar - returns TRUE if contents of String, s, is the same as the
                   string, a.
*/

unsigned int DynamicStrings_EqualCharStar (DynamicStrings_String s, void * a);

/*
   EqualArray - returns TRUE if contents of String, s, is the same as the
                string, a.
*/

unsigned int DynamicStrings_EqualArray (DynamicStrings_String s, char *a_, unsigned int _a_high);

/*
   Mult - returns a new string which is n concatenations of String, s.
*/

DynamicStrings_String DynamicStrings_Mult (DynamicStrings_String s, unsigned int n);

/*
   Slice - returns a new string which contains the elements
           low..high-1

           strings start at element 0
           Slice(s, 0, 2)  will return elements 0, 1 but not 2
           Slice(s, 1, 3)  will return elements 1, 2 but not 3
           Slice(s, 2, 0)  will return elements 2..max
           Slice(s, 3, -1) will return elements 3..max-1
           Slice(s, 4, -2) will return elements 4..max-2
*/

DynamicStrings_String DynamicStrings_Slice (DynamicStrings_String s, int low, int high);

/*
   Index - returns the indice of the first occurance of, ch, in
           String, s. -1 is returned if, ch, does not exist.
           The search starts at position, o.
*/

int DynamicStrings_Index (DynamicStrings_String s, char ch, unsigned int o);

/*
   RIndex - returns the indice of the last occurance of, ch,
            in String, s. The search starts at position, o.
            -1 is returned if, ch, is not found.
*/

int DynamicStrings_RIndex (DynamicStrings_String s, char ch, unsigned int o);

/*
   RemoveComment - assuming that, comment, is a comment delimiter
                   which indicates anything to its right is a comment
                   then strip off the comment and also any white space
                   on the remaining right hand side.
                   It leaves any white space on the left hand side alone.
*/

DynamicStrings_String DynamicStrings_RemoveComment (DynamicStrings_String s, char comment);

/*
   RemoveWhitePrefix - removes any leading white space from String, s.
                       A new string is returned.
*/

DynamicStrings_String DynamicStrings_RemoveWhitePrefix (DynamicStrings_String s);

/*
   RemoveWhitePostfix - removes any leading white space from String, s.
                        A new string is returned.
*/

DynamicStrings_String DynamicStrings_RemoveWhitePostfix (DynamicStrings_String s);

/*
   ToUpper - returns string, s, after it has had its lower case characters
             replaced by upper case characters.
             The string, s, is not duplicated.
*/

DynamicStrings_String DynamicStrings_ToUpper (DynamicStrings_String s);

/*
   ToLower - returns string, s, after it has had its upper case characters
             replaced by lower case characters.
             The string, s, is not duplicated.
*/

DynamicStrings_String DynamicStrings_ToLower (DynamicStrings_String s);

/*
   CopyOut - copies string, s, to a.
*/

void DynamicStrings_CopyOut (char *a, unsigned int _a_high, DynamicStrings_String s);

/*
   char - returns the character, ch, at position, i, in String, s.
*/

char DynamicStrings_char (DynamicStrings_String s, int i);

/*
   string - returns the C style char * of String, s.
*/

void * DynamicStrings_string (DynamicStrings_String s);

/*
   InitStringDB - the debug version of InitString.
*/

DynamicStrings_String DynamicStrings_InitStringDB (char *a_, unsigned int _a_high, char *file_, unsigned int _file_high, unsigned int line);

/*
   InitStringCharStarDB - the debug version of InitStringCharStar.
*/

DynamicStrings_String DynamicStrings_InitStringCharStarDB (void * a, char *file_, unsigned int _file_high, unsigned int line);

/*
   InitStringCharDB - the debug version of InitStringChar.
*/

DynamicStrings_String DynamicStrings_InitStringCharDB (char ch, char *file_, unsigned int _file_high, unsigned int line);

/*
   MultDB - the debug version of MultDB.
*/

DynamicStrings_String DynamicStrings_MultDB (DynamicStrings_String s, unsigned int n, char *file_, unsigned int _file_high, unsigned int line);

/*
   DupDB - the debug version of Dup.
*/

DynamicStrings_String DynamicStrings_DupDB (DynamicStrings_String s, char *file_, unsigned int _file_high, unsigned int line);

/*
   SliceDB - debug version of Slice.
*/

DynamicStrings_String DynamicStrings_SliceDB (DynamicStrings_String s, int low, int high, char *file_, unsigned int _file_high, unsigned int line);

/*
   PushAllocation - pushes the current allocation/deallocation lists.
*/

void DynamicStrings_PushAllocation (void);

/*
   PopAllocation - test to see that all strings are deallocated since
                   the last push.  Then it pops to the previous
                   allocation/deallocation lists.

                   If halt is true then the application terminates
                   with an exit code of 1.
*/

void DynamicStrings_PopAllocation (unsigned int halt);

/*
   PopAllocationExemption - test to see that all strings are deallocated, except
                            string, e, since the last push.
                            Then it pops to the previous allocation/deallocation
                            lists.

                            If halt is true then the application terminates
                            with an exit code of 1.
*/

DynamicStrings_String DynamicStrings_PopAllocationExemption (unsigned int halt, DynamicStrings_String e);

/*
 writeStringDesc write out debugging information about string, s.  */

static void writeStringDesc (DynamicStrings_String s);

/*
   writeNspace -
*/

static void writeNspace (unsigned int n);

/*
   DumpStringInfo -
*/

static void DumpStringInfo (DynamicStrings_String s, unsigned int i);

/*
   doDSdbEnter -
*/

static void doDSdbEnter (void);

/*
   doDSdbExit -
*/

static void doDSdbExit (DynamicStrings_String s);

/*
   DSdbEnter -
*/

static void DSdbEnter (void);

/*
   DSdbExit -
*/

static void DSdbExit (DynamicStrings_String s);
static unsigned int Capture (DynamicStrings_String s);

/*
   Min -
*/

static unsigned int Min (unsigned int a, unsigned int b);

/*
   Max -
*/

static unsigned int Max (unsigned int a, unsigned int b);

/*
   writeString - writes a string to stdout.
*/

static void writeString (char *a_, unsigned int _a_high);

/*
   writeCstring - writes a C string to stdout.
*/

static void writeCstring (void * a);

/*
   writeCard -
*/

static void writeCard (unsigned int c);

/*
   writeLongcard -
*/

static void writeLongcard (long unsigned int l);

/*
   writeAddress -
*/

static void writeAddress (void * a);

/*
   writeLn - writes a newline.
*/

static void writeLn (void);

/*
   AssignDebug - assigns, file, and, line, information to string, s.
*/

static DynamicStrings_String AssignDebug (DynamicStrings_String s, char *file_, unsigned int _file_high, unsigned int line, char *proc_, unsigned int _proc_high);

/*
   IsOn - returns TRUE if, s, is on one of the debug lists.
*/

static unsigned int IsOn (DynamicStrings_String list, DynamicStrings_String s);

/*
   AddTo - adds string, s, to, list.
*/

static void AddTo (DynamicStrings_String *list, DynamicStrings_String s);

/*
   SubFrom - removes string, s, from, list.
*/

static void SubFrom (DynamicStrings_String *list, DynamicStrings_String s);

/*
   AddAllocated - adds string, s, to the head of the allocated list.
*/

static void AddAllocated (DynamicStrings_String s);

/*
   AddDeallocated - adds string, s, to the head of the deallocated list.
*/

static void AddDeallocated (DynamicStrings_String s);

/*
   IsOnAllocated - returns TRUE if the string, s, has ever been allocated.
*/

static unsigned int IsOnAllocated (DynamicStrings_String s);

/*
   IsOnDeallocated - returns TRUE if the string, s, has ever been deallocated.
*/

static unsigned int IsOnDeallocated (DynamicStrings_String s);

/*
   SubAllocated - removes string, s, from the list of allocated strings.
*/

static void SubAllocated (DynamicStrings_String s);

/*
   SubDeallocated - removes string, s, from the list of deallocated strings.
*/

static void SubDeallocated (DynamicStrings_String s);

/*
   SubDebugInfo - removes string, s, from the list of allocated strings.
*/

static void SubDebugInfo (DynamicStrings_String s);

/*
   AddDebugInfo - adds string, s, to the list of allocated strings.
*/

static void AddDebugInfo (DynamicStrings_String s);

/*
   ConcatContents - add the contents of string, a, where, h, is the
                    total length of, a. The offset is in, o.
*/

static void ConcatContents (Contents *c, char *a_, unsigned int _a_high, unsigned int h, unsigned int o);

/*
   DeallocateCharStar - deallocates any charStar.
*/

static void DeallocateCharStar (DynamicStrings_String s);

/*
   CheckPoisoned - checks for a poisoned string, s.
*/

static DynamicStrings_String CheckPoisoned (DynamicStrings_String s);

/*
   MarkInvalid - marks the char * version of String, s, as invalid.
*/

static void MarkInvalid (DynamicStrings_String s);

/*
   ConcatContentsAddress - concatenate the string, a, where, h, is the
                           total length of, a.
*/

static void ConcatContentsAddress (Contents *c, void * a, unsigned int h);

/*
   AddToGarbage - adds String, b, onto the garbage list of, a.  Providing
                  the state of b is marked.  The state is then altered to
                  onlist.  String, a, is returned.
*/

static DynamicStrings_String AddToGarbage (DynamicStrings_String a, DynamicStrings_String b);

/*
   IsOnGarbage - returns TRUE if, s, is on string, e, garbage list.
*/

static unsigned int IsOnGarbage (DynamicStrings_String e, DynamicStrings_String s);

/*
   IsWhite - returns TRUE if, ch, is a space or a tab.
*/

static unsigned int IsWhite (char ch);

/*
   DumpState -
*/

static void DumpState (DynamicStrings_String s);

/*
   DumpStringSynopsis -
*/

static void DumpStringSynopsis (DynamicStrings_String s);

/*
   DumpString - displays the contents of string, s.
*/

static void DumpString (DynamicStrings_String s);

/*
   Init - initialize the module.
*/

static void Init (void);


/*
 writeStringDesc write out debugging information about string, s.  */

static void writeStringDesc (DynamicStrings_String s)
{
  writeCstring (s->debug.file);
  writeString ((char *) ":", 1);
  writeCard (s->debug.line);
  writeString ((char *) ":", 1);
  writeCstring (s->debug.proc);
  writeString ((char *) " ", 1);
  writeAddress ((void *) s);
  writeString ((char *) " ", 1);
  switch (s->head->state)
    {
      case inuse:
        writeString ((char *) "still in use (", 14);
        writeCard (s->contents.len);
        writeString ((char *) ") characters", 12);
        break;

      case marked:
        writeString ((char *) "marked", 6);
        break;

      case onlist:
        writeString ((char *) "on a (lost) garbage list", 24);
        break;

      case poisoned:
        writeString ((char *) "poisoned", 8);
        break;


      default:
        writeString ((char *) "unknown state", 13);
        break;
    }
}


/*
   writeNspace -
*/

static void writeNspace (unsigned int n)
{
  while (n > 0)
    {
      writeString ((char *) " ", 1);
      n -= 1;
    }
}


/*
   DumpStringInfo -
*/

static void DumpStringInfo (DynamicStrings_String s, unsigned int i)
{
  DynamicStrings_String t;

  if (s != NULL)
    {
      writeNspace (i);
      writeStringDesc (s);
      writeLn ();
      if (s->head->garbage != NULL)
        {
          writeNspace (i);
          writeString ((char *) "garbage list:", 13);
          writeLn ();
          do {
            s = s->head->garbage;
            DumpStringInfo (s, i+1);
            writeLn ();
          } while (! (s == NULL));
        }
    }
}


/*
   doDSdbEnter -
*/

static void doDSdbEnter (void)
{
  if (CheckOn)
    DynamicStrings_PushAllocation ();
}


/*
   doDSdbExit -
*/

static void doDSdbExit (DynamicStrings_String s)
{
  if (CheckOn)
    s = DynamicStrings_PopAllocationExemption (TRUE, s);
}


/*
   DSdbEnter -
*/

static void DSdbEnter (void)
{
}


/*
   DSdbExit -
*/

static void DSdbExit (DynamicStrings_String s)
{
}

static unsigned int Capture (DynamicStrings_String s)
{
  /* 
#undef GM2_DEBUG_DYNAMICSTINGS
#if defined(GM2_DEBUG_DYNAMICSTINGS)
#  define DSdbEnter doDSdbEnter
#  define DSdbExit  doDSdbExit
#  define CheckOn   TRUE
#  define TraceOn   TRUE
#endif
  */
  captured = s;
  return 1;
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
   writeString - writes a string to stdout.
*/

static void writeString (char *a_, unsigned int _a_high)
{
  int i;
  char a[_a_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (a, a_, _a_high+1);

  i = libc_write (1, &a, (size_t) StrLib_StrLen ((char *) a, _a_high));
}


/*
   writeCstring - writes a C string to stdout.
*/

static void writeCstring (void * a)
{
  int i;

  if (a == NULL)
    writeString ((char *) "(null)", 6);
  else
    i = libc_write (1, a, libc_strlen (a));
}


/*
   writeCard -
*/

static void writeCard (unsigned int c)
{
  char ch;
  int i;

  if (c > 9)
    {
      writeCard (c / 10);
      writeCard (c % 10);
    }
  else
    {
      ch = (char) (((unsigned int) ('0'))+c);
      i = libc_write (1, &ch, (size_t) 1);
    }
}


/*
   writeLongcard -
*/

static void writeLongcard (long unsigned int l)
{
  char ch;
  int i;

  if (l > 16)
    {
      writeLongcard (l / 16);
      writeLongcard (l % 16);
    }
  else if (l < 10)
    {
      ch = (char) (((unsigned int) ('0'))+((unsigned int ) (l)));
      i = libc_write (1, &ch, (size_t) 1);
    }
  else if (l < 16)
    {
      ch = (char) ((((unsigned int) ('a'))+((unsigned int ) (l)))-10);
      i = libc_write (1, &ch, (size_t) 1);
    }
}


/*
   writeAddress -
*/

static void writeAddress (void * a)
{
  writeLongcard ((long unsigned int ) (a));
}


/*
   writeLn - writes a newline.
*/

static void writeLn (void)
{
  char ch;
  int i;

  ch = ASCII_lf;
  i = libc_write (1, &ch, (size_t) 1);
}


/*
   AssignDebug - assigns, file, and, line, information to string, s.
*/

static DynamicStrings_String AssignDebug (DynamicStrings_String s, char *file_, unsigned int _file_high, unsigned int line, char *proc_, unsigned int _proc_high)
{
  void * f;
  void * p;
  char file[_file_high+1];
  char proc[_proc_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (file, file_, _file_high+1);
  memcpy (proc, proc_, _proc_high+1);

  f = &file;
  p = &proc;
  Storage_ALLOCATE (&s->debug.file, (StrLib_StrLen ((char *) file, _file_high))+1);
  if ((libc_strncpy (s->debug.file, f, (StrLib_StrLen ((char *) file, _file_high))+1)) == NULL)
    {}  /* empty.  */
  s->debug.line = line;
  Storage_ALLOCATE (&s->debug.proc, (StrLib_StrLen ((char *) proc, _proc_high))+1);
  if ((libc_strncpy (s->debug.proc, p, (StrLib_StrLen ((char *) proc, _proc_high))+1)) == NULL)
    {}  /* empty.  */
  return s;
}


/*
   IsOn - returns TRUE if, s, is on one of the debug lists.
*/

static unsigned int IsOn (DynamicStrings_String list, DynamicStrings_String s)
{
  while ((list != s) && (list != NULL))
    list = list->debug.next;
  return list == s;
}


/*
   AddTo - adds string, s, to, list.
*/

static void AddTo (DynamicStrings_String *list, DynamicStrings_String s)
{
  if ((*list) == NULL)
    {
      (*list) = s;
      s->debug.next = NULL;
    }
  else
    {
      s->debug.next = (*list);
      (*list) = s;
    }
}


/*
   SubFrom - removes string, s, from, list.
*/

static void SubFrom (DynamicStrings_String *list, DynamicStrings_String s)
{
  DynamicStrings_String p;

  if ((*list) == s)
    (*list) = s->debug.next;
  else
    {
      p = (*list);
      while ((p->debug.next != NULL) && (p->debug.next != s))
        p = p->debug.next;
      if (p->debug.next == s)
        p->debug.next = s->debug.next;
      else
        /* not found, quit  */
        return;
    }
  s->debug.next = NULL;
}


/*
   AddAllocated - adds string, s, to the head of the allocated list.
*/

static void AddAllocated (DynamicStrings_String s)
{
  Init ();
  AddTo (&frameHead->alloc, s);
}


/*
   AddDeallocated - adds string, s, to the head of the deallocated list.
*/

static void AddDeallocated (DynamicStrings_String s)
{
  Init ();
  AddTo (&frameHead->dealloc, s);
}


/*
   IsOnAllocated - returns TRUE if the string, s, has ever been allocated.
*/

static unsigned int IsOnAllocated (DynamicStrings_String s)
{
  frame f;

  Init ();
  f = frameHead;
  do {
    if (IsOn (f->alloc, s))
      return TRUE;
    else
      f = f->next;
  } while (! (f == NULL));
  return FALSE;
}


/*
   IsOnDeallocated - returns TRUE if the string, s, has ever been deallocated.
*/

static unsigned int IsOnDeallocated (DynamicStrings_String s)
{
  frame f;

  Init ();
  f = frameHead;
  do {
    if (IsOn (f->dealloc, s))
      return TRUE;
    else
      f = f->next;
  } while (! (f == NULL));
  return FALSE;
}


/*
   SubAllocated - removes string, s, from the list of allocated strings.
*/

static void SubAllocated (DynamicStrings_String s)
{
  frame f;

  Init ();
  f = frameHead;
  do {
    if (IsOn (f->alloc, s))
      {
        SubFrom (&f->alloc, s);
        return;
      }
    else
      f = f->next;
  } while (! (f == NULL));
}


/*
   SubDeallocated - removes string, s, from the list of deallocated strings.
*/

static void SubDeallocated (DynamicStrings_String s)
{
  frame f;

  Init ();
  f = frameHead;
  do {
    if (IsOn (f->dealloc, s))
      {
        SubFrom (&f->dealloc, s);
        return;
      }
    else
      f = f->next;
  } while (! (f == NULL));
}


/*
   SubDebugInfo - removes string, s, from the list of allocated strings.
*/

static void SubDebugInfo (DynamicStrings_String s)
{
  if (IsOnDeallocated (s))
    {
      Assertion_Assert (! DebugOn);
      /* string has already been deallocated  */
      return;
    }
  if (IsOnAllocated (s))
    {
      SubAllocated (s);
      AddDeallocated (s);
    }
  else
    /* string has not been allocated  */
    Assertion_Assert (! DebugOn);
}


/*
   AddDebugInfo - adds string, s, to the list of allocated strings.
*/

static void AddDebugInfo (DynamicStrings_String s)
{
  s->debug.next = NULL;
  s->debug.file = NULL;
  s->debug.line = 0;
  s->debug.proc = NULL;
  if (CheckOn)
    AddAllocated (s);
}


/*
   ConcatContents - add the contents of string, a, where, h, is the
                    total length of, a. The offset is in, o.
*/

static void ConcatContents (Contents *c, char *a_, unsigned int _a_high, unsigned int h, unsigned int o)
{
  unsigned int i;
  char a[_a_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (a, a_, _a_high+1);

  i = (*c).len;
  while ((o < h) && (i < MaxBuf))
    {
      (*c).buf.array[i] = a[o];
      o += 1;
      i += 1;
    }
  if (o < h)
    {
      (*c).len = MaxBuf;
      Storage_ALLOCATE ((void **) &(*c).next, sizeof (stringRecord));
      (*c).next->head = NULL;
      (*c).next->contents.len = 0;
      (*c).next->contents.next = NULL;
      ConcatContents (&(*c).next->contents, (char *) a, _a_high, h, o);
      AddDebugInfo ((*c).next);
      (*c).next = AssignDebug ((*c).next, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 701, (char *) "ConcatContents", 14);
    }
  else
    (*c).len = i;
}


/*
   DeallocateCharStar - deallocates any charStar.
*/

static void DeallocateCharStar (DynamicStrings_String s)
{
  if ((s != NULL) && (s->head != NULL))
    {
      if (s->head->charStarUsed && (s->head->charStar != NULL))
        Storage_DEALLOCATE (&s->head->charStar, s->head->charStarSize);
      s->head->charStarUsed = FALSE;
      s->head->charStar = NULL;
      s->head->charStarSize = 0;
      s->head->charStarValid = FALSE;
    }
}


/*
   CheckPoisoned - checks for a poisoned string, s.
*/

static DynamicStrings_String CheckPoisoned (DynamicStrings_String s)
{
  if (((PoisonOn && (s != NULL)) && (s->head != NULL)) && (s->head->state == poisoned))
    M2RTS_HALT (-1);
  return s;
}


/*
   MarkInvalid - marks the char * version of String, s, as invalid.
*/

static void MarkInvalid (DynamicStrings_String s)
{
  if (PoisonOn)
    s = CheckPoisoned (s);
  if (s->head != NULL)
    s->head->charStarValid = FALSE;
}


/*
   ConcatContentsAddress - concatenate the string, a, where, h, is the
                           total length of, a.
*/

static void ConcatContentsAddress (Contents *c, void * a, unsigned int h)
{
  unsigned int i;
  unsigned int j;
  char * p;

  j = 0;
  i = (*c).len;
  p = a;
  while ((j < h) && (i < MaxBuf))
    {
      (*c).buf.array[i] = (*p);
      i += 1;
      j += 1;
      p += 1;
    }
  if (j < h)
    {
      (*c).len = MaxBuf;
      Storage_ALLOCATE ((void **) &(*c).next, sizeof (stringRecord));
      (*c).next->head = NULL;
      (*c).next->contents.len = 0;
      (*c).next->contents.next = NULL;
      ConcatContentsAddress (&(*c).next->contents, (void *) p, h-j);
      AddDebugInfo ((*c).next);
      if (TraceOn)
        (*c).next = AssignDebug ((*c).next, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 896, (char *) "ConcatContentsAddress", 21);
    }
  else
    {
      (*c).len = i;
      (*c).next = NULL;
    }
}


/*
   AddToGarbage - adds String, b, onto the garbage list of, a.  Providing
                  the state of b is marked.  The state is then altered to
                  onlist.  String, a, is returned.
*/

static DynamicStrings_String AddToGarbage (DynamicStrings_String a, DynamicStrings_String b)
{
  DynamicStrings_String c;

  if (PoisonOn)
    {
      a = CheckPoisoned (a);
      b = CheckPoisoned (b);
    }
  /* 
   IF (a#NIL) AND (a#b) AND (a^.head^.state=marked)
   THEN
      writeString('warning trying to add to a marked string') ; writeLn
   END ;
  */
  if (((((a != b) && (a != NULL)) && (b != NULL)) && (b->head->state == marked)) && (a->head->state == inuse))
    {
      c = a;
      while (c->head->garbage != NULL)
        c = c->head->garbage;
      c->head->garbage = b;
      b->head->state = onlist;
      if (CheckOn)
        SubDebugInfo (b);
    }
  return a;
}


/*
   IsOnGarbage - returns TRUE if, s, is on string, e, garbage list.
*/

static unsigned int IsOnGarbage (DynamicStrings_String e, DynamicStrings_String s)
{
  if ((e != NULL) && (s != NULL))
    while (e->head->garbage != NULL)
      if (e->head->garbage == s)
        return TRUE;
      else
        e = e->head->garbage;
  return FALSE;
}


/*
   IsWhite - returns TRUE if, ch, is a space or a tab.
*/

static unsigned int IsWhite (char ch)
{
  return (ch == ' ') || (ch == ASCII_tab);
}


/*
   DumpState -
*/

static void DumpState (DynamicStrings_String s)
{
  switch (s->head->state)
    {
      case inuse:
        writeString ((char *) "still in use (", 14);
        writeCard (s->contents.len);
        writeString ((char *) ") characters", 12);
        break;

      case marked:
        writeString ((char *) "marked", 6);
        break;

      case onlist:
        writeString ((char *) "on a garbage list", 17);
        break;

      case poisoned:
        writeString ((char *) "poisoned", 8);
        break;


      default:
        writeString ((char *) "unknown state", 13);
        break;
    }
}


/*
   DumpStringSynopsis -
*/

static void DumpStringSynopsis (DynamicStrings_String s)
{
  writeCstring (s->debug.file);
  writeString ((char *) ":", 1);
  writeCard (s->debug.line);
  writeString ((char *) ":", 1);
  writeCstring (s->debug.proc);
  writeString ((char *) " string ", 8);
  writeAddress ((void *) s);
  writeString ((char *) " ", 1);
  DumpState (s);
  if (IsOnAllocated (s))
    writeString ((char *) " globally allocated", 19);
  else if (IsOnDeallocated (s))
    writeString ((char *) " globally deallocated", 21);
  else
    writeString ((char *) " globally unknown", 17);
  writeLn ();
}


/*
   DumpString - displays the contents of string, s.
*/

static void DumpString (DynamicStrings_String s)
{
  DynamicStrings_String t;

  if (s != NULL)
    {
      DumpStringSynopsis (s);
      if ((s->head != NULL) && (s->head->garbage != NULL))
        {
          writeString ((char *) "display chained strings on the garbage list", 43);
          writeLn ();
          t = s->head->garbage;
          while (t != NULL)
            {
              DumpStringSynopsis (t);
              t = t->head->garbage;
            }
        }
    }
}


/*
   Init - initialize the module.
*/

static void Init (void)
{
  if (! Initialized)
    {
      Initialized = TRUE;
      frameHead = NULL;
      DynamicStrings_PushAllocation ();
    }
}


/*
   InitString - creates and returns a String type object.
                Initial contents are, a.
*/

DynamicStrings_String DynamicStrings_InitString (char *a_, unsigned int _a_high)
{
  DynamicStrings_String s;
  char a[_a_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (a, a_, _a_high+1);

  Storage_ALLOCATE ((void **) &s, sizeof (stringRecord));
  s->contents.len = 0;
  s->contents.next = NULL;
  ConcatContents (&s->contents, (char *) a, _a_high, StrLib_StrLen ((char *) a, _a_high), 0);
  Storage_ALLOCATE ((void **) &s->head, sizeof (descriptor));
  s->head->charStarUsed = FALSE;
  s->head->charStar = NULL;
  s->head->charStarSize = 0;
  s->head->charStarValid = FALSE;
  s->head->garbage = NULL;
  s->head->state = inuse;
  AddDebugInfo (s);
  if (TraceOn)
    s = AssignDebug (s, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 737, (char *) "InitString", 10);
  return s;
}


/*
   KillString - frees String, s, and its contents.
                NIL is returned.
*/

DynamicStrings_String DynamicStrings_KillString (DynamicStrings_String s)
{
  DynamicStrings_String t;

  if (PoisonOn)
    s = CheckPoisoned (s);
  if (s != NULL)
    {
      if (CheckOn)
        {
          /* avoid gcc warning by using compound statement even if not strictly necessary.  */
          if (IsOnAllocated (s))
            SubAllocated (s);
          else if (IsOnDeallocated (s))
            SubDeallocated (s);
        }
      if (s->head != NULL)
        {
          s->head->state = poisoned;
          s->head->garbage = DynamicStrings_KillString (s->head->garbage);
          if (! PoisonOn)
            DeallocateCharStar (s);
          if (! PoisonOn)
            {
              Storage_DEALLOCATE ((void **) &s->head, sizeof (descriptor));
              s->head = NULL;
            }
        }
      t = DynamicStrings_KillString (s->contents.next);
      if (! PoisonOn)
        Storage_DEALLOCATE ((void **) &s, sizeof (stringRecord));
    }
  return NULL;
}


/*
   Fin - finishes with a string, it calls KillString with, s.
         The purpose of the procedure is to provide a short cut
         to calling KillString and then testing the return result.
*/

void DynamicStrings_Fin (DynamicStrings_String s)
{
  if ((DynamicStrings_KillString (s)) != NULL)
    M2RTS_HALT (-1);
}


/*
   InitStringCharStar - initializes and returns a String to contain the C string.
*/

DynamicStrings_String DynamicStrings_InitStringCharStar (void * a)
{
  DynamicStrings_String s;

  Storage_ALLOCATE ((void **) &s, sizeof (stringRecord));
  s->contents.len = 0;
  s->contents.next = NULL;
  if (a != NULL)
    ConcatContentsAddress (&s->contents, a, (unsigned int) libc_strlen (a));
  Storage_ALLOCATE ((void **) &s->head, sizeof (descriptor));
  s->head->charStarUsed = FALSE;
  s->head->charStar = NULL;
  s->head->charStarSize = 0;
  s->head->charStarValid = FALSE;
  s->head->garbage = NULL;
  s->head->state = inuse;
  AddDebugInfo (s);
  if (TraceOn)
    s = AssignDebug (s, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 936, (char *) "InitStringCharStar", 18);
  return s;
}


/*
   InitStringChar - initializes and returns a String to contain the single character, ch.
*/

DynamicStrings_String DynamicStrings_InitStringChar (char ch)
{
  typedef struct _T2_a _T2;

  struct _T2_a { char array[1+1]; };
  _T2 a;
  DynamicStrings_String s;

  a.array[0] = ch;
  a.array[1] = ASCII_nul;
  s = DynamicStrings_InitString ((char *) &a.array[0], 1);
  if (TraceOn)
    s = AssignDebug (s, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 956, (char *) "InitStringChar", 14);
  return s;
}


/*
   Mark - marks String, s, ready for garbage collection.
*/

DynamicStrings_String DynamicStrings_Mark (DynamicStrings_String s)
{
  if (PoisonOn)
    s = CheckPoisoned (s);
  if ((s != NULL) && (s->head->state == inuse))
    s->head->state = marked;
  return s;
}


/*
   Length - returns the length of the String, s.
*/

unsigned int DynamicStrings_Length (DynamicStrings_String s)
{
  if (s == NULL)
    return 0;
  else
    return s->contents.len+(DynamicStrings_Length (s->contents.next));
}


/*
   ConCat - returns String, a, after the contents of, b, have been appended.
*/

DynamicStrings_String DynamicStrings_ConCat (DynamicStrings_String a, DynamicStrings_String b)
{
  DynamicStrings_String t;

  if (PoisonOn)
    {
      a = CheckPoisoned (a);
      b = CheckPoisoned (b);
    }
  if (a == b)
    return DynamicStrings_ConCat (a, DynamicStrings_Mark (DynamicStrings_Dup (b)));
  else if (a != NULL)
    {
      a = AddToGarbage (a, b);
      MarkInvalid (a);
      t = a;
      while (b != NULL)
        {
          while ((t->contents.len == MaxBuf) && (t->contents.next != NULL))
            t = t->contents.next;
          ConcatContents (&t->contents, (char *) &b->contents.buf.array[0], (MaxBuf-1), b->contents.len, 0);
          b = b->contents.next;
        }
    }
  if ((a == NULL) && (b != NULL))
    M2RTS_HALT (-1);
  return a;
}


/*
   ConCatChar - returns String, a, after character, ch, has been appended.
*/

DynamicStrings_String DynamicStrings_ConCatChar (DynamicStrings_String a, char ch)
{
  typedef struct _T3_a _T3;

  struct _T3_a { char array[1+1]; };
  _T3 b;
  DynamicStrings_String t;

  if (PoisonOn)
    a = CheckPoisoned (a);
  b.array[0] = ch;
  b.array[1] = ASCII_nul;
  t = a;
  MarkInvalid (a);
  while ((t->contents.len == MaxBuf) && (t->contents.next != NULL))
    t = t->contents.next;
  ConcatContents (&t->contents, (char *) &b.array[0], 1, 1, 0);
  return a;
}


/*
   Assign - assigns the contents of, b, into, a.
            String, a, is returned.
*/

DynamicStrings_String DynamicStrings_Assign (DynamicStrings_String a, DynamicStrings_String b)
{
  if (PoisonOn)
    {
      a = CheckPoisoned (a);
      b = CheckPoisoned (b);
    }
  if ((a != NULL) && (b != NULL))
    {
      a->contents.next = DynamicStrings_KillString (a->contents.next);
      a->contents.len = 0;
    }
  return DynamicStrings_ConCat (a, b);
}


/*
   Dup - duplicate a String, s, returning the copy of s.
*/

DynamicStrings_String DynamicStrings_Dup (DynamicStrings_String s)
{
  if (PoisonOn)
    s = CheckPoisoned (s);
  s = DynamicStrings_Assign (DynamicStrings_InitString ((char *) "", 0), s);
  if (TraceOn)
    s = AssignDebug (s, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1152, (char *) "Dup", 3);
  return s;
}


/*
   Add - returns a new String which contains the contents of a and b.
*/

DynamicStrings_String DynamicStrings_Add (DynamicStrings_String a, DynamicStrings_String b)
{
  if (PoisonOn)
    {
      a = CheckPoisoned (a);
      b = CheckPoisoned (b);
    }
  a = DynamicStrings_ConCat (DynamicStrings_ConCat (DynamicStrings_InitString ((char *) "", 0), a), b);
  if (TraceOn)
    a = AssignDebug (a, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1172, (char *) "Add", 3);
  return a;
}


/*
   Equal - returns TRUE if String, a, and, b, are equal.
*/

unsigned int DynamicStrings_Equal (DynamicStrings_String a, DynamicStrings_String b)
{
  unsigned int i;

  if (PoisonOn)
    {
      a = CheckPoisoned (a);
      b = CheckPoisoned (b);
    }
  if ((DynamicStrings_Length (a)) == (DynamicStrings_Length (b)))
    {
      while ((a != NULL) && (b != NULL))
        {
          i = 0;
          Assertion_Assert (a->contents.len == b->contents.len);
          while (i < a->contents.len)
            {
              if (a->contents.buf.array[i] != a->contents.buf.array[i])
                M2RTS_HALT (-1);
              if (b->contents.buf.array[i] != b->contents.buf.array[i])
                M2RTS_HALT (-1);
              if (a->contents.buf.array[i] != b->contents.buf.array[i])
                return FALSE;
              i += 1;
            }
          a = a->contents.next;
          b = b->contents.next;
        }
      return TRUE;
    }
  else
    return FALSE;
}


/*
   EqualCharStar - returns TRUE if contents of String, s, is the same as the
                   string, a.
*/

unsigned int DynamicStrings_EqualCharStar (DynamicStrings_String s, void * a)
{
  DynamicStrings_String t;

  if (PoisonOn)
    s = CheckPoisoned (s);
  t = DynamicStrings_InitStringCharStar (a);
  if (TraceOn)
    t = AssignDebug (t, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1237, (char *) "EqualCharStar", 13);
  t = AddToGarbage (t, s);
  if (DynamicStrings_Equal (t, s))
    {
      t = DynamicStrings_KillString (t);
      return TRUE;
    }
  else
    {
      t = DynamicStrings_KillString (t);
      return FALSE;
    }
}


/*
   EqualArray - returns TRUE if contents of String, s, is the same as the
                string, a.
*/

unsigned int DynamicStrings_EqualArray (DynamicStrings_String s, char *a_, unsigned int _a_high)
{
  DynamicStrings_String t;
  char a[_a_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (a, a_, _a_high+1);

  if (PoisonOn)
    s = CheckPoisoned (s);
  t = DynamicStrings_InitString ((char *) a, _a_high);
  if (TraceOn)
    t = AssignDebug (t, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1267, (char *) "EqualArray", 10);
  t = AddToGarbage (t, s);
  if (DynamicStrings_Equal (t, s))
    {
      t = DynamicStrings_KillString (t);
      return TRUE;
    }
  else
    {
      t = DynamicStrings_KillString (t);
      return FALSE;
    }
}


/*
   Mult - returns a new string which is n concatenations of String, s.
*/

DynamicStrings_String DynamicStrings_Mult (DynamicStrings_String s, unsigned int n)
{
  if (PoisonOn)
    s = CheckPoisoned (s);
  if (n <= 0)
    s = AddToGarbage (DynamicStrings_InitString ((char *) "", 0), s);
  else
    s = DynamicStrings_ConCat (DynamicStrings_Mult (s, n-1), s);
  if (TraceOn)
    s = AssignDebug (s, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1299, (char *) "Mult", 4);
  return s;
}


/*
   Slice - returns a new string which contains the elements
           low..high-1

           strings start at element 0
           Slice(s, 0, 2)  will return elements 0, 1 but not 2
           Slice(s, 1, 3)  will return elements 1, 2 but not 3
           Slice(s, 2, 0)  will return elements 2..max
           Slice(s, 3, -1) will return elements 3..max-1
           Slice(s, 4, -2) will return elements 4..max-2
*/

DynamicStrings_String DynamicStrings_Slice (DynamicStrings_String s, int low, int high)
{
  DynamicStrings_String d;
  DynamicStrings_String t;
  int start;
  int end;
  int o;

  if (PoisonOn)
    s = CheckPoisoned (s);
  if (low < 0)
    low = ((int ) (DynamicStrings_Length (s)))+low;
  if (high <= 0)
    high = ((int ) (DynamicStrings_Length (s)))+high;
  else
    /* make sure high is <= Length (s)  */
    high = Min (DynamicStrings_Length (s), (unsigned int) high);
  d = DynamicStrings_InitString ((char *) "", 0);
  d = AddToGarbage (d, s);
  o = 0;
  t = d;
  while (s != NULL)
    if (low < (o+((int ) (s->contents.len))))
      if (o > high)
        s = NULL;
      else
        {
          /* found sliceable unit  */
          if (low < o)
            start = 0;
          else
            start = low-o;
          end = Max (Min (MaxBuf, (unsigned int) high-o), 0);
          while (t->contents.len == MaxBuf)
            {
              if (t->contents.next == NULL)
                {
                  Storage_ALLOCATE ((void **) &t->contents.next, sizeof (stringRecord));
                  t->contents.next->head = NULL;
                  t->contents.next->contents.len = 0;
                  AddDebugInfo (t->contents.next);
                  if (TraceOn)
                    t->contents.next = AssignDebug (t->contents.next, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1367, (char *) "Slice", 5);
                }
              t = t->contents.next;
            }
          ConcatContentsAddress (&t->contents, &s->contents.buf.array[start], (unsigned int) end-start);
          o += s->contents.len;
          s = s->contents.next;
        }
    else
      {
        o += s->contents.len;
        s = s->contents.next;
      }
  if (TraceOn)
    d = AssignDebug (d, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1384, (char *) "Slice", 5);
  return d;
}


/*
   Index - returns the indice of the first occurance of, ch, in
           String, s. -1 is returned if, ch, does not exist.
           The search starts at position, o.
*/

int DynamicStrings_Index (DynamicStrings_String s, char ch, unsigned int o)
{
  unsigned int i;
  unsigned int k;

  if (PoisonOn)
    s = CheckPoisoned (s);
  k = 0;
  while (s != NULL)
    {
      if ((k+s->contents.len) < o)
        k += s->contents.len;
      else
        {
          i = o-k;
          while (i < s->contents.len)
            {
              if (s->contents.buf.array[i] == ch)
                return k+i;
              i += 1;
            }
          k += i;
          o = k;
        }
      s = s->contents.next;
    }
  return -1;
}


/*
   RIndex - returns the indice of the last occurance of, ch,
            in String, s. The search starts at position, o.
            -1 is returned if, ch, is not found.
*/

int DynamicStrings_RIndex (DynamicStrings_String s, char ch, unsigned int o)
{
  unsigned int i;
  unsigned int k;
  int j;

  if (PoisonOn)
    s = CheckPoisoned (s);
  j = -1;
  k = 0;
  while (s != NULL)
    {
      if ((k+s->contents.len) < o)
        k += s->contents.len;
      else
        {
          if (o < k)
            i = 0;
          else
            i = o-k;
          while (i < s->contents.len)
            {
              if (s->contents.buf.array[i] == ch)
                j = k;
              k += 1;
              i += 1;
            }
        }
      s = s->contents.next;
    }
  return j;
}


/*
   RemoveComment - assuming that, comment, is a comment delimiter
                   which indicates anything to its right is a comment
                   then strip off the comment and also any white space
                   on the remaining right hand side.
                   It leaves any white space on the left hand side alone.
*/

DynamicStrings_String DynamicStrings_RemoveComment (DynamicStrings_String s, char comment)
{
  int i;

  i = DynamicStrings_Index (s, comment, 0);
  if (i == 0)
    s = DynamicStrings_InitString ((char *) "", 0);
  else if (i > 0)
    s = DynamicStrings_RemoveWhitePostfix (DynamicStrings_Slice (DynamicStrings_Mark (s), 0, i));
  if (TraceOn)
    s = AssignDebug (s, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1496, (char *) "RemoveComment", 13);
  return s;
}


/*
   RemoveWhitePrefix - removes any leading white space from String, s.
                       A new string is returned.
*/

DynamicStrings_String DynamicStrings_RemoveWhitePrefix (DynamicStrings_String s)
{
  unsigned int i;

  i = 0;
  while (IsWhite (DynamicStrings_char (s, (int) i)))
    i += 1;
  s = DynamicStrings_Slice (s, (int ) (i), 0);
  if (TraceOn)
    s = AssignDebug (s, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1608, (char *) "RemoveWhitePrefix", 17);
  return s;
}


/*
   RemoveWhitePostfix - removes any leading white space from String, s.
                        A new string is returned.
*/

DynamicStrings_String DynamicStrings_RemoveWhitePostfix (DynamicStrings_String s)
{
  int i;

  i = ((int ) (DynamicStrings_Length (s)))-1;
  while ((i >= 0) && (IsWhite (DynamicStrings_char (s, i))))
    i -= 1;
  s = DynamicStrings_Slice (s, 0, i+1);
  if (TraceOn)
    s = AssignDebug (s, (char *) "/home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/DynamicStrings.mod", 73, 1630, (char *) "RemoveWhitePostfix", 18);
  return s;
}


/*
   ToUpper - returns string, s, after it has had its lower case characters
             replaced by upper case characters.
             The string, s, is not duplicated.
*/

DynamicStrings_String DynamicStrings_ToUpper (DynamicStrings_String s)
{
  char ch;
  unsigned int i;
  DynamicStrings_String t;

  if (s != NULL)
    {
      MarkInvalid (s);
      t = s;
      while (t != NULL)
        {
          i = 0;
          while (i < t->contents.len)
            {
              ch = t->contents.buf.array[i];
              if ((ch >= 'a') && (ch <= 'z'))
                t->contents.buf.array[i] = (char) ((((unsigned int) (ch))-((unsigned int) ('a')))+((unsigned int) ('A')));
              i += 1;
            }
          t = t->contents.next;
        }
    }
  return s;
}


/*
   ToLower - returns string, s, after it has had its upper case characters
             replaced by lower case characters.
             The string, s, is not duplicated.
*/

DynamicStrings_String DynamicStrings_ToLower (DynamicStrings_String s)
{
  char ch;
  unsigned int i;
  DynamicStrings_String t;

  if (s != NULL)
    {
      MarkInvalid (s);
      t = s;
      while (t != NULL)
        {
          i = 0;
          while (i < t->contents.len)
            {
              ch = t->contents.buf.array[i];
              if ((ch >= 'A') && (ch <= 'Z'))
                t->contents.buf.array[i] = (char) ((((unsigned int) (ch))-((unsigned int) ('A')))+((unsigned int) ('a')));
              i += 1;
            }
          t = t->contents.next;
        }
    }
  return s;
}


/*
   CopyOut - copies string, s, to a.
*/

void DynamicStrings_CopyOut (char *a, unsigned int _a_high, DynamicStrings_String s)
{
  unsigned int i;
  unsigned int l;

  l = Min ((_a_high)+1, DynamicStrings_Length (s));
  i = 0;
  while (i < l)
    {
      a[i] = DynamicStrings_char (s, (int) i);
      i += 1;
    }
  if (i <= (_a_high))
    a[i] = ASCII_nul;
}


/*
   char - returns the character, ch, at position, i, in String, s.
*/

char DynamicStrings_char (DynamicStrings_String s, int i)
{
  unsigned int c;

  if (PoisonOn)
    s = CheckPoisoned (s);
  if (i < 0)
    c = (unsigned int ) (((int ) (DynamicStrings_Length (s)))+i);
  else
    c = i;
  while ((s != NULL) && (c >= s->contents.len))
    {
      c -= s->contents.len;
      s = s->contents.next;
    }
  if ((s == NULL) || (c >= s->contents.len))
    return ASCII_nul;
  else
    return s->contents.buf.array[c];
}


/*
   string - returns the C style char * of String, s.
*/

void * DynamicStrings_string (DynamicStrings_String s)
{
  DynamicStrings_String a;
  unsigned int l;
  unsigned int i;
  char * p;

  if (PoisonOn)
    s = CheckPoisoned (s);
  if (s == NULL)
    return NULL;
  else
    {
      if (! s->head->charStarValid)
        {
          l = DynamicStrings_Length (s);
          if (! (s->head->charStarUsed && (s->head->charStarSize > l)))
            {
              DeallocateCharStar (s);
              Storage_ALLOCATE (&s->head->charStar, l+1);
              s->head->charStarSize = l+1;
              s->head->charStarUsed = TRUE;
            }
          p = s->head->charStar;
          a = s;
          while (a != NULL)
            {
              i = 0;
              while (i < a->contents.len)
                {
                  (*p) = a->contents.buf.array[i];
                  i += 1;
                  p += 1;
                }
              a = a->contents.next;
            }
          (*p) = ASCII_nul;
          s->head->charStarValid = TRUE;
        }
      return s->head->charStar;
    }
}


/*
   InitStringDB - the debug version of InitString.
*/

DynamicStrings_String DynamicStrings_InitStringDB (char *a_, unsigned int _a_high, char *file_, unsigned int _file_high, unsigned int line)
{
  char a[_a_high+1];
  char file[_file_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (a, a_, _a_high+1);
  memcpy (file, file_, _file_high+1);

  return AssignDebug (DynamicStrings_InitString ((char *) a, _a_high), (char *) file, _file_high, line, (char *) "InitString", 10);
}


/*
   InitStringCharStarDB - the debug version of InitStringCharStar.
*/

DynamicStrings_String DynamicStrings_InitStringCharStarDB (void * a, char *file_, unsigned int _file_high, unsigned int line)
{
  char file[_file_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (file, file_, _file_high+1);

  return AssignDebug (DynamicStrings_InitStringCharStar (a), (char *) file, _file_high, line, (char *) "InitStringCharStar", 18);
}


/*
   InitStringCharDB - the debug version of InitStringChar.
*/

DynamicStrings_String DynamicStrings_InitStringCharDB (char ch, char *file_, unsigned int _file_high, unsigned int line)
{
  char file[_file_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (file, file_, _file_high+1);

  return AssignDebug (DynamicStrings_InitStringChar (ch), (char *) file, _file_high, line, (char *) "InitStringChar", 14);
}


/*
   MultDB - the debug version of MultDB.
*/

DynamicStrings_String DynamicStrings_MultDB (DynamicStrings_String s, unsigned int n, char *file_, unsigned int _file_high, unsigned int line)
{
  char file[_file_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (file, file_, _file_high+1);

  return AssignDebug (DynamicStrings_Mult (s, n), (char *) file, _file_high, line, (char *) "Mult", 4);
}


/*
   DupDB - the debug version of Dup.
*/

DynamicStrings_String DynamicStrings_DupDB (DynamicStrings_String s, char *file_, unsigned int _file_high, unsigned int line)
{
  char file[_file_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (file, file_, _file_high+1);

  return AssignDebug (DynamicStrings_Dup (s), (char *) file, _file_high, line, (char *) "Dup", 3);
}


/*
   SliceDB - debug version of Slice.
*/

DynamicStrings_String DynamicStrings_SliceDB (DynamicStrings_String s, int low, int high, char *file_, unsigned int _file_high, unsigned int line)
{
  char file[_file_high+1];

  /* make a local copy of each unbounded array.  */
  memcpy (file, file_, _file_high+1);

  DSdbEnter ();
  s = AssignDebug (DynamicStrings_Slice (s, low, high), (char *) file, _file_high, line, (char *) "Slice", 5);
  DSdbExit (s);
  return s;
}


/*
   PushAllocation - pushes the current allocation/deallocation lists.
*/

void DynamicStrings_PushAllocation (void)
{
  frame f;

  if (CheckOn)
    {
      Init ();
      Storage_ALLOCATE ((void **) &f, sizeof (frameRec));
      f->next = frameHead;
      f->alloc = NULL;
      f->dealloc = NULL;
      frameHead = f;
    }
}


/*
   PopAllocation - test to see that all strings are deallocated since
                   the last push.  Then it pops to the previous
                   allocation/deallocation lists.

                   If halt is true then the application terminates
                   with an exit code of 1.
*/

void DynamicStrings_PopAllocation (unsigned int halt)
{
  if ((DynamicStrings_PopAllocationExemption (halt, (DynamicStrings_String) NULL)) == NULL)
    {}  /* empty.  */
}


/*
   PopAllocationExemption - test to see that all strings are deallocated, except
                            string, e, since the last push.
                            Then it pops to the previous allocation/deallocation
                            lists.

                            If halt is true then the application terminates
                            with an exit code of 1.
*/

DynamicStrings_String DynamicStrings_PopAllocationExemption (unsigned int halt, DynamicStrings_String e)
{
  DynamicStrings_String s;
  frame f;
  unsigned int b;

  Init ();
  if (frameHead == NULL)
    writeString ((char *) "mismatched number of PopAllocation's compared to PushAllocation's", 65);
  else
    {
      if (frameHead->alloc != NULL)
        {
          b = FALSE;
          s = frameHead->alloc;
          while (s != NULL)
            {
              if (! (((e == s) || (IsOnGarbage (e, s))) || (IsOnGarbage (s, e))))
                {
                  if (! b)
                    {
                      writeString ((char *) "the following strings have been lost", 36);
                      writeLn ();
                      b = TRUE;
                    }
                  DumpStringInfo (s, 0);
                }
              s = s->debug.next;
            }
          if (b && halt)
            libc_exit (1);
        }
      frameHead = frameHead->next;
    }
  return e;
}

void _M2_DynamicStrings_init (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
  Initialized = FALSE;
  Init ();
}

void _M2_DynamicStrings_finish (__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
}
