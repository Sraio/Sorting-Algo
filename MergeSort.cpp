 #include<bits/stdc++.h>
using namespace std;
void Merge(vector<int> &arr,int st,int mid,int end){
    int left=st,right=mid+1;
    vector<int> temp;
    while(left <= mid && right <= end){
        if(arr[left]>= arr[right]){
            temp.push_back(arr[left]);
            left++;

        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=end){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=0;i<temp.size();i++){
        arr[i+st]=temp[i];
    }
}
void mergeSort(vector <int> &arr,int st,int end){
    if(st<end) {

    int mid=st+(end-st)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        Merge(arr,st,mid,end);
    
    }
}
int main(){
    vector <int> roll={4,3,1,9,4,12,0,8,34,11,14,17,33,14,27,21};
    int st=0,end=roll.size()-1;
    mergeSort(roll,st,end);
    for(int i=0;i<=end;i++){
        cout<<roll[i]<<" ";
    }

}