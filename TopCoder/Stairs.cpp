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

class Stairs {
public:
   int designs( int maxHeight, int minWidth, int totalHeight, int totalWidth ) 
   {
	   int ANS = 0;

	   /* ( time limit )
       int n;
       for (  ; maxHeight > 0 ; maxHeight-- )
           if ( totalHeight % maxHeight == 0 )
           {
              n = ( totalHeight / maxHeight ) - 1;
              if ( totalWidth % n == 0 && ( totalWidth / n ) >= minWidth )
                 ANS++;
           }
	   */

	   /*
	   int width = totalWidth / minWidth;
	   int height = ceil ( (double) totalHeight / maxHeight );
	   for ( int n = width ; n > 0 && ( n + 1 ) >= height ; n-- )
		   if ( totalWidth % n == 0 && totalHeight % ( n + 1 ) == 0 )
			   ANS++;
	   */

	   return ANS;
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
	
	int verify_case( int casenum, const int &expected, const int &received, clock_t elapsed ) { 
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
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case( int casenum ) {
		switch( casenum ) {
		case 0: {
			int maxHeight             = 22;
			int minWidth              = 25;
			int totalHeight           = 100;
			int totalWidth            = 100;
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = Stairs().designs( maxHeight, minWidth, totalHeight, totalWidth );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int maxHeight             = 25;
			int minWidth              = 25;
			int totalHeight           = 60;
			int totalWidth            = 100;
			int expected              = 2;

			clock_t moj_start_time    = clock();
			int received              = Stairs().designs( maxHeight, minWidth, totalHeight, totalWidth );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int maxHeight             = 1000;
			int minWidth              = 1;
			int totalHeight           = 600;
			int totalWidth            = 600;
			int expected              = 6;

			clock_t moj_start_time    = clock();
			int received              = Stairs().designs( maxHeight, minWidth, totalHeight, totalWidth );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 3: {
			int maxHeight             = ;
			int minWidth              = ;
			int totalHeight           = ;
			int totalWidth            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Stairs().designs( maxHeight, minWidth, totalHeight, totalWidth );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 4: {
			int maxHeight             = ;
			int minWidth              = ;
			int totalHeight           = ;
			int totalWidth            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Stairs().designs( maxHeight, minWidth, totalHeight, totalWidth );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 5: {
			int maxHeight             = ;
			int minWidth              = ;
			int totalHeight           = ;
			int totalWidth            = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Stairs().designs( maxHeight, minWidth, totalHeight, totalWidth );
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
