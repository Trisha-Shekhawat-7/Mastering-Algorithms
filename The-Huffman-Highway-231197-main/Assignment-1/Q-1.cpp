#include<bits/stdc++.h>

using namespace std; 
#define ll long long int 
#define vi vector<ll>
#define vii vector<vector<ll>>
#define pb push_back 
#define get(a) ll a ; cin>>a ;
#define rep(i,n) for(ll i=0 ; i< n; i++)   
#define rrep(i,n) for(ll i=n ; i>0 ; i--)
#define f first 
#define s second
const long long int mod = 1e9+7 ;
const long long int N = 1e8  ;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //Input n , the height of the pyramid type pattern which we will print 
    get(n) ; 
    
    //Driver loop .. each iteration of this loop will print one line of the pyramid 
    rep(i,n){ 
        //We have to make n half pyramids , for this we require another loop 
        rep(j,n){
            // we want alternate left and right facing pyramids 
            //Use even j to make right facing pyramids and odd j for left facing
            // NOTE THAT i,j START FROM 0 
            
            
            if(j%2==0){  // Right facing pyramid 
                rep(k,i+1) cout<<k+1 ;
                rep(k,n-i-1) cout<<" " ;
            }
            else{ //Left facing pyramid 
                rep(k,n-i-1) cout<<" " ;
                rrep(k,i+1) cout<<k;
            }
        }
        
        
        cout<<endl ; //Moving to the next line ;
    }
    return 0; 
}
