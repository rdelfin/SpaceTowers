#include "stdafx.h"
#include "Utility.h"

Utility::Utility(void)
{
}

bool Utility::separateList(vector<string>& vec, string listToSeparate)
{
	vec.clear();

	if(listToSeparate[0] != '[' || listToSeparate[listToSeparate.length() - 1] != ']')
		return false;

	listToSeparate = listToSeparate.substr(1, listToSeparate.length() - 2);
	
	vec = split(listToSeparate, ";");

	if(vec.size() == 0)
		return false;

	return true;
}

vector<string> Utility::split(const string& s, const string& delim, const bool keep_empty)
{
    vector<string> result;
    if (delim.empty()) {
        result.push_back(s);
        return result;
    }
    string::const_iterator substart = s.begin(), subend;
    while (true) {
        subend = search(substart, s.end(), delim.begin(), delim.end());
        string temp(substart, subend);
        if (keep_empty || !temp.empty()) {
            result.push_back(temp);
        }
        if (subend == s.end()) {
            break;
        }
        substart = subend + delim.size();
    }
    return result;
}

Utility::~Utility(void)
{
}
