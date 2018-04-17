#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <set>
using std::set;
using std::multiset;;
#include <strings.h>

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of sort.  Supported options:\n\n"
"   -r,--reverse        Sort descending.\n"
"   -f,--ignore-case    Ignore case.\n"
"   -u,--unique         Don't output duplicate lines.\n"
"   --help              Show this message and exit.\n";

struct igncaseComp {
	bool operator()(const string& s1, const string& s2) {
		return (strcasecmp(s1.c_str(),s2.c_str()) < 0);
	}
};
/* NOTE: set<string,igncaseComp> S; would declare a set S which
 * does its sorting in a case-insensitive way! */
set<string,igncaseComp> S;

int main(int argc, char *argv[]) {
	// define long options
	static int descending=0, ignorecase=0, unique=0;
	static struct option long_opts[] = {
		{"reverse",       no_argument,   0, 'r'},
		{"ignore-case",   no_argument,   0, 'f'},
		{"unique",        no_argument,   0, 'u'},
		{"help",          no_argument,   0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "rfuh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'r':
				descending = 1;
				break;
			case 'f':
				ignorecase = 1;
				break;
			case 'u':
				unique = 1;
				break;
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}

	/* TODO: write me... */
	string n;
	while(cin >> n) S.insert(n);

	set<string,igncaseComp>::iterator i;

	if(descending == 0 && ignorecase == 0 && unique == 0)
	{
		for(i = S.begin(); i != S.end(); i++)
		{
			cout << ' ' << *i << endl;
		}
	}

	if(descending == 1)
	{
		set<string,igncaseComp>::reverse_iterator ri;
		// XXX don't try to print *(S.end()).  Maybe look into
		// using a 'reverse iterator' instead!
		for(ri = S.rbegin(); ri != S.rend(); ri++)
		{
			cout << ' ' << *ri << endl;
		}
	}

	if(unique == 1)
	{
		for(i = S.begin(); i != S.end(); i++)
		{
			cout << ' ' << *i << endl;
		}
	}

	return 0;
}
