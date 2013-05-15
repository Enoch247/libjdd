/*******************************************************************************
 Written by: Joshua DeWeese(josh.deweese@gmail.com)
 please catch and release
*******************************************************************************/

#pragma once
#include <string>

using namespace std;
namespace jdd{

//example: scheme:path/over/there?key=val&key=val#fragment
class URI
{
	friend ostream& operator<<(ostream& os, const URI& uri);

	public:

	//constructor
	URI(string uri);

	//convert to string
	operator string () const;

	//convert from string
	string operator = (const string &rhv);

	//get protocol from uri
	string scheme() const;

	//get the uri minus the protocol
	string path() const;

	//get all of the key/value pairs together as one string
	string query() const;

	//return the value that goes with the given key. if the key/value pair
	//does not exsist, return the defaultVal
	string queryVal(string key, string defaultVal="") const;

	private:
	string uri;//the actual uri in string form
};
}//namespace

