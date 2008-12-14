#include "Worker_i.h"

Worker_i::Worker_i (CORBA::ORB_ptr orb,
                    PortableServer::POA_ptr poa,
                    const std::string & object_id,
                    StateSynchronizationAgent_ptr agent)
  : orb_ (CORBA::ORB::_duplicate (orb)),
    poa_ (PortableServer::POA::_duplicate (poa)),
    object_id_ (object_id),
    agent_ (StateSynchronizationAgent::_duplicate (agent)),
    state_ (0),
    suicidal_count_ (0)
{
}

void
Worker_i::run_task (CORBA::Double execution_time)
{
  this->cpu_.run (static_cast <size_t> (execution_time));

  ++state_;

  if ((suicidal_count_ > 0) && (state_ > suicidal_count_))
    {
      std::cerr << "Worker_i::run_task commits suicide after "
                << state_ << " invocations." << std::endl;
      ACE_OS::exit (1);
    }

  agent_->state_changed (object_id_.c_str ());
}

void
Worker_i::set_state (const CORBA::Any & state_value)
{
  // extract value to an intermediate long variable since it's not possible
  // to extract to a long & directly
  CORBA::Long value;

  if (state_value >>= value)
    state_ = value;
  else
    ACE_DEBUG ((LM_WARNING,
                "Worker_i::set_state () "
                "could not extract state value from Any."));

  ACE_DEBUG ((LM_TRACE, "Worker_i::set_state (%d) called.\n", value));
}

CORBA::Any *
Worker_i::get_state ()
{
  // create new any object
  CORBA::Any_var state (new CORBA::Any);
  
  // create intermediate object with the value
  CORBA::Long value = state_;

  ACE_DEBUG ((LM_DEBUG, "Worker_i::get_state returns %d.\n", value));

  // insert value into the any object
  *state <<= value;

  return state._retn ();
}

StateSynchronizationAgent_ptr
Worker_i::agent (void)
{
  return StateSynchronizationAgent::_duplicate (agent_.in ());
}
  
void
Worker_i::agent (StateSynchronizationAgent_ptr agent)
{
  agent_ = agent;
}
  
char *
Worker_i::object_id (void)
{
  return CORBA::string_dup (object_id_.c_str ());
}
  
void
Worker_i::object_id (const char * object_id)
{
  object_id_ = object_id;
}

