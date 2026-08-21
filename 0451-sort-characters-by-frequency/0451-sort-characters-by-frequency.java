class Solution {

    public String frequencySort(String s) {

        // Count frequency of each character
        int[] freq = new int[128];

        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i)]++;
        }

        // Create list of characters
        Character[] chars = new Character[128];
        int count = 0;

        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                chars[count++] = (char) i;
            }
        }

        // Sort characters by decreasing frequency
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {

                if (freq[chars[i]] < freq[chars[j]]) {

                    Character temp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = temp;
                }
            }
        }

        // Build result
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < count; i++) {

            char c = chars[i];

            for (int j = 0; j < freq[c]; j++) {
                result.append(c);
            }
        }

        return result.toString();
    }
}