#include <iostream>
#include <cstring>

using namespace std;

bool is_allowed_char(char ch,
                     char special_char[]="@*$,.\"",
                     int num_special_char=7)
{
    for(int i=0;i<num_special_char;i++)
    {
        if(ch==special_char[i])
        {
            return true;
        }
    }
    if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_equal(char ch1,char ch2)
{
    if((ch1==ch2)||((ch1-'a')==(ch2-'A'))||((ch2-'a')==(ch1-'A')))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_special_char(char ch,
                     char special_char[]="@#$",
                     int num_special_char=4)
{
    bool flag=false;
    for(int i=0;i<num_special_char;i++)
    {
        if(ch==special_char[i])
        {
            flag=true;
            break;
        }
    }
    return flag;
}

bool template_match(char src_str[],
                    char template_str[],
                    int template_length,
                    int start_end_index[2])
{
    bool found=false;
    char *template_offset=template_str;
    char *start_offset;
    char *origin_src=src_str;
    while(*src_str!='\0')
    {
        if(is_special_char(*src_str))
        {
            src_str++;
        }
        else
        {
            if(is_equal(*src_str,*template_offset))
            {
                if(template_offset==template_str)
                {
                    start_offset=src_str;
                }
                src_str++;
                template_offset++;
                if(template_offset-template_str==template_length)
                {
                    start_end_index[0]=start_offset-origin_src;
                    start_end_index[1]=src_str-origin_src;
                    found=true;
                }
            }
            else
            {
                template_offset=template_str;
                src_str++;
            }
        }
    }
    return found;
}

void delete_sub(char src_str[],
                int start_index,
                int end_index)
{
    int length_str=strlen(src_str);
    for(int i=end_index;i<=length_str;i++)
    {
        src_str[start_index]=src_str[i];
        start_index++;
    }
}

int main()
{
    int start_end[2];
    char src[20];
    int n;

    cin.getline(src,20);

    for(n=0;n<strlen(src);n++)
    {
        if(!is_allowed_char(src[n]))
        {
            cout<<src[n]<<endl;
            cout<<"输入不符合要求"<<endl;
            return 0;
        }
        if(n<20)
        {
            n++;
        }
        else
        {
            cout<<"输入不符合要求"<<endl;
            return 0;
        }
    }
    src[n]='\0';

    while(template_match(src,"Fd",2,start_end)
          ||template_match(src,"L4",2,start_end)
          ||template_match(src,"D26",3,start_end))
    {
        delete_sub(src,start_end[0],start_end[1]);
    }

    cout<<src;

    return 0;
}
