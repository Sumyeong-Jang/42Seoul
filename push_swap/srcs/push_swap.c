#include "../include/push_swap.h"

static void	sort_stack(t_stack *stack);

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	stack->a = get_stack_a(argc, argv);
	if (!is_sorted(stack->a))//is_sorted == 0 이면 error (sorting 안된 것) (내가 ! 추가함)
		exit(EXIT_FAILURE);
	stack->b = init_info();
	sort_stack(stack);
	free_t_lists(stack);
	return (0);
}

static void	sort_stack(t_stack *stack)
{
	if (stack->a->size <= 5)
		sort_small(stack);
	else
		sort_large(stack);
}