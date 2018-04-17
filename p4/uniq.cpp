#include <cstdio>
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of uniq.  Supported options:\n\n"
"   -c,--count         prefix lines by their counts.\n"
"   -d,--repeated      only print duplicate lines.\n"
"   -u,--unique        only print lines that are unique.\n"
"   --help             show this message and exit.\n";

int main(int argc, char *argv[]) {
	// define long options
	static int showcount=0, dupsonly=0, uniqonly=0;
	static struct option long_opts[] = {
		{"count",         no_argument, 0, 'c'},
		{"repeated",      no_argument, 0, 'd'},
		{"unique",        no_argument, 0, 'u'},
		{"help",          no_argument, 0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "cduh", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'c':
				showcount = 1;
				break;
			case 'd':
				dupsonly = 1;
				break;
			case 'u':
				uniqonly = 1;
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
	
		// Variable decralration for C
	map<string,int>count;
	string words;
  //Variable declaration for d
	vector<string>duplicates;
	//int dupcount;
	string temp;
	/*****************************SHOWCOUNT *************/
if(showcount==1)
{
		while(cin>>words)
			{
			++count[words];
			}

					for(map<string,int>::iterator i=count.begin();i!=count.end();i++)
					{
					cout<<(*i).second<<"\t"<<(*i).first<<"\n";
					}


}//end of showcount loop
/************************END OF SHOWCOUNT*****************/


/******************DUPLICATE ******************/
	if(dupsonly==1)
	{
	//vector<string>duplicates;


		while(cin>>words)
		{
		duplicates.push_back(words);
		sort(duplicates.begin(),duplicates.end());
		}
			for(int i=0;i<duplicates.size()-1;i++)
			{
					if(duplicates[i]==duplicates[i+1])
					{
						temp=duplicates[i];
						cout<< temp <<"\n";
					}
			}


	}
/*********************END OF DUPLICATE*****************/

	/**********************UNIQONLY********************/
	vector<string>uniqueWords;
	if(uniqonly==1)
	{
		while(cin>>words)
		{
			uniqueWords.push_back(words);
			sort(uniqueWords.begin(),uniqueWords.end());
		}

				for(int i=0;i < uniqueWords.size()-1;i++)
				{
					if(uniqueWords[1]!=uniqueWords[1+1])

						cout<<uniqueWords[i] << "\n";

				}


	}
	/****************END OF UNIQONLY********************/

	return 0;
}