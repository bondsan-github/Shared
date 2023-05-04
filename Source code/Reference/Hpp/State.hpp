#pragma once

#include <memory>



class State abstract
{
	public:

        //virtual ~State() {};
		//virtual void input( Type & in_actor , const int in_input ) {};
		//virtual State std::unique_ptr< Type > update( Type & in_actor , const double & time_delta ) = 0;
        virtual void update() = 0 {}
        //virtual void input( Type & in_actor , Command command );
	//private:
};

//template< typename Type >

