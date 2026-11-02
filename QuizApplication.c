// Quiz Application
// • Display multiple-choice questions with four options.
// • Accept answers from the user.
// • Calculate and display the final score.
// • Use arrays, functions, conditional statements, and loops.( if applicable)

#include <stdio.h>

int score = 0;
int totalQuestions = 0;
int currentSet = 1;
int exitRequested = 0;
char studentName[50];
char studentUSN[20];
int intake();
void programmingC();
void python();
void mathematics();
void linuxQuiz();
int readInt(const char* prompt, int minimum, int maximum);
int chooseQuestionSet();
void runSelectedSet(int set);
void runQuiz(const char* questions[], const char* options[][4], const int answers[], int questionCount);
void displayQuestion(int questionNumber, const char* question,const char* options[]);
int getAnswer();
void calculateScore(int userAnswer, int correctOption);

int intake() {
    int character;
    printf("Welcome to the Quiz Application!\n");
    printf("Enter your name: ");
    if (scanf("%49s", studentName) != 1) {
        return 0;
    }
    while ((character = getchar()) != '\n' && character != EOF) {
    }
    printf("Enter your USN: ");
    if (scanf("%19s", studentUSN) != 1) {
        return 0;
    }
    while ((character = getchar()) != '\n' && character != EOF) {
    }
    printf("Hello, %s! Let's start the quiz.\n", studentName);
    return 1;
}

void programmingC() {
    const char* questions[] = {
        "What is the output of printf(\"%d\", 5 + 3 * 2)?",
        "Which of the following is a valid C variable name?",
        "Which operator is used for logical AND in C?",
        "Which keyword prevents a variable from being modified?",
        "What is the result of 10 % 3?",
        "Which function reads one character from standard input?",
        "What does break do inside a loop?",
        "Which is the logical NOT operator?",
        "What is the first index of a C array?",
        "Which header declares printf()?"
    };
    const char* options[][4] = {
        {"11", "16", "10", "None of the above"},
        {"1variable", "my_variable", "variable-name", "variable name"},
        {"&&", "&", "|", "||"},
        {"const", "static", "volatile", "extern"},
        {"1", "3", "0", "0.33"},
        {"scanf()", "gets()", "getchar()", "read()"},
        {"Skips the current iteration", "Exits the loop", "Restarts the loop", "Halts the program"},
        {"!", "~", "-", "NOT"},
        {"1", "-1", "0", "Depends on array size"},
        {"<conio.h>", "<stdlib.h>", "<stdio.h>", "<math.h>"}
    };
    const int answers[] = {1, 2, 1, 1, 2, 3, 2, 1, 3, 3};

    runQuiz(questions, options, answers, 10);
}

void python() {
    const char* questions[] = {
        "Which keyword defines a function?",
        "Which symbol starts a single-line comment?",
        "What is 3 ** 2?",
        "Which type stores True or False?",
        "How do you create an empty list?",
        "Which keyword begins a conditional?",
        "Which list method adds an item to the end?",
        "What is the first list index?",
        "Which collection stores key-value pairs?",
        "What does len(\"Python\") return?"
    };
    const char* options[][4] = {
        {"func", "def", "function", "define"},
        {"//", "#", "/*", "--"},
        {"6", "8", "9", "27"},
        {"bool", "binary", "truth", "logic"},
        {"{}", "()", "[]", "<>"},
        {"if", "when", "case", "check"},
        {"append()", "push()", "add()", "insertEnd()"},
        {"0", "1", "-1", "It depends"},
        {"list", "tuple", "dictionary", "set"},
        {"5", "6", "7", "Error"}
    };
    const int answers[] = {2, 2, 3, 1, 3, 1, 1, 1, 3, 2};

    runQuiz(questions, options, answers, 10);
}

void mathematics() {
    const char* questions[] = {
        "What is 7 + 8?",
        "What is 9 x 6?",
        "What is the square root of 81?",
        "How many degrees are in a right angle?",
        "What is the perimeter of a square with side 4?",
        "How many sides does a hexagon have?",
        "What is 100 divided by 4?",
        "Which number is an even prime?",
        "What is the absolute value of -9?",
        "What is 12 - 5?"
    };
    const char* options[][4] = {
        {"14", "15", "16", "17"},
        {"45", "54", "56", "63"},
        {"7", "8", "9", "10"},
        {"45", "60", "90", "180"},
        {"8", "12", "16", "20"},
        {"5", "6", "7", "8"},
        {"20", "25", "40", "50"},
        {"0", "1", "2", "4"},
        {"-9", "0", "9", "18"},
        {"5", "6", "7", "8"}
    };
    const int answers[] = {2, 2, 3, 3, 3, 2, 2, 3, 3, 3};

    runQuiz(questions, options, answers, 10);
}

void linuxQuiz() {
    const char* questions[] = {
        "Which command lists files in the current directory?",
        "Which command prints the current working directory?",
        "Which command changes the current directory?",
        "Which command displays a text file's contents?",
        "Which command creates a directory?",
        "Which command copies files?",
        "Which command moves or renames a file?",
        "Which command removes a file?",
        "Which command shows the current user's name?",
        "Which character represents the root directory?"
    };
    const char* options[][4] = {
        {"pwd", "ls", "cd", "cat"},
        {"dir", "where", "pwd", "path"},
        {"cd", "mv", "chdir", "goto"},
        {"cat", "rm", "touch", "ps"},
        {"mkdir", "rmdir", "mkfile", "newdir"},
        {"cp", "mv", "ln", "copy"},
        {"mv", "cp", "rename", "shift"},
        {"rm", "del", "erase", "drop"},
        {"whoami", "username", "user", "idname"},
        {"~", "/", ".", "*"}
    };
    const int answers[] = {2, 3, 1, 1, 1, 1, 1, 1, 1, 2};

    runQuiz(questions, options, answers, 10);
}

int readInt(const char* prompt, int minimum, int maximum) {
    int value;
    int result;
    int character;
    int validLine;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);
        if (result == EOF) {
            return -1;
        }
        if (result != 1) {
            while ((character = getchar()) != '\n' && character != EOF) {
            }
            printf("Please enter a number.\n");
            continue;
        }

        validLine = 1;
        while ((character = getchar()) != '\n' && character != EOF) {
            if (character != ' ' && character != '\t' && character != '\r') {
                validLine = 0;
            }
        }
        if (!validLine) {
            printf("Please enter one number only.\n");
        } else if (value < minimum || value > maximum) {
            printf("Please enter a number from %d to %d.\n", minimum, maximum);
        } else {
            return value;
        }
    }
}

int chooseQuestionSet() {
    printf("\nSelect a set of questions:\n");
    printf("1. Programming C\n");
    printf("2. Python\n");
    printf("3. Mathematics\n");
    printf("4. Linux\n");
    return readInt("Choose a set (1-4): ", 1, 4);
}

void runSelectedSet(int set) {
    switch (set) {
        case 1:
            printf("\nStarting the C quiz.\n");
            programmingC();
            break;
        case 2:
            printf("\nStarting the Python quiz.\n");
            python();
            break;
        case 3:
            printf("\nStarting the mathematics quiz.\n");
            mathematics();
            break;
        case 4:
            printf("\nStarting the Linux quiz.\n");
            linuxQuiz();
            break;
    }
}

void runQuiz(const char* questions[], const char* options[][4], const int answers[], int questionCount) {
    const char* incorrectQuestions[10];
    const char* selectedAnswers[10];
    const char* correctAnswers[10];
    int incorrectCount = 0;
    int scoreAtStart = score;
    int questionsAsked = 0;
    int interrupted = 0;

    while (questionsAsked < questionCount) {
        int chosenIndex = questionsAsked;
        const char* displayOptions[4];
        int displayedCorrectOption = 0;
        int answer;

        for (int i = 0; i < 4; i++) {
            displayOptions[i] = options[chosenIndex][i];
            if (i + 1 == answers[chosenIndex]) {
                displayedCorrectOption = i + 1;
            }
        }

        displayQuestion(questionsAsked + 1, questions[chosenIndex], displayOptions);
        answer = getAnswer();
        if (answer == -1) {
            interrupted = 1;
            break;
        }
        if (answer == 0) {
            exitRequested = 1;
            printf("\nExiting the quiz now.\n");
            break;
        }

        questionsAsked++;
        totalQuestions++;
        calculateScore(answer, displayedCorrectOption);
        if (answer != displayedCorrectOption) {
            incorrectQuestions[incorrectCount] = questions[chosenIndex];
            selectedAnswers[incorrectCount] = options[chosenIndex][answer - 1];
            correctAnswers[incorrectCount] = options[chosenIndex][answers[chosenIndex] - 1];
            incorrectCount++;
        }
    }

    if (questionsAsked > 0) {
        printf("\nScore for this set: %d / %d\n", score - scoreAtStart, questionsAsked);
        printf("Cumulative score: %d / %d\n", score, totalQuestions);
    }
    if (incorrectCount > 0) {
        printf("\nReview of incorrect answers:\n");
        for (int i = 0; i < incorrectCount; i++) {
            printf("%d. %s\n", i + 1, incorrectQuestions[i]);
            printf("   Your answer: %s\n", selectedAnswers[i]);
            printf("   Correct answer: %s\n", correctAnswers[i]);
        }
    } else if (questionsAsked > 0 && !interrupted) {
        printf("\nExcellent! You answered every question correctly.\n");
    }
    if (interrupted) {
        printf("\nQuiz stopped because input ended.\n");
    }
}

void displayQuestion(int questionNumber, const char* question, const char* options[]) {
    printf("\nQuestion %d: %s\n", questionNumber, question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
}

int getAnswer() {
    return readInt("Enter your answer (1-4), or 0 to exit the quiz: ", 0, 4);
}

void calculateScore(int userAnswer, int correctOption) {
    if (userAnswer == correctOption) {
        score++;
    }
}

int main() {
    int choice;

    if (!intake()) {
        return 0;
    }

    currentSet = chooseQuestionSet();
    if (currentSet == -1) {
        return 0;
    }
    runSelectedSet(currentSet);

    while (!exitRequested) {
        printf("\nSelect an option:\n");
        printf("1. Restart this set (reset score)\n");
        printf("2. Change set (reset score)\n");
        printf("3. Continue with another set (keep score)\n");
        printf("4. Exit\n");
        choice = readInt("Choose an option (1-4): ", 1, 4);
        if (choice == -1) {
            break;
        }

        if (choice == 1) {
            score = 0;
            totalQuestions = 0;
            runSelectedSet(currentSet);
        } else if (choice == 2 || choice == 3) {
            if (choice == 2) {
                score = 0;
                totalQuestions = 0;
            }
            currentSet = chooseQuestionSet();
            if (currentSet == -1) {
                break;
            }
            runSelectedSet(currentSet);
        } else {
            break;
        }
        if (exitRequested) {
            break;
        }
    }

    printf("\nThank you for attempting the quiz, %s!\n", studentName);
    printf("USN: %s\n", studentUSN);
    printf("Final score: %d / %d\n", score, totalQuestions);
    return 0;
}