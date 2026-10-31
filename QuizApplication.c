// Quiz Application
// • Display multiple-choice questions with four options.
// • Accept answers from the user.
// • Calculate and display the final score.
// • Use arrays, functions, conditional statements, and loops.( if applicable)

#include <stdio.h>

int score = 0;
int totalQuestions = 0;
int currentSet = 1;
int shuffleMode = 0;
int automaticDifficulty = 1;
int manualDifficulty = 1;
int randomState = 1;
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
void runQuiz(const char* easyQuestions[], const char* easyOptions[][4], const int easyAnswers[], int easyCount, const char* mediumQuestions[], const char* mediumOptions[][4],
const int mediumAnswers[], int mediumCount,const char* hardQuestions[], const char* hardOptions[][4],const int hardAnswers[], int hardCount);
void displayQuestion(int questionNumber, const char* question,const char* options[]);
int getAnswer();
void calculateScore(int userAnswer, int correctOption);
int nextRandom();

int intake() {
    int character;
    int i;
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
    randomState = 0;
    for (i = 0; studentName[i] != '\0'; i++) {
        int characterValue = studentName[i];
        if (characterValue < 0) {
            characterValue = -characterValue;
        }
        randomState = (randomState * 33 + characterValue) % 256;
    }
    if (randomState == 0) {
        randomState = 1;
    }
    printf("Hello, %s! Let's start the quiz.\n", studentName);
    shuffleMode = readInt("Enable shuffle mode? (1 = yes, 0 = no): ", 0, 1);
    if (shuffleMode == -1) {
        return 0;
    }
    automaticDifficulty = readInt("Difficulty: 1 = automatic, 0 = manual: ", 0, 1);
    if (automaticDifficulty == -1) {
        return 0;
    }
    if (!automaticDifficulty) {
        printf("Choose difficulty: 1 = easy, 2 = medium, 3 = hard.\n");
        manualDifficulty = readInt("Difficulty level (1-3): ", 1, 3);
        if (manualDifficulty == -1) {
            return 0;
        }
    }
    return 1;
}

void programmingC() {
    /* EASY: fundamentals and common syntax */
    const char* easyQuestions[] = {
        "What is the output of printf(\"%d\", 5 + 3 * 2)?",
        "Which of the following is a valid C variable name?",
        "Which operator is used for logical AND in C?",
        "Which keyword prevents a variable from being modified?",
        "What is the result of 10 % 3?",
        "Which function reads one character from standard input?",
        "What does break do inside a loop?",
        "Which is the logical NOT operator?",
        "What is the first index of a C array?",
        "Which header declares printf()?",
        "Which loop is guaranteed to run at least once?",
        "Which operator gives the memory address of a variable?",
        "Which token begins a single-line comment in C?",
        "What does continue do inside a loop?",
        "What value does main commonly return to indicate success?"
    };
    const char* easyOptions[][4] = {
        {"11", "16", "10", "None of the above"},
        {"1variable", "my_variable", "variable-name", "variable name"},
        {"&&", "&", "|", "||"},
        {"const", "static", "volatile", "extern"},
        {"1", "3", "0", "0.33"},
        {"scanf()", "gets()", "getchar()", "read()"},
        {"Skips the current iteration", "Exits the loop", "Restarts the loop", "Halts the program"},
        {"!", "~", "-", "NOT"},
        {"1", "-1", "0", "Depends on array size"},
        {"<conio.h>", "<stdlib.h>", "<stdio.h>", "<math.h>"},
        {"for", "while", "do-while", "None of these"},
        {"*", "&", "->", "%"},
        {"//", "/*", "#", "--"},
        {"Exits the loop", "Skips to the next iteration", "Restarts the program", "Ends the function"},
        {"-1", "1", "0", "EOF"}
    };
    const int easyAnswers[] = {1, 2, 1, 1, 2, 3, 2, 1, 3, 3, 3, 2, 1, 2, 3};

    /* MEDIUM: types, pointers, and language rules */
    const char* mediumQuestions[] = {
        "What is the size of int in C?",
        "How do you declare a pointer to an int?",
        "How do you include a user-defined header?",
        "What does malloc return if allocation fails?",
        "What is the printf format specifier for float?",
        "Which listed operator has the highest precedence?",
        "How do you access the value through ptr?",
        "What is a struct?",
        "Which operator accesses a member through a struct pointer?",
        "What does const int *p mean?",
        "What does ++i do?",
        "Which standard header declares malloc()?",
        "What is the value of a logical expression when it is false?",
        "What is recursion?"
    };
    const char* mediumOptions[][4] = {
        {"Exactly 2 bytes", "Exactly 4 bytes", "Exactly 8 bytes", "Depends on the implementation"},
        {"int p;", "int *p;", "int &p;", "ptr int p;"},
        {"#include <file.h>", "#include \"file.h\"", "import file.h", "using file.h"},
        {"0", "NULL", "-1", "Garbage value"},
        {"%d", "%c", "%f", "%lf"},
        {"+", "*", "==", "="},
        {"*ptr", "&ptr", "ptr*", "val(ptr)"},
        {"Similar data types only", "Different data types grouped together", "A built-in function", "A macro"},
        {".", "->", "&", "*"},
        {"The pointed-to int cannot be changed through p", "p cannot point elsewhere", "Both p and the int are constant", "p is not a pointer"},
        {"Uses i, then increments it", "Increments i, then uses it", "Adds two to i", "Does not change i"},
        {"<stdio.h>", "<string.h>", "<stdlib.h>", "<limits.h>"},
        {"-1", "0", "1", "It depends on the compiler"},
        {"A function calling itself", "A loop with no condition", "A function with no return", "A variable declared twice"}
    };
    const int mediumAnswers[] = {4, 2, 2, 2, 3, 2, 1, 2, 2, 1, 2, 3, 2, 1};

    /* HARD: declarations, allocation, and storage duration */
    const char* hardQuestions[] = {
        "Which declares a pointer to a function taking and returning int?",
        "For an array of 5 ints, how many elements are in the array?",
        "Which malloc call requests 40 bytes?",
        "A function with static int n; returns ++n. What does its second call return?",
        "What does pointer arithmetic p + 1 advance by?",
        "What terminates a C string?",
        "What happens when an array is passed to a function?",
        "What does a dangling pointer refer to?",
        "What does the expression *p = 7 do when p points to x?",
        "What is the purpose of a base case in recursion?",
        "What is the result of 5 / 2 when both operands are int?",
        "Which declaration makes p a pointer to a constant int?",
        "What does a function pointer store?",
        "What is the lifetime of a static local variable?",
        "What does calloc do differently from malloc?"
    };
    const char* hardOptions[][4] = {
        {"int *f(int);", "int (*f)(int);", "int f*(int);", "int (&f)(int);"},
        {"1", "4", "5", "20"},
        {"malloc(10)", "malloc(40)", "calloc(10, 4)", "malloc(int * 10)"},
        {"1", "2", "0", "Undefined behavior"},
        {"One byte", "The size of the pointed-to type", "Two bytes", "The size of the pointer"},
        {"A space character", "A newline", "The null character", "EOF"},
        {"The whole array is copied", "A pointer to its first element is passed", "The array is converted to an int", "The function receives its length"},
        {"A pointer to memory that is no longer valid", "A pointer with value zero", "A pointer to a function", "A pointer to constant data"},
        {"Changes x to 7", "Changes p to 7", "Prints 7", "Declares a new variable"},
        {"It stops recursion when the stopping condition is reached", "It starts the first call", "It allocates memory", "It repeats the same call forever"},
        {"2", "2.5", "3", "1"},
        {"const int *p;", "int const p;", "int *const p;", "const p int;"},
        {"An address of a function", "The function's return value", "The number of parameters", "A copy of the function"},
        {"Until the block ends", "Until the next function call", "For the entire program execution", "Until the next loop iteration"},
        {"It initializes allocated memory to zero", "It only allocates one byte", "It frees previous memory", "It allocates stack memory"}
    };
    const int hardAnswers[] = {2, 3, 2, 2, 2, 3, 2, 1, 1, 1, 1, 1, 1, 3, 1};

    runQuiz(easyQuestions, easyOptions, easyAnswers, 15,
            mediumQuestions, mediumOptions, mediumAnswers, 14,
            hardQuestions, hardOptions, hardAnswers, 15);
}

void python() {
    /* EASY: basic syntax and built-in types */
    const char* easyQuestions[] = {
        "Which keyword defines a function?",
        "Which symbol starts a single-line comment?",
        "What is 3 ** 2?",
        "Which type stores True or False?",
        "How do you create an empty list?",
        "Which keyword begins a conditional?",
        "Which list method adds an item to the end?",
        "What is the first list index?",
        "Which collection stores key-value pairs?",
        "What does len(\"Python\") return?",
        "What is the result of 10 // 3?",
        "Which value represents the absence of a value?",
        "Which loop iterates over a sequence?",
        "Which keyword exits a loop immediately?",
        "Which keyword adds an alternative condition after if?"
    };
    const char* easyOptions[][4] = {
        {"func", "def", "function", "define"},
        {"//", "#", "/*", "--"},
        {"6", "8", "9", "27"},
        {"bool", "binary", "truth", "logic"},
        {"{}", "()", "[]", "<>"},
        {"if", "when", "case", "check"},
        {"append()", "push()", "add()", "insertEnd()"},
        {"0", "1", "-1", "It depends"},
        {"list", "tuple", "dictionary", "set"},
        {"5", "6", "7", "Error"},
        {"3", "3.3", "1", "0"},
        {"0", "None", "null", "empty"},
        {"for", "repeat", "foreach", "loop"},
        {"stop", "break", "exitloop", "return"},
        {"else if", "elif", "elseif", "otherwise"}
    };
    const int easyAnswers[] = {2, 2, 3, 1, 3, 1, 1, 1, 3, 2, 1, 2, 1, 2, 2};

    /* MEDIUM: functions, exceptions, and expressions */
    const char* mediumQuestions[] = {
        "Which built-in function returns a sequence's length?",
        "Which keyword handles an exception?",
        "Which operator tests equality?",
        "Which statement imports the math module?",
        "What does upper() do to a string?",
        "Which brackets create a tuple literal?",
        "What does list.pop() return?",
        "What is the result of not True?",
        "What does range(3) produce?",
        "What is the result of 3 == 3.0?",
        "Which built-in function returns the largest item?",
        "How do you get the number of items in a list?",
        "What does str.split() return by default?",
        "Which keyword skips to the next loop iteration?",
        "What does dict.keys() provide?"
    };
    const char* mediumOptions[][4] = {
        {"size()", "count()", "length()", "len()"},
        {"catch", "except", "error", "handle"},
        {"=", "==", "===", "<>"},
        {"include math", "using math", "import math", "require(math)"},
        {"Converts it to uppercase", "Removes spaces", "Splits it", "Reverses it"},
        {"{}", "[]", "()", "<>"},
        {"The removed item", "The list length", "The last index", "A new list"},
        {"True", "False", "None", "Error"},
        {"0, 1, 2", "1, 2, 3", "0, 1, 2, 3", "Only 3"},
        {"True", "False", "None", "Error"},
        {"min()", "max()", "sum()", "sort()"},
        {"size(list)", "length(list)", "len(list)", "count(list)"},
        {"A list of words", "A tuple of characters", "A set of words", "A dictionary"},
        {"continue", "break", "pass", "skip"},
        {"A view of the dictionary's keys", "The dictionary's values", "A list of pairs", "The first key only"}
    };
    const int mediumAnswers[] = {4, 2, 2, 3, 1, 3, 1, 2, 1, 2, 3, 1, 1, 1, 1};

    /* HARD: comprehensions and object semantics */
    const char* hardQuestions[] = {
        "What is [x*x for x in range(5) if x % 2 == 0]?",
        "When are default argument values evaluated?",
        "What does dict.get(\"missing\") return if the key is absent?",
        "What does the is operator test?",
        "What does this return: [1, 2, 3][1:]?",
        "What is the result of bool([])?",
        "What does a shallow copy of a list duplicate?",
        "What does enumerate(items) yield?",
        "What exception does int(\"abc\") raise?",
        "What does the *args parameter collect?",
        "What is the result of {1, 1, 2}?",
        "When does a finally block normally run?",
        "What does sorted(items) return?",
        "What happens when two names refer to the same mutable list and one appends an item?",
        "What is the output of len({\"a\": 1, \"b\": 2})?"
    };
    const char* hardOptions[][4] = {
        {"[0, 4, 16]", "[0, 2, 4]", "[1, 9, 25]", "[0, 4, 16, 25]"},
        {"On every call", "When the function is defined", "When the module exits", "Only on the first call"},
        {"0", "False", "None", "It raises KeyError"},
        {"Whether values are equal", "Whether objects are identical", "Whether types match", "Whether values are truthy"},
        {"[1, 2]", "[2, 3]", "[1, 2, 3]", "[3]"},
        {"True", "False", "None", "Error"},
        {"Only the outer container", "All nested objects recursively", "Only immutable values", "Nothing"},
        {"Pairs of index and item", "Only indexes", "Only items", "A dictionary"},
        {"ValueError", "TypeError", "IndexError", "KeyError"},
        {"Extra positional arguments as a tuple", "Extra keyword arguments as a list", "One required string", "A dictionary of defaults"},
        {"{1, 2}", "{1, 1, 2}", "[1, 2]", "Error"},
        {"Only when an exception occurs", "Only when there is no exception", "Whether or not an exception occurs", "Only after return"},
        {"The original list sorted in place", "A new sorted list", "A tuple", "A set"},
        {"Both names see the appended item", "Only the first name changes", "The list is copied automatically", "Python raises an error"},
        {"1", "2", "3", "Error"}
    };
    const int hardAnswers[] = {1, 2, 3, 2, 2, 2, 1, 1, 1, 1, 1, 3, 2, 1, 2};

    runQuiz(easyQuestions, easyOptions, easyAnswers, 15,
            mediumQuestions, mediumOptions, mediumAnswers, 15,
            hardQuestions, hardOptions, hardAnswers, 15);
}

void mathematics() {
    /* EASY: arithmetic and basic geometry */
    const char* easyQuestions[] = {
        "What is 7 + 8?",
        "What is 9 x 6?",
        "What is the square root of 81?",
        "How many degrees are in a right angle?",
        "What is the perimeter of a square with side 4?",
        "How many sides does a hexagon have?",
        "What is 100 divided by 4?",
        "Which number is an even prime?",
        "What is the absolute value of -9?",
        "What is 12 - 5?",
        "What is 3 x 4?",
        "How many sides does a triangle have?",
        "What is the smallest two-digit whole number?",
        "How many meters are in one kilometer?",
        "What is 3 + 2 x 4?"
    };
    const char* easyOptions[][4] = {
        {"14", "15", "16", "17"},
        {"45", "54", "56", "63"},
        {"7", "8", "9", "10"},
        {"45", "60", "90", "180"},
        {"8", "12", "16", "20"},
        {"5", "6", "7", "8"},
        {"20", "25", "40", "50"},
        {"0", "1", "2", "4"},
        {"-9", "0", "9", "18"},
        {"5", "6", "7", "8"},
        {"7", "10", "12", "14"},
        {"2", "3", "4", "5"},
        {"0", "9", "10", "11"},
        {"100", "500", "1000", "10000"},
        {"20", "11", "14", "24"}
    };
    const int easyAnswers[] = {2, 2, 3, 3, 3, 2, 2, 3, 3, 3, 3, 2, 3, 2, 3};

    /* MEDIUM: fractions, powers, and single-step problems */
    const char* mediumQuestions[] = {
        "What is 15% of 200?",
        "What is 2 raised to the power 5?",
        "What is 3/4 as a decimal?",
        "Solve 2x = 14.",
        "What is the area of a 5 by 3 rectangle?",
        "What is the next prime after 7?",
        "What is the mean of 2, 4, and 6?",
        "What is the sum of a triangle's interior angles?",
        "What is 11 squared?",
        "What is 1/2 + 1/4?",
        "What is 5 squared?",
        "What is 1/5 as a decimal?",
        "Solve x + 4 = 9.",
        "What is the area of a triangle with base 8 and height 3?",
        "What is (-3) x (-4)?"
    };
    const char* mediumOptions[][4] = {
        {"20", "25", "30", "35"},
        {"10", "16", "25", "32"},
        {"0.25", "0.5", "0.75", "1.25"},
        {"5", "6", "7", "8"},
        {"8", "12", "15", "18"},
        {"9", "10", "11", "13"},
        {"3", "4", "5", "6"},
        {"90", "180", "270", "360"},
        {"111", "121", "131", "144"},
        {"0.5", "0.6", "0.75", "1"},
        {"10", "20", "25", "30"},
        {"0.05", "0.2", "0.5", "2"},
        {"3", "4", "5", "6"},
        {"11", "12", "24", "48"},
        {"-12", "-7", "7", "12"}
    };
    const int mediumAnswers[] = {3, 4, 3, 3, 3, 3, 2, 2, 2, 3, 3, 2, 3, 2, 4};

    /* HARD: multi-step problems and formulas */
    const char* hardQuestions[] = {
        "What is a circle's circumference in terms of radius r?",
        "Solve 3(x - 2) = 12.",
        "What is the chance of rolling an even number on a fair die?",
        "Factor 2x^2 - 8.",
        "Sequence 3, 7, 11, ...: what is its 10th term?",
        "A $50 item is discounted by 20%. What is its sale price?",
        "Solve 2(x + 3) = 18.",
        "What is the median of 2, 5, 9, 12, 14?",
        "A bag has 3 red and 2 blue balls. What is the chance of drawing red?",
        "What is the slope between (1, 2) and (3, 6)?",
        "What is the area of a circle with radius 3, in terms of pi?",
        "If 4x + 5 = 21, what is x?",
        "What is the least common multiple of 6 and 8?",
        "A car travels 150 km in 3 hours. What is its average speed?",
        "What is the probability of getting two heads in two fair coin tosses?"
    };
    const char* hardOptions[][4] = {
        {"pi*r", "2*pi*r", "pi*r*r", "4*pi*r"},
        {"4", "5", "6", "8"},
        {"1/6", "1/3", "1/2", "2/3"},
        {"2(x - 2)(x + 2)", "2(x - 4)(x + 2)", "(x - 2)(x + 2)", "2(x - 2)^2"},
        {"35", "39", "40", "43"},
        {"$30", "$35", "$40", "$45"},
        {"3", "5", "6", "9"},
        {"5", "7", "9", "12"},
        {"1/5", "2/5", "3/5", "1/2"},
        {"1", "2", "3", "4"},
        {"3*pi", "6*pi", "9*pi", "12*pi"},
        {"3", "4", "5", "6"},
        {"12", "18", "24", "48"},
        {"30 km/h", "45 km/h", "50 km/h", "75 km/h"},
        {"1/2", "1/3", "1/4", "3/4"}
    };
    const int hardAnswers[] = {2, 3, 3, 1, 2, 3, 3, 3, 3, 2, 3, 2, 3, 3, 3};

    runQuiz(easyQuestions, easyOptions, easyAnswers, 15,
            mediumQuestions, mediumOptions, mediumAnswers, 15,
            hardQuestions, hardOptions, hardAnswers, 15);
}

void linuxQuiz() {
    /* EASY: everyday commands and paths */
    const char* easyQuestions[] = {
        "Which command lists files in the current directory?",
        "Which command prints the current working directory?",
        "Which command changes the current directory?",
        "Which command displays a text file's contents?",
        "Which command creates a directory?",
        "Which command copies files?",
        "Which command moves or renames a file?",
        "Which command removes a file?",
        "Which command shows the current user's name?",
        "Which character represents the root directory?",
        "Which command displays the first lines of a file by default?",
        "Which command displays the last lines of a file by default?",
        "Which command exits a shell session?",
        "Which command creates an empty file?",
        "Which command displays the current date and time?"
    };
    const char* easyOptions[][4] = {
        {"pwd", "ls", "cd", "cat"},
        {"dir", "where", "pwd", "path"},
        {"cd", "mv", "chdir", "goto"},
        {"cat", "rm", "touch", "ps"},
        {"mkdir", "rmdir", "mkfile", "newdir"},
        {"cp", "mv", "ln", "copy"},
        {"mv", "cp", "rename", "shift"},
        {"rm", "del", "erase", "drop"},
        {"whoami", "username", "user", "idname"},
        {"~", "/", ".", "*"},
        {"tail", "head", "top", "first"},
        {"head", "bottom", "tail", "end"},
        {"exit", "close", "quitnow", "stop"},
        {"touch", "mkdir", "cat", "newfile"},
        {"date", "time", "clock", "now"}
    };
    const int easyAnswers[] = {2, 3, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 1, 1, 1};

    /* MEDIUM: searching, processes, and system commands */
    const char* mediumQuestions[] = {
        "Which command searches text using a pattern?",
        "Which command displays running processes?",
        "Which command changes file permissions?",
        "Which command can run a command with elevated privileges?",
        "Which command displays a manual page?",
        "Which command shows filesystem disk space usage?",
        "Which command updates Debian-based package indexes?",
        "Which command finds files by name or other criteria?",
        "Which command shows a user's numeric IDs and groups?",
        "Which command reports memory usage?",
        "Which command prints lines from a file matching a pattern?",
        "Which command displays a snapshot of system processes interactively?",
        "Which command changes a file's owner?",
        "Which command counts lines, words, and bytes?",
        "Which command displays network interface information on many Linux systems?"
    };
    const char* mediumOptions[][4] = {
        {"find", "grep", "locate", "search"},
        {"jobs", "ps", "who", "topdir"},
        {"chmod", "chown", "chgrp", "perm"},
        {"admin", "sudo", "root", "elevate"},
        {"help", "man", "doc", "guide"},
        {"du", "df", "free", "disk"},
        {"apt update", "apt install", "apt remove", "apt search"},
        {"find", "grep", "ps", "where"},
        {"id", "whoami", "groupset", "user"},
        {"free", "df", "du", "mem"},
        {"grep", "head", "cat", "wc"},
        {"top", "ps", "jobs", "run"},
        {"chown", "chmod", "chgrp", "owner"},
        {"wc", "count", "lines", "sum"},
        {"ip addr", "route", "netstat-file", "host"}
    };
    const int mediumAnswers[] = {2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    /* HARD: permissions and shell redirection */
    const char* hardQuestions[] = {
        "What permissions does chmod 640 set for owner, group, and others?",
        "Which redirection sends only standard error to a file?",
        "Which command searches recursively for a pattern in files?",
        "What does the pipe operator (|) do?",
        "What does chmod 755 script.sh allow?",
        "What does >> file do?",
        "What does 2>&1 mean in shell redirection?",
        "Which command finds all .txt files under the current directory?",
        "What does grep -i do?",
        "What does the command line `command1 && command2` do?",
        "What does `>` do to an existing regular file?",
        "What does `2>/dev/null` do?",
        "Which permission is represented by the octal digit 5?",
        "What does `tar -x` generally do?",
        "Which command changes the group ownership of a file?"
    };
    const char* hardOptions[][4] = {
        {"Owner rwx, group r, others none", "Owner rw, group r, others none", "Owner rw, group rw, others r", "Owner r, group w, others none"},
        {"> file", "1> file", "2> file", "&> file"},
        {"grep -R pattern directory", "grep pattern directory", "find pattern", "search -r pattern"},
        {"Runs both commands at once", "Sends one command's output to another as input", "Redirects output to a file", "Runs a command in the background"},
        {"Owner rwx, group r-x, others r-x", "Owner rw, group r, others none", "Owner rwx, group rwx, others rwx", "Owner r, group r, others r"},
        {"Appends output to the file", "Overwrites the file", "Deletes the file", "Reads the file"},
        {"Sends standard output to standard error", "Sends standard error to standard output", "Discards both streams", "Duplicates the command"},
        {"find . -name '*.txt'", "grep '*.txt'", "ls -R '*.txt'", "locate -text"},
        {"Ignores letter case while matching", "Matches only uppercase", "Searches binary files", "Searches filenames only"},
        {"Runs command2 only if command1 succeeds", "Always runs both at the same time", "Runs command2 only if command1 fails", "Sends output to a file"},
        {"Truncates it before writing new output", "Appends to the end", "Does not change it", "Reads its contents"},
        {"Discards standard error output", "Discards standard output", "Saves errors to a file", "Stops the command"},
        {"Read and execute", "Write and execute", "Read and write", "Read only"},
        {"Extracts files from an archive", "Creates an archive", "Lists running processes", "Deletes an archive"},
        {"chgrp", "chown", "chmod", "groupadd"}
    };
    const int hardAnswers[] = {2, 3, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1};

    runQuiz(easyQuestions, easyOptions, easyAnswers, 15,
            mediumQuestions, mediumOptions, mediumAnswers, 15,
            hardQuestions, hardOptions, hardAnswers, 15);
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

void runQuiz(const char* easyQuestions[], const char* easyOptions[][4], const int easyAnswers[], int easyCount, const char* mediumQuestions[], const char* mediumOptions[][4],
const int mediumAnswers[], int mediumCount, const char* hardQuestions[], const char* hardOptions[][4], const int hardAnswers[], int hardCount) {
    const char** questionBanks[3] = {
        easyQuestions, mediumQuestions, hardQuestions
    };
    const char* (*optionBanks[3])[4] = {
        easyOptions, mediumOptions, hardOptions
    };
    const int* answerBanks[3] = {
        easyAnswers, mediumAnswers, hardAnswers
    };
    const int bankCounts[3] = {easyCount, mediumCount, hardCount};
    const int bankOffsets[3] = {0, easyCount, easyCount + mediumCount};
    const char* incorrectQuestions[100];
    const char* selectedAnswers[100];
    const char* correctAnswers[100];
    int used[100] = {0};
    int questionsPerDifficulty[3] = {0, 0, 0};
    int questionsAskedPerDifficulty[3] = {0, 0, 0};
    int incorrectCount = 0;
    int scoreAtStart = score;
    int questionsAsked = 0;
    int correctStreak = 0;
    int currentDifficulty = 1;
    int interrupted = 0;
    int questionLimit = 0;

    for (int level = 0; level < 3; level++) {
        questionsPerDifficulty[level] = 10 + nextRandom() % 6;
        if (automaticDifficulty || level == manualDifficulty - 1) {
            questionLimit += questionsPerDifficulty[level];
        }
    }

    while (questionsAsked < questionLimit) {
        int targetDifficulty = automaticDifficulty ? currentDifficulty : manualDifficulty;
        int chosenBank = -1;
        int chosenIndex = -1;
        int candidateCount = 0;
        int candidateNumber;
        int optionOrder[4] = {0, 1, 2, 3};
        const char* displayOptions[4];
        int answer;
        int actualDifficulty;
        int displayedCorrectOption = 0;

        for (int distance = 0; distance < 3 && chosenIndex == -1; distance++) {
            for (int level = 1; level <= 3 && chosenIndex == -1; level++) {
                int difference = level - targetDifficulty;
                if (difference < 0) {
                    difference = -difference;
                }
                if (difference != distance) {
                    continue;
                }
                candidateCount = 0;
                if (automaticDifficulty ||
                    level == manualDifficulty) {
                    if (questionsAskedPerDifficulty[level - 1] <
                        questionsPerDifficulty[level - 1]) {
                        for (int i = 0; i < bankCounts[level - 1]; i++) {
                            if (!used[bankOffsets[level - 1] + i]) {
                                candidateCount++;
                            }
                        }
                    }
                }
                if (candidateCount > 0) {
                    candidateNumber = shuffleMode
                        ? nextRandom() % candidateCount
                        : 0;
                    for (int i = 0; i < bankCounts[level - 1]; i++) {
                        if (!used[bankOffsets[level - 1] + i]) {
                            if (candidateNumber == 0) {
                                chosenBank = level - 1;
                                chosenIndex = i;
                                break;
                            }
                            candidateNumber--;
                        }
                    }
                }
            }
        }
        if (chosenIndex == -1) {
            break;
        }

        used[bankOffsets[chosenBank] + chosenIndex] = 1;
        questionsAskedPerDifficulty[chosenBank]++;
        actualDifficulty = chosenBank + 1;
        if (automaticDifficulty) {
            currentDifficulty = actualDifficulty;
        }
        if (shuffleMode) {
            for (int i = 3; i > 0; i--) {
                int swapIndex = nextRandom() % (i + 1);
                int temporary = optionOrder[i];
                optionOrder[i] = optionOrder[swapIndex];
                optionOrder[swapIndex] = temporary;
            }
        }
        for (int i = 0; i < 4; i++) {
            displayOptions[i] = optionBanks[chosenBank][chosenIndex][optionOrder[i]];
            if (optionOrder[i] + 1 == answerBanks[chosenBank][chosenIndex]) {
                displayedCorrectOption = i + 1;
            }
        }

        displayQuestion(questionsAsked + 1, questionBanks[chosenBank][chosenIndex], displayOptions);
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
        if (answer == displayedCorrectOption) {
            calculateScore(answer, displayedCorrectOption);
            totalQuestions++;
            if (automaticDifficulty) {
                correctStreak++;
                if (correctStreak == 2 && currentDifficulty < 3) {
                    currentDifficulty++;
                    correctStreak = 0;
                    printf("Difficulty increased to %s.\n",currentDifficulty == 2 ? "medium" : "hard");
                }
            }
        } else {
            int selectedOption = optionOrder[answer - 1];
            calculateScore(answer, displayedCorrectOption);
            incorrectQuestions[incorrectCount] = questionBanks[chosenBank][chosenIndex];
            selectedAnswers[incorrectCount] = optionBanks[chosenBank][chosenIndex][selectedOption];
            correctAnswers[incorrectCount] = optionBanks[chosenBank][chosenIndex][answerBanks[chosenBank][chosenIndex] - 1];
            incorrectCount++;
            totalQuestions++;
            if (automaticDifficulty) {
                correctStreak = 0;
                if (currentDifficulty > 1) {
                    currentDifficulty--;
                    printf("Difficulty decreased to %s.\n", currentDifficulty == 1 ? "easy" : "medium");
                }
            }
        }
    }

    if (questionsAsked > 0) {
        printf("\nScore for this set: %d / %d\n", score - scoreAtStart, questionsAsked);
        printf("Questions by difficulty: Easy %d, Medium %d, Hard %d\n",
               questionsAskedPerDifficulty[0],
               questionsAskedPerDifficulty[1],
               questionsAskedPerDifficulty[2]);
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

int nextRandom() {
    randomState = (randomState * 109 + 89) % 256;
    return randomState;
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