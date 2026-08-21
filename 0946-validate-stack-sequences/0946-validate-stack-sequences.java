import java.util.*;

class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {

        Stack<Integer> stack = new Stack<>();

        int j = 0;

        for (int num : pushed) {

            // Push the element
            stack.push(num);

            // Pop while the top matches popped[j]
            while (!stack.isEmpty() && stack.peek() == popped[j]) {
                stack.pop();
                j++;
            }
        }

        // If all elements were successfully popped
        return stack.isEmpty();
    }
}