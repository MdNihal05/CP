vector<int> computePrefix(string str) {

	int m=int(str.length());
	vector<int> prefix(m);
	for(int i=1,k=0;i<m;++i)
	{
		if(k>0&&str[i]!=str[k])
			k=prefix[k-1];
		if(str[k]==str[i])
			prefix[i]=++k;
		else
			prefix[i]=k;
	}

	return prefix;
}

vector<int>KMP(string &str, string pat) {
	int m = int(str.length());
	int n = int(pat.length());
	vector<int> longestPrefix = computePrefix(pat);
        vector<int>ans;
	for (int i = 0, k = 0; i < m; ++i) {
		if (k > 0 && pat[k] != str[i])
			k = longestPrefix[k - 1];
		if (str[i] == pat[k])
			++k;
		if (k == n) {
            ans.push_back(i-n+1);
			//more than one pattern
			k = longestPrefix[k - 1];
		}
	}
    return ans;
}
