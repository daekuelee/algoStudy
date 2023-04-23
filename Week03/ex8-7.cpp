#include <iostream>

using namespace std;

const int Max = 100;
int cache[Max+1][Max+1];

string W, S;
bool match(int wpos, int spos){
	int &ret = cache[wpos][spos];

	if (ret != -1) return (ret);
	while (wpos < W.size() && spos < S.size() && 
	(W[wpos] == '?' || W[wpos] == S[spos])){
		wpos++;
		spos++;
	}
	if (wpos == W.size())
		return (spos == S.size());
	if (W[wpos] == '*'){
		for (int skip = 0; skip + spos < S.size(); skip++){
			if (match(wpos + 1, spos + skip))
				return (ret = true);
		}
	}
	return (ret = false);
}

bool optMatch(int wpos, int spos){
	int &ret = cache[wpos][spos];

	if (ret != -1) return (ret);

	if (wpos == W.size())
		return (spos == S.size());

	if (wpos < W.size() && spos < S.size() && 
	(W[wpos] == '?' || W[wpos] == S[spos]))
		return (ret = optMatch(wpos+1, spos+1));

	if (W[wpos] == '*'){
		if (optMatch(wpos, spos) || optMatch(wpos, spos+1))
			return (ret = true);
	}
	return (ret = false);
}