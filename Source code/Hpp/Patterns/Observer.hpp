#pragma once

//#include <variant>

class Key;
//class Timer;

class Observer
{
    public:
        
        virtual void notification( Key event ) = 0;

        //virtual void notification( std::variant<Key,Timer> event ) = 0;

        virtual ~Observer() {} 
        // base class destructor required with
        // other virtual methods.
};
