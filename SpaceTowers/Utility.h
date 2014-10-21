#pragma once

#include "stdafx.h"

//Colors
#define CORNFLOWER_BLUE al_map_rgb(100, 149, 237)
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)

class Utility
{
public:
    
	Utility();

	static bool separateList(vector<string>&, string);
	static vector<string> split(const string& s, const string& delim, const bool keep_empty = true);

	~Utility();
};

