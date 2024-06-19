//There is a greedy approach to solve the problem. 
//Just try first digit from lower values to higher (in subtask to minimize number) and 
//check if it is possible to construct a tail in such a way that it satisfies rule about length/sum.
// You can use a function `can(m,s)' that answers if it is possible to construct a sequence of length m with the sum of digits s:
bool can(int m, int s)
{
    return s >= 0 && s <= 9 * m;
}
//Using the function can(m,s) you can easily pick up answer digit-by-digit. For the first part of problem (to minimize number) this part of code is:
    int sum = s;
    for (int i = 0; i < m; i++)
        for (int d = 0; d < 10; d++)
            if ((i > 0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
            {
                minn += char('0' + d);
                sum -= d;
                break;
            }
//The equation (i > 0 || d > 0 || (m == 1 && d == 0)) is needed to be careful with leading zeroes.