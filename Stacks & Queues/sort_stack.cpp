void sortStack(stack<int>& stack) {
    stack<int> tempStack; // Create a temporary stack to hold sorted elements

    while (!stack.empty()) {
        int curr = stack.top(); // Get the top element from the original stack
        stack.pop();

        while (!tempStack.empty() && tempStack.top() < curr) {
            // Move elements from tempStack to the original stack until we find the correct position for the current element
            stack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(curr); // Insert the current element into the tempStack at the correct position
    }

    // Copy elements from tempStack back to the original stack to obtain the sorted stack
    while (!tempStack.empty()) {
        stack.push(tempStack.top());
        tempStack.pop();
    }
}
