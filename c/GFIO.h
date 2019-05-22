/* automatically created by mc from /home/gaius/GM2/graft-8.2.0/gcc-8.2.0/gcc/gm2/gm2-libs/FIO.def.  */


#if !defined (_FIO_H)
#   define _FIO_H

#   ifdef __cplusplus
extern "C" {
#   endif
#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#   include "GSYSTEM.h"

#   if defined (_FIO_C)
#      define EXTERN
#   else
#      define EXTERN extern
#   endif

typedef unsigned int FIO_File;

EXTERN FIO_File FIO_StdIn;
EXTERN FIO_File FIO_StdOut;
EXTERN FIO_File FIO_StdErr;

/*
   IsNoError - returns a TRUE if no error has occured on file, f.
*/

EXTERN unsigned int FIO_IsNoError (FIO_File f);

/*
   IsActive - returns TRUE if the file, f, is still active.
*/

EXTERN unsigned int FIO_IsActive (FIO_File f);

/*
   Exists - returns TRUE if a file named, fname exists for reading.
*/

EXTERN unsigned int FIO_Exists (char *fname_, unsigned int _fname_high);

/*
   OpenToRead - attempts to open a file, fname, for reading and
                it returns this file.
                The success of this operation can be checked by
                calling IsNoError.
*/

EXTERN FIO_File FIO_OpenToRead (char *fname_, unsigned int _fname_high);

/*
   OpenToWrite - attempts to open a file, fname, for write and
                 it returns this file.
                 The success of this operation can be checked by
                 calling IsNoError.
*/

EXTERN FIO_File FIO_OpenToWrite (char *fname_, unsigned int _fname_high);

/*
   OpenForRandom - attempts to open a file, fname, for random access
                   read or write and it returns this file.
                   The success of this operation can be checked by
                   calling IsNoError.
                   towrite, determines whether the file should be
                   opened for writing or reading.
                   newfile, determines whether a file should be created
                   if towrite is TRUE or whether the previous file should
                   be left alone, allowing this descriptor to seek
                   and modify an existing file.
*/

EXTERN FIO_File FIO_OpenForRandom (char *fname_, unsigned int _fname_high, unsigned int towrite, unsigned int newfile);

/*
   Close - close a file which has been previously opened using:
           OpenToRead, OpenToWrite, OpenForRandom.
           It is correct to close a file which has an error status.
*/

EXTERN void FIO_Close (FIO_File f);
EXTERN unsigned int FIO_exists (void * fname, unsigned int flength);
EXTERN FIO_File FIO_openToRead (void * fname, unsigned int flength);
EXTERN FIO_File FIO_openToWrite (void * fname, unsigned int flength);
EXTERN FIO_File FIO_openForRandom (void * fname, unsigned int flength, unsigned int towrite, unsigned int newfile);

/*
   FlushBuffer - flush contents of the FIO file, f, to libc.
*/

EXTERN void FIO_FlushBuffer (FIO_File f);

/*
   ReadNBytes - reads nBytes of a file into memory area, a, returning
                the number of bytes actually read.
                This function will consume from the buffer and then
                perform direct libc reads. It is ideal for large reads.
*/

EXTERN unsigned int FIO_ReadNBytes (FIO_File f, unsigned int nBytes, void * a);

/*
   ReadAny - reads HIGH(a) bytes into, a. All input
             is fully buffered, unlike ReadNBytes and thus is more
             suited to small reads.
*/

EXTERN void FIO_ReadAny (FIO_File f, unsigned char *a, unsigned int _a_high);

/*
   WriteNBytes - writes nBytes of a file into memory area, a, returning
                 the number of bytes actually written.
                 This function will flush the buffer and then
                 write the nBytes using a direct write from libc.
                 It is ideal for large writes.
*/

EXTERN unsigned int FIO_WriteNBytes (FIO_File f, unsigned int nBytes, void * a);

/*
   WriteAny - writes HIGH(a) bytes onto, file, f. All output
              is fully buffered, unlike WriteNBytes and thus is more
              suited to small writes.
*/

EXTERN void FIO_WriteAny (FIO_File f, unsigned char *a, unsigned int _a_high);

/*
   WriteChar - writes a single character to file, f.
*/

EXTERN void FIO_WriteChar (FIO_File f, char ch);

/*
   EOF - tests to see whether a file, f, has reached end of file.
*/

EXTERN unsigned int FIO_EOF (FIO_File f);

/*
   EOLN - tests to see whether a file, f, is about to read a newline.
          It does NOT consume the newline.  It reads the next character
          and then immediately unreads the character.
*/

EXTERN unsigned int FIO_EOLN (FIO_File f);

/*
   WasEOLN - tests to see whether a file, f, has just read a newline
             character.
*/

EXTERN unsigned int FIO_WasEOLN (FIO_File f);

/*
   ReadChar - returns a character read from file, f.
              Sensible to check with IsNoError or EOF after calling
              this function.
*/

EXTERN char FIO_ReadChar (FIO_File f);

/*
   UnReadChar - replaces a character, ch, back into file, f.
                This character must have been read by ReadChar
                and it does not allow successive calls.  It may
                only be called if the previous read was successful,
                end of file or end of line seen.
*/

EXTERN void FIO_UnReadChar (FIO_File f, char ch);

/*
   WriteLine - writes out a linefeed to file, f.
*/

EXTERN void FIO_WriteLine (FIO_File f);

/*
   WriteString - writes a string to file, f.
*/

EXTERN void FIO_WriteString (FIO_File f, char *a_, unsigned int _a_high);

/*
   ReadString - reads a string from file, f, into string, a.
                It terminates the string if HIGH is reached or
                if a newline is seen or an error occurs.
*/

EXTERN void FIO_ReadString (FIO_File f, char *a, unsigned int _a_high);

/*
   WriteCardinal - writes a CARDINAL to file, f.
                   It writes the binary image of the CARDINAL.
                   to file, f.
*/

EXTERN void FIO_WriteCardinal (FIO_File f, unsigned int c);

/*
   ReadCardinal - reads a CARDINAL from file, f.
                  It reads a bit image of a CARDINAL
                  from file, f.
*/

EXTERN unsigned int FIO_ReadCardinal (FIO_File f);

/*
   GetUnixFileDescriptor - returns the UNIX file descriptor of a file.
                           Useful when combining FIO.mod with select
                           (in Selective.def - but note the comments in
                            Selective about using read/write primatives)
*/

EXTERN int FIO_GetUnixFileDescriptor (FIO_File f);

/*
   SetPositionFromBeginning - sets the position from the beginning of the file.
*/

EXTERN void FIO_SetPositionFromBeginning (FIO_File f, long int pos);

/*
   SetPositionFromEnd - sets the position from the end of the file.
*/

EXTERN void FIO_SetPositionFromEnd (FIO_File f, long int pos);

/*
   FindPosition - returns the current absolute position in file, f.
*/

EXTERN long int FIO_FindPosition (FIO_File f);

/*
   GetFileName - assigns, a, with the filename associated with, f.
*/

EXTERN void FIO_GetFileName (FIO_File f, char *a, unsigned int _a_high);

/*
   getFileName - returns the address of the filename associated with, f.
*/

EXTERN void * FIO_getFileName (FIO_File f);

/*
   getFileNameLength - returns the number of characters associated with filename, f.
*/

EXTERN unsigned int FIO_getFileNameLength (FIO_File f);

/*
   FlushOutErr - flushes, StdOut, and, StdErr.
*/

EXTERN void FIO_FlushOutErr (void);
#   ifdef __cplusplus
}
#   endif

#   undef EXTERN
#endif
