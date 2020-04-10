#include<stdio.h>

int main()
{
    int total_marks[100], sub_marks[20], temp_marks[100], rank[100], final_marks[100];
    int num, sub,i,j,k, sum = 0, temp;

    printf("\n*Welcome to Student's Result Management System*\n\n");

    printf("Number of Student(s): ");
    scanf("%d",&num);

    printf("Number of Subject(s): ");
    scanf("%d",&sub);

    for(i=0;i<num;i++)
    {
        printf("\nEnter Subject Marks for Roll No %d ---->\n",i+1);

        for(j=1;j<=sub;j++)
        {
            printf("Subject %d: ",j);
            scanf("%d",&sub_marks[j]);
            sum = sum + sub_marks[j];
        }
        total_marks[i] = sum;
        printf("\nRoll No %d obtained %d\n\n", i+1, total_marks[i]);
        sum =0;
    }

    for(i=0;i<num;i++)
    {
        temp_marks[i] = total_marks[i];
    }

    for(i=1;i<num;i++)
	{
		temp = temp_marks[i];
		j=i-1;
		while(temp>temp_marks[j] && j>=0)
        {
            temp_marks[j+1] = temp_marks[j];
			--j;
		}
		temp_marks[j+1]=temp;
	}

	for(i=0;i<num;i++)
    {
        final_marks[i] = temp_marks[i];
    }

	for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(temp_marks[i]==total_marks[j])
            {
                rank[i] = j+1;
                temp_marks[i] = -1;
                total_marks[j] = -2;
            }
        }
    }

    for(i=0;i<num;i++)
    {
        printf("_________________________________________\n");
        printf("New Roll No: %d\n", i+1);
        printf("Total Marks Obtained: %d\n", final_marks[i]);
        printf("Previous Roll No: %d\n", rank[i]);
        printf("_________________________________________");
        printf("\n\n");

    }



    return 0;
}
