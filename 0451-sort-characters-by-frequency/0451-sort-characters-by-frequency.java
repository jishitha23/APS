import java.util.*;

class Solution {
    public String frequencySort(String s) {

        // Count frequency of each character
        HashMap<Character, Integer> freq = new HashMap<>();

        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        // Create buckets based on frequency
        List<Character>[] bucket = new ArrayList[s.length() + 1];

        for (char c : freq.keySet()) {
            int count = freq.get(c);

            if (bucket[count] == null) {
                bucket[count] = new ArrayList<>();
            }

            bucket[count].add(c);
        }

        // Build answer from highest frequency to lowest
        StringBuilder ans = new StringBuilder();

        for (int i = s.length(); i >= 1; i--) {

            if (bucket[i] != null) {

                for (char c : bucket[i]) {

                    for (int j = 0; j < i; j++) {
                        ans.append(c);
                    }
                }
            }
        }

        return ans.toString();
    }
}