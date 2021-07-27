#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream>
#include <fstream>
#include <string.h>
#include "xmlParser.h"
#include <stdio.h>

const string input_file = "test.xml";

/*
 * Brief Explanation:
 * This program uses a SAX parser. SAX stands for Simple API for XML Parsing. It's an event based parsing and doesn't load the entire document.
 * The advantage of SAX parser is that each node can be accessed separately and memory can be saved when running the parser.
 *
 * At the start of the program, the parser tries to access the file, if it is not able to do so, then exit failure code is returned. If it is able to
 * access it, the parser parses the files on the basis of events.
 *
 * For example:
 *  void on_start_document() override;
    void on_end_document() override;
    void on_start_element(const Glib::ustring &name, const AttributeList &properties) override;
    void on_end_element(const Glib::ustring &name) override;
    void on_characters(const Glib::ustring &characters) override;
    void on_comment(const Glib::ustring &text) override;
    void on_warning(const Glib::ustring &text) override;
    void on_error(const Glib::ustring &text) override;
    void on_fatal_error(const Glib::ustring &text) override;

    In the xmlParser.cpp file, the functions have been defined according to event that occurs. If the parser comes across the starting tag of the element with a
    particular name, so we can define what we want do at that time. We can parse through the attributes if there are any or even do nothing sometimes.
 */

int main()
{
    int number_warnings = 0;
    auto return_code = EXIT_SUCCESS;
    try
    {
        MySaxParser parser;
        parser.set_substitute_entities(true);
        parser.parse_file(input_file);
    }
    catch (const xmlpp::exception &ex)
    {
        std::cerr << "libxml++ exception: " << ex.what() << std::endl;
        return_code = EXIT_FAILURE;
    }
    /*************************************************************************************************************************************************
    *************************************************************************************************************************************************/

    ofstream hdwFile("hw.cfg");

    cout << "Parser starts." << endl;
    cout << endl
         << endl;

    if (hdwFile.is_open())
    {
        hdwFile << hdw.NR_TILES << endl;
        hdwFile << hdw.TIMELY_BLOCK << endl;
        hdwFile << hdw.MSB_PERIODBIT_TT << hdw.PERIOD_DELTA_TT << hdw.NR_PERIODS_TT << hdw.PHASELICE_WIDTH_TT << hdw.PERIOD_ENABLE_TT << endl;
        hdwFile << hdw.MSB_PERIODBIT_ET << hdw.PERIOD_DELTA_ET << hdw.NR_PERIODS_ET << hdw.PHASELICE_WIDTH_ET << hdw.PERIOD_ENABLE_ET << endl;

        for (int i = 0; i < hdw.NR_PORTS.size(); i++)
        {
            if (i == hdw.NR_PORTS.size() - 1)
                hdwFile << hdw.NR_PORTS[i] << hdw.NR_OUT_PORTS[i];
            else
                hdwFile << hdw.NR_PORTS[i] << hdw.NR_OUT_PORTS[i] << endl;
        }
    }
    else
        cout << "hdwFile opening has failed." << endl
             << endl;

    /*************************************************************************************************************************************************
     *************************************************************************************************************************************************/

    string pfileName = "_port.cfg";

    for (int i = 0; i < port_config_lrs.size(); i++)
    {
        ofstream portFile(port_config_lrs[i].NAME + pfileName);
        if (portFile.is_open())
        {
            for (int j = 0; j < port_config_lrs[i].PORT_CONFIGS.size(); j++)
            {
                if (j == port_config_lrs[i].PORT_CONFIGS.size() - 1)
                    portFile << port_config_lrs[i].PORT_CONFIGS[j].ENABLE << port_config_lrs[i].PORT_CONFIGS[j].PORT_SPECS.PORT_SPECS_VALUE_HEX
                             << port_config_lrs[i].PORT_CONFIGS[j].BUFFER_SIZE << port_config_lrs[i].PORT_CONFIGS[j].QUEUE_LENGTH
                             << port_config_lrs[i].PORT_CONFIGS[j].DESTINATION_ADDRESS.COMPLETE_ADDRESS << port_config_lrs[i].PORT_CONFIGS[j].MINT;
                else
                    portFile << port_config_lrs[i].PORT_CONFIGS[j].ENABLE << port_config_lrs[i].PORT_CONFIGS[j].PORT_SPECS.PORT_SPECS_VALUE_HEX
                             << port_config_lrs[i].PORT_CONFIGS[j].BUFFER_SIZE << port_config_lrs[i].PORT_CONFIGS[j].QUEUE_LENGTH
                             << port_config_lrs[i].PORT_CONFIGS[j].DESTINATION_ADDRESS.COMPLETE_ADDRESS << port_config_lrs[i].PORT_CONFIGS[j].MINT << endl;
            }
        }
    }

    number_warnings=hdw.check_number_tiles_ports()+number_warnings;

    number_warnings=hdw.check_nrPort_nrOutPort()+number_warnings;

    cout << "Parsing finished. Number of anomalies encountered= " << number_warnings << endl;
    return 0;
}
