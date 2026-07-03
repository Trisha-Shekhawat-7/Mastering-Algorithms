#include <bits/stdc++.h>

//Necessary macros to make code shorter 
#define all(x)  (x).begin() , (x).end()
#define rep(i , a , b)  for(int i = a ; i<b ; i++)
#define pii pair<int,int> 
#define f first 
#define s second 
#define nl cout<<endl 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n_file = 0 ; 
    cout<<"Enter the number of files : "; 
    cin>>n_file ; 
    nl ; 
    int file_size = 0 ;
    priority_queue<int> pq ; 
    cout<<"Enter the file sizes : ";
    rep(i,0,n_file){
        cin>>file_size; 
        pq.push(-file_size) ;
    }

    int total_cost = 0 ; 
    while(pq.size() > 1 ){
        int merge_cost  = 0 ; 
        rep(i , 0 , 2){
            merge_cost -= pq.top() ;
            pq.pop() ;
        }
        pq.push(-merge_cost) ; 
        total_cost += merge_cost ; 
    }

    cout<<"The minimum cost of merging all the files into a single file is "<<total_cost ; 
    return 0;
}
