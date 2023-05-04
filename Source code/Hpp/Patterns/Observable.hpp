#pragma once

#include <vector>
#include <variant>

#include "Observer.hpp"

class Observable
{
    public:

        void add_observer( Observer * observer )
        {
            observers.push_back( observer );
        }

        void remove_observer( Observer * observer )
        {
            for( auto itr = observers.begin() ; itr != observers.end() ; itr++ )
            {
                if( *itr == observer )
                {
                    observers.erase( itr );

                    break;
                } 
            }
        }

    private:

        // TODO: change to unorded_set
        std::vector< Observer * > observers;

    protected:

        //void notify( std::variant<Key, Timer> event )

        void notify( Key event )
        {
            for( auto * observer : observers )
            {
                observer->notification( event );
            }
        }
};