#include <iostream>
#include <vector>

using namespace std;

void findSubsets(vector<int>& s, int n, vector<int>& subset, int d, int sum, int index) {
    if (sum == d) {
        cout << "Solution found: {";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
        return;
    }

    if (index == n || sum > d) {
        return;
    }

   
    subset.push_back(s[index]);
    sum += s[index];

    
    findSubsets(s, n, subset, d, sum, index + 1);

   
    subset.pop_back();
    sum -= s[index];

   
    findSubsets(s, n, subset, d, sum, index + 1);
}

int main() {
    int n, d;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> s(n);
    cout << "Enter the elements of the set:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    cout << "Enter the target sum: ";
    cin >> d;

    vector<int> subset;
    findSubsets(s, n, subset, d, 0, 0);

    return 0;
}
