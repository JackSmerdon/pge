/* Gerrno.c provides access to errno for Modula-2.

Copyright (C) 2016-2018 Free Software Foundation, Inc.
Contributed by Gaius Mulley <gaius@glam.ac.uk>.

This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GNU Modula-2 is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Modula-2; see the file COPYING.  If not, write to the
Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301, USA.  */

#include <errno.h>

/* geterrno returns errno.  */

int
errno_geterrno (void)
{
  return errno;
}

/* init constructor for the module.  */

void
_M2_errno_init (int argc, char *p)
{
}

/* finish deconstructor for the module.  */

void
_M2_errno_finish (int argc, char *p)
{
}
