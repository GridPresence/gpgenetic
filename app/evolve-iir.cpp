#include <iostream>

#include "sarge/Sarge.h"
#include "Context.hpp"

int main(int argc, char* argv[])
{
    Sarge sarge;
    sarge.setArgument("h", "help", "Get help.", false);
	sarge.setArgument("i", "infile", "Input context file", true);
    sarge.setArgument("o", "outfile", "Output file", true);
    sarge.setUsage("sarge_test <options>");

    if (!sarge.parseArguments(argc, argv)) {
		std::cerr << "Couldn't parse arguments..." << std::endl;
		return 1;
	}
	
    if (sarge.exists("help")) {
		sarge.printHelp();
	}

    std::string infile;
	if (sarge.getFlag("infile", infile)) {
		std::cout << "Got infile: " << infile << std::endl;
	}

    std::string outfile;
	if (sarge.getFlag("outfile", outfile)) {
		std::cout << "Got outfile: " << outfile << std::endl;
	}

	std::string textarg;
	if (sarge.getTextArgument(0, textarg)) {
		std::cout << "Got text argument: " << textarg << std::endl;
	}

    Context context(infile);

	int scope = context.freqs().size();
	for(int i = 0; i < scope; i++)
	{
		std::cout << context.freqs()[i] << "\t" << context.dbs()[i] 
		<< "\t" << context.omegas()[i] << "\t" << context.response()[i]
		<< std::endl;
	}

    return 0;
}