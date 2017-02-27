#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
vector< string > tokenize( string a, string b ) {
  const char *q = a.c_str();
  while( count( b.begin(), b.end(), *q ) ) {
    q++;
  }
  vector< string > oot;
  while( *q ) {
    const char *e = q;
    while( *e && !count( b.begin(), b.end(), *e ) ) {
      e++;
    }
    oot.push_back( string( q, e ) );
    q = e;
    while( count( b.begin(), b.end(), *q ) ) {
      q++;
    }
  }
  return oot;
}
 
vector< int > sti( const vector< string > &a ) {
  vector< int > oot;
  for( int i = 0; i < a.size(); i++ ) {
    oot.push_back( atoi( a[ i ].c_str() ) );
  }
  return oot;
}
 
int gcd( int a, int b ) {
  if( !b ) return a;
  return gcd( b, a % b );
}
 
int ncr[ 51 ][ 51 ];
 
void ncrg() {
  memset( ncr, 0, sizeof( ncr ) );
  for( int i = 0; i < 51; i++ ) {
    ncr[ i ][ 0 ] = 1;
  }
  for( int i = 1; i < 51; i++ ) {
    for( int j = 1; j < 51; j++ ) {
      int targ = ncr[ i - 1 ][ j ] + ncr[ i - 1 ][ j - 1 ];
      if( ncr[ i - 1 ][ j ] == -1 || targ < ncr[ i - 1 ][ j ] ) {
        ncr[ i ][ j ] = -1;
      } else {
        ncr[ i ][ j ] = targ;
      }
    }
  }
};
 
struct tt { };
tt zz;
 
tt &operator,( tt &x, tt &y ) {
  printf( "\n" );
  y=y;
  return x;
}
 
tt &operator,( tt &x, const string &y ) {
  printf( "\"%s\"", y.c_str() );
  return x;
}
 
tt &operator,( tt &x, int y ) {
  printf( "%d", y );
  return x;
}
 
tt &operator,( tt &x, double y ) {
  printf( "%lf", y );
  return x;
}
 
template< typename q, typename z >
tt &operator,( tt &x, const pair< q, z > &y ) {
  printf( "( " );
  x,y.first;
  printf( ", " );
  x,y.second;
  printf( " )" );
  return x;
}
 
template< typename q >
tt &operator,( tt &x, const vector< q > &y ) {
  printf( "{ " );
  for( int i = 0; i < y.size(); i++ ) {
    if( i ) {
      printf( ", " );
    }
    x,y[ i ];
  }    
  printf( " }" );
  return x;
}
 
/*
template< typename q >
tt &operator,( tt &x, const set< q > &y ) {
  printf( "{ " );
  for( set< q >::const_iterator itr = y.begin(); itr != y.end(); itr++ ) {
    if( itr != y.begin() ) {
      printf( ", " );
    }
    x,*itr;
  }    
  printf( " }" );
  return x;
}
 
template< typename q, typename z >
tt &operator,( tt &x, const map< q, z > &y ) {
  printf( "{ " );
  for( map< q, z >::const_iterator itr = y.begin(); itr != y.end(); itr++ ) {
    if( itr != y.begin() ) {
      printf( ", " );
    }
    x,*itr;
  }    
  printf( " }" );
  return x;
}
*/
 
typedef long long i64;
 
i64 ans[ 102 ][ 102 ];
 
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
 
class AvoidRoads {
  public:
  long long numWays(int width, int height, vector <string> bad) {
    ans[ 0 ][ 0 ] = 1;
    set< pair< pair< int, int >, pair< int, int > > > nt;
    for( int i = 0; i < bad.size(); i++ ) {
      vector< int > st = sti( tokenize( bad[ i ], " " ) );
      nt.insert( make_pair( make_pair( st[ 0 ], st[ 1 ] ), make_pair( st[ 2 ], st[ 3 ] ) ) );
      nt.insert( make_pair( make_pair( st[ 2 ], st[ 3 ] ), make_pair( st[ 0 ], st[ 1 ] ) ) );
    }
    for( int x = 0; x <= width; x++ ) {
      for( int y = 0; y <= height; y++ ) {
        for( int k = 0; k < 2; k++ ) {
          int tx = x + dx[ k ];
          int ty = y + dy[ k ];
          if( !nt.count( make_pair( make_pair( x, y ), make_pair( tx, ty ) ) ) ) {
            ans[ tx ][ ty ] += ans[ x ][ y ];
          }
        }
      }
    }
    return ans[ width ][ height ];
  }
};
