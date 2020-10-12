# Worley-Noise
Worley Noise implementation using C++ and SDL2.0
Basic algorithm

The basic idea is to take random points in space (2- or 3-dimensional) and then for every location in space take the distances dn to the nth-closest point (e.g. the second-closest point) and use combinations of those to control color information ( note that dn+1 > dn). More precisely:

Randomly distribute feature points in space organised as grid cells. In practice this is done on the fly without storage (as a procedural noise). The original method considered a variable number of seed points per cell so as to mimic a Poisson distribution, but many implementations just put one.
At run time, extract the distances dn from the given location to the nth-closest seed point. This can be done efficiently by visiting the current cell plus its neighbors.
Noise W(x) is formally the vector of distances, plus possibly the corresponding seed ids, user-combined so as to produce a color.
