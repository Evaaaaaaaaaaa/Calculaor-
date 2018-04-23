/* Extended precision integer calculator
 * Implements +, *, and ^ (power of) operations
 *
 * Skeleton code written by Jianzhong Qi, March 2018
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INT_SIZE	100	/* max number of digits per integer value */
#define LINE_LEN	103	/* maximum length of any input line */
#define NUM_VARS	10	/* number of different huge int "variables" */

#define ASN_OP		'='	/* assignment operator */
#define ECH_OP		'?'	/* echo operator */
#define ADD_OP		'+'	/* addition operator */
#define MUL_OP		'*'	/* multiplication operator */
#define POW_OP		'^'	/* power of operator */

#define OPR1_POS	1	/* position of the first operand */
#define OPR2_POS	3	/* position of the second operand */
#define OP_POS		2	/* position of the operator */

#define CH_ZERO		'0'	/* character 0 */

#define EXIT_CMD 	"exit"	/* command to exit */
#define PROMPT		"> "	/* command prompt */
#define CMT_FLAG	'%'		/* indicator for comment line */

typedef int digit_t;				/* a decimal digit */
typedef digit_t huge_t[INT_SIZE];	/* one huge int "variable" */

/* add your constant and type definitions here */

/****************************************************************/

/* function prototypes */
void read_line(char *line, int max_len);
void init(huge_t vars[], int lens[]); 
void echo(huge_t vars[], int lens[], int opr1_index);
void assign(huge_t vars[], int lens[], int opr1_index, char *opr2_str);
void add(huge_t vars[], int lens[], int opr1_index, char *opr2_str);
void multiply(huge_t vars[], int lens[], int opr1_index, char *opr2_str);
void power(huge_t vars[], int lens[], int opr1_index, char *opr2_str);

/* add your function prototypes here */

/****************************************************************/

/* main function controls all the action, do NOT modify this function */
int
main(int argc, char *argv[]) {
	char line[LINE_LEN+1];		/* to hold the input line */
	huge_t vars[NUM_VARS];		/* to hold 10 huge integers */
	int lens[NUM_VARS];			/* to hold the length of the 10 vars */
	
	int opr1_index;				/* index of the first operand in command */
	char op;					/* operator in command */
	
	init(vars, lens);
	
	while (1) {
		printf(PROMPT);						/* print prompt */
		read_line(line, LINE_LEN);			/* read one line of command */

		if (line[0] == CMT_FLAG) {			/* print comment in the test data */ 
			printf("%s\n", line);			/* used to simplify marking */
			continue;
		}
		
		if (strcmp(line, EXIT_CMD) == 0) {	/* see if command is "exit" */
			return 0;
		} 
		
		opr1_index = line[OPR1_POS] - CH_ZERO;/* first var number at line[1] */
		op = line[OP_POS];					/* operator at line[2] */

		if (op == ECH_OP) {					/* print out the variable */
			echo(vars, lens, opr1_index);
			continue;
		} 
		
		/* do the calculation, second operand starts at line[3] */
		if (op == ASN_OP) {	
			assign(vars, lens, opr1_index, line+OPR2_POS);
		} else if (op == ADD_OP) {
			add(vars, lens, opr1_index, line+OPR2_POS);
		} else if (op == MUL_OP) {
			multiply(vars, lens, opr1_index, line+OPR2_POS);
		} else if (op == POW_OP) {
			power(vars, lens, opr1_index, line+OPR2_POS);
		}
	}
	
	/* all done; take some rest */
	return 0;
}

/* read a line of input into the array passed as argument */
void
read_line(char *line, int max_len) {
	int i = 0, c;
	while (((c = getchar()) != EOF) && (c != '\n') && (c != '\r')) {
		if (i < max_len) {
			line[i++] = c;
		} else {
			printf("Invalid input line, toooooooo long.\n");
			exit(0);
		}
	}
	line[i] = '\0';
}

/* print out a huge integer */
void echo(huge_t vars[], int lens[], int opr1_index) {
	int i;
	
	/* print the digits in a reverse order */
	for (i = lens[opr1_index]-1; i >= 0; i--) {
		printf("%d", vars[opr1_index][i]);
	}
	
	printf("\n");
}


/****************************************************************/

/* add code below to complete the function bodies,
 * add more functions where appropriate.
 */

/* set the vars array to zeros */
void
init(huge_t vars[], int lens[]) {
	
}

/* process the '=' operator */
void
assign(huge_t vars[], int lens[], int opr1_index, char *opr2_str) {
	
}

/* process the '+' operator */
void 
add(huge_t vars[], int lens[], int opr1_index, char *opr2_str) {
	
}

/* process the '*' operator */
void 
multiply(huge_t vars[], int lens[], int opr1_index, char *opr2_str) {

}

/* process the '^' operator */
void 
power(huge_t vars[], int lens[], int opr1_index, char *opr2_str) {

}
