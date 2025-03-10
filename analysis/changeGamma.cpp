//Loading an MD simulation "using systemMD.h".
//Everything needed to do a simulation is already included in systemMD.h.
//Even standard libraries like iostream and fstream are inlcuded.
//But, if any extra libraries are needed you can include them here or in systemMD.h.
//Permenent libraries (included with standard library or with this package) should
// go in systemMD.h, and anything you need that is external should go in this file.

//For molecular dynamics forces and potentials
#include "../include/MD.h"

//For the molecular dynamics variables
#include "../include/system.h"

int main(int argc, char **argv)
{
	if(argc!=3)
	{
		std::cerr << argv[0] << " name gamma\n";
		return 0;
	}

	double gamma;
	std::stringstream cmdArg;
	cmdArg << argv[2];
	std::cout << argv[2] << std::endl;
	cmdArg >> gamma;
	std::cout << gamma << std::endl;

	//the variables for the simulation, call with empty constructor
	Blob<double> System;
	
	//file input-output script engine
	//name part (argv[1] in this case) is used with no extension (*.mpd)
	Script<double, Blob <double> > fileIO(argv[1],std::ios::in,&System);
	
	//read the variables in
	fileIO.read();
	
	//close the file that it is reading from
	fileIO.close();
	
	//Set a new time
	System.setGamma(gamma);

	//Save it
	fileIO.open(argv[1],std::ios::out);
	fileIO.write();
	fileIO.close();
	

	return 0;
}
