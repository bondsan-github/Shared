#pragma once


#include "Custom types.hpp"
#include "Keys.hpp"
#include "Observable.hpp"

#include <string>
#include <map>

class Application;

class Input : public Observable
{
    private:

        Application & application;

    public:

        Input( Application & application );

        void on_key_pressed( uint windows_code );        
};






