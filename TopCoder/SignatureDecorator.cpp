// Paste me into the FileEdit configuration dialog

#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;

class SignatureDecorator {
public:
   string applyDecoration( string name, vector <string> commands, vector <string> decorations ) 
   {
	   for ( int i = 0 ; i < commands.size() ; i++ )
	   {
		   switch ( commands[i][0] )
		   {
			   case 's':
				   name = decorations[i] + name;
				   reverse ( decorations[i].begin() , decorations[i].end() );
				   name += decorations[i];
				   break;
			   case 'a':
				   name += decorations[i];
				   break;
			   default:
				   name = decorations[i] + name;
		   }
	   }
	   return name;
   }
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test( int casenum = -1 ) {
		if ( casenum != -1 ) {
			if ( run_test_case( casenum ) == -1 )
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			return;
		}
		
		int correct = 0, total = 0;
		for ( int i=0;; ++i ) {
			int x = run_test_case(i);
			if ( x == -1 ) {
				if ( i >= 100 ) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if ( total == 0 ) {
			cerr << "No test cases run." << endl;
		} else if ( correct < total ) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case( int casenum, const string &expected, const string &received, clock_t elapsed ) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if ( expected == received ) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			string name               = "Bob";
			string commands[]         = {"surround", "append", "prepend"};
			string decorations[]      = {"-=", "(", ")"};
			string expected           = ")-=Bob=-(";

			clock_t moj_start_time    = clock();
			string received           = SignatureDecorator().applyDecoration( name, vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <string>( decorations, decorations + ( sizeof decorations / sizeof decorations[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string name               = "Super_Man_01";
			// string commands[]      = empty, commented out for VC++;
			// string decorations[]   = empty, commented out for VC++;
			string expected           = "Super_Man_01";

			clock_t moj_start_time    = clock();
			string received           = SignatureDecorator().applyDecoration( name, vector <string>(), vector <string>() );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string name               = "4BcD3FgHIjklMN0pqrS7uVWxYZ_";
			string commands[]         = {"append", "prepend", "surround"};
			string decorations[]      = {"`{[(", ")]}'", ",.;<>?:|-=_+!@#$%^&*~"};
			string expected           = ",.;<>?:|-=_+!@#$%^&*~)]}'4BcD3FgHIjklMN0pqrS7uVWxYZ_`{[(~*&^%$#@!+_=-|:?><;.,";

			clock_t moj_start_time    = clock();
			string received           = SignatureDecorator().applyDecoration( name, vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <string>( decorations, decorations + ( sizeof decorations / sizeof decorations[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string name               = "RacEcaR";
			string commands[]         = {"surround"};
			string decorations[]      = {"([{/"};
			string expected           = "([{/RacEcaR/{[(";

			clock_t moj_start_time    = clock();
			string received           = SignatureDecorator().applyDecoration( name, vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <string>( decorations, decorations + ( sizeof decorations / sizeof decorations[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 4: {
			string name               = ;
			string commands[]         = ;
			string decorations[]      = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = SignatureDecorator().applyDecoration( name, vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <string>( decorations, decorations + ( sizeof decorations / sizeof decorations[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			string name               = ;
			string commands[]         = ;
			string decorations[]      = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = SignatureDecorator().applyDecoration( name, vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <string>( decorations, decorations + ( sizeof decorations / sizeof decorations[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string name               = ;
			string commands[]         = ;
			string decorations[]      = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = SignatureDecorator().applyDecoration( name, vector <string>( commands, commands + ( sizeof commands / sizeof commands[0] ) ), vector <string>( decorations, decorations + ( sizeof decorations / sizeof decorations[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
