#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define vi vector<ll>
#define vii vector<vector<ll>>
#define pb push_back
#define get(a) ll a; cin >> a;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rrep(i, n) for (ll i = n; i > 0; i--)
#define f first
#define s second
const long long int mod = 1e9+7;
const long long int N = 1e8;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 10;

    // Declaring the array and taking input
    int Exam_Scores[n];
    rep(i, n) cin >> Exam_Scores[i];

    // Calculate the average
    int sum = 0;
    double average;
    rep(i, n) sum += Exam_Scores[i];  // finding sum of all values
    average = sum / 10.0;  // calculating average

    // Calculate highest and lowest marks
    int highest_score = 0, lowest_score = 100;
    rep(i, n) {
        highest_score = max(highest_score, Exam_Scores[i]);
        lowest_score = min(lowest_score, Exam_Scores[i]);
    }

    // Calculate number of students above and below average
    int above_avg = 0, below_avg = 0;
    rep(i, n) {
        above_avg += ((double)Exam_Scores[i] > average);
        below_avg += ((double)Exam_Scores[i] < average);
    }

    cout << "Stats of the Exam Scores of the 10 students are as follows: ";
    cout << "\nAverage: " << average;
    cout << "\nHighest Marks: " << highest_score;
    cout << "\nLowest Marks: " << lowest_score;
    cout << "\nNumber of students who scored above average: " << above_avg;
    cout << "\nNumber of students who scored below average: " << below_avg;

    return 0;
}
