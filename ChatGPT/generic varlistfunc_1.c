#include <stdio.h>
#include <stdarg.h>

// Define the struct to hold return values
typedef struct {
	char c;
	int i;
	unsigned int u;
	float f;
	void* ptr; // Pointer to hold any additional data
} ReturnValues;

// Define a function pointer type
typedef ReturnValues (*FuncPtr)(int, ...);

// Define the struct to hold function pointers
typedef struct {
	FuncPtr func1;
	FuncPtr func2;
} FunctionPointerSet;

// Static global variable for ReturnValues
static ReturnValues returnValues;

// Example function implementations
ReturnValues exampleFunction1(int count, ...) {
	va_list args;
	va_start(args, count);
	
	for (int i = 0; i < count; i++) {
		if (i % 4 == 0) {
			returnValues.c = (char)va_arg(args, int);
			} else if (i % 4 == 1) {
			returnValues.i = va_arg(args, int);
			} else if (i % 4 == 2) {
			returnValues.u = va_arg(args, unsigned int);
			} else if (i % 4 == 3) {
			returnValues.f = (float)va_arg(args, double);
		}
	}
	
	va_end(args);
	
	// Example: set ptr to a static value or null
	returnValues.ptr = NULL; // Or point to some static data if needed
	
	return returnValues;
}

ReturnValues exampleFunction2(int count, ...) {
	va_list args;
	va_start(args, count);
	
	for (int i = 0; i < count; i++) {
		if (i % 4 == 0) {
			returnValues.c = (char)va_arg(args, int);
			} else if (i % 4 == 1) {
			returnValues.i = va_arg(args, int);
			} else if (i % 4 == 2) {
			returnValues.u = va_arg(args, unsigned int);
			} else if (i % 4 == 3) {
			returnValues.f = (float)va_arg(args, double);
		}
	}
	
	va_end(args);
	
	// Example: set ptr to a static value or null
	returnValues.ptr = NULL; // Or point to some static data if needed
	
	return returnValues;
}

// Function to initialize the FunctionPointerSet
FunctionPointerSet initFunctionPointerSet() {
	FunctionPointerSet fps = {
		.func1 = exampleFunction1,
		.func2 = exampleFunction2,
	};
	return fps;
}

int main() {
	// Initialize the function pointer set
	FunctionPointerSet a = initFunctionPointerSet();

	// Directly call the function pointer from the struct
	ReturnValues result1 = a.func1(4, 'A', 42, 100u, 3.14f);
	ReturnValues result2 = a.func2(4, 'B', 24, 200u, 2.71f);

	// Print the results
	printf("Function 1 - Char: %c, Int: %d, Unsigned Int: %u, Float: %.2f\n",
	result1.c, result1.i, result1.u, result1.f);
	printf("Function 2 - Char: %c, Int: %d, Unsigned Int: %u, Float: %.2f\n",
	result2.c, result2.i, result2.u, result2.f);

	return 0;
}
