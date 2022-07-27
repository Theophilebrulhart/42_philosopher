#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *test(void *i)
{
	int index = *(int *)i;
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *res;

	res = malloc(sizeof(*res));
	*res = array[index];
	free(i);
	return ((void*)res);
}

int	main(void)
{
	pthread_t thread[10];
	int i;
	int *alloc;
	int *res;

	i = 0;
	while (i < 10)
	{
		alloc = malloc(sizeof(*alloc));
		*alloc = i;
		if (pthread_create(&thread[i], NULL, &test, alloc) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(thread[i], (void**) &res) != 0)
			return (1);
		printf("res : %d\n", *res);
		i++;
	}
	
	return (0);
}