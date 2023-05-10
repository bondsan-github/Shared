#pragma once

#include "Source code/Hpp/Custom types.hpp"

#include "Source code/Hpp/Graphics/DWrite/Text.hpp"
#include "Source code/Hpp/Input/HID/HID_Usages.hpp"

#include <hidpi.h>
#include <string>

namespace HID
{
    class Device;

    class Value : public _HIDP_VALUE_CAPS , public Usages
    {
        private:
            
            Text         information {};
            std::wstring content {};
            ulong        value_unsigned { 0ul }; // = 0xffff'ffff
            long         value_signed { -1 };

            Device * device {};

        public:

            Value( Device * const in_device , _HIDP_VALUE_CAPS const & construct_value );

            void  position( Point const & in_position ) { information.position( in_position ); }
            void  append( std::wstring in_text ) { information.add( in_text ); }

            float right() const { return information.right(); }
            float top()   const { return information.top(); }

            void  update( RAWINPUT * in_raw_data );
            void  collect_information();
            void  update_information();

            //hid_device * get_device() const { return device; }
            long  get_value() const { return value_signed; }

            void  draw() { information.draw(); }
    };
}