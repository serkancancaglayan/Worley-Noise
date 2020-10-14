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
const int WindowHeight = 600;
const int WindowWidth = 800;
const int number_of_random_points = 64;

float distance(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
float min(vector<float> &v) {
	float min = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] < min) min = v[i];
	}
	return min;
}
float max(vector<float>& v) {
	float max = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > max) max = v[i];
	}
	return max;
}
int worley_noise(vector<SDL_Point>& v, int x, int y, int n) {
	assert(n <= number_of_random_points);
	assert(n >= 1);
	vector<float> dists;
	for (SDL_Point& p : v) {
		dists.push_back(distance(p.x, p.y, x, y));
	}
	if (n == 1) {
		return (int)min(dists);
	}
	else if (n == v.size() + 1) {
		return (int)max(dists);
	}
	else {
		sort(dists.begin(), dists.end());
		return (int)dists[n - 1];
	}
}