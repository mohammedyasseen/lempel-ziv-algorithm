#include <bits/stdc++.h> 
#include <iostream>
#include <iterator>
#include <vector>
#include<string>
using namespace std; 
vector<int> lz(string s1 ) 
{ 
	cout << "Encoding\n"; 
	unordered_map<string, int> table; 
		string ch = ""; 
		ch += char(0); 
		table[ch] = 0; 

	string p = "", c = ""; 
	p += s1[0];
	string a;
	int ref = 1;
	int code = 0; 
	vector<int> output_code; 
	output_code.push_back(0);
	cout << "Sequence\t\t\t\t\tBase\t\t\tCode\t\t\t\t\t\tLocation\n"; 
	for (int i = 0; i < s1.length(); i++) { 
		if (i != s1.length() - 1) 
			c += s1[i + 1]; 
		if (table.find(p)!= table.end()) { 
		    a=p;
			p = p + c; 
		} 
		else {table[p] = ref;
		if (p=="0"||p=="1")
		code =0 ;else  {
	         code=table[a];}
	         
		string str= to_string(code);
		
			cout << p << "\t\t\t\t\t\t" <<s1[i] <<"\t\t\t";
			bitset<30> bin_x(code);
			bitset<30> bin_x1(ref);
			
			cout<< bin_x<<s1[i]<< "\t\t\t" << bin_x1<<"\t\t"<<endl; 
			
			output_code.push_back(table[p]); 
			
            ref ++;
			code = ref; 
			p = c; 
		} 
		c = ""; 
	} 
	output_code.push_back(table[p]);
	cout<<"decoding"<<endl;
	for (int i : output_code)
	for ( auto it = table.begin(); it != table.end(); ++it  )
	if (output_code[i] == it->second)
	cout << it->first;
	output_code.push_back(table[p]); 
	return output_code; }
	
  static const char pool [] = "01" ;
int poolsize = sizeof(pool) - 1 ;

char getRandomChar () 
{ return pool [rand()% 2 ] ; }
int main() 
{ 
	 int n ;  
	  srand (time(0));
	  string pass = "" ;
	  cout << " enter number of bits ( max is 1million ) :		 " ;
	  cin >> n ;

	  for ( int i = 0  ; i < n ; i++ ) 
	   pass += getRandomChar () ; 
	    
	
	  
string s = pass;
	
	vector<int> output_code = lz(s); 
	 
} 
