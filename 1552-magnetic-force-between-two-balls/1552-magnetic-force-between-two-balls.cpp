class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
     sort(position.begin(), position.end());
     int low = 1;
     int high = position.back() - position.front();
     while(low<=high){
        int mid = low + (high - low) /2;
        int count = 1;
        int lastposition = position[0];
        for(int i = 1; i < position.size(); i++){
            if(position[i]-lastposition >= mid){
                count++;
                lastposition = position[i];
            }
        }
        if(count >= m){
            low =  mid + 1;
        }
        else{
            high = mid - 1;

        }
     }   
     return high;
    }
};