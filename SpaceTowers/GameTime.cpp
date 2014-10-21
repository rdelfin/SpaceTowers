#include "stdafx.h"
#include "GameTime.h"
#include <chrono>

using namespace std::chrono;

GameTime::GameTime(void)
{
	start = milliseconds_now();
	lastFrame = start;
	currFrame = start;
}


GameTime::~GameTime(void)
{
	
}

long double GameTime::getElapsedGameTime() { return start - currFrame; }
long double GameTime::getMillisecondsPerFrame() { return currFrame - lastFrame; }


void GameTime::Update()
{
	lastFrame = currFrame;
	currFrame = milliseconds_now();
}

long double GameTime::milliseconds_now()
{
    
    milliseconds ms = duration_cast< milliseconds >(high_resolution_clock::now().time_since_epoch());
    return ms.count();
    /*static LARGE_INTEGER s_frequency;
    static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
    if (s_use_qpc)
	{
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (1000LL * now.QuadPart) / s_frequency.QuadPart;
    }
	else
	{
        return GetTickCount64();
    }*/
}

void GameTime::reset()
{
	start = milliseconds_now();
	lastFrame = start;
	currFrame = start;
}