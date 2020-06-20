#include <iostream>
#include <vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int n = stops.size();
    vector<int> x;

    for(int i=0; i<n; i++){
        x.push_back(stops[i]);
    }
    x.insert(x.begin(),1,0);   //insert 0 one time in front of begin.
    x.insert(x.end(),1, dist);  //insert dist one time at front of end.

    int num_refil = 0, current_refil = 0, last_refil = 0;
    while(current_refil <= n){
        last_refil = current_refil;
        while(current_refil <= n && (x[current_refil+1]-x[last_refil]) <= tank){
            current_refil += 1;
        }
        if(current_refil == last_refil){
            return -1;
        }
        if(current_refil <= n){
            num_refil += 1;
        }
    }
    return num_refil;
}


int main() {
    int d = 0;
    cin >> d;  //distance bw cities
    int m = 0;
    cin >> m;  //atmost miles
    int n = 0;
    cin >> n;    //number of stops

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

/* ALGORITHM
numRefills = 0 
currentPosition = 0 
while(currentPosition <= n){ 
    lastPosition = currentPosition 
while(currentPosition <= n && x[currentPosition + 1] – x[lastPosition] <= L) {     
    currentPosition++; 
} 
if (currentPosition == lastPosition) 
return IMPOSSIBLE; 
if (currentPosition <= n) 
numRefills ++; 
} 
return numRefills
*/
