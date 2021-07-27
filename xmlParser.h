#ifndef __LIBXMLPP_EXAMPLES_MYPARSER_H
#define __LIBXMLPP_EXAMPLES_MYPARSER_H

#include <libxml++/libxml++.h>
#include <libxml++config.h>

#include "model.h"

#include <glibmm/convert.h> //For Glib::ConvertError

class MySaxParser : public xmlpp::SaxParser
{
public:
    MySaxParser();
    ~MySaxParser() override;

protected:
    //overrides:
    void on_start_document() override;
    void on_end_document() override;
    void on_start_element(const Glib::ustring &name, const AttributeList &properties) override;
    void on_end_element(const Glib::ustring &name) override;
    void on_characters(const Glib::ustring &characters) override;
    void on_comment(const Glib::ustring &text) override;
    void on_warning(const Glib::ustring &text) override;
    void on_error(const Glib::ustring &text) override;
    void on_fatal_error(const Glib::ustring &text) override;
};

/*
 * Here a parser has been declared whose functions overide the functions of the parent class. The definiton of SaxParser
 * can be found in the file SaxParser.h
 */

class parser
{
public:
    static hdw_config_class parse_hdw_config(const MySaxParser::AttributeList &attributes);
    static string parse_nr_port(const MySaxParser::AttributeList &attributes);
    static string parse_nr_out_port(const MySaxParser::AttributeList &attributes);
    static string parse_phaseslice_width_TT(const MySaxParser::AttributeList &attributes);
    static string parse_phaseslice_width_ET(const MySaxParser::AttributeList &attributes);
    static string parse_nr_periods_TT(const MySaxParser::AttributeList &attributes);
    static string parse_nr_periods_ET(const MySaxParser::AttributeList &attributes);
    static string parse_period_delta_TT(const MySaxParser::AttributeList &attributes);
    static string parse_period_delta_ET(const MySaxParser::AttributeList &attributes);
    static string parse_msb_periodbit_TT(const MySaxParser::AttributeList &attributes);
    static string parse_msb_periodbit_ET(const MySaxParser::AttributeList &attributes);
    static string parse_period_enable_TT(const MySaxParser::AttributeList &attributes);
    static string parse_period_enable_ET(const MySaxParser::AttributeList &attributes);

    static port_configs_lrs_class parse_port_configs_lrs(const MySaxParser::AttributeList &attributes);
    static p_config_class parse_port_config(const MySaxParser::AttributeList &attributes);
    static port_specs_class parse_port_specs(const MySaxParser::AttributeList &attributes);
    static string parse_buffer_size(const MySaxParser::AttributeList &attributes);
    static string parse_queue_length(const MySaxParser::AttributeList &attributes);
    static destination_address_class parse_destination_address(const MySaxParser::AttributeList &attributes);
    static string parse_mint(const MySaxParser::AttributeList &attributes);
};

/*
 *
 */

#endif //__LIBXMLPP_EXAMPLES_MYPARSER_H
