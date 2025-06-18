// #include<stdio.h>

// int main()
// {
//     int n;
//     float value[20], weight[20], capacity, ratio[20], temp;
    
//     printf(" elements: ");
//     scanf("%d", &n);
    
//     printf(" values:\n");
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%f", &value[i]);
//     }

//     printf(" weights:\n");
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%f", &weight[i]);
//     }

//     printf("capacity: ");
//     scanf("%f", &capacity);

//     for(int i = 0; i < n; i++)
//     {
//         ratio[i] = value[i] / weight[i];
//     }

    
//     for(int i = 0; i < n - 1; i++)
//     {
//         for(int j = i + 1; j < n; j++)
//         {
//             if(ratio[i] < ratio[j])
//             {
               
//                 temp = ratio[j];
//                 ratio[j] = ratio[i];
//                 ratio[i] = temp;

                
//                 temp = value[j];
//                 value[j] = value[i];
//                 value[i] = temp;

                
//                 temp = weight[j];
//                 weight[j] = weight[i];
//                 weight[i] = temp;
//             }
//         }
//     }

//     float remaining_capacity = capacity;
//     float total_value = 0.0;

//     for(int i = 0; i < n; i++)
//     {
//         if(weight[i] <= remaining_capacity)
//         {
//             total_value += value[i];
//             remaining_capacity -= weight[i];
//         }
//         else
//         {
//             float fraction = remaining_capacity / weight[i];
//             total_value += fraction * value[i];
//             break;
//         }
//     }

//     printf("Total value = %.2f\n", total_value);

//     return 0;
// }




#include<stdio.h>


int main()
{
    float value[20],weight[20],ratio[20],capacity,total_value=0.0;
    int n;
    printf("Total Element:");
    scanf("%d",&n);
    printf("value = ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&value[i]);
    }
   printf("weight = ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&weight[i]);
    }

    printf("capacity ");
   scanf("%f",&capacity);

   for(int i=0;i<n;i++)
   {
    ratio[i]=value[i]/weight[i];
   }

   for(int i=0;i<n-1;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        if(ratio[i]<ratio[j])
        {
            int temp=ratio[j];
            ratio[j]=ratio[i];
            ratio[i]= temp;


            temp=weight[j];
            weight[j]=weight[i];
            weight[i]=temp;


            temp=value[j];
            weight[j]=weight[i];
            weight[i]=temp;
        }
    }
   }

   float remaining_capacity=capacity;
   
   for(int i=0;i<n;i++)
   {
    if(weight[i]<=remaining_capacity)
    {
        total_value+=value[i];
        remaining_capacity-=weight[i];
    }

    else{
        float fraction=remaining_capacity/weight[i];
        total_value+=fraction*value[i];
        break;

    }
   }
   printf("Total value= %.2f",total_value);
   return 0;

}
