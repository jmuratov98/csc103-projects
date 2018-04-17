/*
 * CSc103 Project 5: Towers of Hanoi
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 
 */

// TODO: write the program.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function

void Hanoi(short n, short start, short end, short aux_rod);
short findAux_rod(short start, short end);

/* Here's a skeleton main function for processing the arguments. */
int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"start",        required_argument, 0, 's'},
		{"end",          required_argument, 0, 'e'},
		{"num-disks",    required_argument, 0, 'n'},
		{0,0,0,0} // this denotes the end of our options.
	};
	// now process the options:
	char c; // to hold the option
	int opt_index = 0;
	short n=0,start=0,end=0; /* to store inputs to the towers function. */
	while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 's': // process option s
				start = atoi(optarg);
				break;
			case 'e': // process option e
				end = atoi(optarg);
				break;
			case 'n': // process option n
				n = atoi(optarg);
				break;
			case '?': // this will catch unknown options.
				// here is where you would yell at the user.
				// although, getopt will already print an error message.
				return 1;
		}
	}

	/* TODO: now that you have the options and arguments,
	 * solve the puzzle. */
	
	// This is for test puposes 
	/*cout << "start = " << start << endl;
	cout << "end = " << end << endl;
	cout << "number of disks = " << n << endl;*/

	if(end > 3)
	{
		cout << "Can't have more then 3 pegs" << endl;
		return 0;
	}

	//find auxillary rod
	short aux_rod = findAux_rod(start,end);

	Hanoi(n,start,end, aux_rod);

	return 0;
}

void Hanoi(short n, short start, short end, short aux_rod)
{
	aux_rod = findAux_rod(start,end);
	//cout << "aux_rod = " << aux_rod << endl;
	if(n == 1)
	{
		cout << start << '\t' << end << endl;
		return;
	}
	Hanoi(n-1,start,aux_rod,end);
	cout << start << '\t' << end << endl;
	Hanoi(n-1,aux_rod,end,start);
}

short findAux_rod(short start, short end)
{
	short aux_rod;
	if(start == 1)
	{
		if(end == 3) aux_rod = 2;
		if(end == 2) aux_rod = 3;
	}
	else if(start == 2)
	{
		if(end == 1) aux_rod = 3;
		if(end == 3) aux_rod = 1;
	}
	else if(start == 3)
	{
		if(end == 1) aux_rod = 2;
		if(end == 2) aux_rod = 1;
	}
	return aux_rod;
}
