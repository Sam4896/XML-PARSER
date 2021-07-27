//============================================================================
// Name        : XML_PARSER_SAM.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "xmlParser.h"
#include <cmath>

using namespace std;

/********************************************************************************************************************************************************************************
*********************************************************************************************************************************************************************************

Function definitions for parsing the hdw configuration

    for (const auto &attr_pair : attributes)
    {
        if (!attr_pair.name.compare("nr_tiles"))
            h.NR_TILES = attr_pair.value;

        else if (!attr_pair.name.compare("timely_block"))
            h.TIMELY_BLOCK = attr_pair.value;
    }

    Basic explanation: The for loop iterates over the whole list of the attributes for that element. Then name of the attribute is compared to the name of the one with which we
    want to work. After that the value is passed on to the appropriate variable.

*********************************************************************************************************************************************************************************
*********************************************************************************************************************************************************************************/

hdw_config_class parser::parse_hdw_config(const MySaxParser::AttributeList &attributes)
{
    hdw_config_class h;

    for (const auto &attr_pair : attributes)
    {
        if (!attr_pair.name.compare("nr_tiles"))
            h.NR_TILES = attr_pair.value;

        else if (!attr_pair.name.compare("timely_block"))
        {
        	if (attr_pair.value=="ACTIVE")
        		h.TIMELY_BLOCK = "1";
        	else if (attr_pair.value=="INACTIVE")
        		h.TIMELY_BLOCK = "0";
        }

    }
    return h;
}

string parser::parse_nr_port(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_nr_out_port(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_phaseslice_width_TT(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_phaseslice_width_ET(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_nr_periods_TT(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_nr_periods_ET(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_period_delta_TT(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_period_delta_ET(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_msb_periodbit_TT(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_msb_periodbit_ET(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_period_enable_TT(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

string parser::parse_period_enable_ET(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

/********************************************************************************************************************************************************************************
*********************************************************************************************************************************************************************************

Function definitions for parsing the port configurations

*********************************************************************************************************************************************************************************
*********************************************************************************************************************************************************************************/

p_config_class parser::parse_port_config(const MySaxParser::AttributeList &attributes)
{
    p_config_class p;

    for (const auto &attr_pair : attributes)
    {
        if (!attr_pair.name.compare("id"))
            p.ID = attr_pair.value;

        else if (!attr_pair.name.compare("enable"))
            {
        	if (attr_pair.value=="ENABLE")
            	p.ENABLE = "1";
            else if (attr_pair.value=="DISABLE")
            	p.ENABLE = "0";
            }
    }
    return p;
}
port_specs_class parser::parse_port_specs(const MySaxParser::AttributeList &attributes)
{
    port_specs_class pt;
    for (const auto &attr_pair : attributes)
    {
        if (!attr_pair.name.compare("port_type"))
        {
            if (attr_pair.value == "TT")
                pt.PORT_TYPE = "00";
            else if (attr_pair.value == "RC1")
                pt.PORT_TYPE = "01";
            else if (attr_pair.value == "RC2")
                pt.PORT_TYPE = "10";
            else if (attr_pair.value == "BE")
                pt.PORT_TYPE = "11";
        }
        else if (!attr_pair.name.compare("direction"))
        {
            if (attr_pair.value == "OUT")
                pt.DIRECTION = "0";
            else if (attr_pair.value == "IN")
                pt.DIRECTION = "1";
        }
        else if (!attr_pair.name.compare("semantics"))
        {
            if (attr_pair.value == "STATE")
                pt.SEMANTICS = "0";
            else if (attr_pair.value == "EVENT")
                pt.SEMANTICS = "1";
        }
    }
    pt.combine_port_specs_value_string();
    return pt;
}
string parser::parse_buffer_size(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}
string parser::parse_queue_length(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}
destination_address_class parser::parse_destination_address(const MySaxParser::AttributeList &attributes)
{

    destination_address_class da;

    for (const auto &attr_pair : attributes)
    {
        if (!attr_pair.name.compare("cluster_id"))
            da.CLUSTER_ID = attr_pair.value;
        else if (!attr_pair.name.compare("node_id"))
            da.NODE_ID = attr_pair.value;
        else if (!attr_pair.name.compare("tile_id"))
            da.TILE_ID = attr_pair.value;
        else if (!attr_pair.name.compare("port_id"))
            da.PORT_ID = attr_pair.value;
    }
    da.combine_destination_address();
    return da;
}
string parser::parse_mint(const MySaxParser::AttributeList &attributes)
{
    string s;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("value"))
            s = attr_pair.value;
    return s;
}

port_configs_lrs_class parser::parse_port_configs_lrs(const MySaxParser::AttributeList &attributes)
{
    port_configs_lrs_class p;
    for (const auto &attr_pair : attributes)
        if (!attr_pair.name.compare("name"))
            p.NAME = attr_pair.value;
    return p;
}

/********************************************************************************************************************************************************************************
*********************************************************************************************************************************************************************************
*********************************************************************************************************************************************************************************/

MySaxParser::MySaxParser() : xmlpp::SaxParser() {}

MySaxParser::~MySaxParser() {}

void MySaxParser::on_start_document() {}

void MySaxParser::on_end_document()
{
}

void MySaxParser::on_start_element(const Glib::ustring &name, const AttributeList &attributes)
{
	//function definition to tell what to do when a node or element with a particular name is encountered.
	//the names in the compare() are same as that in the XML file.

    if (!name.compare("hdw_config"))
        hdw = parser::parse_hdw_config(attributes);
    else if (!name.compare("nr_ports"))
        hdw.NR_PORTS.push_back(parser::parse_nr_port(attributes));
    else if (!name.compare("nr_out_ports"))
        hdw.NR_OUT_PORTS.push_back(parser::parse_nr_out_port(attributes));
    else if (!name.compare("phaseslice_width_TT"))
        hdw.PHASELICE_WIDTH_TT = parser::parse_phaseslice_width_TT(attributes);
    else if (!name.compare("phaseslice_width_ET"))
        hdw.PHASELICE_WIDTH_ET = parser::parse_phaseslice_width_ET(attributes);
    else if (!name.compare("nr_periods_TT"))
        hdw.NR_PERIODS_TT = parser::parse_nr_periods_TT(attributes);
    else if (!name.compare("nr_periods_ET"))
        hdw.NR_PERIODS_ET = parser::parse_nr_periods_ET(attributes);
    else if (!name.compare("period_delta_TT"))
        hdw.PERIOD_DELTA_TT = parser::parse_period_delta_TT(attributes);
    else if (!name.compare("period_delta_ET"))
        hdw.PERIOD_DELTA_ET = parser::parse_period_delta_ET(attributes);
    else if (!name.compare("msb_periodbit_TT"))
        hdw.MSB_PERIODBIT_TT = parser::parse_msb_periodbit_TT(attributes);
    else if (!name.compare("msb_periodbit_ET"))
        hdw.MSB_PERIODBIT_ET = parser::parse_msb_periodbit_ET(attributes);
    else if (!name.compare("period_enable_TT"))
        hdw.PERIOD_ENABLE_TT = parser::parse_period_enable_TT(attributes);
    else if (!name.compare("period_enable_ET"))
        hdw.PERIOD_ENABLE_ET = parser::parse_period_enable_TT(attributes);

    else if (!name.compare("port_configs_lrs"))
        ;
    else if (!name.compare("port_config_lrs"))
        pcfg_lrs = parser::parse_port_configs_lrs(attributes);
    else if (!name.compare("p_config"))
        pcfg = parser::parse_port_config(attributes);
    else if (!name.compare("port_specs"))
        pcfg.PORT_SPECS = parser::parse_port_specs(attributes);
    else if (!name.compare("buffer_size"))
        pcfg.BUFFER_SIZE = parser::parse_buffer_size(attributes);
    else if (!name.compare("queue_length"))
        pcfg.QUEUE_LENGTH = parser::parse_queue_length(attributes);
    else if (!name.compare("destination_address"))
        pcfg.DESTINATION_ADDRESS = parser::parse_destination_address(attributes);
    else if (!name.compare("mint"))
        pcfg.MINT = parser::parse_mint(attributes);

    else if ((!name.compare("configuration")))
        ;
    else
        cout << "unresolved:" << name << "\n";
}

void MySaxParser::on_end_element(const Glib::ustring &name)
{
    if (!name.compare("p_config"))
        port_cfgs.push_back(pcfg);
    //Adding one p_config to the port_cfgs vector. Piling up all the port config details in one lrs. This vector later on be passed to port_config_lrs.PORT_CONFIGS

    else if (!name.compare("port_config_lrs"))
    {
        pcfg_lrs.PORT_CONFIGS = port_cfgs; //pushing the configs for one lrs at the end of the element for the that LRS.
        port_config_lrs.push_back(pcfg_lrs);
        port_cfgs.clear(); //the vector is cleared so that the port config of one LRS are not passes on to another LRS while pushing back.
    }
}

void MySaxParser::on_characters(const Glib::ustring &text)
{
}

void MySaxParser::on_comment(const Glib::ustring &text)
{
}

void MySaxParser::on_warning(const Glib::ustring &text)
{
    try
    {
        std::cout << "on_warning(): " << text << std::endl;
    }
    catch (const Glib::ConvertError &ex)
    {
        std::cerr << "MySaxParser::on_warning(): Exception caught while converting text for std::cout: " << ex.what() << std::endl;
    }
}

void MySaxParser::on_error(const Glib::ustring &text)
{
    try
    {
        std::cout << "on_error(): " << text << std::endl;
    }
    catch (const Glib::ConvertError &ex)
    {
        std::cerr << "MySaxParser::on_error(): Exception caught while converting text for std::cout: " << ex.what() << std::endl;
    }
}

void MySaxParser::on_fatal_error(const Glib::ustring &text)
{
    try
    {
        std::cout << "on_fatal_error(): " << text << std::endl;
    }
    catch (const Glib::ConvertError &ex)
    {
        std::cerr << "MySaxParser::on_characters(): Exception caught while converting value for std::cout: " << ex.what() << std::endl;
    }
}
