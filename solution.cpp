#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &b, int k,int mid){
    int pcount=1;
    int time=0;
    for(int i : b){

    if(time+i<=mid){
        time += mid;

    }
    else{
         pcount++;
         if(pcount > k || i > mid ){
            return false;
         }
         time = i;
    }
    return true;

    }
}
int findLargestMinDistance(vector<int> &boards, int k){
int s=0;
int sum=0;
for(int i: boards){
    sum += i;
}
int e=sum;
int ans=-1;
while(s<=e){
    int mid = s+(e-s)/2;
if(ispossible(boards,k,mid)){
    ans=mid;
    e=mid-1;
}
else{
    s=mid+1;
}
}
return ans;

}