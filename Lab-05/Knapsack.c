#include<stdio.h>

int main()
{
    int n;
    float value[20], weight[20], capacity, ratio[20], temp;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter values:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &value[i]);
    }

    printf("Enter weights:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &weight[i]);
    }

    printf("Enter capacity: ");
    scanf("%f", &capacity);

    // Calculate ratio
    for(int i = 0; i < n; i++)
    {
        ratio[i] = value[i] / weight[i];
    }

    // Sort by ratio in descending order
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                // Swap ratio
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap value
                temp = value[j];
                value[j] = value[i];
                value[i] = temp;

                // Swap weight
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }

    float remaining_capacity = capacity;
    float total_value = 0.0;

    for(int i = 0; i < n; i++)
    {
        if(weight[i] <= remaining_capacity)
        {
            total_value += value[i];
            remaining_capacity -= weight[i];
        }
        else
        {
            float fraction = remaining_capacity / weight[i];
            total_value += fraction * value[i];
            break;
        }
    }

    printf("Total value = %.2f\n", total_value);

    return 0;
}
