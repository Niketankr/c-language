#include <stdio.h>
#include <string.h>

void respond(char input[]) {
    if (strstr(input, "hello") || strstr(input, "hi"))
        printf("Bot: Hello! How can I help you today?\n");
    else if (strstr(input, "bye"))
        printf("Bot: Goodbye! Have a great day!\n");
    else if (strstr(input, "help"))
        printf("Bot: I can assist with orders, support, or general questions.\n");
    else
        printf("Bot: I'm sorry, I didn't understand that.\n");
}

int main() {
    char userInput[100];

    printf("WhatsApp ChatBot Simulation\n");
    printf("Type 'bye' to exit.\n\n");

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0; // remove newline

        if (strcmp(userInput, "bye") == 0) {
            respond(userInput);
            break;
        }

        respond(userInput);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

void respond(char input[]) {
    // Greetings
    if (strstr(input, "hello") || strstr(input, "hi"))
        printf("Bot: Hello! How can I help you today?\n");

    // State Capitals
    else if (strstr(input, "capital of Maharashtra"))
        printf("Bot: The capital of Maharashtra is Mumbai.\n");
    else if (strstr(input, "capital of Tamil Nadu"))
        printf("Bot: The capital of Tamil Nadu is Chennai.\n");
    else if (strstr(input, "capital of West Bengal"))
        printf("Bot: The capital of West Bengal is Kolkata.\n");
    else if (strstr(input, "capital of Uttar Pradesh"))
        printf("Bot: The capital of Uttar Pradesh is Lucknow.\n");
    else if (strstr(input, "capital of Rajasthan"))
        printf("Bot: The capital of Rajasthan is Jaipur.\n");

    // Neighboring Country Capitals
    else if (strstr(input, "capital of Nepal"))
        printf("Bot: The capital of Nepal is Kathmandu.\n");
    else if (strstr(input, "capital of Bangladesh"))
        printf("Bot: The capital of Bangladesh is Dhaka.\n");
    else if (strstr(input, "capital of Bhutan"))
        printf("Bot: The capital of Bhutan is Thimphu.\n");
    else if (strstr(input, "capital of Pakistan"))
        printf("Bot: The capital of Pakistan is Islamabad.\n");
    else if (strstr(input, "capital of Myanmar"))
        printf("Bot: The capital of Myanmar is Naypyidaw.\n");

    // Indian Leaders
    else if (strstr(input, "President of India"))
        printf("Bot: The President of India is Droupadi Murmu.\n");
    else if (strstr(input, "Prime Minister of India"))
        printf("Bot: The Prime Minister of India is Narendra Modi.\n");
    else if (strstr(input, "Vice President of India"))
        printf("Bot: The Vice President of India is Jagdeep Dhankhar.\n");

    // Cabinet Ministers
    else if (strstr(input, "Home Minister"))
        printf("Bot: The Home Minister of India is Amit Shah.\n");
    else if (strstr(input, "Finance Minister"))
        printf("Bot: The Finance Minister of India is Nirmala Sitharaman.\n");
    else if (strstr(input, "Defence Minister"))
        printf("Bot: The Defence Minister of India is Rajnath Singh.\n");
    else if (strstr(input, "External Affairs Minister"))
        printf("Bot: The External Affairs Minister is Dr. S. Jaishankar.\n");
    else if (strstr(input, "Education Minister"))
        printf("Bot: The Education Minister is Dharmendra Pradhan.\n");

    // Exit
    else if (strcmp(input, "bye") == 0)
        printf("Bot: Goodbye! Have a great day!\n");

    // Default
    else
        printf("Bot: I'm sorry, I didn't understand that.\n");
}

int main() {
    char userInput[100];

    printf("=== India Info ChatBot ===\n");
    printf("Type 'bye' to exit.\n\n");

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = 0;

        respond(userInput);

        if (strcmp(userInput, "bye") == 0)
            break;
    }

    return 0;
}
