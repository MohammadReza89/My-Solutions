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

class TxMsg {
public:
	bool MOH ( char ch )
	{
		switch ( ch )
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				return false;
			default:
				return true;
		}
	}

	int IsVowel ( string s )
	{
		bool b;
		for ( int i = 0 ; i < s.length() ; i++ )
		{
			b = MOH ( s[i] );
			if ( b == true )
				return 1;
		}
		return 0;
	}

	string Change ( string s )
	{
		vector <bool> b ( s.length() , true );
		for ( int i = 0 ; i < s.length() ; i++ )
			b[i] = MOH ( s[i] );
		for ( int i = 0 ; i < b.size() ; i++ )
			if ( b[i] == false || ( b[i] == true && ( i > 0 && b[i-1] == true ) ) )
				s[i] = ' ';
		for ( int i = 0 ; i < s.length() ; i++ )
			if ( s[i] == ' ' )
			{
				s.erase ( s.begin() + i );
				i--;
			}
		return s;
	}

	string getMessage( string original )
	{
	   /*(1)
	   string ANS;
	   for ( int i = 0 ; i < original.length() ; i++ )
	   {
		   int j;
		   for ( j = i ; j < original.length() && original[j] != ' ' ; j++ );
		   string str ( original.begin() + i , original.begin() + j );
		   if ( IsVowel ( str ) == 0 )
			   ANS = ANS + " " + str;
		   else
			   ANS =  ANS + " " + Change ( str );
		   i = j;
	   }
	   ANS.erase ( ANS.begin() );
	   return ANS;*/

		/*(2)
		original = " " + original;
		vector <int> b ( original.length() , 1 );
		for ( int i = 0 ; i < original.length() ; i++ )
		{
			switch ( original[i] )
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					b[i] = -1;
			}
			if ( original[i] == ' ' )
				b[i] = 0;
		}
		for ( int i = 1 ; i < b.size() ; i++ )
		{
			bool m = true;
			int j;
			for ( j = i ; j < b.size() && b[j] != 0 ; j++ )
				if ( b[j] == 1 )
					m = false;
			if ( m == true )
				for ( j = i ; j < b.size() && b[j] != 0 ; j++ )
					b[j] = 1;
			else
				for ( int x = j - 1 ; x > 0 && b[x] != 0 ; x-- )
					if ( b[x] == 1 && b[x-1] == 1 )
						b[x] = -1;
			i = j;
		}
		for ( int i = 1 ; i < b.size() ; i++ )
			if ( b[i] == -1 )
				original[i] = '-';
		for ( int i = 0 ; i < original.length() ; i++ )
			if ( original[i] == '-' )
			{
				original.erase ( original.begin() + i );
				i--;
			}
		string ANS ( original.begin() + 1 , original.end() );
		return ANS;*/
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
			string original           = "text message";
			string expected           = "tx msg";

			clock_t moj_start_time    = clock();
			string received           = TxMsg().getMessage( original );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 1: {
			string original           = "ps i love u";
			string expected           = "p i lv u";

			clock_t moj_start_time    = clock();
			string received           = TxMsg().getMessage( original );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 2: {
			string original           = "please please me";
			string expected           = "ps ps m";

			clock_t moj_start_time    = clock();
			string received           = TxMsg().getMessage( original );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 3: {
			string original           = "back to the ussr";
			string expected           = "bc t t s";

			clock_t moj_start_time    = clock();
			string received           = TxMsg().getMessage( original );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}
		case 4: {
			string original           = "aeiou bcdfghjklmnpqrstvwxyz";
			string expected           = "aeiou b";

			clock_t moj_start_time    = clock();
			string received           = TxMsg().getMessage( original );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}

		// custom cases

/*      case 5: {
			string original           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = TxMsg().getMessage( original );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 6: {
			string original           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = TxMsg().getMessage( original );
			return verify_case( casenum, expected, received, clock()-moj_start_time );
		}*/
/*      case 7: {
			string original           = ;
			string expected           = ;

			clock_t moj_start_time    = clock();
			string received           = TxMsg().getMessage( original );
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
