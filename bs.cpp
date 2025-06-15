bool check(int mid) {
    // Function to check if 'mid' is a valid answer
    // Return true if 'mid' is valid, false otherwise
}

int binarySearch(int low, int high) {
    int ans = -1; // Initialize the answer to an invalid value

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;  // Store the current valid answer
            // Adjust the search space based on the problem requirements
            // For example: if we need the smallest valid answer, move 'high' to mid -1
            // For example: if we need the largest valid answer, move 'low' to mid + 1
        } else {
            // Adjust the search space based on the problem requirements
            // For example: move 'low' to mid + 1 if 'mid' is too small
            // For example: move 'high' to mid - 1 if 'mid' is too large
        }
    }
    return ans; // Return the final answer
}