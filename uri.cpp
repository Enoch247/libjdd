#include <string>
#include "uri.h"

namespace jdd{

URI::URI(string uri):
	uri(uri)
{
}

URI::operator string () const
{
	return uri;
}

string URI::operator = (const string &rhv)
{
	uri = rhv;
	return rhv;
}

string URI::scheme() const
{
	return uri.substr(0, uri.find(":"));
}

string URI::path() const
{
	unsigned int pathPos = uri.find(":");
	if(pathPos == string::npos) return "";
	else pathPos++;
	unsigned int pathLen = uri.find_first_of("?#") - pathPos;
	return uri.substr(pathPos, pathLen);
}

string URI::query() const
{
	unsigned int qPos = uri.find("?");
	if(qPos == string::npos) return "";
	else qPos++;
	unsigned int qLen = uri.find_first_of("#") - qPos;
	return uri.substr(qPos, qLen);
}

string URI::queryVal(string key, string defaultVal) const
{
	string q = query();
	unsigned int keyPos = q.find(key);
	if(keyPos == string::npos) return defaultVal;
	unsigned int valPos = keyPos + key.length() + 1;
	unsigned int valLen = q.find_first_of("&#", valPos) - valPos;
	return q.substr(valPos, valLen);
}

//==============================================================================

ostream& operator<<(ostream& os, const jdd::URI& uri)
{
	os << (string)uri;
	return os;
}

}// end namespace

