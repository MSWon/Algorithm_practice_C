#include <stdio.h>
#include <math.h>
#include <cmath>

int main()
{
	float a1, a2;
	float b1, b2;
	float c1, c2;
	float length_ab, length_bc, length_ac;
	float longest, sum, twoline;
	float area;

	printf("Input coordinates of Pi:");
	scanf_s("%f %f", &a1, &a2);
	printf("Input coordinates of Pj:");
	scanf_s("%f %f", &b1, &b2);
	printf("Input coordinates of Pk:");
	scanf_s("%f %f", &c1, &c2);

	length_ab = sqrt((a1 - b1)*(a1 - b1) + (a2 - b2)*(a2 - b2));
	length_bc = sqrt((b1 - c1)*(b1 - c1) + (b2 - c2)*(b2 - c2));
	length_ac = sqrt((a1 - c1)*(a1 - c1) + (a2 - c2)*(a2 - c2));
	area = abs((a1*(b2 - c2) + b1*(c2 - a2) + c1*(a2 - b2)) / 2);

	longest = (length_ab > length_bc ? length_ab : length_bc);
	longest = (longest > length_ac ? longest : length_ac);
	sum = length_ab + length_bc + length_ac;
	twoline = sum - longest;

	if (twoline > longest){
		printf("\nArea of the triangle formed with the three vertices: %.1f\n", area);
	}
	else{
		printf("\nNot a triangle\n");
	}
	return 0;
}