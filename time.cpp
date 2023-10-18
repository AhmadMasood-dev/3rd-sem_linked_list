#include <iostream>
int main()
{
	//part1 5
	int sum1;
	for (int i = 0; i < 5; i++) {
		sum1++;
	}

	//part2 30n+8 
	int sum2;
	int n = 5;
	for (int i = 0; i < 30; i++) {
		for (int i = 0; i < n; i++) {
			sum2++;

		}
	}
	for (int i = 0; i < 8; i++) {
		sum2++;
	}

	//part3 n^2+1
	int sum3 = 0;
	for (int i = 0; i < 30; i++) {
		for (int i = 0; i < n; i++) {
			sum3++;

		}
	}
	sum3++;

	//part4 8n^2
	int sum4 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				sum4++;

			}
		}
	}

	// part5 3n^3+4^2+50
	int sum5 = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++)
				{
					sum5++;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				sum5++;
			}
		}
	}

	for (int i = 0; i < 50; i++) {
		sum5++;
	}

	//part6 nlog2(n)
	int sum6 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j * 2) {
			sum6++;
		}
	}

	//part7 n^2log3(logn)
	int sum7 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k * 3) {
				sum7++;

			}
		}
	}

	//part8 n(n+1)/2

	int sum8 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum8++;
		}
	}

	//part9 n(n-1)/2
	int sum9 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 2; j < n; j++) {
			sum9++;
		}
	}

	//part10 n^2/2
	int sum10 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			sum10++;
		}
	}
	return 0;

}
