# Quiz Application

A beginner-friendly terminal-based multiple-choice quiz written in C. The program
asks the student for their name and USN, lets them select a quiz topic, and then
runs a series of question rounds for one of four subjects:

- Programming C
- Python
- Mathematics
- Linux

The project focuses on core C programming concepts such as arrays, functions,
conditional statements, loops, simple score tracking, and input validation.

## Features

- Collects the student's name and USN.
- Lets the student choose a quiz topic from four options.
- Uses parallel arrays to store questions, answer choices, and correct answers.
- Validates numeric user input and rejects invalid menu or answer selections.
- Tracks the score for each set and overall total across the session.
- Reviews incorrect answers at the end of a quiz set.
- Allows the user to enter `0` to exit the current quiz early.
- Gives a menu to restart the current set, switch topics, continue with another
  set, or exit the application.
- Prints a final thank-you message with the student's name, USN, and final score.

## Requirements

- A C compiler that supports C99 or later.
- No extra C libraries are required beyond `stdio.h`.

## Build and run

From a terminal in the project folder, compile with GCC:

```sh
gcc QuizApplication.c -o QuizApplication
```

Run on Windows:

```powershell
.\QuizApplication.exe
```

Run on Linux or macOS:

```sh
./QuizApplication
```

## How to use

1. Enter your name and USN.
2. Choose one of the four quiz sets.
3. Answer each question with `1` to `4`.
4. Enter `0` at any time to exit the quiz early.
5. Review any incorrect answers shown after the set finishes.
6. Use the menu to restart the set, select another topic, continue, or exit.

## Question bank format

Each topic is defined with parallel arrays for:

- question text
- 4 answer options
- the index of the correct option

The arrays are aligned by index, so each question, option set, and answer must
stay in the same position.

Example:

```c
const char* questions[] = {
    "What is 2 + 3?",
    "How many sides does a triangle have?"
};

const char* options[][4] = {
    {"4", "5", "6", "7"},
    {"2", "3", "4", "5"}
};

const int answers[] = {2, 2};
```

The values in `answers` use the same numbering as the displayed choices:
`1` through `4`. If a question is added, keep the same index across all three
arrays so the correct answer stays matched to the right prompt.

## Functions

| Function | Purpose |
|---|---|
| `main` | Starts the application, chooses the quiz set, manages the menu, and prints the final report. |
| `intake` | Reads the student's name and USN and welcomes them to the quiz. |
| `programmingC` | Defines the C question set and starts that quiz. |
| `python` | Defines the Python question set and starts that quiz. |
| `mathematics` | Defines the mathematics question set and starts that quiz. |
| `linuxQuiz` | Defines the Linux question set and starts that quiz. |
| `readInt` | Reads an integer while validating the input and enforcing a valid range. |
| `chooseQuestionSet` | Displays the available topics and reads the student's choice. |
| `runSelectedSet` | Calls the selected quiz function based on the topic number. |
| `runQuiz` | Runs the question loop, checks answers, updates the score, and prints review details. |
| `displayQuestion` | Prints a question and its four options. |
| `getAnswer` | Reads a valid answer from `1` to `4` or allows `0` to exit. |
| `calculateScore` | Increments the score when the selected answer matches the correct option. |

### Input validation example

`readInt` is used for menu choices and quiz answers. It rejects non-numeric
input and values outside the allowed range:

```c
int getAnswer() {
    return readInt("Enter your answer (1-4), or 0 to exit the quiz: ", 0, 4);
}
```

### Score and answer review

`runQuiz` stores missed questions, the student's selected answer, and the
correct answer in arrays. After the set finishes, it prints the review for each
incorrect question instead of revealing the result immediately after each answer.

```c
printf("\nReview of incorrect answers:\n");
for (int i = 0; i < incorrectCount; i++) {
    printf("%d. %s\n", i + 1, incorrectQuestions[i]);
    printf("   Your answer: %s\n", selectedAnswers[i]);
    printf("   Correct answer: %s\n", correctAnswers[i]);
}
```

## Menu options

- **Restart this set** — repeats the current topic and resets the score for the current session.
- **Change set** — selects a different topic and resets the accumulated score.
- **Continue with another set** — picks a different subject while keeping the current score.
- **Exit** — ends the application and prints the final score report.

## Screenshots

### Welcome and student details

![Quiz welcome, student details, and topic selection](ScreenShots/img1.png)

### Question screen

![Quiz question and answer prompt](ScreenShots/img2.png)

### Final student report

![Quiz final report with student details and score](ScreenShots/img3.png)

## THANK YOU 😊