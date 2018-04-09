#include <stdio.h>
int generate(int n_times);
int main() {

	int n_digits = 10;
	int sum_of_generator = 0;
	int sum_of_all = 0, sum_of_self = 0;
	int check_generator[10000] = { 0, };
	int generate_state=0;
	for (int i = 1; i <= 10000; i++) {
		generate_state = generate(i);
		

		if (check_generator[generate_state-1] == 0) {
			check_generator[generate_state-1] = 1;
		}
		else { continue; }

	}

	for (int q = 1; q<=10000; q++) {
		if (check_generator[q-1] == 0) {
			printf("%d\n", (q));
		}
	}
	
	



}


int generate(int n_times) {
	int now_decimal = n_times, sum_of_generator=0;
	int digits = n_times, run = 1;
	while (digits >= 1) {
		digits /= 10;

		run*=10;
	}
	while (run>=1) {
		sum_of_generator += now_decimal / run;
		now_decimal -= (now_decimal / run)*run;
		run /= 10;
	}
	
	return sum_of_generator += n_times;

}
