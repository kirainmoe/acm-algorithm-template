/**
 * Greatest Common Divisor / 最大公约数
 * @param  int a
 * @param  int b
 * @return int
 */
int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

/**
 * Least Common Multiple / 最小公倍数
 * 
 * a * b = gcd(a, b) * lcm(a, b) => lcm(a, b) = a * b / gcd(a, b)
 * @param  int a 
 * @param  int b 
 * @return int
 */
int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}