/*
 * model.h
 *
 *  Created on: 14-May-2021
 *      Author: saksham
 *
 *      The header files contains the declaration of all the classes that will
 *      hold the parsed elements and the values of the attributes. The names
 *      of the classes and the attributes have been made similar to names of the
 *      nodes and attributes in XML file. For the nodes that occur more than once,
 *      a vector has been made for the same and a new element is pushed back into
 *      the vector when a node with the same name is encountered.
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class hdw_config_class
{

public:
    string NR_TILES;     //nr_tiles_class NR_TILES;
    string TIMELY_BLOCK; //timely_block_class TIMELY_BLOCK;

    vector<string> NR_PORTS;
    vector<string> NR_OUT_PORTS;

    string PHASELICE_WIDTH_TT;
    string PHASELICE_WIDTH_ET;
    string NR_PERIODS_TT;
    string NR_PERIODS_ET;
    string PERIOD_DELTA_TT;
    string PERIOD_DELTA_ET;
    string MSB_PERIODBIT_TT;
    string MSB_PERIODBIT_ET;
    string PERIOD_ENABLE_TT;
    string PERIOD_ENABLE_ET;
    int check_number_tiles_ports();
    int check_nrPort_nrOutPort();
};

/**************************************************************/
/**************************************************************/
/**************************************************************/

class port_specs_class
{
public:
    string PORT_TYPE;
    string DIRECTION;
    string SEMANTICS;
    string PORT_SPECS_VALUE_HEX;
    string PORT_SPECS_VALUE_BINARY_STRING;
    void combine_port_specs_value_string();
};

class destination_address_class
{
public:
    string CLUSTER_ID, NODE_ID, TILE_ID, PORT_ID;
    string COMPLETE_ADDRESS;
    void combine_destination_address();
};

class p_config_class
{
public:
    string ID;
    string ENABLE;
    port_specs_class PORT_SPECS;
    string BUFFER_SIZE;
    string QUEUE_LENGTH;
    destination_address_class DESTINATION_ADDRESS;
    string MINT;
};

class port_configs_lrs_class
{
public:
    string NAME;
    vector<p_config_class> PORT_CONFIGS;
};

extern hdw_config_class hdw;
extern vector<p_config_class> port_cfgs;
extern p_config_class pcfg;
extern port_configs_lrs_class pcfg_lrs;
extern vector<port_configs_lrs_class> port_config_lrs;

#endif /* MODEL_H_ */
