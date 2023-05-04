#pragma once

#include "Observer.hpp"

class State : public Observer
{
	public:
    
        virtual State * update( double time_delta ) = 0;
        
        virtual void render() = 0;

        //virtual ~State() {} 
        // the class State implicitly has a virtual destructor because
        // the base class Observer has a virtual destructor.
};


