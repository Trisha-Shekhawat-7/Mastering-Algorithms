#include<bits/stdc++.h>
using namespace std; 

#define ll long long int 
#define lld long double
const long long int mod = 1e9+7; 
#define vi vector<ll>
#define vii vector<vector<ll>>
#define pb push_back 
#define get(a) ll a; cin >> a;
#define rep(i, n) for(ll i = 0; i < n; i++)

const lld PI = 3.14159;
const lld precision = 0.000001 ;

// Power function for floating-point base and integer exponent
lld power(lld a, ll b) {
    if(b==0) return 1.0 ; 
    lld ans = 1 ;
    while(b){
        if(b&1){
            ans*=a ;
        }
        a = a*a ; 
        b = b/2 ; 
        
    }
    return ans ;
}

// Factorial function
ll fac(ll a) {
    if (a == 0 || a == 1) return 1;
    else {
        ll x = 1;
        for (ll i = 2; i <= a; i++) x *= i;
        return x;
    }
}

// Sine function using Taylor series expansion
lld sine(lld a) {
    // Convert degrees to radians
    a = a * PI / 180.0;
    lld term = a, sum = a;
    ll i = 1;
    while (abs(term) > precision) {
        term *= -1 * a * a / ((2 * i) * (2 * i + 1));
        sum += term;
        i++;
    }
    return sum;
}

// Natural logarithm function using Taylor series expansion for ln(1 + x)
lld ln(lld a) {
    if (a <= 0) return -1; // ln is not defined for non-positive values
    a = (a - 1) / (a + 1); // Transform to make series converge faster
    lld term = a, sum = 2 * a;
    lld a2 = a * a;
    ll i = 1;
    while (abs(term) > precision) {
        term *= a2 * (2 * i - 1) / (2 * i + 1);
        sum += 2 * term;
        i++;
    }
    return sum;
}

// Cosine function using Taylor series expansion
lld cosine(lld a) {
    
    a = a * PI / 180.0; // Convert degrees to radians
    lld term = 1, sum = 1;
    ll i = 1;
    while (abs(term) > 0.000001) {
        term *= -1 * a * a / ((2 * i - 1) * (2 * i));
        sum += term;
        i++;
    }
    return sum;
}

// Exponential function using Taylor series expansion
lld exponent(lld a) {
    lld term = 1, sum = 1;
    ll i = 1;
    while (abs(term) > precision) {
        term *= a / i;
        sum += term;
        i++;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    get(n) ; 
    lld x ; cin>>x ;
    string s ;
    
    while(n--){
        cin>>s ;
        if(s=="ln") cout<<ln(x)<<endl ;
        else if(s=="sin") cout<<sine(x)<<endl ;
        else if(s=="cos") cout<<cosine(x)<<endl ; 
        else if(s=="exp") cout<<exponent(x)<<endl ;
    }
    return 0; 
}
