#ifndef _BUFFER_STATE_HPP_
#define _BUFFER_STATE_HPP_

#include "module.hpp"
#include "flit.hpp"
#include "credit.hpp"
#include "config_utils.hpp"

class BufferState : public Module {

   int  _wait_for_tail_credit;
   int  _buf_size;
   int  _vcs;

   int  _last_avail;

   bool *_in_use;
   bool *_tail_sent;
   int  *_cur_occupied;

   void _Init( const Configuration& config, int seperate_network_ratio, int uid );

public:
    BufferState() : Module( ) {}
   void init( const Configuration& config, int seperate_network_ratio, int net_num );
   BufferState( const Configuration& config, 
                Module *parent, const string& name, int seperate_network_ratio, int uid );
   ~BufferState( );

   void ProcessCredit( Credit *c );
   void SendingFlit( Flit *f );

   void TakeBuffer( int vc = 0 );

   bool IsFullFor( int vc = 0 ) const;
   bool IsAvailableFor( int vc = 0 ) const;

   int FindAvailable( Flit *f );

   void Display( ) const;
};

#endif 
