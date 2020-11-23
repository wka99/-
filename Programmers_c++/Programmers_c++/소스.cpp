/*
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

vector<int> c;
set<vector<int>> ways;
int maxCnt = 0;

void eatCookies(int prev, int cnt, vector<int> tmp){
	if(prev==c.size()-1){
		if(maxCnt<=cnt){
			maxCnt = cnt;
			ways.insert(tmp);
		}
	}
	for(int i=prev+1;i<c.size();i++){
		if(c[prev]<c[i]){
			tmp.push_back(c[i]);
			eatCookies(i, cnt+1, tmp);
			tmp.pop_back();
		}
		else{
			if(maxCnt<=cnt){
				maxCnt = cnt;
				ways.insert(tmp);
			}
		}
	}
}
vector<int> solution(vector<int> cookies, int k)
{
	vector<int> answer;
	c = cookies;
	for(int i=0;i<cookies.size();i++){
		vector<int> tmp;
		tmp.push_back(cookies[i]);
		eatCookies(i, 1, tmp);
	}
	set<vector<int>>::iterator it=ways.begin();
	vector<vector<int>> maxways;
	for(it;it!=ways.end();it++){
		if((*it).size()==maxCnt)
			maxways.push_back(*it);
	}
	sort(maxways.begin(), maxways.end());
	answer = maxways[k-1];
	return answer;
}
*/
/*
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

vector<int> c;
vector<vector<int>> ways;
int maxCnt = 0;

void findWays(int prev, int cnt, vector<int> tmp){
	if(cnt==maxCnt){
		ways.push_back(tmp);
		return;
	}
	for(int i=prev+1;i<c.size();i++){
		if(c[prev]<c[i]){
			tmp.push_back(c[i]);
			findWays(i, cnt+1, tmp);
			tmp.pop_back();
		}
	}
}
void eatCookies(int prev, int cnt){
	if(prev==c.size()-1){
		if(maxCnt<cnt){
			maxCnt = cnt;
		}
	}
	for(int i=prev+1;i<c.size();i++){
		if(c[prev]<c[i]){
			eatCookies(i, cnt+1);
		}
		else{
			if(maxCnt<cnt){
				maxCnt = cnt;
			}
		}
	}
}
vector<int> solution(vector<int> cookies, int k)
{
	vector<int> answer;
	c = cookies;
	for(int i=0;i<cookies.size();i++){
		eatCookies(i, 1);
	}
	for(int i=0;i<cookies.size();i++){
		vector<int> tmp;
		tmp.push_back(cookies[i]);
		findWays(i, 1, tmp);
	}
	sort(ways.begin(), ways.end());
	answer = ways[k-1];
	return answer;
}
*/