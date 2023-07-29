#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STACK_LENGTH 6
#define EMPTY (-1)

int stack_a[STACK_LENGTH];
int stack_b[STACK_LENGTH];
int topa = EMPTY;
int topb = EMPTY;

int	pusha(int value)
{
	if (topa >= STACK_LENGTH - 1)
		return (-1);

	topa++;
	stack_a[topa] = value;
	return (1);
}

int popa(void)
{
	int	temp;

	if (topa <= EMPTY)
		return INT_MIN;
	temp = stack_a[topa];
	stack_a[topa] = 0;
	topa--;
	return (temp);
}

int	pushb(int value)
{
	if (topb >= STACK_LENGTH - 1)
		return (-1);

	topb++;
	stack_b[topb] = value;
	return (1);
}

int popb(void)
{
	int	temp;

	if (topb <= EMPTY)
		return INT_MIN;
	temp = stack_b[topb];
	stack_b[topb] = 0;
	topb--;
	return (temp);
}

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
void	sa()
{
	int	temp1;
	int temp2;
	if (topa < 1)
		return ;
	
	temp1 = popa();
	temp2 = popa();
	pusha(temp1);
	pusha(temp2);
}

/*
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
*/

void	sb()
{
	int	temp1;
	int temp2;
	if (topb < 1)
		return ;
	
	temp1 = popb();
	temp2 = popb();
	pushb(temp1);
	pushb(temp2);
}

/*
ss : sa and sb at the same time
*/

void ss()
{
	sa();
	sb();
}

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
*/

void pa()
{
	int temp_b;
	
	if (topb < 0)
		return ;
	temp_b = popb();
	pusha(temp_b);
}

/*
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty
*/

void pb()
{
	int temp_a;
	
	if (topa < 0)
		return ;
	temp_a = popa();
	pushb(temp_a);
}

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
*/

void ra()
{
	int t_topa;
	int	temp;

	t_topa = topa;
	temp = 0;
	while (t_topa > 0)
	{
		temp = stack_a[t_topa];
		stack_a[t_topa] = stack_a[t_topa - 1];
		stack_a[t_topa - 1] = temp;
		t_topa--;
	}
}
/*
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
*/
void rb()
{
	int t_topb;
	int	temp;

	t_topb = topb;
	temp = 0;
	while (t_topb > 0)
	{
		temp = stack_b[t_topb];
		stack_b[t_topb] = stack_b[t_topb - 1];
		stack_b[t_topb - 1] = temp;
		t_topb--;
	}
}

/*
rr : ra and rb at the same time.
*/
void rr()
{
	ra();
	rb();
}


/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
*/

void rra()
{
	int temp;
	int	i;

	// [1][2][3][4]
	// [2][3][4][1]

	i = 0;
	temp = 0;
	while (i < topa)
	{
		temp = stack_a[i + 1];
		stack_a[i + 1] = stack_a[i];
		stack_a[i] = temp;
		i++;
	}
}



/*
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
*/
void rrb()
{
	int temp;
	int	i;

	i = 0;
	temp = 0;
	while (i < topb)
	{
		temp = stack_b[i + 1];
		stack_b[i + 1] = stack_b[i];
		stack_b[i] = temp;
		i++;
	}
}


/*
rrr : rra and rrb at the same time
*/

void rrr()
{
	rra();
	rrb();
}





int main()
{
	int i = 0;

	pusha(8);
	pusha(5);
	pusha(6);
	pusha(3);
	pusha(1);
	pusha(2);

	printf("sa\n");
	sa();
	while (i < STACK_LENGTH)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	printf("\n");


	printf("3 pb\n");
	pb();
	pb();
	pb();
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_b[i]);
		i++;
	}
	printf("\n");


	printf("rr\n");
	rr();
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_b[i]);
		i++;
	}
	printf("\n");


	printf("rrr\n");
	rrr();
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_b[i]);
		i++;
	}
	printf("\n");

	
	
	
	printf("sa\n");
	sa();
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_b[i]);
		i++;
	}
	printf("\n");



	printf("3 pa\n");
	pa();
	pa();
	pa();
	i = 0;
	while (i < 6)
	{
		printf("%d ", stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 3)
	{
		printf("%d ", stack_b[i]);
		i++;
	}
	printf("\n");

	return (0);
}



/*

int main(int ac, char **av)
{
	pusha(1);
	pusha(2);
	pusha(3);
	pusha(4);


	printf("before sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	sa();
	printf("after sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);


	pushb(1);
	pushb(2);
	pushb(3);


	printf("before sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);
	sb();
	printf("after sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);


	printf("using pa\n");
	printf("before pa | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	printf("before pa | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);
	pa();
	printf("after pa | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	printf("after pa | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);
	

	printf("using pb\n");
	printf("before pb | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	printf("before pb | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);
	pb();
	printf("after pb | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	printf("after pb | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);


	printf("using ra\n");
	printf("before ra | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	ra();
	printf("after ra | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);


	printf("using rb\n");
	printf("before rb | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);
	rb();
	printf("after rb | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);


	printf("using rr\n");
	printf("before rr | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	printf("before rr | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);
	rr();
	printf("after rr | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	printf("after rr | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);

	
	printf("Using rra\n");
	printf("before rra | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	rra();
	printf("after rra | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);


	printf("Using rrb\n");
	printf("before rrb | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);
	rrb();
	printf("after rrb | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);


	printf("using rrr\n");
	printf("before rrr | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	printf("before rrr | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);
	rrr();
	printf("after rrr | sa -> %d %d %d %d %d\n", stack_a[0], stack_a[1], stack_a[2], stack_a[3], stack_a[4]);
	printf("after rrr | sb -> %d %d %d %d %d\n", stack_b[0], stack_b[1], stack_b[2], stack_b[3], stack_b[4]);

	return (0);
}

*/