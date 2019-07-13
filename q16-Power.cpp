/* 
 * my version
 * better: should consider base == 0 && exponent < 0
 * use global variable to deal with exception
 * repeated calculation
 * can use bitwise operation
 * unsigned int?
 */
double Power(double base, int exponent) {
	if (base == 0) {
		return 0;
	}
	if (exponent == 0) {
		return 1;
	}
	if (exponent == 1) {
		return base;
	}
	if (exponent > 0) {
		if (exponent % 2 == 0) {
			return Power(base, exponent / 2) * Power(base, exponent / 2);
		}
		else {
			return Power(base, exponent / 2) * Power(base, exponent / 2) * base;
		}
	}
	else {
		if (exponent % 2 == 0) {
			return 1 / (Power(base, -exponent / 2) * Power(base, -exponent / 2));
		}
		else {
			return 1 / (Power(base, -exponent / 2) * Power(base, -exponent / 2) * base);
		}
	}
}

/* 
 * official answer
 */
bool g_InvalidInput = false;
double Power(double base, int exponent) {
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0) {
		absExponent = -exponent;
	}
	double result = PowerWithUnsignedExponent(base, absExponent);
	result *= result;
	if (exponent < 0) {
		result = 1.0 / result;
	}
	return result;
}

double PowerWithUnsignedExponent(double base, int exponent) {
	if (exponent == 0) {
		return 1;
	}
	if (exponent == 1) {
		return base;
	}
	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1) {
		result *= base;
	}
	return result;
}