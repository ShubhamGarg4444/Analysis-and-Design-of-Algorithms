// we have to maximize the number of activities done by a person if a person can work only on a single activity at a time

#include<bits/stdc++.h>
using namespace std ;

struct Activity 
{
    int start ; // start time of activity
    int end ; // end time of activity
};

// Comparison function to sort activities by their end time
bool compare(Activity a, Activity b)
{
    int e1 = a.end ;
    int e2 = b.end ;
    return e1 < e2 ; // sort the activities in increasing order of their end times
}

// Function to find the maximum number of activities that can be performed
int maxActivities(int n, int s[], int e[])
    // n = number of activities
    // s[] = start time array
    // e[] = end time array
{
    vector<Activity> activity ;
    for(int i=0;i<n;i++)
    {
        activity.push_back({s[i], e[i]}) ;
    }
    
    sort(activity.begin(), activity.end(), compare) ; // sort the activites wrt to the increasing end times (compare function)

    int cnt = 0 ; // no activity started initially
    int last = activity[0].end ; // end time of first activity

    cout<<"selected activity - "<<activity[0].start<<" "<<activity[0].end<<endl ;
    cnt++ ;

    for(int i=1;i<n;i++)
    {
        if(activity[i].start >= last)
        {
            cout<<"selected activity - "<<activity[i].start<<" "<<activity[i].end<<endl ;
            last = activity[i].end ;
            cnt++ ;
        }
        else{
            continue ;
        }
    }
    return cnt ;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    
    int s[n], e[n];
    cout << "Enter start and end times of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }
    
    int maxAct = maxActivities(n, s, e);
    cout << "Maximum number of activities: " << maxAct << endl;
    
    return 0;
}









