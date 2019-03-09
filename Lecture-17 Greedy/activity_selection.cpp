#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second < b.second;
}

int main(){

	vector<pair<int,int> > v;
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int s,e;
		cin>>s>>e;
		v.push_back(make_pair(s,e));
	}
	//sort the activities according to the end time
	sort(v.begin(),v.end(),cmp);

	//activitiy 
	int act = 1;
	int endTime = v[0].second;
	for(int i=1;i<v.size();i++){
		pair<int,int> current_act = v[i];
		int current_start = v[i].first;
		if(current_start>=endTime){
			act++;
			endTime = current_act.second;
		}
	}
	cout<<act<<endl;	
	

	return 0;
}