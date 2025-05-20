void reverseLL(Node** head)
{
    // Create a stack "s" of Node type
    stack<Node*> s;
    Node* temp = *head;
    while (temp->next != NULL) {
        // Push all the nodes in to stack
        s.push(temp);
        temp = temp->next;
    }
    *head = temp;
    while (!s.empty()) {
        // Store the top value of stack in list
        temp->next = s.top();
        // Pop the value from stack
        s.pop();
        // update the next pointer in the list
        temp = temp->next;
    }
    temp->next = NULL;
}
