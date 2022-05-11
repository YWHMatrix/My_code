/* ANSI C 移植算法 */
static unsigned long int next = 1;//种子

int rand1()
{
    next = next * 1103515245 + 12345;
    return (unsigned int ) (next / 65536) % 32768;
}
