// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.7
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1216

#ifndef CIAO_DDS_PUB_EXEC_MKL1YH_H_
#define CIAO_DDS_PUB_EXEC_MKL1YH_H_

#include /**/ "ace/pre.h"

#include "DDS_PubEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "DDS_Pub_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_DDS_Pub_Impl
{
  class DDS_PUB_EXEC_Export DDS_Pub_exec_i
    : public virtual DDS_Pub_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    DDS_Pub_exec_i (void);
    virtual ~DDS_Pub_exec_i (void);
    
    //@{
    /** Supported operations and attributes. */
    
    //@}
    
    //@{
    /** Component attributes and port operations. */
    
    //@}
    
    //@{
    /** Operations from Components::SessionComponent. */
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}
    
  
  private:
    ::CCM_DDS_Pub_Context_var context_;
  };
  
  extern "C" DDS_PUB_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_DDS_Pub_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

