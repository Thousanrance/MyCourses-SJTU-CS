#include<cstdio>

char getPair(char c)
{
	if(c == ')')
    {
       return '(';
    }
	else if(c == ']')
    {
        return '[';
    }
	else if(c == '}')
    {
        return '{';
    }
	else
    {
        return '@';
    }
}

bool isMatch(char* seq, int length)
{
	if(length == 0)
    {
		return true;
	}
	char* stackk = new char[length];
	int top = 0;
	for(int i = 0; i < length; i++)
	{
		if(top == 0)
		{
			stackk[top] = seq[i];
			top++;
			continue;
		}
		if(stackk[top - 1] == getPair(seq[i]))
		{
			top--;
		}
		else
		{
			stackk[top] = seq[i];
			top++;
		}
	}
	delete[] stackk;
	if(top == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	int n = 0, ins = 0;
	char op = 0;
	scanf("%i", &n);

	char* stackk = new char[n];
	int top = 0;

	for(int i = 0; i < n; i++)
    {
		scanf(" %d", &ins);
		switch(ins)
		{
            case 1:
                {
                    scanf("%c",&op);
                    stackk[top] = op;
                    top++;
                    break;
                }
            case 2:
                    {
                        if(top != 0)
                        {
                            top--;
                        }
                        break;
                    }
            case 3:
                    {
                        if(top != 0)
                        {
                            printf("%c\n", stackk[top - 1]);
                        }
                        break;
                    }
            case 4:
                    {
                        if(isMatch(stackk, top))
                        {
                            printf("YES\n");
                        }
                        else
                        {
                            printf("NO\n");
                        }
                        break;
                    }
            default:break;
		}
	}
	delete [] stackk;
	return 0;
}
