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

class Soccer {
public:
   int maxPoints( vector <int> wins, vector <int> ties ) 
   {
	   int teams = wins.size();
	   int Result = 0;
	   for ( int i = 0 ; i < teams ; i++ )
		   Result = max ( 3 * wins[i] + ties[i] , Result );
	   return Result;
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
			int wins[]                = {1,4,3,0,0};
			int ties[]                = {3,1,5,3,1};
			int expected              = 14;

			clock_t moj_start_time    = clock();
			int received              = Soccer().maxPoints( vector <int>( wins, wins + ( sizeof wins / sizeof wins[0] ) ), vector <int>( ties, ties + ( sizeof ties / sizeof ties[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			int wins[]                = {12,45,20,17,48,0};
			int ties[]                = {48,10,53,94,0,100};
			int expected              = 145;

			clock_t moj_start_time    = clock();
			int received              = Soccer().maxPoints( vector <int>( wins, wins + ( sizeof wins / sizeof wins[0] ) ), vector <int>( ties, ties + ( sizeof ties / sizeof ties[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			int wins[]                = {35,0};
			int ties[]                = {0,76};
			int expected              = 105;

			clock_t moj_start_time    = clock();
			int received              = Soccer().maxPoints( vector <int>( wins, wins + ( sizeof wins / sizeof wins[0] ) ), vector <int>( ties, ties + ( sizeof ties / sizeof ties[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			int wins[]                = {0,0,0,0};
			int ties[]                = {0,0,0,0};
			int expected              = 0;

			clock_t moj_start_time    = clock();
			int received              = Soccer().maxPoints( vector <int>( wins, wins + ( sizeof wins / sizeof wins[0] ) ), vector <int>( ties, ties + ( sizeof ties / sizeof ties[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			int wins[]                = {13,79,26,73,14,89,71,37,89,71,19,59,39};
			int ties[]                = {88,27,5,70,84,94,20,50,2,11,31,22,50};
			int expected              = 361;

			clock_t moj_start_time    = clock();
			int received              = Soccer().maxPoints( vector <int>( wins, wins + ( sizeof wins / sizeof wins[0] ) ), vector <int>( ties, ties + ( sizeof ties / sizeof ties[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			int wins[]                = ;
			int ties[]                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Soccer().maxPoints( vector <int>( wins, wins + ( sizeof wins / sizeof wins[0] ) ), vector <int>( ties, ties + ( sizeof ties / sizeof ties[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			int wins[]                = ;
			int ties[]                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Soccer().maxPoints( vector <int>( wins, wins + ( sizeof wins / sizeof wins[0] ) ), vector <int>( ties, ties + ( sizeof ties / sizeof ties[0] ) ) );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			int wins[]                = ;
			int ties[]                = ;
			int expected              = ;

			clock_t moj_start_time    = clock();
			int received              = Soccer().maxPoints( vector <int>( wins, wins + ( sizeof wins / sizeof wins[0] ) ), vector <int>( ties, ties + ( sizeof ties / sizeof ties[0] ) ) );
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
