/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------
Write a function that determines if a given number is a power of 2.
This function returns 1 if the given number is a power of 2,
otherwise it returns 0.

Your function must be declared as follows:
int	is_power_of_2(unsigned int n);

	判断一个 unsigned int 数字 n 是不是 2 的幂
		如果 n 是 2 的幂，返回 1
		如果 n 不是 2 的幂，返回 0
	“2 的幂”意思是这个数可以写成：
		2^0, 2^1, 2^2, 2^3, ...
		即 1, 2, 4, 8, 16, 32, 64, 128, ...
	注意：1 也是 2 的幂，因为：2^0 = 1, 但0 不是 2 的幂
	如果一个数真的是 2 的幂，那么它应该可以一直被 2 整除，直到最后变成 1

	核心代码：
	n % 2 == 0 表示n 能被 2 整除，即n是偶数
*/

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n = n / 2;
	if (n == 1)
		return (1);
	else
		return (0);
}
