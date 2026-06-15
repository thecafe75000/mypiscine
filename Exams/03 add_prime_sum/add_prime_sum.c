/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------
Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.
If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.
Yes, the examples are right.

Examples:
$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

	给程序传入 一个正整数参数，计算并输出 小于或等于这个数的所有质数之和，最后输出换行
	如果参数不合法：输出 0
	否则：从 2 遍历到 n, 如果当前数字是质数,加到 sum 里面
	输出 sum

	合法的参数只包含数字字符，并且数值大于 0
	需要自己写一个函数，功能和atoi函数一样，把字符串转成整数，同时检查是否合法

	质数：大于 1，并且只能被 1 和它自己整除的整数
	注意：
		0 不是质数
		1 不是质数
		2 是最小的质数
*/
