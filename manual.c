/*
 * Name:	Paige-Uelses
 * Section:	03
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
    char up[101], low[101];
    int i = 0;
    for (; s[i] != '\0' && i < 100; ++i) {
        up[i]  = (char)toupper((unsigned char)s[i]);
        low[i] = (char)tolower((unsigned char)s[i]);
    }
    up[i] = '\0';
    low[i] = '\0';

    printf("%s\n%s", up, low);
    return NULL;
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    int a = atoi(s1);
    int b = atoi(s2);
    int c = atoi(s3);
    int d = atoi(s4);
    return a + b + c + d;
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    float a = (float)atof(s1);
    float b = (float)atof(s2);
    float c = (float)atof(s3);
    float d = (float)atof(s4);
    return a + b + c + d;
}

//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
    int cmp = strcmp(s1, s2);
    if (cmp < 0) {
        printf("\n\n%s < %s", s1, s2);
    } else if (cmp == 0) {
        printf("\n\n%s = %s", s1, s2);
    } else {
        printf("\n\n%s > %s", s1, s2);
    }
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
    int cmp = strncmp(s1, s2, (size_t)n);
    printf("\n\nComparison of first %d chars: ", n);
    if (cmp < 0) {
        printf("%s < %s", s1, s2);
    } else if (cmp == 0) {
        printf("%s = %s", s1, s2);
    } else {
        printf("%s > %s", s1, s2);
    }
}

//6.(Random Sentences) 
void randomize(void) {
    const char *article[] = {"the", "a", "one", "some", "any"};
    const char *noun[] = {"boy", "girl", "dog", "town", "car"};
    const char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    const char *prep[] = {"to", "from", "over", "under", "on"};

    for (int i = 0; i < 20; ++i) {
        char sentence[128] = "";
        const char *w1 = article[rand() % 5];
        const char *w2 = noun[rand() % 5];
        const char *w3 = verb[rand() % 5];
        const char *w4 = prep[rand() % 5];
        const char *w5 = article[rand() % 5];
        const char *w6 = noun[rand() % 5];

        // build "w1 w2 w3 w4 w5 w6"
        strcat(sentence, w1); strcat(sentence, " ");
        strcat(sentence, w2); strcat(sentence, " ");
        strcat(sentence, w3); strcat(sentence, " ");
        strcat(sentence, w4); strcat(sentence, " ");
        strcat(sentence, w5); strcat(sentence, " ");
        strcat(sentence, w6);

        // capitalize first letter
        sentence[0] = (char)toupper((unsigned char)sentence[0]);
        // add period
        size_t L = strlen(sentence);
        if (L < sizeof(sentence) - 2) {
            sentence[L] = '.';
            sentence[L + 1] = '\0';
        }
        printf("\n%s", sentence);
    }
   
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    char copy[64];
    strncpy(copy, num, sizeof(copy) - 1);
    copy[sizeof(copy) - 1] = '\0';

    char *tok = strtok(copy, " ()-");
    if (!tok) return 1;
    int area = atoi(tok);

    char *first3 = strtok(NULL, " ()-");
    char *last4  = strtok(NULL, " ()-");
    if (!first3 || !last4) return 1;

    char seven[16];
    seven[0] = '\0';
    strcat(seven, first3);
    strcat(seven, last4);

    long phone = atol(seven);

    printf("\n\n%d %ld", area, phone);
    return 0;
  
}

//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char buf[256];
    strncpy(buf, text, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    char *words[64];
    int count = 0;

    char *tok = strtok(buf, " ");
    while (tok && count < 64) {
        words[count++] = tok;
        tok = strtok(NULL, " ");
    }

    printf("\n");
    for (int i = count - 1; i >= 0; --i) {
        printf("%s", words[i]);
        if (i) printf(" ");
    }
}

//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    if (!*sub) return 0;
    int count = 0;
    char *p = line;
    size_t step = strlen(sub);

    while ((p = strstr(p, sub)) != NULL) {
        ++count;
        p += step; // count non-overlapping occurrences
    }
    return count;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
    char *p = line;
    while ((p = strchr(p, c)) != NULL) {
        ++count;
        ++p; // move past this occurrence
    }
    return count;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    int freq[26] = {0};
    for (const char *p = string; *p; ++p) {
        if (isalpha((unsigned char)*p)) {
            char lower = (char)tolower((unsigned char)*p);
            freq[lower - 'a']++;
        }
    }

    printf("\n");
    for (int i = 0; i < 26; ++i) {
        printf("%c,%c | %d\n", 'A' + i, 'a' + i, freq[i]);
    }
}

//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    char buf[256];
    strncpy(buf, string, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    int count = 0;
    char *tok = strtok(buf, " \n\t");
    while (tok) {
        ++count;
        tok = strtok(NULL, " \n\t");
    }
    return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {
    int size = 5;
    printf("\n");
    for (int i = 0; i < size; ++i) {
        if (string[i] && tolower((unsigned char)string[i][0]) == 'b') {
            for (int j = 0; string[i][j]; j++) {
                printf("%c", tolower((unsigned char)string[i][j]));
            }
            printf(" ");
        }
    }
}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {
    int size = 5;
    printf("\n");
    for (int i = 0; i < size; ++i) {
        if (!string[i]) continue;
        size_t L = strlen(string[i]);
        if (L >= 2) {
            char c1 = (char)tolower((unsigned char)string[i][L - 2]);
            char c2 = (char)tolower((unsigned char)string[i][L - 1]);
            if (c1 == 'e' && c2 == 'd') {
                // Convert entire string to lowercase for output
                for (int j = 0; string[i][j]; j++) {
                    printf("%c", tolower((unsigned char)string[i][j]));
                }
                printf(" ");
            }
        }
    }
}