#include "Source code/Hpp/Input/HID/HID_Collections.hpp"

#include "Source code/Hpp/Input/HID/HID_Device.hpp"
#include "Source code/Hpp/Input/HID/HID_Item.hpp"
#include "Source code/Hpp/Input/HID/HID_Usages.hpp"

#include "Source code/Hpp/Application.hpp"

namespace HID
{
    Collections::Collections( Application & in_application )
    : application { in_application }
    {
    }

    void Collections::add_buttons( Device * in_device , Report_type in_type , _HIDP_BUTTON_CAPS * in_buttons , uint in_size )
    {
        for( uint index{ 0 }; index < in_size; index++ )
        {
            uint   collection_index = in_buttons[ index ].LinkCollection;
            Button button( in_device , in_buttons[ index ] );

            switch( in_type )
            {
                case Report_type::input:
                {
                    collections.at( collection_index ).add_button( in_type , button );
                } break;

                case Report_type::output:
                {
                    collections.at( collection_index ).add_button( in_type , button );
                } break;

                case Report_type::feature:
                {
                    collections.at( collection_index ).add_button( in_type , button );
                } break;

            }
        }
    }

    void Collections::add_values( Device * const in_device , Report_type in_type , _HIDP_VALUE_CAPS * in_values , uint in_size )
    {
        for( uint index{ 0 }; index < in_size; index++ )
        {
            uint       collection_index = in_values[ index ].LinkCollection;
            Value  value( in_device , in_values[ index ] );

            switch( in_type )
            {
                case Report_type::input:
                {
                    collections.at( collection_index ).add_value( in_type , value );
                } break;

                case Report_type::output:
                {
                    collections.at( collection_index ).add_value( in_type , value );
                } break;

                case Report_type::feature:
                {
                    collections.at( collection_index ).add_value( in_type , value );
                }
            }
        }
    }

    void Collections::add_collection( _HIDP_LINK_COLLECTION_NODE * in_nodes , uint in_size )
    {
        collections.resize( in_size );

        uint index{ 0 };

        for( auto & node : collections )
        {
            node = in_nodes[ index ];
            node.collect_information();
            index++;
        }
    }

    void Collections::calculate_positions( Device const & device )
    {
        Size client_size = application.get_client_size();
        
        float spacer_y = static_cast< float >( client_size.height() ) - device.get_bottom();

        spacer_y -= collections.front().get_height() * collections.size();
        spacer_y /=  collections.size() + 1 ;

        Point collection_position // spacing = screen_height - device_text.bottom / collection_amount
        {
            device.get_left() ,
            device.get_bottom() + 60.0f// + spacer_y
        };

        auto collection_itr = collections.begin();

        for( ; collection_itr < collections.end() ; collection_itr++ )
        {
            collection_itr->set_position( collection_position );

            collection_position.y( collection_position.y() + 160) ;//spacer_y; // search all collections for highest text bottom

            collection_itr->calculate_positions();
        }
    }
    
    uint Collections::get_contact_amount()
    {
        uint amount { 0 };

        for( auto & collection : collections )
        {
            //amount = collection.get_contact_amount_maximum();
            break;
        }

        return amount;
    }

    Range Collections::get_resolution()
    {
        Range touchpad_resolution {};
        //Range values {};

        for( auto & collection : collections )
        {
            touchpad_resolution.minimum = collection.get_range( 0x01 , 0x30 , Report_type::input , Item_type::logical ).minimum;
            touchpad_resolution.maximum = collection.get_range( 0x01 , 0x31 , Report_type::input , Item_type::logical ).maximum;

            if( touchpad_resolution.minimum > 0 and touchpad_resolution.maximum > 0 ) break;
        }

        return touchpad_resolution;
    }
    /*
    uint Collections::get_contact_identifier()
    {
        uint amount{ 0 };

        for( auto & collection : collections )
        {
            amount = collection.get_contact_amount();
        }

        return amount;
    }

    uint Collections::get_x()
    {
        uint x { 0 };

        for( auto & collection : collections )
        {
            x = collection.get_x();
        }

        return x;
    }
    */
} // namespace hid
