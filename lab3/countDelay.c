#include <stdio.h>
#include <math.h>

int cpu_freq = 16000000;
double wanted_delay = 1;

int calcDelayConstant(int cycleCount) {
	double exponent = log(cycleCount/4.0)/3.0;
	double result = exp(exponent);
	return (int) result;
}

int calcDelayCycles(double delayTime) {
	double result = delayTime * cpu_freq;
	return (int)result;
}

int main() {
	int delayCycles = calcDelayCycles(wanted_delay);
	int delayConstant = calcDelayConstant(delayCycles);
	printf("%i", delayConstant);
	return 0;
}
