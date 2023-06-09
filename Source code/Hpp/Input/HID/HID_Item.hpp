﻿#pragma once

#include "Source code/Hpp/Custom types.hpp"

#include <vector>
#include <string>

namespace HID
{
    enum class Item_type : unsigned long
    {
        undefined          , // 0x00
        physical           , // 0x01
        application        , // 0x02
        logical            , // 0x03
        report             , // 0x04
        named_array        , // 0x05
        usage_switch       , // 0x06
        usage_modifier     , // 0x07
        reserved_start     , //
        // ...
        reserved_end       , // 0x7F
        device             , // 0x80 // vendor_defined_start , // 0x80
        // ...
        vendor_defined_end , // 0xFF ,
    };

    // HID Usage Tables FOR Universal Serial Bus( USB ) Version 1.3
    // usb.org/sites/default/files/hut1_3_0.pdf
    const std::vector< std::wstring > Item_type_text
    {
        L"undefined"          , //
        L"physical"           , //
        L"application"        , // 
        L"logical"            , // 
        L"report"             , //
        L"named array"        , //
        L"usage switch"       , //
        L"usage modifier"     , //
        L"reserved start"     , //
        L"reserved end"       , //
        L"device"             , //
        L"vendor defined end" , //
    };

    //using link = vector< item >::const_reference;
    //using link = ushort;
    //using ⛓   = link;
    
    /*
    struct hid_range
    {
        long begin { 0 };
        long end   { 0 };
    };
    */

    //using index      = ushort;
    //using identifier = index; // ♈♉♊♋♌♍♎♏♐♑♒♓

    struct Limits
    {
        long minimum { 0 };
        long maximum { 0 };
    };
    
} // namespace hid
