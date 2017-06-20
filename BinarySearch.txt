//Searching for the last True in TTTTTTTTTTTTTTFFFFFFFFFFFFF pattern
//change val to !val to search for last False in FFFFFFFFFTTTTTTTTT pattern
vlong b_s(vlong s, vlong e) {
	while (s < e) {
		vlong mid = s + (e - s + 1) / 2;
		if (valid(mid))
			s = mid;
		else
			e = mid - 1;
	}
	return s;
}
//Searching for the first True in FFFFFFFFTTTTTTTTT pattern
//change val to !val to search for the first False in TTTTTTTTTFFFFFFF pattern
vlong bs(vlong s, vlong e) {
	while (s < e) {
		vlong mid = (s + (e - s) / 2);
		if (valid(mid))
			e = mid;
		else
			s = mid + 1;
	}
	return s;
}

//first true double 
double bs(double l, double r) {
	int cnt = 0;
	while (fabs(l - r) > eps && cnt < 100) {
		double mid = (l + r) / 2;
		if (!valid(mid))
			l = mid;
		else
			r = mid;
		cnt++;
	}
	return l;
}
