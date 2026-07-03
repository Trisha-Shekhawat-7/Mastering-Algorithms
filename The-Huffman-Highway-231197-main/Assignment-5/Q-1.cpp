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
 
    int n_trains ; 
    cout<<"Enter the number of trains : " ;
    cin>> n_trains ; 
    nl ; 

    vector<pii> arrival_time( n_trains ) , departure_time( n_trains ) ; 
    vector<int> platforms(n_trains , -1) ;
    int a_time , d_time ; 

    cout<<"Enter the arrival time of each train : " ; 
    nl ; 
    rep( i , 0 , n_trains){
        cout<<"Arrival time of train - "<<i+1<<" : ";
        cin>>a_time ; 
        arrival_time[i] = { a_time , i} ;
        nl ;
    }
    rep( i , 0 , n_trains){
        cout<<"Departure time of train - "<<i+1<<" : " ;
        cin>>d_time ;
        departure_time[i] = {d_time , i} ;
        nl ;
    }

    sort(all(arrival_time)) ;
    sort(all(departure_time)) ;

    int a_iterator = 0 , d_iterator = 0 ; 
    int curr_platform = 1 ,  max_platforms = 1 ; 
    platforms[arrival_time[a_iterator].s] = curr_platform ;
    a_iterator++ ;
    while( a_iterator < n_trains && d_iterator<n_trains){
        if(arrival_time[a_iterator].f <= departure_time[d_iterator].f){
            curr_platform ++ ; 
            platforms[arrival_time[a_iterator].s] = curr_platform ; 
            a_iterator++ ; 
        }
        else{
            curr_platform-- ;
            d_iterator++ ;
        }

        max_platforms = max( curr_platform , max_platforms) ;
    }
    
    cout<<"Minimum number of platforms required is : "<<max_platforms<<endl ;
    cout<<"Platform number of each train is : " <<endl;
    rep( i , 0 , n_trains){
        cout<<"Train "<<i+1<<" : "<<platforms[i]<<endl ;
    }
    return 0;
}
