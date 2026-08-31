class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;

        // Minimum capacity = heaviest package
        // Maximum capacity = total weight
        for (int weight : weights) {
            low = max(low, weight);
            high += weight;
        }

        while (low < high) {

            int mid = low + (high - low) / 2;

            int requiredDays = 1;
            int currentWeight = 0;

            // Check: mid capacity mein kitne days lagenge?
            for (int weight : weights) {

                if (currentWeight + weight > mid) {
                    requiredDays++;
                    currentWeight = 0;
                }

                currentWeight += weight;
            }

            // Capacity possible hai
            if (requiredDays <= days) {
                high = mid;
            }
            // Capacity kam hai
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};