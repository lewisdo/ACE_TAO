// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_poll.h
 *
 *  $Id$
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_POLL_H
# define ACE_OS_NS_POLL_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_poll.h"

class ACE_Time_Value;

namespace ACE_OS {

  int poll (struct pollfd *pollfds,
            unsigned long len,
            const ACE_Time_Value *tv = 0);
  int poll (struct pollfd *pollfds,
            unsigned long len,
            const ACE_Time_Value &tv);

} /* namespace ACE_OS */

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_poll.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_POLL_H */
