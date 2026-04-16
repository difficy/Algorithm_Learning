#pragma once
#include<functional>
#include<ctime>
#include<queue>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

using Comp = function<bool(int, int)>;
Comp comp = greater<int>{};
Comp mincomp = less<int>{};