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

class Quipu {
public:
   int readKnots( string knots ) 
   {
       int sum , j;
	   string ANS;
	   for ( int i = 0 ; i < knots.length() ; i++ )
	   {
		   sum = 0;
		   for ( j = i ; j < knots.length() && knots[j] == knots[i] ; j++ )
			   sum++;
		   if ( knots[i] == '-' )
			   for ( int k = 1 ; k < sum ; k++ )
				   ANS = ANS + "0";
		   else
		   {
			   string str1 , s;
			   stringstream ss1 ( str1 );
			   ss1 << sum;
			   ss1 >> s;
			   ANS = ANS + s;
		   }
		   i = j - 1;
	   }
	   stringstream ss2 ( ANS );
	   ss2 >> sum;
	   return sum;
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
			string knots              = "-XX-XXXX-XXX-";
			int expected              = 243;

			clock_t moj_start_time    = clock();
			int received              = Quipu().readKnots( knots );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string knots              = "-XX--XXXX---XXX-";
			int expected              = 204003;

			clock_t moj_start_time    = clock();
			int received              = Quipu().readKnots( knots );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string knots              = "-X-";
			int expected              = 1;

			clock_t moj_start_time    = clock();
			int received              = Quipu().readKnots( knots );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string knots              = "-X-------";
			int expected              = 1000000;

			clock_t moj_start_time    = clock();
			int received              = Quipu().readKnots( knots );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string knots              = "-XXXXXXXXX--XXXXXXXXX-XXXXXXXXX-XXXXXXX-XXXXXXXXX-";
			int expected              = 909979;

			clock_t moj_start_time    = clock();
			int received              = Quipu().readKnots( knots );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string knots              = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Quipu().readKnots( knots );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string knots              = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Quipu().readKnots( knots );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string knots              = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Quipu().readKnots( knots );
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
