#pragma once

#include "Source code/Hpp/Custom types.hpp"

#include "Source code/Hpp/Input/HID/HID_Globals.hpp"
#include "Source code/Hpp/Input/HID/HID_Collection.hpp"

#include <vector>
#include <hidpi.h>

namespace HID
{
    class Device;

    class Collections
    {
        private:

            // collection of same device items 
            std::vector< Collection > collections;

            //float spacer { 120.0f };

        public:

            void add( _HIDP_LINK_COLLECTION_NODE * in_nodes , uint in_size );
            void positions( Device const & in_device );

            void add_buttons( Device * in_device , Report_type in_type , _HIDP_BUTTON_CAPS * in_buttons , uint in_size );
            void add_values( Device * in_device , Report_type in_type , _HIDP_VALUE_CAPS * in_value , uint in_size );

            uint contact_amount_maximum();
            //uint get_contact_identifier();
            //uint get_x();
            //uint get_y();
            Range resolution();

            void update( RAWINPUT * in_raw_data )
            //void update( RAWHID in_raw_data )
            {
                for( auto & collection : collections ) collection.update( in_raw_data );
            }

            void draw()
            {
                for( auto & collection : collections ) collection.draw();
            }
    };
}
