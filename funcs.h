#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <cassert>
using namespace std;
const int WindowHeight = 400;
const int WindowWidth = 600;
const int number_of_random_points = 48;

float distance(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int worley_noise(vector<SDL_Point>& v, int x, int y, int n) {
	assert(n >= 1);
	assert(n <= number_of_random_points);
	vector<float> dists;
	for (SDL_Point& p : v) {
		dists.push_back(distance(p.x, p.y, x, y));
	}
	sort(dists.begin(), dists.end());
	return (int)dists[n - 1];
}
