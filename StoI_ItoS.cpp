int StoI(string s) {
	int v, i, result = 0;
	for (i = 0; i < SZ(s); i++) {
		v = s[i] - '0';
		result = result * 10 + v;
	}
	return result;
}

string ItoS(int num) {
	if (num == 0)
		return "0";
	string str;
	while (num != 0) {
		int nlet = num % 10;
		str += (nlet + '0');
		num /= 10;
	}
	reverse(ALL(str));

	return str;
}
