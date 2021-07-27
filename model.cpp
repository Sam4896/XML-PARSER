#include "model.h"

string binaryString_to_hex(string s)
/*
 * The function converts the binary number into hexadecimal format. The function accepts
 * the binary number as the arguments as string type variable.
 */
{
    string hex, zero = "0";
    int size = s.size();
    for (int j = size - 1; j >= 0; j = j - 4)
    {
        string nibble; // nibble will max of length 4 so that the 4 binary digits are directly compared in the if else statements
        for (int i = j; i >= j - 3; i--)
        {
            if (i < 0)
            {
                while (nibble.size() < 4)
                {
                    nibble.insert(0, zero);
                }
                break;
            }
            else
            {
                string c(1, s.at(i));
                nibble.insert(0, c);
            }
        }
        if (nibble == "0000")
            hex.insert(0, string(1, '0'));
        else if (nibble == "0001")
            hex.insert(0, string(1, '1'));
        else if (nibble == "0010")
            hex.insert(0, string(1, '2'));
        else if (nibble == "0011")
            hex.insert(0, string(1, '3'));
        else if (nibble == "0100")
            hex.insert(0, string(1, '4'));
        else if (nibble == "0101")
            hex.insert(0, string(1, '5'));
        else if (nibble == "0110")
            hex.insert(0, string(1, '6'));
        else if (nibble == "0111")
            hex.insert(0, string(1, '7'));
        else if (nibble == "1000")
            hex.insert(0, string(1, '8'));
        else if (nibble == "1001")
            hex.insert(0, string(1, '9'));
        else if (nibble == "1010")
            hex.insert(0, string(1, 'A'));
        else if (nibble == "1011")
            hex.insert(0, string(1, 'B'));
        else if (nibble == "1100")
            hex.insert(0, string(1, 'C'));
        else if (nibble == "1101")
            hex.insert(0, string(1, 'D'));
        else if (nibble == "1110")
            hex.insert(0, string(1, 'E'));
        else if (nibble == "1111")
            hex.insert(0, string(1, 'F'));
    }
    return hex;
}

int hex_to_decimal(string num)
{
    int len = num.size();
    int base = 1;
    int temp = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            temp += (num[i] - 48) * base;
            base = base * 16;
        }
        else if (num[i] >= 'A' && num[i] <= 'F')
        {
            temp += (num[i] - 55) * base;
            base = base * 16;
        }
    }
    return temp;
}

int hdw_config_class::check_number_tiles_ports()
{
	if (NR_PORTS.size() > hex_to_decimal(NR_TILES))
	{
		cout << "Warning: Number of ports greater that number of tiles." << endl<<endl;
		return 1;
	}
	else
		return 0;
}

int hdw_config_class::check_nrPort_nrOutPort()
{
	int warn=0;
	for(int i=0;i<NR_OUT_PORTS.size();i++)
	if (hex_to_decimal(NR_OUT_PORTS[i]) > hex_to_decimal(NR_PORTS[i]))
	{
		cout<<"Warning: For NR_PORTS entry "<<i<<", number of out ports greater than the number of ports"<<endl<<endl;
		warn++;
	}

	return warn;

}
void port_specs_class::combine_port_specs_value_string()
{
    PORT_SPECS_VALUE_BINARY_STRING = PORT_TYPE + DIRECTION + SEMANTICS;
    PORT_SPECS_VALUE_HEX = binaryString_to_hex(PORT_SPECS_VALUE_BINARY_STRING);

    //PORT_SPECS_VALUE has been converted into hex format because the port.cfg file demands for the three
    //values to be combined and converted into hexadecimal format
}

void destination_address_class::combine_destination_address()
{
    COMPLETE_ADDRESS = CLUSTER_ID + NODE_ID + TILE_ID + PORT_ID;
}

hdw_config_class hdw;
vector<p_config_class> port_cfgs;
p_config_class pcfg;
port_configs_lrs_class pcfg_lrs;
vector<port_configs_lrs_class> port_config_lrs;
