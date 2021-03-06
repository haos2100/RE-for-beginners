#include <stdint.h>
#include <windows.h>
#include <winnt.h>

// from the Numerical Recipes book:
#define RNG_a 1664525
#define RNG_c 1013904223

__declspec( thread ) uint32_t rand_state;

void my_srand (uint32_t init)
{
        rand_state=init;
}

int my_rand ()
{
	rand_state=rand_state*RNG_a;
	rand_state=rand_state+RNG_c;
	return rand_state & 0x7fff;
}

int main()
{
	my_srand(0x12345678);
	printf ("%d\n", my_rand());
};
