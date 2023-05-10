#include "Source code/Hpp/Input/HID/HID_Collections.hpp"

#include "Source code/Hpp/Input/HID/HID_Device.hpp"
#include "Source code/Hpp/Input/HID/HID_Item.hpp"

namespace HID
{
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

    void Collections::add_values( Device * const in_device , item_type in_type , _HIDP_VALUE_CAPS * in_values , uint in_size )
    {
        for( uint index{ 0 }; index < in_size; index++ )
        {
            uint       collection_index = in_values[ index ].LinkCollection;
            Value  value( in_device , in_values[ index ] );

            switch( in_type )
            {
                case item_type::input:
                {
                    collections.at( collection_index ).add_value( in_type , value );
                } break;

                case item_type::output:
                {
                    collections.at( collection_index ).add_value( in_type , value );
                } break;

                case item_type::feature:
                {
                    collections.at( collection_index ).add_value( in_type , value );
                }
            }
        }
    }

    void Collections::add( _HIDP_LINK_COLLECTION_NODE * in_nodes , uint in_size )
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

    void Collections::positions( Device const & device )
    {
        RECT client_size = locate::get_windows().get_client_rectangle();
        
        float spacer_y = static_cast< float >( client_size.bottom ) - device.bottom();

        spacer_y -= collections.front().height() * collections.size();
        spacer_y /=  collections.size() + 1 ;

        Point collection_position // spacing = screen_height - device_text.bottom / collection_amount
        {
            device.left() ,
            device.bottom() + 60.0f// + spacer_y
        };

        auto collection_itr = collections.begin();

        for( ; collection_itr < collections.end() ; collection_itr++ )
        {
            collection_itr->position( collection_position );

            collection_position.y += 160;//spacer_y; // search all collections for highest text bottom

            collection_itr->positions();
        }
    }
    
    uint Collections::contact_amount_maximum()
    {
        uint amount { 0 };

        for( auto & collection : collections )
        {
            //amount = collection.get_contact_amount_maximum();
            break;
        }

        return amount;
    }

    Range Collections::resolution()
    {
        Range touchpad_resolution {};
        Range values;

        for( auto & collection : collections )
        {
            touchpad_resolution.minimum = collection.range( 0x01 , 0x30 , Report_type::input , Item_type::logical ).maximum;
            touchpad_resolution.maximum = collection.range( 0x01 , 0x31 , Report_type::input , Item_type::logical ).maximum;

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
