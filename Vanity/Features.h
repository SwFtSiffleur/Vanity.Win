#pragma once

#include <Windows.h>
#include <iostream>
#include <intrin.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <Windows.h>
#include <chrono>
#include <math.h>
#include <stdio.h> 
#include <cmath>
#include <ctime>
#include <mmsystem.h>
#include <winbase.h>
#include <tchar.h>
#include <windows.h>
#include <cstdio>


#pragma comment(lib, "winmm.lib")


int IsMuzzleBoost(float Delay);
double ScopeAttachment();
double BarrelAttachment();
double ScopeAttachment1();
double ScopeAttachment1();
double BarrelAttachment1();
void SetConsole();
void little_sleep(std::chrono::milliseconds us);
void ms_sleep(int milliseconds);
void pQuerySleep(int ms);
void Menu();
void Smoothing(double delay, double control_time, int x, int y);
void Sound(bool type);
bool RecoilExecution();


