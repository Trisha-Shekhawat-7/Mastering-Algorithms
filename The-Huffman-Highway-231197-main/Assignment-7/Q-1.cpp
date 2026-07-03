#include <bits/stdc++.h>
using namespace std; 

int maxProjectValue(vector<int>& Values, vector<vector<string>>& LanguageProficiencyList, set<string>& knownLanguages, int N) {
    vector<int> dp(N + 1, -1e9); 
    dp[0] = 0; 

    for (int i = 0; i < N; i++) {
        bool canTake = true;
        for (auto& lang : LanguageProficiencyList[i]) {
            if (knownLanguages.find(lang) == knownLanguages.end()) {
                canTake = false; 
                break; 
            }
        }
        if (canTake) {
            dp[i + 1] = max(dp[i + 1], Values[i] + dp[i]); 
        } else {
            dp[i + 1] = max(dp[i + 1], dp[i]); 
        }
    }

    return dp[N]; 
}

int main() {
    int N; 
    cout << "Enter the number of projects: "; 
    cin >> N; 
    cout << endl; 
    
    vector<int> Values(N); 
    cout << "Enter the reward values for the projects: ";
    for (int i = 0; i < N; i++) {
        cin >> Values[i]; 
    }
    cout << endl; 

    vector<vector<string>> LanguageProficiencyList(N);  
    string language; 
    for (int i = 0; i < N; i++) {
        cout << "Enter the number of languages required for project " << i + 1 << ": ";
        int numOfLanguages; 
        cin >> numOfLanguages; 
        cout << "Enter all the languages required for this project: ";
        while (numOfLanguages--) {
            cin >> language; 
            LanguageProficiencyList[i].push_back(language); 
        }
        cout << endl;
    }

    set<string> knownLanguages; 
    int num; 
    cout << "Enter the number of known languages: "; 
    cin >> num;
    cout << "Enter the known languages: ";
    for (int i = 0; i < num; i++) {
        cin >> language; 
        knownLanguages.insert(language); 
    }

    cout << "Maximum total reward possible is: " << maxProjectValue(Values, LanguageProficiencyList, knownLanguages, N) << endl; 
    return 0; 
}
