/**
 * Author: Simon Lindholm
 * Description: Add (merges overlapping intervals) and remove intervals from a set of disjoint intervals.
 * Intervals are [inclusive, exclusive).
 */

set<pair<int, int>>::iterator addInterval(set<pair<int, int>>& is, int L, int R) {
	if (L == R) return is.end();
	auto it = is.lower_bound({L, R}), before = it;
	while (it != is.end() && it->first <= R) {
		R = max(R, it->second);
		before = it = is.erase(it);
	}
	if (it != is.begin() && (--it)->second >= L) {
		L = min(L, it->first);
		R = max(R, it->second);
		is.erase(it);
	}
	return is.insert(before, {L,R});
}

void removeInterval(set<pair<int, int>>& is, int L, int R) {
	if (L == R) return;
	auto it = addInterval(is, L, R);
	auto r2 = it->second;
	if (it->first == L) is.erase(it);
	else (int&)it->second = L;
	if (R != r2) is.emplace(R, r2);
}


// Alternatively
typedef std::map< int, int > interval_set;
typedef std::pair< const int, int > interval; // {one greater than top, bottom}

bool split_interval( interval_set & s, int p ) {
    interval_set::iterator it = s.upper_bound( p );
    if ( p < it->second ) return false; // Interval doesn't exist. Bail out.

    s.insert( interval{ p + 1, it->second } ); // Insert a new lower-part interval.
    it->second = p; // Cut the lower part from the existing interval.
    return true;
}

intervals[ 26 ] = 14; // Insert interval [14, 25]

intervals[ 21 ] = 14; // Insert interval [14, 20]
intervals[ 26 ] = 21; // Cut [14, 25] down to [21, 25]
