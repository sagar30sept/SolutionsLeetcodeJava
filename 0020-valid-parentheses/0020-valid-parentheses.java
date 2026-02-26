class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        
        for (char x : s.toCharArray()) {
            if (x == '(' || x == '{' || x == '[') {
                stack.push(x);
            } else if (stack.isEmpty() ||
                      (x == ')' && stack.peek() != '(') ||
                      (x == '}' && stack.peek() != '{') ||
                      (x == ']' && stack.peek() != '[')) {
                return false;
            } else {
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
}
